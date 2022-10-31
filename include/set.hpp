#ifndef SET_HPP
# define SET_HPP

#include <memory>

namespace ft{
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > class set{
		public:
		//member functions
			set();
			explicit set( const Compare& comp, const Allocator& alloc = Allocator() );
			template< class InputIt > set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			set( const set& other );
			~set();
			set& operator=( const set& other );
			allocator_type get_allocator() const;

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
			void swap( set& other );
			size_type count( const Key& key ) const;
			iterator find( const Key& key );
			const_iterator find( const Key& key ) const;
			std::pair<iterator,iterator> equal_range( const Key& key );
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
			iterator lower_bound( const Key& key );
			const_iterator lower_bound( const Key& key ) const;
			iterator upper_bound( const Key& key );
			const_iterator upper_bound( const Key& key ) const;
		
		//observers
			key_compare key_comp() const;
			std::set::value_compare value_comp() const;
	
		private:
		protected:
	};
	template< class Key, class Compare, class Alloc > bool operator==( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs );
	template< class Key, class Compare, class Alloc > bool operator!=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs );
	template< class Key, class Compare, class Alloc > bool operator<( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs );
	template< class Key, class Compare, class Alloc > bool operator<=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs );
	template< class Key, class Compare, class Alloc > bool operator>( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs );
	template< class Key, class Compare, class Alloc > bool operator>=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs );
};

#endif