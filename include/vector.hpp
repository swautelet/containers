#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft
{
    template<class T, class Allocator = std::allocator<T> > class vector
    {
        public:
        //member functions
            vector();
            explicit vector( const Allocator& alloc );
            explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
            template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
            vector( const vector& other );
            ~vector();
            vector&  operator=(const vector& other);
            void assign( size_type count, const T& value );
            allocator_type get_allocator() const;

        //element access
            reference at( size_type pos );
            reference operator[]( size_type pos );
            reference front();
            reference back();
            T* data();
            const T* data() const;

        //iterators
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;

        //Capacity
            bool empty() const;
            size_type size() const;
            size_type max_size() const;
            void reserve( size_type new_cap );
            size_type capacity() const;

        //modifiers
            void clear();
            iterator insert( const_iterator pos, const T& value );
            iterator insert( const_iterator pos, size_type count, const T& value );
            constexpr iterator insert( const_iterator pos, size_type count, const T& value );
            template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );
            iterator erase( iterator pos );
            iterator erase( iterator first, iterator last );
            void push_back( const T& value );
            void pop_back();
            void resize( size_type count, T value = T() );
            void swap( vector& other );

        private:
            allocator  alloc;
        protected:
    };
    template< class T, class Alloc > bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
    template< class T, class Alloc > bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
    template< class T, class Alloc > bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
    template< class T, class Alloc > bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
    template< class T, class Alloc > bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
    template< class T, class Alloc > bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
};

#endif