#ifndef STACK_HPP
# define STACK_HPP

#include <deque>
#include <memory>
#include "Vector.hpp"

namespace ft{
	template< class T, class Container = ft::vector<T> > class stack{
		public:
		typedef T											value_type;
		typedef T&											reference;
		typedef size_t										size_type;
		typedef typename Container::iterator				iterator;
		typedef stack<T, Container>							container_type;
		//member functions
			explicit stack( const Container& cont = Container() ):c(cont){};
			// stack( const stack& other );
			~stack(){};
			stack& operator=( const stack& other ){
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
	
		friend bool operator==( stack& lhs, stack& rhs ){
				if (lhs.c.size() != rhs.c.size())
					return false;
				for (iterator i = lhs.c.begin(), j = rhs.c.begin(); i != lhs.c.end() && j != rhs.c.end(); i++, j++){
					if (*i != *j)
						return false;
				}
				return true;
			};
			friend bool operator!=( stack& lhs, stack& rhs ){return !(lhs == rhs);};
			friend bool operator>=( stack& lhs, stack& rhs ){return !(lhs < rhs);};
			friend bool operator<=( stack& lhs, stack& rhs ){return (rhs >= lhs);};
			friend bool operator>( stack& lhs, stack& rhs ){return (rhs < lhs);};
			friend bool operator<( stack& lhs, stack& rhs ){
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
	// template< class T, class Container > bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){return (lhs.c == rhs.c)};
	// template< class T, class Container > bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){return (lhs.c != rhs.c)};
	// template< class T, class Container > bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){return (lhs.c < rhs.c)};
	// template< class T, class Container > bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){return (lhs.c <= rhs.c)};
	// template< class T, class Container > bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){return (lhs.c > rhs.c)};
	// template< class T, class Container > bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){return (lhs.c >= rhs.c)};
};

#endif
