#ifndef UTILITIES_HPP
# define UTILITIES_HPP


namespace ft{
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

// template< class T >
// class is_integral{
// 	public:
// 	//member function
// 		// is_integral():_value(false);
// 		operator bool(){
// 			return _value;
// 		};
// 		is_integral(T& init){
// 			if (dynamic_cast<int*>(&init) || dynamic_cast<bool*>(&init) || dynamic_cast<char*>(&init) || dynamic_cast<char16_t*>(&init) || dynamic_cast<char32_t*>(&init) || dynamic_cast<wchar_t*>(&init) || dynamic_cast<short*>(&init) || dynamic_cast<int*>(&init) || dynamic_cast<long*>(&init) || dynamic_cast<long long*>(&init))
// 				_value = true;
// 			else
// 				_value = false;
// 		};

// 	private:
// 	//member value
// 		bool _value;
// };
template <typename T>
struct is_integral { static const bool value = false; };

template <>
struct is_integral<bool> { static const bool value = true; };
        
template <>
struct is_integral<char> { static const bool value = true; };

template <>
struct is_integral<short> { static const bool value = true; };

template <>
struct is_integral<int> { static const bool value = true; };

template <>
struct is_integral<long> { static const bool value = true; };

template <>
struct is_integral<long long> { static const bool value = true; };

template <>
struct is_integral<unsigned char> { static const bool value = true; };

template <>
struct is_integral<unsigned short> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<unsigned long> { static const bool value = true; };

template <>
struct is_integral<unsigned long long> { static const bool value = true; };
};

#endif