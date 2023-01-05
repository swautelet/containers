#ifndef MAP_NODE_HPP
# define MAP_NODE_HPP

#include "Map.hpp"

template<class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map_node{
	public:
		typedef ft::pair<const Key, T>				mapped_type;
		typedef map_node <Key, T, Allocator>		node;

		map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
		map_node(mapped_type content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){
			_content = _alloc.allocate(1);
			_alloc.construct(_content, content);
		};
		map_node(node& other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(NULL){
			_content = _alloc.allocate(1);
			_alloc.construct(_content, *(other._content));
		};
		~map_node(){
			if (_content){
				_alloc.destroy(_content);
				_alloc.deallocate(_content, 1);
			}
		};
		const Key&	First(){
			return _content->first;
		};
		T&		Second(){
			return _content->second;
		};
		void	setSecond(T& value){
			_content->second = value;
		};
		void	setContent(mapped_type* value){
			_content = value;
		};
		void	setParent(node* parent){
			_parent = parent;
		};
		void	setChild_l(node* child){
			_child_l = child;
		};
		void	setChild_r(node* child){
			_child_r = child;
		};
		node*	getParent() const{
			return _parent;
		};
		node*	getChild_l() const{
			return _child_l;
		};
		node*	getChild_r() const{
			return _child_r;
		};
		mapped_type*	getContent() const{
			return _content;
		}
		mapped_type*	operator->() const{
			return _content;
		}
		mapped_type& operator *(){
			return *_content;
		};
		void	setPos(bool x){
			_red_black = x;
		};
		bool	getPos(){
			return _red_black;
		};
	private:

		Allocator			_alloc;
		node*				_parent;
		node*				_child_l;
		node*				_child_r;
		mapped_type*		_content;
		bool				_red_black;

	};

	#endif