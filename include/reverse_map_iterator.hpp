#ifndef REVERSE_MAP_ITERATOR_HPP
# define REVERSE_MAP_ITERATOR_HPP

#include "map_iterator.hpp"

namespace ft{

template <class Key, class T,class Compare = std::less<Key>, bool B = false >
class reverse_map_iterator
{
	public:
		typedef long int																				difference_type;
		typedef ft::pair<const Key, T>																	value_type;
		typedef size_t																					size_type;

		typedef map_node<Key, T>*																		node_pointer;
		typedef std::random_access_iterator_tag															iterator_category;
		typedef typename chooseConst<B, ft::pair<const Key, T>&, const ft::pair<const Key, T>&>::type	reference;
		typedef typename chooseConst<B, ft::pair<const Key, T>*, const ft::pair<const Key, T>*>::type	pointer;
		typedef ft::pair<const Key, T>*																	elemPtr;

		reverse_map_iterator():_target(NULL){};
		reverse_map_iterator(node_pointer target, node_pointer root):_target(target), _root(root){};
		reverse_map_iterator(reverse_map_iterator<Key, T> other):_target(other.getNode_pointer()), _root(other.getRoot()){};
		reverse_map_iterator(reverse_map_iterator<Key, T,Compare, true> other):_target(other.getNode_pointer()), _root(other.getRoot()){};
		~reverse_map_iterator(){};

		elemPtr getElemPtr() const      { return _target->getContent(); };
		node_pointer	getNode_pointer() const {return _target;};
		node_pointer	getRoot() const {return _root;};

		reference operator*() const         { return (*_target->getContent()); };
		pointer operator->() const          { 
			// std::cout << _target->getContent() << std::endl;;
			return (_target->getContent()); };
		reverse_map_iterator& operator=(const reverse_map_iterator& other){
			this->_target = other.getNode_pointer();
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
		bool	operator==(const reverse_map_iterator& it) const    { return (it._target == _target); };
		bool	operator!=(const reverse_map_iterator& it) const    { return (it._target != _target); };
	private:
		node_pointer		_target;
		node_pointer		_root;

		map_node<Key, T>*	moving_up(map_node<Key, T>* reader, ssize_t& stage, bool called_from_down){
			while (reader->getParent() && reader == reader->getParent()->getChild_r()){
				reader = reader->getParent();
				stage++;
			}
			if (reader->getParent() && reader->getParent()->getChild_r()){
				reader = reader->getParent()->getChild_r();
				return (moving_down(reader, stage, false));
			}
			else{
				while (reader->getParent() && !reader->getParent()->getChild_r()){
					reader = reader->getParent();
					stage++;
				}
				if (reader->getParent() && reader->getParent()->getChild_r()){
					reader = reader->getParent()->getChild_r();
					return (moving_down(reader, stage, false));
				}
			}
			if (!reader->getParent() && !called_from_down)
				return (moving_down(reader, stage, true));
			else 
				return NULL;
			// if (!reader->getParent() && called_from_down)
		};
		map_node<Key, T>*	moving_down(map_node<Key, T>* reader, ssize_t& stage, bool next_stage){
			if (next_stage)
				stage++;
			if (!stage)
				return reader;
			if (stage && reader->getChild_l())
				return (moving_down(reader->getChild_l(), --stage, false));
			else if (stage && reader->getChild_r())
				return (moving_down(reader->getChild_r(), --stage, false));
			else 
				return (moving_up(reader, stage, true));
				// if (stage && !reader->getChild_l() && !reader->getChild_r())
		};
		map_node<Key, T>*	moving_up_r(map_node<Key, T>* reader, ssize_t& stage, bool called_from_down){
			// std::cout << "test " << stage << "|" << std::endl;
			// std::cout << "first test " << reader->getParent() << "|" << reader << "|" << stage << std::endl;
			while (reader->getParent() && reader == reader->getParent()->getChild_l()){
				reader = reader->getParent();
				stage++;
				// std::cout << "i go up  " << reader << std::endl;
			}
			// std::cout << "second test " << reader->getParent() << "|" << reader << "|" << stage << std::endl;
			if (reader->getParent() && reader->getParent()->getChild_l()){
				reader = reader->getParent()->getChild_l();
				// std::cout << "first moving down " << reader << std::endl;
				return (moving_down_r(reader, stage, false));
			}
			else{
				while (reader->getParent() && !reader->getParent()->getChild_l()){
					reader = reader->getParent();
					stage++;
				}
				if (reader->getParent() && reader->getParent()->getChild_l()){
					reader = reader->getParent()->getChild_l();
					// std::cout << "second moving down " << reader << std::endl;
					return (moving_down_r(reader, stage, false));
				}
			}
			if (!reader->getParent() && !called_from_down){
				// std::cout << "third moving down " << reader << std::endl;
				return (moving_down_r(reader, stage, true));}
			else {
				// std::cout << "should not happen" << std::endl;
				return NULL;
			}
				// if (!reader->getParent() && called_from_down)
		};
		map_node<Key, T>*	moving_down_r(map_node<Key, T>* reader, ssize_t& stage, bool previous_stage){
			if (previous_stage)
				stage--;
			if (!stage)
				return reader;
			if (stage && reader->getChild_r())
				return (moving_down_r(reader->getChild_r(), --stage, false));
			else if (stage && reader->getChild_l())
				return (moving_down_r(reader->getChild_l(), --stage, false));
			else 
				return (moving_up_r(reader, stage, true));
				// if (stage && !reader->getChild_l() && !reader->getChild_r())
		};
		void	move_left(){
			ssize_t stage = 0;
			// std::cout << "try to move right" << std::endl;
			// map_node<Key, T>* reader = _target;
			// if (!reader)
			// 	return ;
			// while (reader->getParent() && reader == reader->getParent()->getChild_r()){
			// 	reader = reader->getParent();
			// 	stage++;
			// }
			// if (reader->getParent() && reader->getParent()->getChild_r()){
			// 	reader = reader->getParent()->getChild_r();
			// 	while(stage > 0 && reader->getChild_l()){
			// 		reader = reader->getChild_l();
			// 		stage--;
			// 	}
			// }
			// else if (!reader->getParent()){
			// 	while (stage >= 0){
			// 		reader = reader->getChild_l();
			// 		stage--;
			// 	}
			// }
			// _target = reader;
			// _target = moving_up(_target, stage, false);
			find_next();
			// std::cout << "done moving right" << std::endl;
		};
		void	move_right(){
			// ssize_t stage = 0;
			// if (_target == _root)
			// 	return ;
			// if (!_target){
			// 	node_pointer temp = _root;
			// 	// std::cout << "before crash" << std::endl;
			// 	while (temp){
			// 		_target = temp;
			// 		temp = moving_up(temp, stage, false);
			// 	}
			// }
			// else{
			// 	stage = 0;
				// std::cout << "target " << _target << "|" << stage << std::endl;
			// map_node<Key, T>* reader = _target;
			// if (!reader)
			// 	return ;
			// while (reader->getParent() && reader == reader->getParent()->getChild_l()){
			// 	reader = reader->getParent();
			// 	stage++;
			// }
			// if (reader->getParent() && reader->getParent()->getChild_l()){
			// 	reader = reader->getParent()->getChild_l();
			// 	while(stage > 0 && reader->getChild_r()){
			// 		reader = reader->getChild_r();
			// 		stage--;
			// 	}
			// }
			// else if (!reader->getParent()){
			// 	while (stage > 1){
			// 		reader = reader->getChild_r();
			// 		stage--;
			// 	}
			// }
			// _target = reader;
			// _target = moving_up_r(_target, stage, false);
			// }
			// std::cout << "target is " << _target << " root is " << _root << std::endl;
			if (!_target)
				find_last();
			else
				find_previous();
		};
		void	find_next(){
			node_pointer reader = _root;
			if (!_target){
				while(reader->getChild_l())
					reader = reader->getChild_l();
				_target = reader;
			}
			else{
				Key now = _target->First();
				while (reader){
					// std::cout << "key : " << reader->First();
					// if (reader->getChild_l())
					// 	std::cout << "		key child left  " << reader->getChild_l()->First();
					// if (reader->getChild_r())
					// 	std::cout << "		key child right  " << reader->getChild_r()->First();
					// std::cout << std::endl;
					if (reader->First() <= now && reader->getChild_r())
						reader = reader->getChild_r();
					else if (reader->First() >= now && reader->getChild_l() && still_something_higher(reader->getChild_l(), now))
						reader = reader->getChild_l();
					else if (reader->First() > now)
						break ;
					else
						reader = NULL;
				}
				_target = reader;
				// if (_target)
				// 	std::cout << "found : " << _target->First() << " with : " << now << std::endl;
			}
		};
		void	find_previous(){
			// std::cout << "begin decrease : " << _target->First() << std::endl;
			node_pointer reader = _root;
			Key now = _target->First();
			while (reader){
				// std::cout << "key : " << reader->First();
				// if (reader->getChild_l())
				// 	std::cout << "		key child left  " << reader->getChild_l()->First();
				// if (reader->getChild_r())
				// 	std::cout << "		key child right  " << reader->getChild_r()->First();
				// std::cout << std::endl;
				if (reader->First() >= now && reader->getChild_l())
					reader = reader->getChild_l();
				else if (reader->First() <= now && reader->getChild_r() && still_something_lower(reader->getChild_r(), now)){
					// std::cout << "returned true" << std::endl;
					reader = reader->getChild_r();
				}
				else if (reader->First() < now)
					break ;
				else
					reader = NULL;
			}
			_target = reader;
			// if (_target)
			// 	std::cout << "found : " << _target->First() << " with : " << now << std::endl;
			// std::cout << "done  " << _target << std::endl;
		};
		void	find_last(){
			// std::cout << "test" << std::endl;
			node_pointer reader = _root;
			while (reader && reader->getChild_r())
				reader = reader->getChild_r();
			_target = reader;
			// std::cout << "done" << std::endl;
		};
		bool still_something_higher(node_pointer reader, Key& searched){
			if (reader->First() > searched)
				return true;
			else if (reader->getChild_l() && reader->getChild_l()->First() > searched)
				return true;
			else if (reader->getChild_r() && reader->getChild_r()->First() > searched)
				return true;
			else if (reader->getChild_r())
				return still_something_higher(reader->getChild_r(), searched);
			else if (reader->getChild_l())
				return still_something_higher(reader->getChild_l(), searched);
			else
				return false;
		}
		bool still_something_lower(node_pointer reader, Key searched){
			// std::cout << "still lower : " << reader->First() << "|" << searched << std::endl;
			if (reader->First() < searched)
				return true;
			else if (reader->getChild_l() && reader->getChild_l()->First() < searched)
				return true;
			else if (reader->getChild_r() && reader->getChild_r()->First() < searched)
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