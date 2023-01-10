#ifndef TESTER_HPP
# define TESTER_HPP

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <iostream>

#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"
#include "Utility.hpp"

#define	_vector 			ft::Vector
#define	_stack	 			ft::Stack
#define	_map 				ft::Map
#define	_set	 			ft::Set
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_lexicographical	ft::lexicographical_compare
#define	_equal				ft::equal
#define _ratio 10

void	vector_test(std::ofstream& out);
void	map_test(std::ofstream& out);
void	stack_test(std::ofstream& out);
void    utility_test(std::ofstream& out);
void    print_result(std::ofstream& out, std::vector<int>& answer);
void    run_test(std::string name);
// vector test
// template <typename T>
// std::vector<int> assign_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> assign_test(_vector<T> vector);
// template <typename T>
// std::vector<int> assign_std_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> assign_std_test(_vector<T> vector);
// template <typename T>
// std::vector<int> at_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> at_test(_vector<T> vector);
// template <typename T>
// std::vector<int> back_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> back_test(_vector<T> vector);
// template <typename T>
// std::vector<int> begin_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> begin_test(_vector<T> vector);
// template <typename T>
// std::vector<int> capacity_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> capacity_test(_vector<T> vector);
// template <typename T>
// std::vector<int> clear_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> clear_test(_vector<T> vector);
// template <typename T>
// std::vector<int> constructor_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> constructor_test(_vector<T> vector);
// template <typename T>
// std::vector<int> constructor_std_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> constructor_std_test(_vector<T> vecto);
// template <typename T>
// std::vector<int> data_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> data_test(_vector<T> vector);
// template <typename T>
// std::vector<int> empty_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> empty_test(_vector<T> vector);
// template <typename T>
// std::vector<int> end_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> end_test(_vector<T> vector);
// template <typename T>
// std::vector<int> erase_test_2(std::vector<T> vector);
// template <typename T>
// std::vector<int> erase_test_2(_vector<T> vector);
// template <typename T>
// std::vector<int> erase_test_1(std::vector<T> vector);
// template <typename T>
// std::vector<int> erase_test_1(_vector<T> vector);
// template <typename T>
// std::vector<int> front_test(std::vector<T> vector);
// template <typename T>
// std::vector<int> front_test(_vector<T> vector);
// template <typename T>
// std::vector<int> insert_test_2(std::vector<T> vector);
// template <typename T>
// std::vector<int> insert_test_2(_vector<T> vector);
#endif