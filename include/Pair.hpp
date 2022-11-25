#ifndef PAIR_HPP
# define PAIR_HPP

#include <utility>

namespace ft{
template< class T1, class T2> 
	struct pair{
		public:
		// typedef
			typedef T1 first_type;
			typedef T2 second_type;

		// member function
			pair(): first(T1()), second(T2()){};
			pair(const T1& x, const T2& y): first(x), second(y){};
			template< class U1, class U2 >pair( const pair<U1, U2>& p ): first(p.first), second(p.second){};
			pair( const pair<T1, T2>& p ): first(p.first), second(p.second){};
			pair& operator=( const pair& other ){
				first = other.first;
				second = other.second;
			};
			~pair(){};
		
		// public attribute
			T1	first;
			T2	second;

		private:

};
template< class T1, class T2 >
pair<T1, T2> make_pair( T1 t, T2 u ){
	return (ft::pair<T1, T2>( t, u));
};
template< class T1, class T2 >
bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	if (lhs.first == rhs.first && lhs.second == rhs.second)
		return true;
	return false;
};
template< class T1, class T2 >
bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return !(lhs == rhs);
};
template< class T1, class T2 >
bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	if (lhs.first < rhs.first)
		return true;
	else if (lhs.first == rhs.first && lhs.second < rhs.second)
		return true;
	else
		return false;
};
template< class T1, class T2 >
bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return !(lhs > rhs);
};
template< class T1, class T2 >
bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return (rhs < lhs);
};
template< class T1, class T2 >
bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return !(lhs < rhs);
};
};

#endif