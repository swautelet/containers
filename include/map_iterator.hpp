#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "Map.hpp"
#include "is_const.hpp"
#include "map_node.hpp"
#include "reverse_map_iterator.hpp"

namespace ft{
// template<class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> > >
// class map_node{
// 	public:
// 		typedef ft::pair<const Key, T>				mapped_type;
// 		typedef map_node <Key, T, Allocator>		node;

// 		map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
// 		map_node(mapped_type content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){
// 			_content = _alloc.allocate(1);
// 			_alloc.construct(_content, content);
// 		};
// 		map_node(node& other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(NULL){
// 			_content = _alloc.allocate(1);
// 			_alloc.construct(_content, *(other._content));
// 		};
// 		~map_node(){
// 			if (_content){
// 				_alloc.destroy(_content);
// 				_alloc.deallocate(_content, 1);
// 			}
// 		};
// 		const Key&	First(){
// 			return _content->first;
// 		};
// 		T&		Second(){
// 			return _content->second;
// 		};
// 		void	setSecond(T& value){
// 			_content->second = value;
// 		};
// 		void	setParent(node* parent){
// 			_parent = parent;
// 		};
// 		void	setChild_l(node* child){
// 			_child_l = child;
// 		};
// 		void	setChild_r(node* child){
// 			_child_r = child;
// 		};
// 		node*	getParent() const{
// 			return _parent;
// 		};
// 		node*	getChild_l() const{
// 			return _child_l;
// 		};
// 		node*	getChild_r() const{
// 			return _child_r;
// 		};
// 		mapped_type*	getContent() const{
// 			return _content;
// 		}
// 		mapped_type& operator *(){
// 			return *_content;
// 		};

// 	private:
// 		Allocator			_alloc;
// 		node*				_parent;
// 		node*				_child_l;
// 		node*				_child_r;
// 		mapped_type*		_content;
// 	};

template <class Key, class T, bool B = false >
class map_iterator
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

		map_iterator():_target(NULL){};
		map_iterator(node_pointer target):_target(target){};
		map_iterator(map_iterator<Key, T> other):_target(other._target){};
		map_iterator(map_iterator<Key, T, true> other):_target(other.getNode_pointer()){};
		~map_iterator(){};

		elemPtr getElemPtr() const      { return _target->getContent(); };
		node_pointer	getNode_pointer() const {return _target;};

		reference operator*() const         { return (*_target->getContent()); };
		pointer operator->() const          { 
			// std::cout << _target->getContent() << std::endl;;
			return (_target->getContent()); };
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

	private:
		node_pointer		_target;

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
			while (reader->getParent() && reader == reader->getParent()->getChild_l()){
				reader = reader->getParent();
				stage++;
			}
			if (reader->getParent() && reader->getParent()->getChild_l()){
				reader = reader->getParent()->getChild_l();
				return (moving_down_r(reader, stage, false));
			}
			else{
				while (reader->getParent() && !reader->getParent()->getChild_l()){
					reader = reader->getParent();
					stage++;
				}
				if (reader->getParent() && reader->getParent()->getChild_l()){
					reader = reader->getParent()->getChild_l();
					return (moving_down_r(reader, stage, false));
				}
			}
			if (!reader->getParent() && !called_from_down)
				return (moving_down_r(reader, stage, true));
			else 
				return NULL;
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
		void	move_right(){
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
			_target = moving_up(_target, stage, false);
			// std::cout << "done moving right" << std::endl;
		};
		void	move_left(){
			ssize_t stage = 0;
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
			_target = moving_up_r(_target, stage, false);
		};
};
// template <class Key, class T, bool B >
// class reverse_map_iterator
// {
// 	public:
// 		typedef long int																				difference_type;
// 		typedef ft::pair<const Key, T>																	value_type;
// 		typedef size_t																					size_type;

// 		typedef map_node<value_type>																	node_pointer;
// 		typedef std::random_access_iterator_tag															iterator_category;
// 		typedef typename chooseConst<B, ft::pair<const Key, T>&, const ft::pair<const Key, T>&>::type	reference;
// 		typedef typename chooseConst<B, ft::pair<const Key, T>*, const ft::pair<const Key, T>*>::type	pointer;
// 		typedef ft::pair<const Key, T>*																	elemPtr;

// 		reverse_map_iterator():_target(NULL){};
// 		reverse_map_iterator(map_node<Key, T>* target):_target(target){};
// 		reverse_map_iterator(reverse_map_iterator& other):_target(other._target){};
// 		~reverse_map_iterator(){};

// 		elemPtr getElemPtr() const      { return _target; };

// 		reference operator*() const         { return (*_target); };
// 		pointer operator->() const          { return (_target); };
// 		reverse_map_iterator& operator=(const reverse_map_iterator& other){
// 			this->_target = other.getElemPtr();
// 			return (*this);
// 		};
// 		operator unsigned long(){return ((unsigned long)_target);};

// 		reverse_map_iterator& operator++()       { move_right(); return (*this); };
// 		reverse_map_iterator& operator--()       { move_left(); return (*this); };

// 		reverse_map_iterator operator++(int){
// 			reverse_map_iterator res(*this);
// 			move_right();
// 			return (res);
// 		};
// 		reverse_map_iterator operator--(int){
// 			reverse_map_iterator res(*this);
// 			move_left();
// 			return (res);
// 		};
// 		reverse_map_iterator& operator+=(int decal){
// 			for (int i = 0; i < decal; i++){
// 				move_right();
// 			}
// 			return (*this);
// 		};
// 		reverse_map_iterator& operator-=(int decal){
// 			for (int i = 0; i < decal; i++){
// 				move_left();
// 			}
// 			return (*this);
// 		};
// 		reverse_map_iterator operator+(int nb) const{
// 			reverse_map_iterator it(*this);
// 			for (int i = 0; i < nb; i++){
// 				it.move_right();
// 			}
// 			return (it);
// 		}
// 		reverse_map_iterator operator-(int nb) const{
// 			reverse_map_iterator it(*this);
// 			for (int i = 0; i < nb; i++){
// 				it.move_left();
// 			}
// 			return (it);
// 		};
// 		reverse_map_iterator operator+(size_t nb) const{
// 			reverse_map_iterator it(*this);
// 			for (size_t i = 0; i < nb; i++){
// 				it.move_right();
// 			}
// 			return (it);
// 		};
// 		reverse_map_iterator operator-(size_t nb) const{
// 			reverse_map_iterator it(*this);
// 			for (size_t i = 0; i < nb; i++){
// 				it.move_left();
// 			}
// 			return (it);
// 		};

// 	private:
// 		node_pointer	_target;

// 		void	move_left(){
// 			ssize_t stage = 0;
// 			map_node<Key, T>* reader = _target;
// 			if (!reader)
// 				return ;
// 			while (reader->getParent() && reader == reader->getParent()->getChild_r()){
// 				reader = reader->getParent();
// 				stage++;
// 			}
// 			if (reader->getParent() && reader->getParent()->getChild_r()){
// 				reader = reader->getParent()->getChild_r();
// 				while(stage > 0 && reader->getChild_l()){
// 					reader = reader->getChild_l();
// 					stage--;
// 				}
// 			}
// 			else if (!reader->getParent()){
// 				while (stage >= 0){
// 					reader = reader->getChild_l();
// 					stage--;
// 				}
// 			}
// 			_target = reader;
// 		};
// 		void	move_right(){
// 			ssize_t stage = 0;
// 			map_node<Key, T>* reader = _target;
// 			if (!reader)
// 				return ;
// 			while (reader->getParent() && reader == reader->getParent()->getChild_l()){
// 				reader = reader->getParent();
// 				stage++;
// 			}
// 			if (reader->getParent() && reader->getParent()->getChild_l()){
// 				reader = reader->getParent()->getChild_l();
// 				while(stage > 0 && reader->getChild_r()){
// 					reader = reader->getChild_r();
// 					stage--;
// 				}
// 			}
// 			else if (!reader->getParent()){
// 				while (stage > 1){
// 					reader = reader->getChild_r();
// 					stage--;
// 				}
// 			}
// 			_target = reader;
// 		};
// };
// template < class T >
// class ft::map_node{
// 	public:
// 		ft::map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
// 		ft::map_node(T	content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(content){};
// 		ft::map_node(ft::map_node other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(other._content){};
// 		~ft::map_node();
// 	private:
// 		ft::map_node*	_parent;
// 		ft::map_node*	_child_l;
// 		ft::map_node*	_child_r;
// 		T*			_content;
// };


};


#endif