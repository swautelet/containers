#ifndef TESTER_HPP
# define TESTER_HPP

#include <vector>
#include <string>
#include <iostream>

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

void	vector_test();
void	map_test();
void	stack_test();
void    utility_test();
void    print_result(std::ofstream& out, std::vector<int>& answer);
void    run_test(std::string name);
#endif