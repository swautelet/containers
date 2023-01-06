#ifndef UTILITIES_HPP
# define UTILITIES_HPP

namespace ft{

// template <class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> >, bool B = false >
// class map_iterator;

// template<class T, bool B = false> class vect_iterator;

template< class T >
void swap( T& a, T& b ){
	T temp = a;
	a = b;
	b = temp;
};

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };


// template <class T, bool V>
// struct integral_const{
// 	static const bool value = V;
// 	typedef T	value_type;
// 	operator value_type(){
// 	return value;
// }
// };


template <typename T>
struct is_integral { static const bool value = false;
operator bool(){
	return value;
};
};

template <>
struct is_integral<bool> { static const bool value = true;
operator bool(){
	return value;
};
 };
        
template <>
struct is_integral<char> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<signed char> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<char16_t> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<char32_t> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<wchar_t> { static const bool value = true; 
operator bool(){
	return value;
};
};


template <>
struct is_integral<short> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<int> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<long> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<long long> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<unsigned char> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<unsigned short> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<unsigned int> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<unsigned long> { static const bool value = true; 
operator bool(){
	return value;
};
};

template <>
struct is_integral<unsigned long long> { static const bool value = true; 
operator bool(){
	return value;
};
};

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp ){
	while (*first1 != *last1){
		if (first2 == last2 || comp(*first1, *first2))
			return false;
		else if (comp(*first1, *first2))
			return true;
		first1++;
		first2++;
	}
	if (first2 != last2)
		return true;
	else
		return false;
};

template< class InputIt1, class InputIt2>
bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
	while (*first1 != *last1){
		if (first2 == last2 || *first2 > *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		first1++;
		first2++;
	}
	if (first2 != last2)
		return true;
	else
		return false;
};
template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ){
	while (first1!=last1) {
   		if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      		return false;
    	++first1; ++first2;
  	}
  	return true;
	// InputIt2 last2 = first2 + (std::distance(last1, first1));
	// if (!(ft::lexicographical_compare<InputIt1, InputIt2>(first1, last1, first2, last2)) && !(ft::lexicographical_compare<InputIt2, InputIt1>(first2, last2, first1, last1)))
	// 	return true;
	// else
	// 	return false;
};
template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p ){
	while (first1!=last1) {
   		if (!(p(*first1, *first2)))   // or: if (!pred(*first1,*first2)), for version 2
      		return false;
    	++first1; ++first2;
  	}
  	return true;
	// InputIt2 last2 = first2 + (std::distance(last1, first1));
	// if (!(ft::lexicographical_compare<InputIt1, InputIt2, BinaryPredicate>(first1, last1, first2, last2, p)) && !(ft::lexicographical_compare<InputIt1, InputIt2, BinaryPredicate>(first2, last2, first1, last1, p)))
	// 	return true;
	// else
	// 	return false;
};

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template< class Iter >
struct iterator_traits{
	typedef typename Iter::difference_type			difference_type;
	typedef typename Iter::value_type				value_type;
	typedef typename Iter::pointer					pointer;
	typedef typename Iter::reference				reference;
	typedef typename Iter::iterator_category		iterator_category;
};

template <class T> struct iterator_traits<T*>{
    typedef ptrdiff_t                       difference_type;
    typedef T                               value_type;
    typedef T*                              pointer;
    typedef T&                              reference;
    typedef ft::random_access_iterator_tag  iterator_category;
};
template <class T> class iterator_traits<const T*>{
    typedef ptrdiff_t                       difference_type;
    typedef T                               value_type;
    typedef const T*                        pointer;
    typedef const T&                        reference;
    typedef ft::random_access_iterator_tag  iterator_category;
};
// template<class Key, class T>
// struct iterator_traits< map_iterator<Key, T> >{
// 	typedef ft::Map::difference_type		difference_type;
// 	typedef ft::Map::value_type				value_type;
// 	typedef ft::Map::pointer				pointer;
// 	typedef ft::Map::reference				reference;
// 	typedef ft::Map::iterator_category		iterator_category;
// };

// template<class T>
// struct iterator_traits< vect_iterator<T> >{
// 	typedef ft::Vector::difference_type		difference_type;
// 	typedef ft::Vector::value_type				value_type;
// 	typedef ft::Vector::pointer				pointer;
// 	typedef ft::Vector::reference				reference;
// 	typedef ft::Vector::iterator_category		iterator_category;
// };

// template< class T >
// struct iterator_traits<T*>;
// template< class T >
// struct iterator_traits<const T*>;
};
#endif
