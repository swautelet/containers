#ifndef UTILITIES_HPP
# define UTILITIES_HPP

namespace ft{
template< class T >
void swap( T& a, T& b ){
	T temp = a;
	a = b;
	b = temp;
};
};

#endif