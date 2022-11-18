#ifndef STACK_HPP
# define STACK_HPP

#include <deque>
#include <memory>
#include "Vector.hpp"

namespace ft{
	template< class T, class Container = std::deque<T> > class stack: public template<class T, class Allocator = std::allocator<T> > class Vector{
		public:
		//member functions
			explicit stack( const Container& cont = Container() );
			stack( const stack& other );
			~stack();
			stack& operator=( const stack& other );

		//element access
			reference top();
			const_reference top() const;
	
		//capacity
			bool empty() const;
			size_type size() const;
	
		//modifiers
			void push( const value_type& value );
			void pop();
	
		private:
		protected:
	};
	template< class T, class Container > bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	template< class T, class Container > bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	template< class T, class Container > bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	template< class T, class Container > bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	template< class T, class Container > bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	template< class T, class Container > bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
};

#endif