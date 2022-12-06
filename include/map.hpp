#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
// #include <map>
#include "Pair.hpp"
#include "map_iterator.hpp"

namespace ft{
	// class map_node{
	// public:
	// 	map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
	// 	map_node(U	content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){
	// 		_content = Allocator.allocate(1);
	// 		Allocator.construct(_content, content);
	// 	};
	// 	map_node(map_node other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(NULL){
	// 		_content = Allocator.allocate(1);
	// 		Allocator.construct(_content, other._content);
	// 	};
	// 	~map_node(){
	// 		if (_content){
	// 			Allocator.destroy(_content);
	// 			Allocator.deallocate(_content, 1);
	// 		}
	// 	};
	// 	Key&	First(){
	// 		return _content.first;
	// 	};
	// 	T&		Second(){
	// 		return _content.second;
	// 	};
	// 	void	setSecond(T& value){
	// 		_content.second = value;
	// 	};
	// 	void	setParent(map_node* parent){
	// 		_parent = parent;
	// 	};
	// 	void	setChild_l(map_node* child){
	// 		_child_l = child;
	// 	};
	// 	void	setChild_r(map_node* child){
	// 		_child_r = child;
	// 	};
	// 	map_node*	getParent(){
	// 		return _parent;
	// 	};
	// 	map_node*	getChild_l(){
	// 		return _child_l;
	// 	};
	// 	map_node*	getChild_r(){
	// 		return _child_r;
	// 	};
	// 	ft::pair<const Key, T>*	getContent(){
	// 		return _content;
	// 	}
	// 	ft::pair<const Key, T>& operator *(){
	// 		return *_content;
	// 	};

	// private:
	// 	ft::map_node*				_parent;
	// 	ft::map_node*				_child_l;
	// 	ft::map_node*				_child_r;
	// 	ft::pair<const Key, T>*	_content;
	// };

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class Map{
		public:
		// typedef 
			typedef map_node<Key, T, Allocator>			node;
			typedef const Key									key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef ft::map_iterator<Key, T, false>				iterator;
			typedef ft::map_iterator<Key, T, true>				const_iterator;
			typedef ft::reverse_map_iterator<Key, T, false>		reverse_iterator;
			typedef ft::reverse_map_iterator<Key, T, true>		const_reverse_iterator;
		//member functions
			Map():_root(NULL), _nb_node(0){};
			explicit Map( const Compare& comp, const Allocator& alloc = Allocator()):_root(NULL), _nb_node(0){};
			template< class InputIt > Map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):_root(NULL), _nb_node(0){
				while (first != last){
					add_node(*first);
					first++;
				}
			};
			Map( const Map& other ):_root(NULL), _nb_node(0){
				bool first = true;
				for (iterator i = other.begin(); i != other.end(); i++){
						add_node(*i);
				}
			};
			~Map(){
				clear();
			};
			Map& operator=( const Map& other ){
				clear();
				int count = 0;
				for (iterator i = other.begin(); i != other.end(); i++){
					add_node(*i);
					count++;
					// std::cout << count << " node added " << std::endl;
				}
			};
			allocator_type get_allocator() const{return _alloc;};

		//element access
			T& at( const Key& key ){
				node* reader = find(key);
				if (!reader)
					throw (out_of_range_exception());
				else
					return reader->Second();
			};
			const T& at( const Key& key ) const{
				node* reader = find(key);
				if (!reader)
					throw (out_of_range_exception());
				else
					return reader->Second();
			};
			T& operator[]( const Key& key ){
				node* reader = find(key);
				if (reader)
					return reader->Second();
				else
					add_node(ft::pair< Key, T >(key, T()) );
				reader = find(key);
				return reader->second();
			};
			node*	getRoot(){
				return _root;
			}

		//iterators
			iterator begin(){
				node* reader = _root;
				while (reader && reader->getChild_l())
					reader = reader->getChild_l();
				iterator ret (reader, _root);
				return ret;
			};
			const_iterator begin() const{
				node* reader = _root;
				while (reader && reader->getChild_l())
					reader = reader->getChild_l();
				iterator ret (reader, _root);
				return ret;
			};
			iterator end(){
				iterator ret (NULL, _root);
				return ret;
			};
			const_iterator end() const{
				iterator ret (NULL, _root);
				return ret;
			};
			reverse_iterator rbegin(){
				node* reader = _root;
				while (reader && reader->getChild_l())
					reader = reader->getChild_l();
				reverse_iterator ret (reader, _root);
				return ret;
			};
			const_reverse_iterator rbegin() const{
				node* reader = _root;
				while (reader && reader->getChild_l())
					reader = reader->getChild_l();
				reverse_iterator ret (reader, _root);
				return ret;
			};
			reverse_iterator rend(){
				reverse_iterator ret (NULL, _root);
				return ret;
			};
			const_reverse_iterator rend() const{
				reverse_iterator ret (NULL, _root);
				return ret;
			};

		//capacity
			bool empty() const{
				if (_root)
					return false;
				else
					return true;
			};
			size_type size() const{
				return _nb_node;
			};
			size_type max_size() const{
				return _alloc.max_size();
			};

		//modifiers
			void clear(){
				while (_nb_node){
					node* reader(_root);
					while (reader->getChild_l() || reader->getChild_r()){
						if (reader->getChild_l())
							reader = reader->getChild_l();
						else if (reader->getChild_r())
							reader = reader->getChild_r();
					}
					delete_node(reader);
					// std::cout << "here " << _nb_node << std::endl;
				}
				_root = NULL;
			};
			ft::pair<iterator, bool> insert(const value_type& value ){
				iterator reader = find(value.first);
				if (reader){
					iterator ret (reader.getNode_pointer(), _root);
					return ft::make_pair(ret, false);
				};
				iterator ret (add_node(value), _root);
				return (ft::make_pair(ret, true));
			};
			iterator insert( iterator pos, const value_type& value ){
				node* reader = find(value);
				if (reader)
					return reader;
				return add_node(value);
			};
			template< class InputIt > void insert( InputIt first, InputIt last ){
				for (InputIt i = first; i != last; i++){
					if (!find(i.First()))
						add_node(*i);
				}
			};
			iterator erase( iterator pos ){
				delete_node(pos);
				return NULL;
			};
			iterator erase( iterator first, iterator last ){
				for (iterator i = first; i != last; i++){
					delete_node(i);
				}
				return NULL;
			};
			size_type erase( const Key& key ){
				node* reader = find(key);
				if (reader){
					delete_node(reader);
					return 1;
				}
				return 0;
			};
			void swap( Map& other ){
				swap(this->_root, other._root);
				swap(this->_nb_node, other._nb_node);
			};

		//lookup
			size_type count( const Key& key ) const{
				if (find(key))
					return 1;
				return 0;
			};
			iterator find( const Key& key ){
				node* reader = _root;
				while(reader && reader->First() != key){
					if (reader->First() < key)
						reader = reader->getChild_l();
					else 
						reader = reader->getChild_r();
				}
				iterator ret (reader, _root);
				return (ret);
			};
			const_iterator find( const Key& key ) const{
				for (iterator i = begin(); i != end(); i++){
					if (i->first() == key)
						return (i);
				}
				return (NULL, _root);
			};
			ft::pair<iterator,iterator> equal_range( const Key& key ){
				ft::pair<iterator, iterator> ret;
				for (iterator i = begin(); i != end(); i++){
					if (!(i->first() < key) && i->first() == key){
						ret.first = i;
						i++;
						ret.second = i;
						break ;
					}
					else if (!(i->first() < key)){
						ret.first = i;
						ret.second = i;
						break ;
					}
				}
				return ret;
			};
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				ft::pair<iterator, iterator> ret;
				for (iterator i = begin(); i != end(); i++){
					if (!(i->first() < key) && i->first() == key){
						ret.first = i;
						i++;
						ret.second = i;
						break ;
					}
					else if (!(i->first() < key)){
						ret.first = i;
						ret.second = i;
						break ;
					}
				}
				return ret;
			};
			iterator lower_bound( const Key& key ){
				node* reader = _root;
				while (reader && Compare(reader->First(), key))
					reader = reader->getChild_r();
				return (reader, _root);
			};
			const_iterator lower_bound( const Key& key ) const{
				node* reader = _root;
				while (reader && Compare(reader->First(), key))
					reader = reader->getChild_r();
				return (reader, _root);
			};
			iterator upper_bound( const Key& key ){
				node* reader = _root;
				while (reader && (Compare(reader->First(), key) || reader->First() == key))
					reader = reader->getChild_r();
				return (reader, _root);
			};
			const_iterator upper_bound( const Key& key ) const{
				node* reader = _root;
				while (reader && (Compare(reader->First(), key) || reader->First() == key))
					reader = reader->getChild_r();
				return (reader, _root);
			};

		//observer
			key_compare key_comp() const{return _compare;};
			Compare value_comp() const{return comp_node;};
	
		// exception
			class out_of_range_exception: public std::exception{
			public:
				const char* what() const throw(){
					return ("Error : out of range exception");
				};
			};
		private:
			bool	comp_node(ft::pair<const Key, T> one, ft::pair<const Key, T> two){
				return Compare(one.first, two.first);
			}
		//private attribute
			node*						_root;
			size_type												_nb_node;
			std::allocator < node >	_alloc;
			Compare													_compare;

		// nodes manipulation functions
			node* new_node(value_type value){
				// node model(value);
				node* temp = _alloc.allocate(1);
				_alloc.construct(temp, value);
				_nb_node++;
				// std::cout << "new_node created : " << temp << "|" << temp->getChild_l() << "|" << temp->getChild_r() << "|" << temp->getParent() << std::endl;
				// if (temp == _root)
				// 	std::cout << "it's over 9999999999 impossible " << std::endl;
				return temp;
			};
			node*	add_node(value_type value){
				node* reader = _root;
			// std::cout << "begin adding" << std::endl;
				if (!_root){
					_root = new_node(value);
					// std::cout << "first node " << std::endl;
				// 	std::cout << "reader is " << _root->First() << std::endl;
				// std::cout << "value " << value.first << std::endl;
				}
				// else{
				// 	std::cout << "reader is " << reader << std::endl;
				// 	std::cout << reader->getChild_r() << std::endl;
				// std::cout << "value " << value.first << std::endl;
				// }
				while (reader){
					
					if (value.first == reader->First()){
						reader->setSecond(value.second);
						// std::cout << "assigned" << std::endl;
						return reader;
					}
					else if (reader->getChild_l() != NULL && _compare(value.first, reader->First())){
						reader = reader->getChild_l();
						// std::cout << "looping left" << std::endl;
					}
					else if (reader->getChild_r() != NULL && _compare(reader->First(), value.first)){
						// std::cout << "looping right : " << reader << " " << reader->getChild_l() << " " << reader->getChild_r() << std::endl;
						// std::cout << reader->First() << "|" << reader->getChild_r()->First() << std::endl;
						reader = reader->getChild_r();
					}
					else if (_compare(value.first, reader->First())){
						add_child_l(reader, new_node(value));
						// std::cout << "done adding left" << std::endl;
				// 		std::cout << "reader is " << reader->First() << std::endl;
				// std::cout << "value " << value.first << std::endl;
						return reader->getChild_l();
					}
					else if (_compare(reader->First(), value.first)){
						add_child_r(reader, new_node(value));
						// std::cout << "done adding right" << std::endl;
				// 		std::cout << "reader is " << reader->First() << std::endl;
				// std::cout << "value " << value.first << std::endl;
						return reader->getChild_r();
					}
					// else 
					// 	std::cout << "hello from loop " << reader << " " << reader->getChild_l() << " " << reader->getChild_r() << std::endl;
				}
				// std::cout << "done adding" << std::endl;
				return _root;
			};
			void	delete_node(node* target){
				while (target->getChild_r())
					swapChild_r(target);
				// std::cout << "node destroyed " << target->getContent() << std::endl;
				if (target->getParent() && target == target->getParent()->getChild_l())
					target->getParent()->setChild_l(NULL);
				else if (target->getParent() && target == target->getParent()->getChild_r())
					target->getParent()->setChild_r(NULL);
				_alloc.destroy(target);
				_alloc.deallocate(target, 1);
				// std::cout << "done " << std::endl;
				_nb_node--;
			};
			void	add_child_l(node* parent, node* child){
				parent->setChild_l(child);
				child->setParent(parent);
			};
			void	add_child_r(node* parent, node* child){
				if (parent == child)
					std::cout << " Warning ---------------- : " << _root << "|" << parent << "|" << child << std::endl;
				parent->setChild_r(child);
				child->setParent(parent);
			};
			void	swapChild_l(node* parent){
				if (!parent->getChild_l())
					return ;
				node* pp = parent->getParent();
				node* pcl = parent->getChild_l();
				node* pcr = parent->getChild_r();
				node* child = pcl;
				parent->setParent(child->getParent());
				parent->setChild_l(child->getChild_l());
				parent->setChild_r(child->getChild_r());
				child->setParent(pp);
				child->setChild_l(pcl);
				child->setChild_r(pcr);
			};
			void	swapChild_r(node* parent){
				if (!parent->getChild_r())
					return ;
				node* pp = parent->getParent();
				node* pcl = parent->getChild_l();
				node* pcr = parent->getChild_r();
				node* child = pcr;
				parent->setParent(child->getParent());
				parent->setChild_l(child->getChild_l());
				parent->setChild_r(child->getChild_r());
				child->setParent(pp);
				child->setChild_l(pcl);
				child->setChild_r(pcr);
			};
		// private template map node
			// class map_node{
			// 	public:
			// 		map_node():_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){};
			// 		map_node(U	content):_parent(NULL), _child_l(NULL), _child_r(NULL), _content(NULL){
			// 			_content = Allocator.allocate(1);
			// 			Allocator.construct(_content, content);
			// 		};
			// 		map_node(map_node other):_parent(other._parent), _child_l(other._child_l), _child_r(other._child_r), _content(NULL){
			// 			_content = Allocator.allocate(1);
			// 			Allocator.construct(_content, other._content);
			// 		};
			// 		~map_node(){
			// 			if (_content){
			// 				Allocator.destroy(_content);
			// 				Allocator.deallocate(_content, 1);
			// 			}
			// 		};
			// 		Key&	First(){
			// 			return _content.first;
			// 		};
			// 		T&		Second(){
			// 			return _content.second;
			// 		};
			// 		void	setSecond(T& value){
			// 			_content.second = value;
			// 		};
			// 		void	setParent(map_node* parent){
			// 			_parent = parent;
			// 		};
			// 		void	setChild_l(map_node* child){
			// 			_child_l = child;
			// 		};
			// 		void	setChild_r(map_node* child){
			// 			_child_r = child;
			// 		};
			// 		map_node*	getParent(){
			// 			return _parent;
			// 		};
			// 		map_node*	getChild_l(){
			// 			return _child_l;
			// 		};
			// 		map_node*	getChild_r(){
			// 			return _child_r;
			// 		};
			// 		ft::pair<const Key, T>*	getContent(){
			// 			return _content;
			// 		}
			// 		ft::pair<const Key, T>& operator *(){
			// 			return *_content;
			// 		};

			// 	private:
			// 		map_node*				_parent;
			// 		map_node*				_child_l;
			// 		map_node*				_child_r;
			// 		ft::pair<const Key, T>*	_content;
			// };

		protected:
	};
	template< class Key, class T, class Compare, class Alloc > bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		if (lhs._nb_node != rhs._nb_node)
			return false;
		ft::map_iterator<Key, T, false> i = lhs.begin(), j = rhs.begin();
		while (i && j){
			if (i.second != j.second)
				return false;
			i++;
			j++;
		}
		return (i == j);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return !(rhs == lhs);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator<( const map<Key,T,Compare,Alloc>& lhs,  const map<Key,T,Compare,Alloc>& rhs ){
		if (lhs._nb_node < rhs._nb_node)
			return true;
		ft::map_iterator<Key, T, false> i = lhs.begin(), j = rhs.begin();
		while (i && j){
			if (i.second < j.second)
				return true;
			i++;
			j++;
		}
		return (i < j);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return !(rhs > lhs);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	};
	template< class Key, class T, class Compare, class Alloc > bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs < rhs);
	};
};

//check add_node and make a tidying function

#endif