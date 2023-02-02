#ifndef VECT_UTILS_HPP
# define VECT_UTILS_HPP

#include "is_const.hpp"

namespace ft
{
template<class T, bool B> class reverse_vect_iterator;
template<class T, bool B = false> class vect_iterator
{
	public:
		typedef long int                                        difference_type;
		typedef T                                               value_type;
		typedef size_t                                          size_type;

		typedef std::random_access_iterator_tag                 iterator_category;
		typedef typename chooseConst<B, T&, const T&>::type     reference;
		typedef typename chooseConst<B, T*, const T*>::type     pointer;
		typedef T*                                              elemPtr;
		typedef pointer											iterator_type;
	
		vect_iterator():_value(NULL){};
		vect_iterator(T* val):_value(val){};
		vect_iterator(size_type val):_value((T*)val){};
		// vect_iterator(const vect_iterator<T, true>& other):_value(other.getElemPtr()){};
		vect_iterator(const vect_iterator<T, B>& other):_value(other.getElemPtr()){};
		vect_iterator(const reverse_vect_iterator<T, B>& other):_value(other.getElemPtr()){};
		template <bool C>
		vect_iterator(const vect_iterator<T, C>& other, typename ft::enable_if<(!C)>::type* = 0):_value(other.getElemPtr()){};
		template <bool C>
		vect_iterator(const reverse_vect_iterator<T, C>& other, typename ft::enable_if<(!C)>::type* = 0):_value(other.getElemPtr()){};
		~vect_iterator(){};

		iterator_type base()	{return _value;};

		elemPtr getElemPtr() const      { return _value; };

		reference operator*() const         { return (*_value); };
		pointer operator->() const          { return (_value); };
		vect_iterator& operator=(const vect_iterator& other){
			this->_value = other.getElemPtr();
			return (*this);
		};
		// operator size_t(){return ((size_t)_value);};

		vect_iterator& operator++()       { ++_value; return (*this); };
		vect_iterator& operator--()       { --_value; return (*this); };
		vect_iterator operator++(int){
			vect_iterator res(*this);
			++(*this);
			return (res);
		};
		vect_iterator operator--(int){
			vect_iterator res(*this);
			--(*this);
			return (res);
		};
		vect_iterator& operator+=(int decal){
			_value += decal;
			return (*this);
		};
		vect_iterator& operator-=(int decal){
			_value -= decal;
			return (*this);
		};
		vect_iterator operator+(int nb) const{
			vect_iterator it(*this);
			it._value += nb;
			return (it);
		}
		vect_iterator operator-(int nb) const{
			vect_iterator it(*this);
			it._value -= nb;
			return (it);
		};
		vect_iterator operator+(size_t nb) const{
			vect_iterator it(*this);
			it._value += nb;
			return (it);
		};
		vect_iterator operator-(size_t nb) const{
			vect_iterator it(*this);
			it._value -= nb;
			return (it);
		};
		size_t operator-(const vect_iterator& nb) const{
			// std::cout << " i sustract " << _value << " to " << nb.getElemPtr() << std::endl;
			// if (_value > nb.getElemPtr())
			return (_value - nb.getElemPtr());
			// else
			// 	return (nb.getElemPtr() - _value);
			// size_t res = 0;
			// vect_iterator temp(nb);
			// if (temp == *this)
			// 	return res;
			// else if (temp < *this){
			// 	while (temp < *this){
			// 		temp++;
			// 		res++;
			// 	}
			// 		// std::cout << " i did res ++ 2 " << res << std::endl;
			// }
			// else {
			// 	while (temp > *this){
			// 		temp --;
			// 		res ++;
			// 	}
			// 		// std::cout << " i did res ++" << res << std::endl;
			// }
			// // std::cout << " i found dist : " << res << std::endl;
			// return (res);
		};
		reference	operator[](size_t decal){return *(_value + decal);};
		friend bool	operator==(const vect_iterator& it, const vect_iterator& ite)    { return (it._value == ite._value); };
		friend bool	operator!=(const vect_iterator& it, const vect_iterator& ite)    { return (it._value != ite._value); };
		friend bool	operator<(const vect_iterator& it, const vect_iterator& ite)     { return (it._value < ite._value); };
		friend bool	operator>(const vect_iterator& it, const vect_iterator& ite)     { return (it._value > ite._value); };
		friend bool	operator<=(const vect_iterator& it, const vect_iterator& ite)    { return (it._value <= ite._value); };
		friend bool	operator>=(const vect_iterator& it, const vect_iterator& ite)    { return (it._value >= ite._value); };
	private:
		T*	_value;
	protected:
};
template<class T, bool B = false> class reverse_vect_iterator
{
	public:
		typedef long int                                        difference_type;
		typedef T                                               value_type;
		typedef size_t                                          size_type;

		typedef std::random_access_iterator_tag                 iterator_category;
		typedef typename chooseConst<B, T&, const T&>::type     reference;
		typedef typename chooseConst<B, T*, const T*>::type     pointer;
		typedef T*                                              elemPtr;
		typedef pointer											iterator_type;
		reverse_vect_iterator():_value(NULL){};
		reverse_vect_iterator(T* val):_value(val){};
		reverse_vect_iterator(size_type val):_value((T*)val){};
		// reverse_vect_iterator(const reverse_vect_iterator<T, true>& other):_value(other.getElemPtr()){};
		reverse_vect_iterator(const reverse_vect_iterator<T, B>& other):_value(other.getElemPtr()){};
		reverse_vect_iterator(const vect_iterator<T, B>& other):_value(other.getElemPtr()){};
		template <bool C>
		reverse_vect_iterator(const vect_iterator<T, C>& other, typename ft::enable_if<(!C)>::type* = 0):_value(other.getElemPtr()){};
		template <bool C>
		reverse_vect_iterator(const reverse_vect_iterator<T, C>& other, typename ft::enable_if<(!C)>::type* = 0):_value(other.getElemPtr()){};
		~reverse_vect_iterator(){};

		iterator_type base()	{return _value;};

		elemPtr getElemPtr() const      { return _value; };

		reference operator*() const         { return (*_value); };
		pointer operator->() const          { return (_value); };
		// operator size_t(){return ((size_t)_value);};

		reverse_vect_iterator& operator++()       { ++_value; return (*this); };
		reverse_vect_iterator& operator--()       { --_value; return (*this); };
		reverse_vect_iterator operator++(int){
			reverse_vect_iterator res(*this);
			++(*this);
			return (res);
		};
		reverse_vect_iterator operator--(int){
			reverse_vect_iterator res(*this);
			--(*this);
			return (res);
		};
		reverse_vect_iterator& operator+=(int decal){
			_value += decal;
			return (*this);
		};
		reverse_vect_iterator& operator-=(int decal){
			_value -= decal;
			return (*this);
		};
		reverse_vect_iterator operator+(size_t nb) const{
			reverse_vect_iterator it(*this);
			it._value += nb;
			return (it);
		}
		reverse_vect_iterator operator-(size_t nb) const{
			reverse_vect_iterator it(*this);
			it._value -= nb;
			return (it);
		};
		size_t operator-(reverse_vect_iterator& nb) const{
		// 	if (_value > nb.getElemPtr())
			return (_value - nb.getElemPtr());
		// 	else
		// 		return (nb.getElemPtr() - _value);
		// 	// size_t res = 0;
		// 	// reverse_vect_iterator temp(nb);
		// 	// if (temp < *this){
		// 	// 	while (temp != *this){
		// 	// 		temp++;
		// 	// 		res++;
		// 	// 	}
		// 	// }
		// 	// else {
		// 	// 	while (temp != *this){
		// 	// 		temp --;
		// 	// 		res --;
		// 	// 	}
		// 	// }
		// 	// return (res);
		};
		reference	operator[](size_t decal){return *(_value + decal);};
		friend bool	operator==(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value == ite._value); };
		friend bool	operator!=(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value != ite._value); };
		friend bool	operator<(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)     { return (it._value < ite._value); };
		friend bool	operator>(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)     { return (it._value > ite._value); };
		friend bool	operator<=(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value <= ite._value); };
		friend bool	operator>=(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value >= ite._value); };
	private:
		T*	_value;
	protected:
};
template <class T>
vect_iterator<T> operator+(int a, vect_iterator<T> b){
	return b + a;
};
template <class T>
reverse_vect_iterator<T> operator+(int a, reverse_vect_iterator<T> b){
	return b + a;
};
template <class T>
size_t operator-(vect_iterator<T, true> a, vect_iterator<T, false> b){
	return a - b;
}
template <class T>
size_t operator-(reverse_vect_iterator<T, true> a, reverse_vect_iterator<T, false> b){
	return a - b;
}
};

#endif
