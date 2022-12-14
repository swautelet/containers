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
				// std::cout << "clear before copy" << std::endl;
				for (iterator i = other.begin(); i != other.end(); i++){
					add_node(*i);
					count++;
					// std::cout << count << " node added " << std::endl;
				}
				// ordered_copy(other);
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
				if (reader){
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
				// std::cout << "after in find " << std::endl;
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
				node* reader = _root;
			// std::cout << "begin adding" << std::endl;
				if (!_root){
					_root = new_node(value);
					// std::cout << "first node " << std::endl;
				// 	std::cout << "reader is " << _root->First() << std::endl;
				// std::cout << "value " << value.first << std::endl;
				}
				tidying_tree();
				// if (!(_nb_node % 100)){
				// 	ft::Map<Key, T, Compare, Allocator> temp;
				// 	temp = (*this);
				// 	*this = temp;
				// }
				// else{
				// 	std::cout << "reader is " << reader << std::endl;
				// 	std::cout << reader->getChild_r() << std::endl;
				// std::cout << "value " << value.first << std::endl;
				// }
				while (reader){
					
					if (value.first == reader->First()){
						reader->setSecond(value.second);
						// std::cout << "assigned" << std::endl;
						return reader;
					}
					else if (reader->getChild_l() != NULL && _compare(value.first, reader->First())){
						reader = reader->getChild_l();
						// std::cout << "looping left" << std::endl;
					}
					else if (reader->getChild_r() != NULL && _compare(reader->First(), value.first)){
						// std::cout << "looping right : " << reader << " " << reader->getChild_l() << " " << reader->getChild_r() << std::endl;
						// std::cout << reader->First() << "|" << reader->getChild_r()->First() << std::endl;
						reader = reader->getChild_r();
					}
					else if (_compare(value.first, reader->First())){
						add_child_l(reader, new_node(value));
						// std::cout << "done adding left" << std::endl;
				// 		std::cout << "reader is " << reader->First() << std::endl;
				// std::cout << "value " << value.first << std::endl;
						return reader->getChild_l();
					}
					else if (_compare(reader->First(), value.first)){
						add_child_r(reader, new_node(value));
						// std::cout << "done adding right" << std::endl;
				// 		std::cout << "reader is " << reader->First() << std::endl;
				// std::cout << "value " << value.first << std::endl;
						return reader->getChild_r();
					}
					// else 
					// 	std::cout << "hello from loop " << reader << " " << reader->getChild_l() << " " << reader->getChild_r() << std::endl;
				}
				// std::cout << "done adding" << std::endl;
				// reorder_map();
				return _root;
			};
			void	extract_node(node* target){
				// std::cout << " i try to extract node " << target->First() << " root is : " << _root->First() << std::endl;
				if (!target->getChild_l() && target->getChild_r()){
					// std::cout << "first case : " << target->getParent()->First() << " with : " << target->getChild_r()->First() << std::endl;
					if (target->getPos() == HIGHER){
						add_child_r(target->getParent(), target->getChild_r());}
					else if (target->getPos() == LOWER){
						add_child_l(target->getParent(), target->getChild_r());}
					// std::cout << "after : " << target->getParent()->getChild_r()->First() << " and : " << target->getChild_r()->getParent()->First() << std::endl;
				}
				else if (!target->getChild_r() && target->getChild_l()){
					// std::cout << "second  case : " << target->getParent()->First() << " with : " << target->getChild_r()->First() << std::endl;
					if (target->getPos() == HIGHER)
						add_child_r(target->getParent(), target->getChild_l());
					else if (target->getPos() == LOWER)
						add_child_l(target->getParent(), target->getChild_l());
				}
				else if (target->getChild_r() && target->getChild_l()){
					// std::cout << "third  case : " << target->getParent()->First() << " with : " << target->getChild_r()->First() << std::endl;
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
				// std::cout << " end of extract" << std::endl;
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
				// std::cout << "target is : " << target << " with : " << target->getContent() << " root is : " << _root << " with : " << _root->getContent() << " size is : " << size() << std::endl;
				if (target == _root){
					delete_root();
					return ;
				}
				// while (target->getChild_r()){
				// 	swapChild_r(target);}
				extract_node(target);
				// if (target->getParent() && target->getPos() == LOWER)
				// 	target->getParent()->setChild_l(NULL);
				// else if (target->getParent() && target->getPos() == HIGHER)
				// 	target->getParent()->setChild_r(NULL);
				// if (target == _root && target->getChild_l())
				// 	_root = _root->getChild_l();
				_alloc.destroy(target);
				_alloc.deallocate(target, 1);
				_nb_node--;
				if (_nb_node == 0)
					_root = NULL;
				// reorder_map();
			};
			void	delete_root(){
				node* temp = _root;
				if (_nb_node > 1){
					extract_root();}
				// if (!_root)
				// 	return ;
				// else if (!_root->getChild_l() && _root->getChild_r()){
				// 	_root = _root->getChild_r();
				// }
				// else if (!_root->getChild_r() && _root->getChild_l()){
				// 	_root = _root->getChild_l();
				// }
				// else if (_root->getChild_r() && _root->getChild_l()){
				// 	// while (_root->getChild_r()){
				// 	// 	swapChild_r(_root);}
				// 	extract_root();
				// 	while (_root->getParent())
				// 		_root = _root->getParent();
				// }
				// std::cout << "before" << std::endl;
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				// std::cout << "after" << std::endl;
				_nb_node--;
				if (_nb_node == 0)
					_root = NULL;
			};
			void	reposition_node(node* x){
				node* reader = _root;
				// std::cout << "repositioning : " << x->First() << " root is : " << _root->First() << std::endl;
				// if (x->First() < _root->First() && )
				// print_node(getRoot());->getChild_l() && reader->getChild_r()
				while (reader){
					if (reader->getChild_l() && _compare(x->First(), reader->First()))
						reader = reader->getChild_l();
					else if (reader->getChild_r() && _compare(reader->First(), x->First()))
						reader = reader->getChild_r();
					else if (!reader->getChild_l() && _compare(x->First(), reader->First())){
						add_child_l(reader, x);
						break ;
					}
					else if (!reader->getChild_r() && _compare(reader->First(), x->First())){
						add_child_r(reader, x);
						break ;
					}
				}
				while (true){
					bool checker = false;
					check_all_position(_root, checker);
					if (!checker)
						break ;
				}
				// std::cout << "end repositioning " << std::endl;
				// print_node(getRoot());
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
			// void	ordered_copy(const Map& other){
			// 	recursive_copy(other.begin(), other.size());
			// 	for (iterator i = other.begin(); i != other.end(); i++){
			// 		insert(*i);
			// 	}
			// };
			// void	recursive_copy(iterator begin, size_type size){
			// 	if (size < 1){
			// 		return ;
			// 	}
			// 	iterator new_root = find_middle(begin, size);
			// 	// std::cout << " i begin with node : " << begin->first << " new_middle found : " << new_root->first << " size is " << size << std::endl;
			// 	if (new_root == begin)
			// 		return ;
			// 	if (new_root.getNode_pointer()){
			// 		// std::cout << "i insert node : " << new_root->first << std::endl;
			// 		insert(*new_root);}
			// 	if (size > 1){
			// 		// size++;
			// 		recursive_copy(begin, size / 2);
			// 		recursive_copy(new_root, size / 2);
			// 	}
			// };
			// iterator	find_middle(iterator begin, size_type size){
			// 	// std::cout << "test" << std::endl;
			// 	// std::cout << "	find_middle begin with : " << begin->first << " and size : " << size << std::endl;
			// 	if (size < 2){
			// 		// std::cout << "	end of find middle secur  " << std::endl;
			// 		return begin;}
			// 	if (size % 2)
			// 		size--;
			// 	for (size_t i = 0; i < size / 2; i++)
			// 		begin++;
			// 	// std::cout << "	end of find middle " << std::endl;
			// 	return begin;
			// };
			void	check_all_position(node* begin, bool& checker){
				if (begin == NULL)
					return ;
				// std::cout << "chekcing position with : " << begin->First() << std::endl;
				if (begin->getChild_l() && _compare(begin->First(), begin->getChild_l()->First())){
					// std::cout << "swapping left : " << begin->First() << " and : " << begin->getChild_l()->First() << std::endl;
					checker = true;
					swapChild_l(begin);}
				if (begin->getChild_r() && _compare(begin->getChild_r()->First(), begin->First())){
					checker = true;
					// std::cout << "swapping right " << std::endl;
					swapChild_r(begin);}
				check_all_position(begin->getChild_l(), checker);
				check_all_position(begin->getChild_r(), checker);
				// std::cout << " end of position check " << std::endl;
			};
			void	tidying_tree(){
				// std::cout << "begin tidying tree : " << _root << std::endl;
				size_t right = 0;
				size_t left = 0;
				if (_root->getChild_l()){
					left++;
					how_much_child(_root->getChild_l(), left);
				}
				if (_root->getChild_r()){
					right++;
					how_much_child(_root->getChild_r(), right);
				// }
				if (left > right + 1)
					decal_root_left();
				else if (right > left + 1)
					decal_root_right();
				if (_root->getChild_l())
					stabilize_node(_root->getChild_l());
				if (_root->getChild_r())
					stabilize_node(_root->getChild_r());
				// std::cout << "end tidying tree " << _root << std::endl;
			};
			void	how_much_child(node* begin, size_t& counter){
				// std::cout << "begin how much child  " << std::endl;
				if (begin->getChild_l()){
					counter++;
					how_much_child(begin->getChild_l(), counter);
				}
				if (begin->getChild_r()){
					counter++;
					how_much_child(begin->getChild_r(), counter);
				}
				// std::cout << "end how much child " << std::endl;
			};
			void	decal_root_right(){
				// std::cout << "begin decal root right : " << _root << std::endl;
				if (_root->getChild_r()){
					node* temp = _root;
					_root = _root->getChild_r();
					temp->setChild_r(NULL);
					_root->setParent(NULL);
					reposition_node(temp);
				}
				// std::cout << "end decal root right : " << _root << std::endl;
			};
			void	decal_root_left(){
				// std::cout << "begin decal root left : " << _root << std::endl;
				if (_root->getChild_l()){
					node* temp = _root;
					_root = _root->getChild_l();
					temp->setChild_l(NULL);
					_root->setParent(NULL);
					reposition_node(temp);
				}
				// std::cout << "end decal root left : " << _root << std::endl;
			};
			void	stabilize_node(node* target){
				// std::cout << "begin stabilize node : " << target << std::endl;
				size_t right = 0;
				size_t left = 0;
				if (target->getChild_l()){
					left++;
					how_much_child(_root->getChild_l(), left);
				}
				if (target->getChild_r()){
					right++;
					how_much_child(_root->getChild_r(), right);
				}
				if (right > left)
					decal_node_left(target);
				else if (left > right)
					decal_node_right(target);
				if (target->getChild_l())
					stabilize_node(target->getChild_l());
				if (target->getChild_r())
					stabilize_node(target->getChild_r());
				// std::cout << "end stabilize node : " << target << std::endl;
			};
			void	decal_node_right(node* target){
				// std::cout << "begin decal node right : " << target << std::endl;
				if (!target->getChild_r() || !target->getParent())
					return ;
				node* parent = target->getParent();
				node* child = target->getChild_r();
				target->setParent(NULL);
				target->setChild_r(NULL);
				if (target->getPos() == HIGHER){
					add_child_r(parent, child);}
				else if (target->getPos() == LOWER){
					add_child_l(parent, child);}
				reposition_node(target);
				// std::cout << "end decal node right : " << target << std::endl;
			};
			void	decal_node_left(node* target){
				// std::cout << "begin decal node left : " << target << std::endl;
				if (!target->getChild_l() || !target->getParent())
					return ;
				node* parent = target->getParent();
				node* child = target->getChild_l();
				target->setParent(NULL);
				target->setChild_l(NULL);
				if (target->getPos() == HIGHER){
					add_child_r(parent, child);}
				else if (target->getPos() == LOWER){
					add_child_l(parent, child);}
				reposition_node(target);
				// std::cout << "end decal node left : " << target << std::endl;
			};
			void	swapChild_l(node* parent){
				if (!parent->getChild_l())
					return ;
				value_type* temp = parent->getContent();
				parent->setContent(parent->getChild_l()->getContent());
				parent->getChild_l()->setContent(temp);
				// ft::swap(*parent, *parent->getChild_l());
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
			};
			void	swapChild_r(node* parent){
				if (!parent->getChild_r())
					return ;
				value_type* temp = parent->getContent();
				parent->setContent(parent->getChild_r()->getContent());
				parent->getChild_r()->setContent(temp);
				// ft::swap(*parent, *parent->getChild_r());
				// node* pp = parent->getParent();
				// node* pcl = parent->getChild_l();
				// node* pcr = parent->getChild_r();
				// bool tmp_pos = parent->getPos();
				// node* child = pcr;
				// parent->setParent(child->getParent());
				// parent->setChild_l(child->getChild_l());
				// parent->setChild_r(child->getChild_r());
				// parent->setPos(child->getPos());
				// child->setPos(tmp_pos);
				// child->setParent(pp);
				// child->setChild_l(pcl);
				// child->setChild_r(pcr);
			};
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
