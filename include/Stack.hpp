#ifndef STACK_HPP
# define STACK_HPP

#include <deque>
#include <memory>
#include "Vector.hpp"

namespace ft{
	template< class T, class Container = ft::Vector<T> > class Stack{
		public:
		typedef T											value_type;
		typedef T&											reference;
		typedef size_t										size_type;
		typedef typename Container::iterator							iterator;
		//member functions
			explicit Stack( const Container& cont = Container() ):c(cont){};
			// Stack( const Stack& other );
			~Stack(){};
			Stack& operator=( const Stack& other ){
				c = other.c;
				return *(this);
			};

		//element access
			reference top(){
				return *(--c.end());
			};
			// const_reference top() const;
	
		//capacity
			bool empty() const{
				return c.empty();
			};
			size_type size() const{
				return c.size();
			};
	
		//modifiers
			void push( const value_type& value ){
				c.push_back(value);
			};
			void pop(){
				c.pop_back();
			};
	
		friend bool operator==( Stack& lhs, Stack& rhs ){
				if (lhs.c.size() != rhs.c.size())
					return false;
				for (iterator i = lhs.c.begin(), j = rhs.c.begin(); i != lhs.c.end() && j != rhs.c.end(); i++, j++){
					if (*i != *j)
						return false;
				}
				return true;
			};
			friend bool operator!=( Stack& lhs, Stack& rhs ){return !(lhs == rhs);};
			friend bool operator>=( Stack& lhs, Stack& rhs ){return !(lhs < rhs);};
			friend bool operator<=( Stack& lhs, Stack& rhs ){return (rhs >= lhs);};
			friend bool operator>( Stack& lhs, Stack& rhs ){return (rhs < lhs);};
			friend bool operator<( Stack& lhs, Stack& rhs ){
				for (iterator i = lhs.c.begin(), j = rhs.c.begin(); i != lhs.c.end() && j != rhs.c.end(); i++, j++){
					if (*i < *j)
						return true;
				}
				return (lhs.size() < rhs.size());
			};
		private:
		protected:
			Container c;
	};
	template< class T, class Container > bool operator==( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
	template< class T, class Container > bool operator!=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
	template< class T, class Container > bool operator<( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
	template< class T, class Container > bool operator<=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
	template< class T, class Container > bool operator>( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
	template< class T, class Container > bool operator>=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
};

#endif
