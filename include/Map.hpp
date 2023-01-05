#ifndef MAP_HPP
# define MAP_HPP


#include <memory>

#include <map>

#include "Pair.hpp"
#include "map_iterator.hpp"
#include "print_map.hpp"
#include "utilities.hpp"

#define HIGHER true
#define LOWER false

namespace ft{

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class Map{
		public:
		// typedef 
			typedef map_node<Key, T, Allocator>							node;
			typedef const Key											key_type;
			typedef T													mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;

			typedef ft::map_iterator<Key, T, Allocator, false>						iterator;
			typedef ft::map_iterator<Key, T, Allocator, true>						const_iterator;
			typedef ft::reverse_map_iterator<Key, T, Allocator, false>				reverse_iterator;
			typedef ft::reverse_map_iterator<Key, T, Allocator, true>				const_reverse_iterator;

		//member functions
			Map():_root(NULL), _nb_node(0){};
			explicit Map( const Compare& comp, const Allocator& alloc = Allocator()):_root(NULL), _nb_node(0){};
			template< class InputIt > Map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):_root(NULL), _nb_node(0){
				while (first != last){
					add_node(*first);
					first++;
				}
			};
			Map( const Map& other ):_root(NULL), _nb_node(0){
				bool first = true;
				for (iterator i = other.begin(); i != other.end(); i++){
						add_node(*i);
				}
			};
			~Map(){
				clear();
			};
			Map& operator=( const Map& other ){
				clear();
				int count = 0;

				// print_node(_root);
				for (iterator i = other.begin(); i != other.end(); i++){
					add_node(*i);
					count++;
					// std::cout << count << " node added " << std::endl;
				}
				// print_node(_root);
				// copy_ordered(other.begin(), other.size());
				return (*this);
			};
			allocator_type get_allocator() const{return _alloc;};

		//element access
			T& at( const Key& key ){
				iterator reader = find(key);
				if (!reader)
					throw (out_of_range_exception());
				else
					return reader->second;
			};
			const T& at( const Key& key ) const{
				node* reader = find(key);
				if (!reader)
					throw (out_of_range_exception());
				else
					return reader->Second();
			};
			T& operator[]( const Key& key ){
				iterator reader = find(key);
				if (reader)
					return reader->second;
				else
					add_node(ft::pair< Key, T >(key, T()) );
				reader = find(key);
				return reader->second;
			};
			node*	getRoot(){
				return _root;
			}

		//iterators
			iterator begin(){
				node* reader = _root;
				while (reader && reader->getChild_l())
					reader = reader->getChild_l();
				return iterator(reader, _root);
			};
			const_iterator begin() const{
				node* reader = _root;
				while (reader && reader->getChild_l())
					reader = reader->getChild_l();
				return const_iterator(reader, _root);
			};
			iterator end(){
				// iterator ret (NULL, _root);
			// if (std::is_same<Compare, std::plus<Key> >::value == true)
			// 	std::cout << "in map Compare is stdplus " << std::endl;
			// else
			// 	std::cout << " in map Compare is wrong "<< std::endl;
			return iterator(NULL, _root);
			};
			const_iterator end() const{
				// iterator ret (NULL, _root);
				return const_iterator(NULL, _root);
			};
			reverse_iterator rbegin(){
				node* reader = _root;
				while (reader && reader->getChild_r())
					reader = reader->getChild_r();
				reverse_iterator ret (reader, _root);
				return ret;
			};
			const_reverse_iterator rbegin() const{
				node* reader = _root;
				while (reader && reader->getChild_r())
					reader = reader->getChild_r();
				reverse_iterator ret (reader, _root);
				return ret;
			};
			reverse_iterator rend(){
				reverse_iterator ret (NULL, _root);
				return ret;
			};
			const_reverse_iterator rend() const{
				reverse_iterator ret (NULL, _root);
				return ret;
			};

		//capacity
			bool empty() const{
				if (_root)
					return false;
				else
					return true;
			};
			size_type size() const{
				return _nb_node;
			};
			size_type max_size() const{
				return _alloc.max_size();
			};

		//modifiers
			void clear(){
				while (_nb_node){
					node* reader(_root);
					while (reader->getChild_l() || reader->getChild_r()){
						if (reader->getChild_l())
							reader = reader->getChild_l();
						else if (reader->getChild_r())
							reader = reader->getChild_r();
					}
					delete_node(reader);
					// std::cout << "here " << _nb_node << std::endl;
				}
				_root = NULL;
			};
			ft::pair<iterator, bool> insert(const value_type& value ){
				iterator reader = find(value.first);
				if (reader != end()){
					iterator ret (reader.getNode_pointer(), _root);
					return ft::make_pair(ret, false);
				};
				iterator ret (add_node(value), _root);
				return (ft::make_pair(ret, true));
			};
			iterator insert( iterator pos, const value_type& value ){
				iterator reader = find(value.first);
				if (reader)
					return reader;
				return iterator(add_node(value), _root);
			};
			template< class InputIt > void insert( InputIt first, InputIt last ){
				for (InputIt i = first; i != last; i++){
					if (!find(i->first))
						add_node(*i);
				}
			};
			iterator erase( iterator pos ){
				delete_node(pos.getNode_pointer());
				return iterator(NULL, _root);
			};
			iterator erase( iterator first, iterator last ){
				iterator previous(NULL, _root);
				for (iterator i = first; i != last; i++){
					if (previous.getNode_pointer())
						delete_node(previous.getNode_pointer());
					previous = i;
				}
				if (previous.getNode_pointer())
					delete_node(previous.getNode_pointer());
				return iterator(NULL, _root);
			};
			size_type erase( const Key& key ){
				// std::cout << "begin to erase" << std::endl;
				iterator reader = find(key);
				// std::cout << "after find " << std::endl;
				if (reader && reader.getNode_pointer()){
					delete_node(reader.getNode_pointer());
					// std::cout << " erased " << std::endl;
					return 1;
				}
				// std::cout << "erased " << std::endl;
				return 0;
			};
			void swap( Map& other ){
				ft::swap(this->_root, other._root);
				ft::swap(this->_nb_node, other._nb_node);
			};

		//lookup
			size_type count( const Key& key ) const{
				if (find(key))
					return 1;
				return 0;
			};
			iterator find( const Key& key ){
				node* reader = _root;
				// std::cout << "before in find " << key << std::endl;
				while(reader && reader->First() != key){
					// std::cout << "looking for " << reader->First() << std::endl;
					if (_compare(reader->First(), key))
						reader = reader->getChild_r();
					else 
						reader = reader->getChild_l();
				}
				// std::cout << "after in find : " << reader << std::endl;
				iterator ret (reader, _root);
				return (ret);
			};
			const_iterator find( const Key& key ) const{
				for (iterator i = begin(); i != end(); i++){
					if (i->first == key)
						return (i);
				}
				return const_iterator(NULL, _root);
			};
			ft::pair<iterator,iterator> equal_range( const Key& key ){
				ft::pair<iterator, iterator> ret;
				for (iterator i = begin(); i != end(); i++){
					if (!_compare(i->first, key) && i->first == key){
						ret.first = i;
						i++;
						ret.second = i;
						break ;
					}
					else if (!_compare(i->first, key)){
						ret.first = i;
						ret.second = i;
						break ;
					}
				}
				return ret;
			};
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				ft::pair<iterator, iterator> ret;
				for (iterator i = begin(); i != end(); i++){
					if (!_compare(i->first(), key) && i->first() == key){
						ret.first = i;
						i++;
						ret.second = i;
						break ;
					}
					else if (!_compare(i->first(), key)){
						ret.first = i;
						ret.second = i;
						break ;
					}
				}
				return ret;
			};
			iterator lower_bound( const Key& key ){
				node* reader = _root;
				while (reader && _compare(reader->First(), key))
					reader = reader->getChild_r();
				while (reader && reader->getChild_l() && _compare(key, reader->getChild_l()->First()))
					reader = reader->getChild_l();
				return iterator(reader, _root);
			};
			const_iterator lower_bound( const Key& key ) const{
				node* reader = _root;
				while (reader && _compare(reader->First(), key))
					reader = reader->getChild_r();
				while (reader && reader->getChild_l() && _compare(key, reader->getChild_l()->First()))
					reader = reader->getChild_l();
				return const_iterator(reader, _root);
			};
			iterator upper_bound( const Key& key ){
				node* reader = _root;
				// std::cout << "begin upper bound with key : " << key << " and reader : " << reader << " and root : " << _root << std::endl;
				while (reader && _compare(reader->First(), key)){
					// std::cout << "first loop " << std::endl;
					reader = reader->getChild_r();
				}
				// std::cout << "between loop" <<  std::endl;
				while (reader && reader->getChild_l() && _compare(key, reader->getChild_l()->First())){
					// std::cout << " second loop" << std::endl;
					reader = reader->getChild_l();
				}
				// std::cout << " end of upper bound" << std::endl;
				return iterator(reader, _root);
			};
			const_iterator upper_bound( const Key& key ) const{
				node* reader = _root;
				// std::cout << "begin upper bound with key : " << key << " and reader : " << reader << " and root : " << _root << std::endl;
				while (reader && _compare(reader->First(), key)){
					// std::cout << "first loop " << std::endl;
					reader = reader->getChild_r();
				}
				// std::cout << "between loop" <<  std::endl;
				while (reader && reader->getChild_l() && _compare(key, reader->getChild_l()->First())){
					// std::cout << " second loop" << std::endl;
					reader = reader->getChild_l();
				}
				// std::cout << " end of upper bound" << std::endl;
				return const_iterator(reader, _root);
			};

		//observer
			key_compare key_comp() const{return _compare;};
			Compare value_comp() const{return comp_node;};
	
		// exception
			class out_of_range_exception: public std::exception{
			public:
				const char* what() const throw(){
					return ("Error : out of range exception");
				};
			};
		private:
			bool	comp_node(ft::pair<const Key, T> one, ft::pair<const Key, T> two){
				return Compare(one.first, two.first);
			}
		//private attribute
			node*						_root;
			size_type												_nb_node;
			std::allocator < node >	_alloc;
			Compare													_compare;

		// nodes manipulation functions
			node* new_node(value_type value){
				// node model(value);
				node* temp = _alloc.allocate(1);
				_alloc.construct(temp, value);
				_nb_node++;
				// std::cout << "new_node created : " << temp << "|" << temp->getChild_l() << "|" << temp->getChild_r() << "|" << temp->getParent() << std::endl;
				// if (temp == _root)
				// 	std::cout << "it's over 9999999999 impossible " << std::endl;
				return temp;
			};
			node*	add_node(value_type value){
				// std::cout << " adding node : " << value.first << std::endl;
				if (!_root){
					_root = new_node(value);
					return _root;
				}
				for (iterator i = begin(); i != end(); i++){
					if (i->first == value.first)
						return i.getNode_pointer();
				}
				// std::cout << "adding node " << std::endl;
				node* reader = _root;
				int stage = 0;
				while (reader->getChild_l()){
					stage++;
					reader = reader->getChild_l();
				}
				node* last = _root;
				int stage_of_last = 0;
				while (last->getChild_r()){
					stage_of_last++;
					last = last->getChild_r();
				}
				// std::cout << " mid adding node " << std::endl;
				if (stage > stage_of_last && reader != last){
					node* ret = add_on_same_stage(reader, value);
					// std::cout << "node added : " << value.first << std::endl;
					ret = put_in_place(ret);
					reordering(_root);
					return ret;
				}
				else{
					node* ret = add_new_stage(value);
					// std::cout << "node added" << std::endl;
					ret = put_in_place(ret);
					reordering(_root);
					return ret;
				}

				// node* reader = _root;
				// if (!_root){
				// 	_root = new_node(value);
				// }
				// while (reader){
				// 	if (value.first == reader->First()){
				// 		reader->setSecond(value.second);
				// 		return reader;
				// 	}
				// 	else if (reader->getChild_l() != NULL && _compare(value.first, reader->First())){
				// 		reader = reader->getChild_l();
				// 	}
				// 	else if (reader->getChild_r() != NULL && _compare(reader->First(), value.first)){
				// 		reader = reader->getChild_r();
				// 	}
				// 	else if (_compare(value.first, reader->First())){
				// 		add_child_l(reader, new_node(value));
				// 		return reader->getChild_l();
				// 	}
				// 	else if (_compare(reader->First(), value.first)){
				// 		add_child_r(reader, new_node(value));
				// 		return reader->getChild_r();
				// 	}
				// }
				// return _root;
			};
			void	reordering(node* target){
				if (_root->getChild_l() && _compare(_root->getContent()->first, _root->getChild_l()->getContent()->first) == _compare(_root->getChild_l()->getContent()->first, _root->getContent()->first))
					return ;
				else if (_root->getChild_r() && _compare(_root->getContent()->first, _root->getChild_r()->getContent()->first) == _compare(_root->getChild_r()->getContent()->first, _root->getContent()->first))
					return ;
				if (!target)
					return ;
				else if (target == put_in_place(target)){
					// put_in_place(target);
					reordering(target->getChild_l());
					reordering(target->getChild_r());
				}
				else
					reordering(_root);
			};
			node*	put_in_place(node* target){
				if (_root->getChild_l() && _compare(_root->getContent()->first, _root->getChild_l()->getContent()->first) == _compare(_root->getChild_l()->getContent()->first, _root->getContent()->first))
					return target;
				else if (_root->getChild_r() && _compare(_root->getContent()->first, _root->getChild_r()->getContent()->first) == _compare(_root->getChild_r()->getContent()->first, _root->getContent()->first))
					return target;
				if (!target)
					return target;
				// std::cout << "starting tidying root is : " << _root->getContent()->first << " target is : " << target->getContent()->first << " map size is : " << _nb_node << std::endl;
				// if (target->getPos() == HIGHER)
				// 	std::cout << "i'm higher " << std::endl;
				// else
				// 	std::cout << " i'm lower " << std::endl;
				if (target->getParent() && check_parents(*target->getContent(), target) ){
					// std::cout << " first path " << std::endl;
					// && !_compare(target->getParent()->getContent()->first, target->getContent()->first)
					swap_parent(target);
					return put_in_place(target->getParent());
				}
				else if (target->getParent() && check_parents(*target->getContent(), target)){
					// std::cout << " second path " << std::endl;
					// !_compare(target->getContent()->first, target->getParent()->getContent()->first) &&
					swap_parent(target);
					return put_in_place(target->getParent());
				}
				else if (target->getChild_l() && _compare(target->getContent()->first, target->getChild_l()->getContent()->first)){
					// std::cout << "thirs path " << std::endl;
					// ! && _compare(target->getChild_l()->getContent()->first, target->getContent()->first)
					swap_child_l(target);
					return put_in_place(target->getChild_l());
				}
				else if (target->getChild_r() && _compare(target->getChild_r()->getContent()->first, target->getContent()->first)){
					// std::cout << " fourth path " << std::endl;
					// !_compare(target->getContent()->first, target->getChild_l()->getContent()->first) && 
					swap_child_r(target);
					return put_in_place(target->getChild_r());
				}
				else{
					// print_node(_root);
					// std::cout << "tidying done -------------- " << std::endl;
					return target;
				}
			};
			bool	check_parents(value_type& to_check, node* target) const{
				while (target->getParent()){
					if (target->getPos() == HIGHER && _compare(to_check.first, target->getParent()->getContent()->first))
						return true;
					else if (target->getPos() == LOWER &&  _compare(target->getParent()->getContent()->first, to_check.first))
						return true;
					else
						target = target->getParent();
				}
				return false;
			};
			node*	add_on_same_stage(node* reader, value_type value){
				int stage = 0;
				while (reader->getParent() && reader->getPos() == HIGHER){
					stage++;
					reader = reader->getParent();
				}
				if (reader->getParent() && reader->getPos() == LOWER){
					stage++;
					reader = reader->getParent();
				}
				if (reader->getChild_r()){
					stage--;
					reader = reader->getChild_r();
				}
				else{
					node* new_child = new_node(value);
					add_child_r(reader, new_child);
					return new_child;
				}
				while (reader->getChild_l() && stage > 0){
					stage--;
					reader = reader->getChild_l();
				}
				if (stage <= 0)
					return (add_on_same_stage(reader, value));
				else{
					node* new_child = new_node(value);
					add_child_l(reader, new_child);
					return new_child;
				}

			};
			node*	add_new_stage(value_type value){
				node* reader = _root;
				while (reader->getChild_l()){
					reader = reader->getChild_l();}
				node* added = new_node(value);
				add_child_l(reader, added);
				return added;
			};
			void	extract_node(node* target){
				if (!target->getChild_l() && target->getChild_r()){
					if (target->getPos() == HIGHER){
						add_child_r(target->getParent(), target->getChild_r());}
					else if (target->getPos() == LOWER){
						add_child_l(target->getParent(), target->getChild_r());}
				}
				else if (!target->getChild_r() && target->getChild_l()){
					if (target->getPos() == HIGHER)
						add_child_r(target->getParent(), target->getChild_l());
					else if (target->getPos() == LOWER)
						add_child_l(target->getParent(), target->getChild_l());
				}
				else if (target->getChild_r() && target->getChild_l()){
					if (target->getPos() == HIGHER){
						add_child_r(target->getParent(), target->getChild_r());
						reposition_node(target->getChild_l());
					}
					else if (target->getPos() == LOWER){
						add_child_l(target->getParent(), target->getChild_r());
						reposition_node(target->getChild_l());
					}
				}
				else if (!target->getChild_l() && !target->getChild_r()){
					if (target->getPos() == HIGHER)
						target->getParent()->setChild_r(NULL);
					else if (target->getPos() == LOWER)
						target->getParent()->setChild_l(NULL);
				}
			};
			void	extract_root(){
				if (!_root->getChild_l() && _root->getChild_r()){
					_root = _root->getChild_r();
					_root->setParent(NULL);
				}
				else if (!_root->getChild_r() && _root->getChild_l()){
					_root = _root->getChild_l();
					_root->setParent(NULL);
				}
				else if (_root->getChild_r() && _root->getChild_l()){
					_root = _root->getChild_r();
					reposition_node(_root->getParent()->getChild_l());
				}
			};
			void	delete_node(node* target){
				if (target == _root){
					delete_root();
					return ;
				}
				extract_node(target);
				_alloc.destroy(target);
				_alloc.deallocate(target, 1);
				_nb_node--;
				if (_nb_node == 0)
					_root = NULL;
			};
			void	delete_root(){
				node* temp = _root;
				if (_nb_node > 1){
					extract_root();}
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				_nb_node--;
				if (_nb_node == 0)
					_root = NULL;
			};
			void	reposition_node(node* x){
				node* reader = _root;
				while (reader->getChild_l() && reader->getChild_r()){
					if (reader->getChild_l() && _compare(x->First(), reader->First()))
						reader = reader->getChild_l();
					else if (reader->getChild_r() && _compare(reader->First(), x->First()))
						reader = reader->getChild_r();
					else if (!reader->getChild_l() && _compare(x->First(), reader->First()))
						add_child_l(reader, x);
					else if (!reader->getChild_r() && _compare(reader->First(), x->First()))
						add_child_r(reader, x);
				}
			};
			void	add_child_l(node* parent, node* child){
				if (parent == child)
					return ;
				parent->setChild_l(child);
				child->setParent(parent);
				child->setPos(LOWER);
			};
			void	add_child_r(node* parent, node* child){
				if (parent == child)
					return ;
				parent->setChild_r(child);
				child->setParent(parent);
				child->setPos(HIGHER);
			};
			void	copy_ordered(iterator begin, size_type size){
				if (size < 1){
					return ;
				}
				iterator new_root = find_middle(begin, size);
				std::cout << " i begin with node : " << new_root->first << " size is " << size << std::endl;
				if (new_root.getNode_pointer())
					insert(*new_root);
				if (size % 2 && size > 1)
					size ++;
				if (size > 1){
					copy_ordered(begin, size / 2);
					copy_ordered(new_root, size / 2);
				}
			};
			iterator	find_middle(iterator begin, size_type size){
				if (!begin.getNode_pointer())
					return begin;
				if (size < 2)
					return begin;
				if (size % 2)
					size++;
				for (size_t i = 0; i < size / 2; i++)
					begin++;
				return begin;
			}
			void	swap_child_r(node* target){
				if (!target || !target->getChild_r())
					return ;
				swap_nodes(target, target->getChild_r());
				// value_type* temp = target->getChild_r()->getContent();
				// target->getChild_r()->setContent(target->getContent());
				// target->setContent(temp);
			};
			void	swap_child_l(node* target){
				if (!target || !target->getChild_l())
					return ;
				swap_nodes(target, target->getChild_l());
				// value_type* temp = target->getChild_l()->getContent();
				// target->getChild_l()->setContent(target->getContent());
				// target->setContent(temp);
			};
			void	swap_parent(node* target){
				if (!target || !target->getParent())
					return ;
				swap_nodes(target, target->getParent());
				// value_type* temp = target->getParent()->getContent();
				// target->getParent()->setContent(target->getContent());
				// target->setContent(temp);
			};
			void	swap_nodes(node* first, node* second){
				if (!first || !second)
					return ;
				// std::cout << "here i begin switching" << std::endl;
				node* pp = first->getParent();
				node* pcl = first->getChild_l();
				node* pcr = first->getChild_r();
				bool tmp_pos = first->getPos();
				first->setParent(second->getParent());
				first->setChild_l(second->getChild_l());
				first->setChild_r(second->getChild_r());
				first->setPos(second->getPos());
				second->setPos(tmp_pos);
				second->setParent(pp);
				second->setChild_l(pcl);
				second->setChild_r(pcr);
				reciprocate_link(first);
				reciprocate_link(second);
				// std::cout << "switch done " << std::endl;
			};
			void	reciprocate_link(node* target){
				// std::cout << "reciprocate " << std::endl;
				if (target->getParent() && target->getPos() == HIGHER)
					target->getParent()->setChild_r(target);
				else if (target->getParent() && target->getPos() == LOWER)
					target->getParent()->setChild_l(target);
				if (target->getChild_l())
					target->getChild_l()->setParent(target);
				if (target->getChild_r())
					target->getChild_r()->setParent(target);
				if (target->getParent() == target)
					target->setParent(NULL);
				if (target->getChild_l() == target)
					target->setChild_l(NULL);
				if (target->getChild_r() == target)
					target->setChild_r(NULL);
			};
			// void	swapChild_l(node* parent){
			// 	if (!parent->getChild_l())
			// 		return ;
				// node* pp = parent->getParent();
				// node* pcl = parent->getChild_l();
				// node* pcr = parent->getChild_r();
				// bool tmp_pos = parent->getPos();
				// node* child = pcl;
				// parent->setParent(child->getParent());
				// parent->setChild_l(child->getChild_l());
				// parent->setChild_r(child->getChild_r());
				// parent->setPos(child->getPos());
				// child->setPos(tmp_pos);
				// child->setParent(pp);
				// child->setChild_l(pcl);
				// child->setChild_r(pcr);
			// };
			// void	swapChild_r(node* parent){
			// 	if (!parent->getChild_r())
			// 		return ;
			// 	node* pp = parent->getParent();
			// 	node* pcl = parent->getChild_l();
			// 	node* pcr = parent->getChild_r();
			// 	bool tmp_pos = parent->getPos();
			// 	node* child = pcr;
			// 	parent->setParent(child->getParent());
			// 	parent->setChild_l(child->getChild_l());
			// 	parent->setChild_r(child->getChild_r());
			// 	parent->setPos(child->getPos());
			// 	child->setPos(tmp_pos);
			// 	child->setParent(pp);
			// 	child->setChild_l(pcl);
			// 	child->setChild_r(pcr);
			// };
		// private template map node
			// class map_node{
			// 	public:
			// 		map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
			// 		map_node(U	content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){
			// 			_content = Allocator.allocate(1);
			// 			Allocator.construct(_content, content);
			// 		};
			// 		map_node(map_node other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(NULL){
			// 			_content = Allocator.allocate(1);
			// 			Allocator.construct(_content, other._content);
			// 		};
			// 		~map_node(){
			// 			if (_content){
			// 				Allocator.destroy(_content);
			// 				Allocator.deallocate(_content, 1);
			// 			}
			// 		};
			// 		Key&	First(){
			// 			return _content.first;
			// 		};
			// 		T&		Second(){
			// 			return _content.second;
			// 		};
			// 		void	setSecond(T& value){
			// 			_content.second = value;
			// 		};
			// 		void	setParent(map_node* parent){
			// 			_parent = parent;
			// 		};
			// 		void	setChild_l(map_node* child){
			// 			_child_l = child;
			// 		};
			// 		void	setChild_r(map_node* child){
			// 			_child_r = child;
			// 		};
			// 		map_node*	getParent(){
			// 			return _parent;
			// 		};
			// 		map_node*	getChild_l(){
			// 			return _child_l;
			// 		};
			// 		map_node*	getChild_r(){
			// 			return _child_r;
			// 		};
			// 		ft::pair<const Key, T>*	getContent(){
			// 			return _content;
			// 		}
			// 		ft::pair<const Key, T>& operator *(){
			// 			return *_content;
			// 		};

			// 	private:
			// 		map_node*				_parent;
			// 		map_node*				_child_l;
			// 		map_node*				_child_r;
			// 		ft::pair<const Key, T>*	_content;
			// };

		protected:
	};
	template< class Key, class T, class Compare, class Alloc > bool operator==( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		ft::map_iterator<Key, T, Alloc, false> i = lhs.begin(), j = rhs.begin();
		while (i && j){
			if (*i != *j)
				return false;
			i++;
			j++;
		}
		return (i == j);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator!=( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
		return !(rhs == lhs);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator<( const Map<Key,T,Compare,Alloc>& lhs,  const Map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() < rhs.size())
			return true;
		ft::map_iterator<Key, T, Alloc, false> i = lhs.begin(), j = rhs.begin();
		while (i && j){
			if (*i < *j)
				return true;
			i++;
			j++;
		}
		return (i < j);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator<=( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs > rhs);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator>( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator>=( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs < rhs);
	};
};

//check add_node and make a tidying function

#endif
