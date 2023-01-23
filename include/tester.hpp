#pragma once
#ifndef HEAD_TESTER_HPP
#define HEAD_TESTER_HPP

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/time.h>

#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"
#include "Utility.hpp"
#ifndef FAST
#define _ratio 100
#else
#define _ratio 1
#endif

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

typedef long time_t;

time_t g_start;
time_t g_end;

time_t timer();

#include "../src/vector/assign().hpp"
#include "../src/vector/assign(std_iterators).hpp"
#include "../src/vector/at().hpp" 
#include "../src/vector/back().hpp" 
#include "../src/vector/begin().hpp"
#include "../src/vector/capacity().hpp"
#include "../src/vector/clear().hpp" 
#include "../src/vector/constructor.hpp"
#include "../src/vector/constructor(std_iterators).hpp"
#include "../src/vector/data().hpp"
#include "../src/vector/empty().hpp"
#include "../src/vector/end().hpp"
#include "../src/vector/erase(range).hpp"
#include "../src/vector/erase(value).hpp"
#include "../src/vector/front().hpp"
#include "../src/vector/insert(fill).hpp"
#include "../src/vector/insert(range).hpp"
#include "../src/vector/insert(std_iterators).hpp"
#include "../src/vector/insert(value).hpp"
#include "../src/vector/iterators.hpp"
#include "../src/vector/max_size().hpp"
#include "../src/vector/operator!=.hpp"
#include "../src/vector/operator<.hpp"
#include "../src/vector/operator<=.hpp"
#include "../src/vector/operator==.hpp"
#include "../src/vector/operator>.hpp"
#include "../src/vector/operator>=.hpp"
#include "../src/vector/operator[].hpp"
#include "../src/vector/pop_back().hpp"
#include "../src/vector/push_back().hpp"
#include "../src/vector/rbegin().hpp"
#include "../src/vector/rend().hpp"
#include "../src/vector/reserve().hpp"
#include "../src/vector/resize().hpp"
#include "../src/vector/size().hpp"
#include "../src/vector/swap().hpp"
#include "../src/vector/using_allocator.hpp"
#include "../src/vector/v__service.hpp"
#include "../src/map/assign_overload.hpp"
#include "../src/map/at().hpp"
#include "../src/map/clear().hpp"
#include "../src/map/compare_class.hpp"
#include "../src/map/constructor.hpp"
#include "../src/map/count().hpp"
#include "../src/map/empty().hpp"
#include "../src/map/equal_range().hpp"
#include "../src/map/erase(InputIt).hpp"
#include "../src/map/erase(key).hpp"
#include "../src/map/erase(pos).hpp"
#include "../src/map/find().hpp"
#include "../src/map/insert(hint).hpp"
#include "../src/map/insert(InputIt).hpp"
#include "../src/map/insert(value).hpp"
#include "../src/map/iterators.hpp"
#include "../src/map/key_comp().hpp"
#include "../src/map/lower_bound().hpp"
#include "../src/map/max_size().hpp"
#include "../src/map/operator!=.hpp"
#include "../src/map/operator<.hpp"
#include "../src/map/operator<=.hpp"
#include "../src/map/operator==.hpp"
#include "../src/map/operator>.hpp"
#include "../src/map/operator>=.hpp"
#include "../src/map/operator[].hpp"
#include "../src/map/reverse_iterators.hpp"
#include "../src/map/size().hpp"
#include "../src/map/swap().hpp"
#include "../src/map/upper_bound().hpp"
#include "../src/map/using_allocator.hpp"
#include "../src/map/m__service.hpp"
#include "../src/stack/constructor.hpp"
#include "../src/stack/empty().hpp"
#include "../src/stack/operator!=.hpp"
#include "../src/stack/operator<.hpp"
#include "../src/stack/operator<=.hpp"
#include "../src/stack/operator==.hpp"
#include "../src/stack/operator>.hpp"
#include "../src/stack/operator>=.hpp"
#include "../src/stack/pop().hpp"
#include "../src/stack/push().hpp"
#include "../src/stack/size().hpp"
#include "../src/stack/top().hpp"
#include "../src/stack/s__service.hpp"
#include "../src/utility/enable_if.hpp"
#include "../src/utility/equal.hpp"
#include "../src/utility/is_integral.hpp"
#include "../src/utility/iterator_traits.hpp"
#include "../src/utility/lexicographical.hpp" 

void	vector_test(std::ofstream& out, std::ofstream& out_time);
void	map_test(std::ofstream& out, std::ofstream& out_time);
void	stack_test(std::ofstream& out, std::ofstream& out_time);
void    utility_test(std::ofstream& out, std::ofstream& out_time);
void    print_result(std::ofstream& out, std::vector<int> answer);
void    run_test(std::string name, std::string name_time);
void	display_time(std::string mess, std::ofstream& out_time);
#endif