#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
// #include <vector>


namespace ft
{
	template<class T, class Allocator = std::allocator<T> > class vector
	{
		typedef T                                        value_type;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef implementation-defined                   iterator;
		typedef implementation-defined                   const_iterator;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		typedef std::reverse_iterator<iterator>          reverse_iterator;
		typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
		public:
		//member functions
			vector():_alloc(Allocator()), _first(NULL), _size(0), _capacity(0){};
			explicit vector( const Allocator& alloc ):_alloc(alloc), _first(NULL), _size(0), _capacity(0){};
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()):_alloc(alloc), _first(_alloc.allocate(count)), _size(count), _capacity(count){
				for (size_t i = 0; i < _size; i++){
					_alloc.construct(_first + i, value);
				}
			};
			template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ):_alloc(alloc), _first(_alloc.alocate(last - first)), _size(last - first), _capacity(last - first){
				for (size_t i = 0; first + i != last; i++){
					_alloc.construct(_first + i, first + i);
				}
			};
			vector( const vector& other ):_alloc(other._alloc), _first(_alloc.allocate(other._size)), _size(other._size), _capacity(other._size){
				for (size_t i = 0; i < other.size(); i++){
					_alloc.construct(_first + i, other[i]);
				}
			};
			~vector(){
				_alloc.deallocate(_first, _capacity);
			};
			vector&  operator=(const vector& other){
				if (_capacity >= other.size()){
					for(size_t i = 0; i < other.size(); i++){
						if (i < _size)
							this[i] = other[i];
						else
							_alloc.construct(_first + i, other[i]);
					}
					if (_size > other.size()){
						for (size_t i = other.size(); i < _size; i++){
							_alloc.destroy(_first + i);
						}
					}
					this->_size = other.size();
				}
				else{
					reallocate(other.size());
					for (size_t i = 0; i < _size; i++){
						_alloc.construct(_first + i, other[i]);
					}
				}
				return *this;
			};
			void assign( size_type count, const T& value ){
				if (_capacity >= count){
					for(size_t i = 0; i < count; i++){
						if (i < _size)
							this[i] = value;
						else
							_alloc.construct(_first + i, value);
					}
					if (_size > count){
						for (size_t i = count; i < _size; i++){
							_alloc.destroy(_first + i);
						}
					}
					this->_size = count;
				}
				else{
					reallocate(count);
					for (size_t i = 0; i < _size; i++){
						_alloc.construct(_first + i, value);
					}
				}
			};
			allocator_type get_allocator() const{
				return _alloc;
			};

		//element access
			reference at( size_type pos ){
				if (pos >= _size)
					throw out_of_range_exception();
				return (_first + pos);
			};
			reference operator[]( size_type pos ){
				if (pos >= _size)
					throw out_of_range_exception();
				return (_first + pos);
			};
			reference front(){
				return (*_first);
			};
			reference back(){
				return (*(_first + _size));
			};
			T* data(){
				return _first;
			};
			const T* data() const{
				return _first;
			};

		//iterators
			iterator begin(){
				return _first;
			};
			const_iterator begin() const{
				return _first;
			};
			iterator end(){
				return _first + _size;
			};
			const_iterator end() const{
				return _first + _size;
			};
			reverse_iterator rbegin(){
				return (reverse_iterator(_first));
			};
			const_reverse_iterator rbegin() const{
				return (reverse_iterator(_first));
			};
			reverse_iterator rend(){
				return (reverse_iterator(_first + _size));
			};
			const_reverse_iterator rend() const{
				return (reverse_iterator(_first + _size));
			};

		//Capacity
			bool empty() const{
				if (_first)
					return false;
				else
					return true;
			};
			size_type size() const{
				return _size;
			};
			size_type max_size() const{
				return _alloc.max_size();
			};
			void reserve( size_type new_cap ){
				if (_capacity >= new_cap)
					return ;
				else{
					pointer temp = _alloc.allocate(new_cap);
					for (size_t i = 0; i < _size; i++){
						_alloc.construct(temp + i, _first[i]);
						_alloc.destroy(_first + i);
					}
					_alloc.deallocate(_first, _capacity);
					_first = temp;
					_capacity = new_cap;
				}
			};
			size_type capacity() const{
				return _capacity;
			};

		//modifiers
			void clear(){
				for (size_t i = 0; i < _size; i++){
					_alloc.destroy(_first + i);
				}
				_size = 0;
			};
			iterator insert( const_iterator pos, const T& value ){
				if (pos < _first || pos > _first + _size)
					throw out_of_range_exception();
				if (_capacity == _size)
					reserve(_size * 2);
				for (iterator i = end(); i > pos; i--){
					i = i - 1;
				}
				*pos = value;
			};
			iterator insert( const_iterator pos, size_type count, const T& value ){
				if (pos < _first || pos > _first + _size)
					throw out_of_range_exception();
				if (_capacity <= _size + count && count < _size)
					reserve(_size * 2);
				else if (_capacity <= _size + count)
					reserve(_size + count);
				for (iterator i = end(); i > pos + count; i--){
					i = i - count;
				}
				for (size_type i = 0; i < count; i++){
					*(pos + i) = value;
				}
				return (_first + pos - _first);
			};
			constexpr iterator insert( const_iterator pos, size_type count, const T& value ){
				if (pos < _first || pos > _first + _size)
					throw out_of_range_exception();
				if (_capacity <= _size + count && count < _size)
					reserve(_size * 2);
				else if (_capacity <= _size + count)
					reserve(_size + count);
				for (iterator i = end(); i > pos + count; i--){
					i = i - count;
				}
				for (size_type i = 0; i < count; i++){
					*(pos + i) = value;
				}
				return (pos);
			};
			template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last ){
				size_t count = last - first;
				if (pos < _first || pos > _first + _size)
					throw out_of_range_exception();
				if (_capacity <= _size + count && count < _size)
					reserve(_size * 2);
				else if (_capacity <= _size + count)
					reserve(_size + count);
				for (iterator i = end(); i > pos + count; i--){
					i = i - count;
				}
				for (size_type i = 0; i < count; i++){
					*(pos + i) = first + i;
				}
				return (pos);
			};
			iterator erase( iterator pos ){
				if (pos < _first || pos > _first + _size)
					throw out_of_range_exception();
				for (size_t i = pos - _first; i < _size - 1; i++){
					_first[i] = _first[i + 1];
				}
				_alloc.destroy(_first + _size - 1);
				return pos;
			};
			iterator erase( iterator first, iterator last ){
				size_t count = last - first;
				if (first < _first || first > _first + _size || last < _first || last > _first + _size)
					throw out_of_range_exception();
				for (iterator i = first; i != last; i++){
					*i = *(i + count);
				}
				for (iterator i = 0; i < count; i++){
					_alloc.destroy(_first + _first - first + count);
				}
				return first;
			};
			void push_back( const T& value ){
				if (_size == _capacity)
					reserve(_size * 2);
				_alloc.construct(_first + _size, value);
				_size++;
			};
			void pop_back(){
				_alloc.destroy(_first + _size - 1);
				_size --;
			};
			void resize( size_type count, T value = T() ){
				if (count < _size){
					for (size_t i = count; i < _size; i++){
						_alloc.destroy(_first + i);
					}
					_size = count;
				}
				else if (count > _size){
					if (count > _capacity)
						reserve(count);
					for (size_t i = _size; i < count; i++){
						_alloc.construct(_first + i, value);
					}
				}
			};
			void swap( vector& other ){
				vector& temp = other;
				other = *this;
				*this = temp;
			};

		// exceptions 
			class out_of_range_exception: public std::exception{
			public:
				const char* what() const throw(){
					return ("out of range exception");
				};
			};

		private:
			void	reallocate(size_t n){
				if (_first)
				{
					for(size_t i = 0; i < _size; i++){
						_alloc.destroy(_first + i);
					}
					_alloc.deallocate(_first, _capacity);
				}
				_first = _alloc.allocate(n);
				_size = n;
				_capacity = _size;
			};
			allocator	_alloc;
			pointer		_first;
			size_t		_size;
			size_t		_capacity;

		protected:
	};
	template< class T, class Alloc > bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++){
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	};
	template< class T, class Alloc > bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return true;
		for (size_t i = 0; i < lhs.size(); i++){
			if (lhs[i] != rhs[i])
				return true;
		}
		return false;
	};
	template< class T, class Alloc > bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++){
			if (lhs[i] < rhs[i])
				return true;
		}
		if (lhs.size() > rhs.size())
			return true;
		return false;
	};
	template< class T, class Alloc > bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++){
			if (lhs[i] <= rhs[i])
				return true;
		}
		if (lhs.size() >= rhs.size())
			return true;
		return false;
	};
	template< class T, class Alloc > bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++){
			if (lhs[i] > rhs[i])
				return true;
		}
		if (lhs.size() < rhs.size())
			return true;
		return false;
	};
	template< class T, class Alloc > bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++){
			if (lhs[i] >= rhs[i])
				return true;
		}
		if (lhs.size() <= rhs.size())
			return true;
		return false;
	};
};

#endif