#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "Map.hpp"

namespace ft{

template <class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map_iterator
{
	public:
		typedef long int																				difference_type;
		typedef ft::pair<const Key, T>																	value_type;
		typedef size_t																					size_type;

		typedef std::random_access_iterator_tag															iterator_category;
		typedef typename chooseConst<B, ft::pair<const Key, T>&, const ft::pair<const Key, T>&>::type	reference;
		typedef typename chooseConst<B, ft::pair<const Key, T>*, const ft::pair<const Key, T>*>::type	pointer;
		typedef ft::pair<const Key, T>*																	elemPtr;

		map_iterator():_target(NULL){};
		map_iterator(map_node& target):_target(target){};
		map_iterator(map_iterator& other):_target(other._target){};
		~map_iterator(){};

		elemPtr getElemPtr() const      { return _target; };

		reference operator*() const         { return (*_target); };
		pointer operator->() const          { return (_target); };
		vect_iterator& operator=(const vect_iterator& other){
			this->_target = other.getElemPtr();
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
			for (int i = 0; i < decal; i++){
				it.move_right();
			}
			return (it);
		}
		map_iterator operator-(int nb) const{
			map_iterator it(*this);
			for (int i = 0; i < decal; i++){
				it.move_left();
			}
			return (it);
		};
		map_iterator operator+(size_t nb) const{
			map_iterator it(*this);
			for (size_t i = 0; i < decal; i++){
				it.move_right();
			}
			return (it);
		};
		map_iterator operator-(size_t nb) const{
			map_iterator it(*this);
			for (size_t i = 0; i < decal; i++){
				it.move_left();
			}
			return (it);
		};

	private:
		map_node*	_target;

		void	move_right(){
			ssize_t stage = 0;
			map_node* reader = _target;
			if (!reader)
				return ;
			while (reader->getParent() && reader == reader->getParent()->getChild_r()){
				reader = reader->getParent();
				stage++;
			}
			if (reader->getParent() && reader->getParent()->getChild_r()){
				reader = reader->getParent()->getChild_r();
				while(stage > 0 && reader->getChild_l()){
					reader = reader->getChild_l();
					stage--;
				}
			}
			else if (!reader->getParent()){
				while (stage >= 0){
					reader = reader->getChild_l();
					stage--;
				}
			}
			_target = reader;
		};
		void	move_left(){
			ssize_t stage = 0;
			map_node* reader = _target;
			if (!reader)
				return ;
			while (reader->getParent() && reader == reader->getParent()->getChild_l()){
				reader = reader->getParent();
				stage++;
			}
			if (reader->getParent() && reader->getParent()->getChild_l()){
				reader = reader->getParent()->getChild_l();
				while(stage > 0 && reader->getChild_r()){
					reader = reader->getChild_r();
					stage--;
				}
			}
			else if (!reader->getParent()){
				while (stage > 1){
					reader = reader->getChild_r();
					stage--;
				}
			}
			_target = reader;
		};
};

template <class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> > >
class reverse_map_iterator
{
	public:
		typedef long int																				difference_type;
		typedef ft::pair<const Key, T>																	value_type;
		typedef size_t																					size_type;

		typedef std::random_access_iterator_tag															iterator_category;
		typedef typename chooseConst<B, ft::pair<const Key, T>&, const ft::pair<const Key, T>&>::type	reference;
		typedef typename chooseConst<B, ft::pair<const Key, T>*, const ft::pair<const Key, T>*>::type	pointer;
		typedef ft::pair<const Key, T>*																	elemPtr;

		map_iterator():_target(NULL){};
		map_iterator(map_node& target):_target(target){};
		map_iterator(map_iterator& other):_target(other._target){};
		~map_iterator(){};

		elemPtr getElemPtr() const      { return _target; };

		reference operator*() const         { return (*_target); };
		pointer operator->() const          { return (_target); };
		vect_iterator& operator=(const vect_iterator& other){
			this->_target = other.getElemPtr();
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
			for (int i = 0; i < decal; i++){
				it.move_right();
			}
			return (it);
		}
		map_iterator operator-(int nb) const{
			map_iterator it(*this);
			for (int i = 0; i < decal; i++){
				it.move_left();
			}
			return (it);
		};
		map_iterator operator+(size_t nb) const{
			map_iterator it(*this);
			for (size_t i = 0; i < decal; i++){
				it.move_right();
			}
			return (it);
		};
		map_iterator operator-(size_t nb) const{
			map_iterator it(*this);
			for (size_t i = 0; i < decal; i++){
				it.move_left();
			}
			return (it);
		};

	private:
		map_node*	_target;

		void	move_right(){
			ssize_t stage = 0;
			map_node* reader = _target;
			if (!reader)
				return ;
			while (reader->getParent() && reader == reader->getParent()->getChild_l()){
				reader = reader->getParent();
				stage++;
			}
			if (reader->getParent() && reader->getParent()->getChild_l()){
				reader = reader->getParent()->getChild_l();
				while(stage > 0 && reader->getChild_r()){
					reader = reader->getChild_r();
					stage--;
				}
			}
			else if (!reader->getParent()){
				while (stage > 1){
					reader = reader->getChild_r();
					stage--;
				}
			}
			_target = reader;
		};
		void	move_left(){
			ssize_t stage = 0;
			map_node* reader = _target;
			if (!reader)
				return ;
			while (reader->getParent() && reader == reader->getParent()->getChild_r()){
				reader = reader->getParent();
				stage++;
			}
			if (reader->getParent() && reader->getParent()->getChild_r()){
				reader = reader->getParent()->getChild_r();
				while(stage > 0 && reader->getChild_l()){
					reader = reader->getChild_l();
					stage--;
				}
			}
			else if (!reader->getParent()){
				while (stage >= 0){
					reader = reader->getChild_l();
					stage--;
				}
			}
			_target = reader;
		};
};
// template < class T >
// class map_node{
// 	public:
// 		map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
// 		map_node(T	content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(content){};
// 		map_node(map_node other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(other._content){};
// 		~map_node();
// 	private:
// 		map_node*	_parent;
// 		map_node*	_child_l;
// 		map_node*	_child_r;
// 		T*			_content;
// };


};


#endif