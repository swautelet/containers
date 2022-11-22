#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
// #include <map>
#include "Pair.hpp"
#include "map_iterator.hpp"

namespace ft{
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map{
		public:
		// typedef 
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef ft::map_iterator							iterator;
			typedef const ft::map_iterator						const_iterator;
			typedef ft::reverse_map_iterator					reverse_iterator;
			typedef const ft::reverse_map_iterator				const_reverse_iterator;
		//member functions
			map():_root(NULL), _nb_node(0){};
			explicit map( const Compare& comp, const Allocator& alloc = Allocator()):_root(NULL), _nb_node(0){};
			template< class InputIt > map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):_root(NULL), _nb_node(0){
				while (first != last){
					add_node(*first);
					first++;
				}
			};
			map( const map& other ):_root(NULL), _nb_node(0){
				for (ft::map_iterator i = other.first(); i != other.end(); i++){
					add_node(*i);
				}
			};
			~map(){
				clear();
			};
			map& operator=( const map& other ){
				clear();
				for (ft::map_iterator i = other.first(); i != other.end(); i++){
					add_node(*i);
				}
			};
			allocator_type get_allocator() const{return Allocator};

		//element access
			T& at( const Key& key ){
				for (ft::map_iterator i = other.first(); i != other.end(); i++){
					if (i.first() == key)
						return i.second();
				}
				throw (out_of_range_exception());
			};
			const T& at( const Key& key ) const{
				for (ft::map_iterator i = other.first(); i != other.end(); i++){
					if (i.first() == key)
						return i.second();
				}
				throw (out_of_range_exception());
			};
			T& operator[]( const Key& key ){
				for (ft::map_iterator i = other.first(); i != other.end(); i++){
					if (i.first() == key)
						return i.second();
				}
				add_node(ft::pair< key, T()>);
				for (ft::map_iterator i = other.first(); i != other.end(); i++){
					if (i.first() == key)
						return i.second();
				}
				return _root.second();
			};

		//iterators
			iterator begin(){return _root;};
			const_iterator begin() const{return _root;};
			iterator end(){return NULL;};
			const_iterator end() const{return NULL;};
			reverse_iterator rbegin(){return _root;};
			const_reverse_iterator rbegin() const{return _root;};
			reverse_iterator rend(){return NULL;};
			const_reverse_iterator rend() const{return NULL;};

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
				return Allocator.max_size();
			};

		//modifiers
			void clear(){
				while (_nb_node){
					map_node* reader(_root);
					while (i->getChild_l() || i->getChild_r()){
						if (i->getChild_l())
							i = i->getChild_l();
						else if (i->getChild_r())
							i = i->getChild_r();
					}
					delete_node(i);
				}
			};
			std::pair<iterator, bool> insert( const value_type& value ){
				add_node(value);
			};
			iterator insert( iterator pos, const value_type& value ){
				add_node(value);
			};
			template< class InputIt > void insert( InputIt first, InputIt last ){
				for (InputIt i = first; i != last; i++){
					add_node(*i);
				}
			};
			iterator erase( iterator pos ){
				delete_node(pos);
			};
			iterator erase( iterator first, iterator last ){
				for (iterator i = first; i != last; i++){
					delete_node(i)
				}
			};
			size_type erase( const Key& key ){
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (i.first() == key)
						delete_node(i);
				}
			};
			void swap( map& other ){
				swap(this->_root, other._root);
				swap(this->_nb_node, other._nb_node);
			};

		//lookup
			size_type count( const Key& key ) const{
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (i->first() == key)
						return 1;
				}
				return 0;
			};
			iterator find( const Key& key ){
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (i->first() == key)
						return i;
				}
				return NULL;
			};
			const_iterator find( const Key& key ) const{
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (i->first() == key)
						return i;
				}
				return NULL;
			};
			ft::pair<iterator,iterator> equal_range( const Key& key ){
				ft::pair<iterator, iterator> ret;
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (!(i->first() < key) && i->first() == key){
						ret.first = i;
						i++;
						ret.second = i;
						break ;
					}
					else if (!(i->first() < key)){
						ret.first = i;
						ret.second = i;
						break ;
					}
				}
				return ret;
			};
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				ft::pair<iterator, iterator> ret;
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (!(i->first() < key) && i->first() == key){
						ret.first = i;
						i++;
						ret.second = i;
						break ;
					}
					else if (!(i->first() < key)){
						ret.first = i;
						ret.second = i;
						break ;
					}
				}
				return ret;
			};
			iterator lower_bound( const Key& key ){
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (!(i.first() < key))
						return i;
				}
				return NULL;
			};
			const_iterator lower_bound( const Key& key ) const{
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (!(i.first() < key))
						return i;
				}
				return NULL;
			};
			iterator upper_bound( const Key& key ){
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (i.first() > key)
						return i;
				}
				return NULL;
			};
			const_iterator upper_bound( const Key& key ) const{
				for (ft::map_iterator i = begin(); i != end(); i++){
					if (i.first() > key)
						return i;
				}
				return NULL;
			};

		//observer
			key_compare key_comp() const{return Compare;};
			ft::map::value_compare value_comp() const{return comp_node;};
	
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
			map_node*						_root;
			size_type						_nb_node;
			std::allocator < map_node > >	_alloc;

		// nodes manipulation functions
			map_node* new_node(ft::pair<const Key, T> value){
				map_node model(value);
				map_node* temp = _alloc.allocate(1);
				_alloc.construct(temp, model);
				_nb_node++;
				return temp;
			};
			void	add_node(ft::pair<const Key, T> value){
				map_node* reader = _root;
				while (reader->getChild_l() || reader->getChild_r()){
					if (value.first == reader->First())
						reader->setSecond(value.second);
					else if (reader->getChild_l() && Compare(value.first, reader->First()))
						reader = reader->getChild_l();
					else if (reader->getChild_r() && Compare(reader->First(), value.first))
						reader = reader->getChild_r();
					else if (Compare(value.first, reader->First()))
						add_child_l(reader, new_node(value));
					else if (Compare(reader->First(), value.first))
						add_child_r(reader, new_node(value));
				}
			};
			void	delete_node(map_node& target){
				while (target.getChild_r())
					swapChild_r(target);
				_alloc.destroy(&target);
				_alloc.deallocate(&target, 1);
				_nb_node--;
			};
			void	add_child_l(map_node& parent, map_node& child){
				parent.setChild_l(&child);
				child.setParent(&parent);
			};
			void	add_child_r(map_node& parent, map_node& child){
				parent.setChild_r(&child);
				child.setParent(&parent);
			};
			void	swapChild_l(map_node& parent){
				if (!parent.getChild_l())
					return ;
				map_node* pp = parent.getParent();
				map_node* pcl = parent.getChild_l();
				map_node* pcr = parent.getChild_r();
				map_node* child = pcl;
				parent.setParent(child->getParent());
				parent.setChild_l(child->getChild_l());
				parent.setChild_r(child->getChild_r());
				child->setParent(pp);
				child->setChild_l(pcl);
				child->setChild_r(pcr);
			};
			void	swapChild_r(map_node& parent){
				if (!parent.getChild_r())
					return ;
				map_node* pp = parent.getParent();
				map_node* pcl = parent.getChild_l();
				map_node* pcr = parent.getChild_r();
				map_node* child = pcr;
				parent.setParent(child->getParent());
				parent.setChild_l(child->getChild_l());
				parent.setChild_r(child->getChild_r());
				child->setParent(pp);
				child->setChild_l(pcl);
				child->setChild_r(pcr);
			};
		// private template map node
			class map_node{
				public:
					map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
					map_node(U	content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){
						_content = Allocator.allocate(1);
						Allocator.construct(_content, content);
					};
					map_node(map_node other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(NULL){
						_content = Allocator.allocate(1);
						Allocator.construct(_content, other._content);
					};
					~map_node(){
						if (_content){
							Allocator.destroy(_content);
							Allocator.deallocate(_content, 1);
						}
					};
					Key&	First(){
						return _content.first;
					};
					T&		Second(){
						return _content.second;
					};
					void	setSecond(T& value){
						_content.second = value;
					};
					void	setParent(map_node* parent){
						_parent = parent;
					};
					void	setChild_l(map_node* child){
						_child_l = child;
					};
					void	setChild_r(map_node* child){
						_child_r = child;
					};
					map_node*	getParent(){
						return _parent;
					};
					map_node*	getChild_l(){
						return _child_l;
					};
					map_node*	getChild_r(){
						return _child_r;
					};

				private:
					map_node*				_parent;
					map_node*				_child_l;
					map_node*				_child_r;
					ft::pair<const Key, T>*	_content;
			};

		protected:
	};
	template< class Key, class T, class Compare, class Alloc > bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc > bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc > bool operator<( const map<Key,T,Compare,Alloc>& lhs,  const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc > bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc > bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc > bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
};

//check add_node and make a tidying function

#endif