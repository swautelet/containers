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
			explicit Stack( const Container& cont = Container() ):_content(cont){};
			// Stack( const Stack& other );
			~Stack(){};
			Stack& operator=( const Stack& other ){
				_content = other._content;
				return *(this);
			};

		//element access
			reference top(){
				return *(--_content.end());
			};
			// const_reference top() const;
	
		//capacity
			bool empty() const{
				return _content.empty();
			};
			size_type size() const{
				return _content.size();
			};
	
		//modifiers
			void push( const value_type& value ){
				_content.push_back(value);
			};
			void pop(){
				_content.pop_back();
			};
	
		friend bool operator==( Stack& lhs, Stack& rhs ){
				if (lhs._content.size() != rhs._content.size())
					return false;
				for (iterator i = lhs._content.begin(), j = rhs._content.begin(); i != lhs._content.end() && j != rhs._content.end(); i++, j++){
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
				for (iterator i = lhs._content.begin(), j = rhs._content.begin(); i != lhs._content.end() && j != rhs._content.end(); i++, j++){
					if (*i < *j)
						return true;
				}
				return (lhs.size() < rhs.size());
			};
		private:
			Container _content;
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