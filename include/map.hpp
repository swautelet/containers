#ifndef MAP_HPP
# define MAP_HPP


#include <memory>

#include <map>
// #include <type_traits>

#include "pair.hpp"
#include "map_iterator.hpp"
#include "reverse_map_iterator.hpp"
#include "print_map.hpp"
#include "utility.hpp"

#define HIGHER true
#define LOWER false

namespace ft{

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map{
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
		private:
			class value_compare: public std::binary_function<value_type, value_type, bool>
        	{
        	    friend class ft::map<key_type, mapped_type, Compare, Allocator>;
	
        	    public:
        	        // typedef bool        result_type;
        	        // typedef value_type  first_argument_type;
        	        // typedef value_type  second_argument_type;
	
        	    protected:
        	        Compare comp;
	
        	    public:
        	        value_compare(Compare c): comp(c) {};
					~value_compare(){};
        	    bool operator()(const value_type &x, const value_type &y) const
        	    { return (comp(x.first, y.first)); }
        	};
		public:
		//member functions
			map():_root(NULL), _nb_node(0){};
			explicit map( const Compare& comp, const Allocator& alloc = Allocator()):_root(NULL), _nb_node(0), _alloc_node(alloc), _compare(comp), _compare_valid(compar_is_valid()){};
			template< class InputIt > map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):_root(NULL), _nb_node(0), _alloc_node(alloc), _compare(comp), _compare_valid(compar_is_valid()){
				ordered_copy(first, last);
			};
			map( const map& other ):_root(NULL), _nb_node(0), _alloc_node(other.get_allocator()), _compare(other.key_comp()), _compare_valid(compar_is_valid()){
				ordered_copy(other.begin(), other.end());
			};
			~map(){
				clear();
			};
			map& operator=( const map& other ){
				clear();
				ordered_copy(other.begin(), other.end());
				return (*this);
			};
			allocator_type get_allocator() const{return Allocator();};

		//element access
			T& at( const Key& key ){
				iterator reader = find(key);
				if (!reader.getNode_pointer())
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
				if (reader.getNode_pointer())
					return reader->second;
				else
					add_node(ft::pair< Key, T >(key, T()) );
				reader = find(key);
				return reader->second;
			};
			// node*	getRoot(){
			// 	return _root;
			// }

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
			return iterator(NULL, _root);
			};
			const_iterator end() const{
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
				}
				_root = NULL;
			};
			ft::pair<iterator, bool> insert(const value_type& value ){
				iterator reader = find(value.first);
				if (reader.getNode_pointer()){
					iterator ret (reader.getNode_pointer(), _root);
					return ft::make_pair(ret, false);
				};
				iterator ret (add_node(value), _root);
				return (ft::make_pair(ret, true));
			};
			iterator insert( iterator pos, const value_type& value ){
				(void)pos;
				iterator reader = find(value.first);
				if (reader.getNode_pointer())
					return reader;
				return iterator(add_node(value), _root);
			};
			template< class InputIt > void insert( InputIt first, InputIt last ){
				ordered_copy(first, last);
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
				iterator reader = find(key);
				if (reader.getNode_pointer()){
					delete_node(reader.getNode_pointer());
					return 1;
				}
				return 0;
			};
			void swap( map& other ){
				ft::swap(&this->_root, &other._root);
				ft::swap(this->_nb_node, other._nb_node);
			};

		//lookup
			size_type count( const Key& key ) const{
				if (find(key).getNode_pointer())
					return 1;
				return 0;
			};
			iterator find( const Key& key ){
				node* reader = _root;
				while(reader && reader->First() != key){
					if (_compare(reader->First(), key))
						reader = reader->getChild_r();
					else 
						reader = reader->getChild_l();
				}
				iterator ret (reader, _root);
				return (ret);
			};
			const_iterator find( const Key& key ) const{
				for (const_iterator i = begin(); i != end(); i++){
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
				ft::pair<const_iterator, const_iterator> ret;
				for (const_iterator i = begin(); i != end(); i++){
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
			iterator lower_bound( const Key& key ){
				node* reader = _root;
				while (reader && reader->getChild_l() && _compare(key, reader->First()))
					reader = reader->getChild_l();
				iterator i (reader, _root);
				while(i.getNode_pointer() && _compare(i->first, key))
					i++;
				return i;
			};
			const_iterator lower_bound( const Key& key ) const{
				node* reader = _root;
				while (reader && reader->getChild_l() && _compare(key, reader->First()))
					reader = reader->getChild_l();
				const_iterator i (reader, _root);
				while(i.getNode_pointer() && _compare(i->first, key))
					i++;
				return i;
			};
			iterator upper_bound( const Key& key ){
				node* reader = _root;
				while (reader && reader->getChild_l() && _compare(key, reader->First()))
					reader = reader->getChild_l();
				iterator i (reader, _root);
				while(i.getNode_pointer() && _compare(i->first, key))
					i++;
				if (i.getNode_pointer() && i->first == key)
					i++;
				return i;
			};
			const_iterator upper_bound( const Key& key ) const{
				node* reader = _root;
				while (reader && reader->getChild_l() && _compare(key, reader->First()))
					reader = reader->getChild_l();
				iterator i (reader, _root);
				while(i.getNode_pointer() && _compare(i->first, key))
					i++;
				if (i.getNode_pointer() && i->first == key)
					i++;
				return i;
			};

		//observer
			key_compare key_comp() const{return _compare;};
			value_compare value_comp() const{return value_compare(_compare);};
	
		// exception
			class out_of_range_exception: public std::exception{
			public:
				const char* what() const throw(){
					return ("Error : out of range exception");
				};
			};
		//operators 
			friend bool operator==( const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs ){
				if (lhs.size() != rhs.size())
					return false;
				ft::map_iterator<Key, T, Allocator, true> i = lhs.begin(), j = rhs.begin();
				while (i.getNode_pointer() && j.getNode_pointer()){
					if (*i != *j)
						return false;
					i++;
					j++;
				}
				return true;
			};
			friend bool operator!=( const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs ){
				return !(rhs == lhs);
			};
			friend bool operator<( const map<Key,T,Compare,Allocator>& lhs,  const map<Key,T,Compare,Allocator>& rhs ){
				if (lhs.size() < rhs.size())
					return true;
				ft::map_iterator<Key, T, Allocator, true> i = lhs.begin(), j = rhs.begin();
				while (i.getNode_pointer() && j.getNode_pointer()){
					if (*i < *j)
						return true;
					i++;
					j++;
				}
				return false;
			};
			friend bool operator<=( const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs ){
				return !(lhs > rhs);
			};
			friend bool operator>( const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs ){
				return (rhs < lhs);
			};
			friend bool operator>=( const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs ){
				return !(lhs < rhs);
			};
		private:
			
			bool	comp_node(ft::pair<const Key, T> one, ft::pair<const Key, T> two){
				return _compare(one.first, two.first);
			}
		//private attribute
			node*						_root;
			size_type					_nb_node;
			std::allocator < node >		_alloc;
			Allocator					_alloc_node;
			Compare						_compare;
			bool						_compare_valid;

		// nodes manipulation functions
			node* new_node(value_type value){
				node* temp = _alloc.allocate(1);
				_alloc.construct(temp, value);
				_nb_node++;
				return temp;
			};
			node*	add_node(value_type value){
				node* reader = _root;
				if (_nb_node == 2){
					// std::cout << "compar was " << _compare_valid << std::endl;
					_compare_valid = compar_is_valid();
					// std::cout << "compare is now " << _compare_valid << std::endl;
				}
				if (!_root){
					_root = new_node(value);
				}
				while (reader){
					
					if (value.first == reader->First()){
						reader->setSecond(value.second);
						return reader;
					}
					else if (_compare(value.first, reader->First())){
						if (reader->getChild_l() != NULL)
							reader = reader->getChild_l();
						else{
							add_child_l(reader, new_node(value));
							if (_compare_valid)
								while (balance_node(_root));
							return reader->getChild_l();
						}
					}
					else if (_compare(reader->First(), value.first)){
						if (reader->getChild_r() != NULL)
							reader = reader->getChild_r();
						else{
							add_child_r(reader, new_node(value));
							if (_compare_valid)
								while (balance_node(_root));
							return reader->getChild_r();
						}
					}
					// else if (_compare(value.first, reader->First())){
					// 	add_child_l(reader, new_node(value));
					// 	// while (!is_ordered(_root) && _compare_valid)
					// 	// 	balance_node(_root);
					// 	return reader->getChild_l();
					// }
					// else if (_compare(reader->First(), value.first)){
					// 	add_child_r(reader, new_node(value));
					// 	// while (!is_ordered(_root) && _compare_valid)
					// 	// 	balance_node(_root);
					// 	return reader->getChild_r();
					// }
				}
				return _root;
			};
			void	extract_node_l(node* target){
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
			void	extract_node_r(node* target){
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
						add_child_r(target->getParent(), target->getChild_l());
						reposition_node(target->getChild_r());
					}
					else if (target->getPos() == LOWER){
						add_child_l(target->getParent(), target->getChild_l());
						reposition_node(target->getChild_r());
					}
				}
				else if (!target->getChild_l() && !target->getChild_r()){
					if (target->getPos() == HIGHER)
						target->getParent()->setChild_r(NULL);
					else if (target->getPos() == LOWER)
						target->getParent()->setChild_l(NULL);
				}
			};
			void	extract_root_r(){
				node* temp = _root;
				if (!_root->getChild_l() && _root->getChild_r()){
					_root = _root->getChild_r();
					_root->setParent(NULL);
					temp->setChild_r(NULL);
				}
				else if (!_root->getChild_r() && _root->getChild_l()){
					_root = _root->getChild_l();
					_root->setParent(NULL);
					temp->setChild_l(NULL);
				}
				else if (_root->getChild_r() && _root->getChild_l()){
					_root = _root->getChild_l();
					temp->setChild_l(NULL);
					_root->setParent(NULL);
					reposition_node(temp);
				}
			};
			void	extract_root_l(){
				node* temp = _root;
				if (!_root->getChild_l() && _root->getChild_r()){
					_root = _root->getChild_r();
					_root->setParent(NULL);
					temp->setChild_r(NULL);
				}
				else if (!_root->getChild_r() && _root->getChild_l()){
					_root = _root->getChild_l();
					_root->setParent(NULL);
					temp->setChild_l(NULL);
				}
				else if (_root->getChild_r() && _root->getChild_l()){
					_root = _root->getChild_r();
					temp->setChild_r(NULL);
					_root->setParent(NULL);
					reposition_node(temp);
				}
			};
			void	delete_node(node* target){
				if (target == _root){
					delete_root();
					return ;
				}
				extract_node_r(target);
				_alloc.destroy(target);
				_alloc.deallocate(target, 1);
				_nb_node--;
				if (_nb_node == 0)
					_root = NULL;
			};
			void	delete_root(){
				node* temp = _root;
				if (_nb_node > 1){
					extract_root_r();}
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				_nb_node--;
				if (_nb_node == 0)
					_root = NULL;
			};
			void	reposition_node(node* x){
				node* reader = _root;

				while (reader){
					if (_compare(x->First(), reader->First())){
						if (reader->getChild_l())
							reader = reader->getChild_l();
						else{
							add_child_l(reader, x);
							break ;
						}
					}
					else if (x->First() == reader->First()){
						break ;
					}
					else{
						if (reader->getChild_r())
							reader = reader->getChild_r();
						else{
							add_child_r(reader, x);
							break ;
						}
					}
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
			bool	balance_node(node* x){
				if (!x || _nb_node < 3){
					return false;
				}
				size_t left = 0;
				size_t right = 0;
				how_much_child(x->getChild_r(), right);
				how_much_child(x->getChild_l(), left);
				if (x == _root){
					if (left > right + 3){
						extract_root_r();
						reposition_node(x);
						return true;
					}
					else if (right > left + 3){
						extract_root_l();
						reposition_node(x);
						return true;
					}
					else if(balance_node(x->getChild_r()) || balance_node(x->getChild_l())){
						return true;
					}
				}
				else{
					if (left > right + 1){
						extract_node_r(x);
						clean_link(x);
						reposition_node(x);
						return true;
					}
					else if (right > left + 1){
						extract_node_l(x);
						clean_link(x);
						reposition_node(x);
						return true;
					}
					else if(balance_node(x->getChild_r()) || balance_node(x->getChild_l())){
						return true;
					}
				}
				return false;
			};
			void	clean_link(node* x){
				x->setChild_l(NULL);
				x->setChild_r(NULL);
				x->setParent(NULL);
			};
			void	how_much_child(node* x, size_t& count){
				if (!x)
					return ;
				else{
					count++;
					how_much_child(x->getChild_l(), count);
					how_much_child(x->getChild_r(), count);
				}
			};
			bool	is_ordered(node* x){
				if (!x)
					return true;
				size_t left = 0;
				size_t right = 0;
				how_much_child(x->getChild_l(), left);
				how_much_child(x->getChild_r(), right);
				if (left > right + 1 || right > left + 1){
					return false ;
				}
				else if (is_ordered(x->getChild_l()) && is_ordered(x->getChild_r())){
					return true ;
				}
				else{
					return false ;
				}
			};
			bool	compar_is_valid(){
				if (_nb_node > 1 && (std::is_same<Compare, std::logical_and<Key> >::value && std::is_same<Compare, std::plus<Key> >::value)){
					if (_root->getChild_l()){
						if (_compare(_root->First(), _root->getChild_l()->First()) && !_compare(_root->getChild_l()->First(), _root->First()))
							return true;
						else if (!_compare(_root->First(), _root->getChild_l()->First()) && _compare(_root->getChild_l()->First(), _root->First()))
							return true;
					}
					else if (_root->getChild_r()){
						if (_compare(_root->First(), _root->getChild_r()->First()) && !_compare(_root->getChild_r()->First(), _root->First()))
							return true;
						else if (!_compare(_root->First(), _root->getChild_r()->First()) && _compare(_root->getChild_r()->First(), _root->First()))
							return true;
					}
				}
				return false;
			};
			template <class InputIt>
			void	ordered_copy(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0){
				while (first != last){
					add_node(*first);
					first++;
					if (first != last){
						last--;
						add_node(*last);
					}
				}
			};
		protected:
	};
};
namespace std{
	template <class Key, class T>
	void swap (ft::map<Key, T>& a, ft::map<Key, T>& b){ a.swap(b);};
}
#endif
