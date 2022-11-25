#ifndef REVERSE_MAP_ITERATOR_HPP
# define REVERSE_MAP_ITERATOR_HPP

#include "map_iterator.hpp"

namespace ft{

template <class Key, class T, bool B >
class reverse_map_iterator
{
	public:
		typedef long int																				difference_type;
		typedef ft::pair<const Key, T>																	value_type;
		typedef size_t																					size_type;

		typedef map_node<Key, T>																	node_pointer;
		typedef std::random_access_iterator_tag															iterator_category;
		typedef typename chooseConst<B, ft::pair<const Key, T>&, const ft::pair<const Key, T>&>::type	reference;
		typedef typename chooseConst<B, ft::pair<const Key, T>*, const ft::pair<const Key, T>*>::type	pointer;
		typedef ft::pair<const Key, T>*																	elemPtr;

		reverse_map_iterator():_target(NULL){};
		reverse_map_iterator(map_node<Key, T>* target):_target(target){};
		reverse_map_iterator(reverse_map_iterator<Key, T, true>& other):_target(other._target){};
		~reverse_map_iterator(){};

		elemPtr getElemPtr() const      { return _target; };

		reference operator*() const         { return (_target->getContent()); };
		pointer operator->() const          { return (_target->getContent()); };
		reverse_map_iterator& operator=(const reverse_map_iterator& other){
			this->_target = other.getElemPtr();
			return (*this);
		};
		operator unsigned long(){return ((unsigned long)_target);};

		reverse_map_iterator& operator++()       { move_right(); return (*this); };
		reverse_map_iterator& operator--()       { move_left(); return (*this); };

		reverse_map_iterator operator++(int){
			reverse_map_iterator res(*this);
			move_right();
			return (res);
		};
		reverse_map_iterator operator--(int){
			reverse_map_iterator res(*this);
			move_left();
			return (res);
		};
		reverse_map_iterator& operator+=(int decal){
			for (int i = 0; i < decal; i++){
				move_right();
			}
			return (*this);
		};
		reverse_map_iterator& operator-=(int decal){
			for (int i = 0; i < decal; i++){
				move_left();
			}
			return (*this);
		};
		reverse_map_iterator operator+(int nb) const{
			reverse_map_iterator it(*this);
			for (int i = 0; i < nb; i++){
				it.move_right();
			}
			return (it);
		}
		reverse_map_iterator operator-(int nb) const{
			reverse_map_iterator it(*this);
			for (int i = 0; i < nb; i++){
				it.move_left();
			}
			return (it);
		};
		reverse_map_iterator operator+(size_t nb) const{
			reverse_map_iterator it(*this);
			for (size_t i = 0; i < nb; i++){
				it.move_right();
			}
			return (it);
		};
		reverse_map_iterator operator-(size_t nb) const{
			reverse_map_iterator it(*this);
			for (size_t i = 0; i < nb; i++){
				it.move_left();
			}
			return (it);
		};

	private:
		node_pointer		_target;

		void	move_right(){
			ssize_t stage = 0;
			map_node<Key, T>* reader = _target;
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
			map_node<Key, T>* reader = _target;
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
};

#endif