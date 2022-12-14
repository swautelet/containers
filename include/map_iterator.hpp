#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "Map.hpp"
#include "is_const.hpp"
#include "map_node.hpp"
#include "reverse_map_iterator.hpp"
#include "utilities.hpp"

#define HIGHER true
#define LOWER false

namespace ft{

template <class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> >, bool B = false >
class map_iterator
{
	public:
		typedef long int																				difference_type;
		typedef ft::pair<const Key, T>																	value_type;
		typedef size_t																					size_type;

		typedef map_node<Key, T, Allocator>*															node_pointer;
		typedef std::random_access_iterator_tag															iterator_category;
		typedef iterator_category																		iterator_type;
		typedef typename chooseConst<B, ft::pair<const Key, T>&, const ft::pair<const Key, T>&>::type	reference;
		typedef typename chooseConst<B, ft::pair<const Key, T>*, const ft::pair<const Key, T>*>::type	pointer;
		typedef ft::pair<const Key, T>*																	elemPtr;

		map_iterator():_target(NULL){};
		map_iterator(node_pointer target, node_pointer root):_target(target), _root(root){};
		map_iterator(map_iterator<Key, T, Allocator> other):_target(other.getNode_pointer()), _root(other.getRoot()){};
		map_iterator(map_iterator<Key, T, Allocator, true> other):_target(other.getNode_pointer()), _root(other.getRoot()){};
		~map_iterator(){};

		elemPtr getElemPtr() const      { return _target->getContent(); };
		node_pointer	getNode_pointer() const {return _target;};
		node_pointer	getRoot() const {return _root;};

		reference operator*() const         { return (*_target->getContent()); };
		pointer operator->() const          { return (_target->getContent()); };
		map_iterator& operator=(const map_iterator& other){
			this->_target = other.getNode_pointer();
			return (*this);
		};
		operator unsigned long(){return ((unsigned long)_target);};

		map_iterator& operator++()       { move_right(); return (*this); };
		map_iterator& operator--()       { move_left(); return (*this); };

		map_iterator operator++(int){
			map_iterator res(*this);
			move_right();
			return (res);
		};
		map_iterator operator--(int){
			map_iterator res(*this);
			move_left();
			return (res);
		};
		map_iterator& operator+=(int decal){
			for (int i = 0; i < decal; i++){
				move_right();
			}
			return (*this);
		};
		map_iterator& operator-=(int decal){
			for (int i = 0; i < decal; i++){
				move_left();
			}
			return (*this);
		};
		map_iterator operator+(int nb) const{
			map_iterator it(*this);
			for (int i = 0; i < nb; i++){
				it.move_right();
			}
			return (it);
		}
		map_iterator operator-(int nb) const{
			map_iterator it(*this);
			for (int i = 0; i < nb; i++){
				it.move_left();
			}
			return (it);
		};
		map_iterator operator+(size_t nb) const{
			map_iterator it(*this);
			for (size_t i = 0; i < nb; i++){
				it.move_right();
			}
			return (it);
		};
		map_iterator operator-(size_t nb) const{
			map_iterator it(*this);
			for (size_t i = 0; i < nb; i++){
				it.move_left();
			}
			return (it);
		};
		bool	operator==(const map_iterator& it) const    { return (it._target == _target); };
		bool	operator!=(const map_iterator& it) const    { return (it._target != _target); };

	private:
		node_pointer		_target;
		node_pointer		_root;

		void	move_right(){
			if (!_target)
				find_first();
			else
				find_next();
		};
		void	move_left(){
			if (!_target)
				find_last();
			else
				find_previous();
		};
		void	find_previous(){
			if (_target->getChild_l()){
				node_pointer reader = _target->getChild_l();
				while (reader->getChild_r())
					reader = reader->getChild_r();
				_target = reader;
			}
			else if (_target->getParent() && _target->getPos() == HIGHER)
				_target = _target->getParent();
			else if (_target->getParent()){
				node_pointer reader = _target;
				while (reader->getParent() && reader->getPos() == LOWER)
					reader = reader->getParent();
				if (reader->getParent() && reader->getPos() == HIGHER)
					_target = reader->getParent();
				else
					_target = NULL;
			}
			else
				_target = NULL;
		};
		void	find_next(){
			if (_target->getChild_r()){
				node_pointer reader = _target->getChild_r();
				while (reader->getChild_l())
					reader = reader->getChild_l();
				_target = reader;
			}
			else if (_target->getParent() && _target->getPos() == LOWER)
				_target = _target->getParent();
			else if (_target->getParent()){
				node_pointer reader = _target;
				while (reader->getParent() && reader->getPos() == HIGHER)
					reader = reader->getParent();
				if (reader->getParent() && reader->getPos() == LOWER)
					_target = reader->getParent();
				else
					_target = NULL;
			}
			else
				_target = NULL;
		};
		void	find_last(){
			node_pointer reader = _root;
			while (reader && reader->getChild_r())
				reader = reader->getChild_r();
			_target = reader;
		};
		void	find_first(){
			node_pointer reader = _root;
			while (reader && reader->getChild_l())
				reader = reader->getChild_l();
			_target = reader;
		};
		bool still_something_higher(node_pointer reader, Key& searched){
			if (reader->First() > searched)
				return true;
			else if (reader->getChild_l() && _compare(searched, reader->getChild_l()->First()))
				return true;
			else if (reader->getChild_r() && _compare(searched, reader->getChild_l()->First()))
				return true;
			else if (reader->getChild_r())
				return still_something_higher(reader->getChild_r(), searched);
			else if (reader->getChild_l())
				return still_something_higher(reader->getChild_l(), searched);
			else
				return false;
		}
		bool still_something_lower(node_pointer reader, Key searched){
			if (reader->First() < searched)
				return true;
			else if (reader->getChild_l() && _compare(reader->getChild_l()->First(), searched))
				return true;
			else if (reader->getChild_r() && _compare(reader->getChild_r()->First(), searched))
				return true;
			else if (reader->getChild_r())
				return still_something_lower(reader->getChild_r(), searched);
			else if (reader->getChild_l())
				return still_something_lower(reader->getChild_l(), searched);
			else
				return false;
		}
};


};


#endif