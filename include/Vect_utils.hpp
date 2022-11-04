#ifndef VECT_UTILS_HPP
# define VECT_UTILS_HPP

#include "is_const.hpp"

namespace ft
{
template<class T, bool B> class vect_iterator
{
	typedef long int                                        difference_type;
	typedef T                                               value_type;
	typedef size_t                                          size_type;

	typedef std::random_access_iterator_tag                 iterator_category;
	typedef typename chooseConst<B, T&, const T&>::type     reference;
	typedef typename chooseConst<B, T*, const T*>::type     pointer;
	typedef T*                                              elemPtr;
	public:
		vect_iterator():_value(NULL){};
		vect_iterator(T* val):_value(val){};
		vect_iterator(const vect_iterator& other):_value(other._value){};
		~vect_iterator(){};

		elemPtr getElemPtr() const      { return _value; };

		reference operator*() const         { return (*_value); };
		pointer operator->() const          { return (_value); };
		operator unsigned long(){return ((unsigned long)_value);};

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
		size_t operator-(vect_iterator& nb) const{
			size_t res = 0;
			vect_iterator temp(nb);
			while (temp != *this){
				temp++;
				res++;
			}
			return (res);
		};
		bool	operator==(const vect_iterator& it) const    { return (it._value == _value); };
		bool	operator!=(const vect_iterator& it) const    { return (it._value != _value); };
		bool	operator<(const vect_iterator& it) const     { return (it._value > _value); };
		bool	operator>(const vect_iterator& it) const     { return (it._value < _value); };
		bool	operator<=(const vect_iterator& it) const    { return (it._value >= _value); };
		bool	operator>=(const vect_iterator& it) const    { return (it._value <= _value); };
	private:
		T*	_value;
	protected:
};
template<class T, bool B> class reverse_vect_iterator
{
	typedef long int                                        difference_type;
	typedef T                                               value_type;
	typedef size_t                                          size_type;

	typedef std::random_access_iterator_tag                 iterator_category;
	typedef typename chooseConst<B, T&, const T&>::type     reference;
	typedef typename chooseConst<B, T*, const T*>::type     pointer;
	typedef T*                                              elemPtr;
	public:
		reverse_vect_iterator():_value(NULL){};
		reverse_vect_iterator(T* val):_value(val){};
		reverse_vect_iterator(const reverse_vect_iterator& other):_value(other._value){};
		~reverse_vect_iterator(){};

		elemPtr getElemPtr() const      { return _value; };

		reference operator*() const         { return (*_value); };
		pointer operator->() const          { return (_value); };
		operator unsigned long(){return ((unsigned long)_value);};

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
		reverse_vect_iterator operator+(int nb) const{
			reverse_vect_iterator it(*this);
			it._value += nb;
			return (it);
		}
		reverse_vect_iterator operator-(int nb) const{
			reverse_vect_iterator it(*this);
			it._value -= nb;
			return (it);
		};
		// size_t operator-(reverse_vect_iterator nb) const{
		// 	reverse_vect_iterator it(*this);
		// 	it._value -= nb.getElemPtr();
		// 	return (it._value);
		// };
		bool	operator==(const reverse_vect_iterator& it) const    { return (it._value == _value); };
		bool	operator!=(const reverse_vect_iterator& it) const    { return (it._value != _value); };
		bool	operator<(const reverse_vect_iterator& it) const     { return (it._value > _value); };
		bool	operator>(const reverse_vect_iterator& it) const     { return (it._value < _value); };
		bool	operator<=(const reverse_vect_iterator& it) const    { return (it._value >= _value); };
		bool	operator>=(const reverse_vect_iterator& it) const    { return (it._value <= _value); };
	private:
		T*	_value;
	protected:
};
};

#endif