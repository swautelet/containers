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

			typedef map_iterator								iterator;
			typedef const map_iterator							const_iterator;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
		//member functions
			map();
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
			template< class InputIt > map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			map( const map& other );
			~map();
			map& operator=( const map& other );
			allocator_type get_allocator() const;

		//element access
			T& at( const Key& key );
			const T& at( const Key& key ) const;
			T& operator[]( const Key& key );

		//iterators
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

		//capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

		//modifiers
			void clear();
			std::pair<iterator, bool> insert( const value_type& value );
			iterator insert( iterator pos, const value_type& value );
			template< class InputIt > void insert( InputIt first, InputIt last );
			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type erase( const Key& key );
			void swap( map& other );

		//lookup
			size_type count( const Key& key ) const;
			iterator find( const Key& key );
			const_iterator find( const Key& key ) const;
			std::pair<iterator,iterator> equal_range( const Key& key );
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
			iterator lower_bound( const Key& key );
			const_iterator lower_bound( const Key& key ) const;
			iterator upper_bound( const Key& key );
			const_iterator upper_bound( const Key& key ) const;

		//observer
			key_compare key_comp() const;
			std::map::value_compare value_comp() const;
	
		private:
		//private attribute
			map_node*						_root;
			map_node*						_last;
			size_type						nb_node;
			std::allocator < map_node > >	_alloc;

		// nodes manipulation functions
			map_node& new_node(ft::pair<const Key, T> value){
				map_node model(value);
				map_node* temp = _alloc.allocate(1);
				_alloc.construct(temp, model);
				return temp;
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

#endif