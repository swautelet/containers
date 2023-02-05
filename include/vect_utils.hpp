#ifndef VECT_UTILS_HPP
# define VECT_UTILS_HPP

#include "is_const.hpp"

#include <thread>

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
		vect_iterator(pointer val):_value(val){};
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

		pointer getElemPtr() const      { return _value; };

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
		difference_type operator-(const vect_iterator& nb) const{
			// if (_value > nb.getElemPtr())
				return (_value - nb.getElemPtr());
			// else
			// 	return (nb.getElemPtr() - _value);
		};
		reference	operator[](size_t decal){return *(_value + decal);};
		friend bool	operator==(const vect_iterator& it, const vect_iterator& ite)    { return (it._value == ite._value); };
		friend bool	operator!=(const vect_iterator& it, const vect_iterator& ite)    { return (it._value != ite._value); };
		friend bool	operator<(const vect_iterator& it, const vect_iterator& ite)     { return (it._value < ite._value); };
		friend bool	operator>(const vect_iterator& it, const vect_iterator& ite)     { return (it._value > ite._value); };
		friend bool	operator<=(const vect_iterator& it, const vect_iterator& ite)    { return (it._value <= ite._value); };
		friend bool	operator>=(const vect_iterator& it, const vect_iterator& ite)    { return (it._value >= ite._value); };
	private:
		pointer	_value;
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
		reverse_vect_iterator(pointer val):_value(val){};
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

		pointer getElemPtr() const      { return _value; };

		reference operator*() const         { return (*(_value - 1)); };
		pointer operator->() const          { return (_value - 1); };
		// operator size_t(){return ((size_t)_value);};

		reverse_vect_iterator& operator++()       { --_value; return (*this); };
		reverse_vect_iterator& operator--()       { ++_value; return (*this); };
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
			_value -= decal;
			return (*this);
		};
		reverse_vect_iterator& operator-=(int decal){
			_value += decal;
			return (*this);
		};
		reverse_vect_iterator operator+(size_t nb) const{
			reverse_vect_iterator it(*this);
			it._value -= nb;
			return (it);
		}
		reverse_vect_iterator operator-(size_t nb) const{
			reverse_vect_iterator it(*this);
			it._value += nb;
			return (it);
		};
		difference_type operator-(const reverse_vect_iterator& nb) const{
			// if (base() < nb.base()())
				return (nb.base() - base()());
			// else
			// 	return (nb.base() - base());
		};
		reference	operator[](size_t decal){return *(_value - decal - 1);};
		friend bool	operator==(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value == ite._value); };
		friend bool	operator!=(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value != ite._value); };
		friend bool	operator<(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)     { return (it._value > ite._value); };
		friend bool	operator>(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)     { return (it._value < ite._value); };
		friend bool	operator<=(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value >= ite._value); };
		friend bool	operator>=(const reverse_vect_iterator& it, const reverse_vect_iterator& ite)    { return (it._value <= ite._value); };
	private:
		pointer	_value;
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
ssize_t operator-(vect_iterator<T, true> a, vect_iterator<T, false> b){
	return a.base() - b.base();
}
template <class T>
ssize_t operator-(reverse_vect_iterator<T, true> a, reverse_vect_iterator<T, false> b){
	return b.base() - a.base();
}
};
// template <class T>
// size_t operator-(const ft::vect_iterator<T, true>& lhs, const ft::vect_iterator<T, true>& rhs){
// 	std::cout << "test " << std::endl;
// 	if (lhs.base() > rhs.base()())
// 		return (lhs.base() - rhs.base()());
// 	else
// 		return (rhs.base() - lhs.base());
// };
#endif
