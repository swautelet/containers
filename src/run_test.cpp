#include "tester.hpp"

#ifndef STD
    using namespace ft;
#else
    using namespace std;
#endif

void    run_test(std::string name){
    std::ofstream outfile(name);

    // outfile.open(name);
    if (outfile.is_open()){
        vector_test(outfile);
        map_test(outfile);
        stack_test(outfile);
        utility_test(outfile);
        outfile.close();
    }
    else{
        std::cout << " error file is not open " << std::endl;
    }
}

void    print_result(std::ofstream& out, std::vector<int> answer){
    for (size_t i = 0; i < answer.size(); i++){
        out << i << " : " << answer[i] << std::endl;
    }
}

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}


void    stack_test(std::ofstream& out){
    Stack<int> test;
    out << "--- constructor test : ---" << std::endl;
    print_result(out, constructor_test(test));
    out << "--- empty test : ---" << std::endl;
    print_result(out, empty_test(test));
    out << "--- stack_not_equal_test : ---" << std::endl;
    if (stack_not_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- stack_less_than_test : ---" << std::endl;
    if (stack_less_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- stack_less_or_equal_test : ---" << std::endl;
    if (stack_less_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- stack_equal_test : ---" << std::endl;
    if (stack_less_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- stack_more_than_test : ---" << std::endl;
    if (stack_more_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- stack_more_or_equal_test : ---" << std::endl;
    if (stack_more_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- pop_test : ---" << std::endl;
    print_result(out, pop_test(test));
    out << "--- push_test : ---" << std::endl;
    print_result(out, push_test(test));
    out << "--- size_test : ---" << std::endl;
    print_result(out, size_test(test));
    out << "--- top_test : ---" << std::endl;
    print_result(out, top_test(test));
    out << "--- done ---" << std::endl;
}

void    map_test(std::ofstream& out){
    Map<int, int> test;
    out << "--- assign overload test : ---" << std::endl;
    print_result(out, assign_overload_test(test));
    out << "--- at test : ---" << std::endl;
    print_result(out, at_test(test));
    out << "--- clear test : ---" << std::endl;
    print_result(out, clear_test(test));
    out << "--- assign overload test : ---" << std::endl;
    print_result(out, comparator_test(test));
    out << "--- comparator test : ---" << std::endl;
    print_result(out, copy_constructor_test(test));
    out << "--- count test : ---" << std::endl;
    print_result(out, count_test(test));
    out << "--- empty test : ---" << std::endl;
    print_result(out, empty_test(test));
    out << "--- equal range test : ---" << std::endl;
    print_result(out, equal_range_test(test));
    out << "--- erase 3 test : ---" << std::endl;
    print_result(out, erase_test_3(test));
    out << "--- erase 1 test : ---" << std::endl;
    print_result(out, erase_test_1(test));
    out << "--- erase 2 test : ---" << std::endl;
    print_result(out, erase_test_2(test));
    out << "--- find test : ---" << std::endl;
    print_result(out, find_test(test));
    out << "--- insert 3 test : ---" << std::endl;
    print_result(out, insert_test_3(test));
    out << "--- insert 2 test : ---" << std::endl;
    print_result(out, insert_test_2(test));
    out << "--- insert test : ---" << std::endl;
    print_result(out, insert_test(test));
    out << "--- iterators test : ---" << std::endl;
    print_result(out, iterators_test(test));
    out << "--- key comp test : ---" << std::endl;
    print_result(out, key_comp_test(test));
    out << "--- lower bound test : ---" << std::endl;
    print_result(out, lower_bound_test(test));
    out << "--- max size test : ---" << std::endl;
    print_result(out, max_size_test(test));
    out << "--- map not equal test : ---" << std::endl;
    if (map_not_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- map less than test : ---" << std::endl;
    if (map_less_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- map less or equal test : ---" << std::endl;
    if (map_less_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- map equal test : ---" << std::endl;
    if (map_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- map more than test : ---" << std::endl;
    if (map_more_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- map more or equal test : ---" << std::endl;
    if (map_more_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    out << "--- operator sq test : ---" << std::endl;
    print_result(out, operator_sq_test(test));
    out << "--- reverse iterators test : ---" << std::endl;
    print_result(out, reverse_iterators_test(test));
    out << "--- size test : ---" << std::endl;
    print_result(out, size_test(test));
    out << "--- swap test : ---" << std::endl;
    print_result(out, swap_test(test));
    out << "--- upper bound test : ---" << std::endl;
    print_result(out, upper_bound_test(test));
    out << "--- allocator test : ---" << std::endl;
    allocator_test(test);
    out << "allocator test ok" << std::endl;
    out << "--- done --- " << std::endl;

}

void    utility_test(std::ofstream& out){
    out << "--- utility test : ---" << std::endl;
    if (enable_if_test_())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    if (equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    if (is_integral_test_())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    if (iterator_traits_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    if (lexicographical_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
}

void    vector_test(std::ofstream& out){
    Vector<int> test;
    out << "--- vector test : ---" << std::endl;
    out << "assign test :" << std::endl;
    print_result(out, assign_test(test));
    out << "assign_std_test :" << std::endl;
    print_result(out, assign_std_test(test));
    out << "at_test :" << std::endl;
    print_result(out, at_test(test));
    out << "back_test :" << std::endl;
    print_result(out, back_test(test));
    out << "begin_test :" << std::endl;
    print_result(out, begin_test(test));
    out << "capacity_test :" << std::endl;
    print_result(out, capacity_test(test));
    out << "clear_test :" << std::endl;
    print_result(out, clear_test(test));
    out << "constructor_test :" << std::endl;
    print_result(out, constructor_test(test));
    out << "constructor_std_test :" << std::endl;
    print_result(out, constructor_std_test(test));
    out << "data_test :" << std::endl;
    print_result(out, data_test(test));
    out << "empty_test :" << std::endl;
    print_result(out, empty_test(test));
    out << "end_test :" << std::endl;
    print_result(out, end_test(test));
    out << "erase_test_2 :" << std::endl;
    print_result(out, erase_test_2(test));
    out << "erase_test_1 :" << std::endl;
    print_result(out, erase_test_1(test));
    out << "front_test :" << std::endl;
    print_result(out, front_test(test));
    out << "insert_test_2 :" << std::endl;
    print_result(out, insert_test_2(test));
    out << "insert_test_3 :" << std::endl;
    print_result(out, insert_test_3(test));
    out << "insert_std_test :" << std::endl;
    print_result(out, insert_std_test(test));
    out << "insert_test_1 :" << std::endl;
    print_result(out, insert_test_1(test));
    out << "iterator_test :" << std::endl;
    print_result(out, iterator_test(test));
    out << "maxsize_test :" << std::endl;
    print_result(out, maxsize_test(test));
    out << "operator_not_equal_test :" << std::endl;
    if (operator_not_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    out << "operator_less_test :" << std::endl;
    if (operator_less_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    out << "operator_less_equal_test :" << std::endl;
    if (operator_less_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    out << "operator_equal_test :" << std::endl;
    if (operator_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    out << "operator_more_test :" << std::endl;
    if (operator_more_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    out << "operator_more_equal_test :" << std::endl;
    if (operator_more_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    out << "operator1_test :" << std::endl;
    print_result(out, operator1_test(test));
    out << "pop_back_test :" << std::endl;
    print_result(out, pop_back_test(test));
    out << "push_back_test :" << std::endl;
    print_result(out, push_back_test(test));
    out << "rbegin_test :" << std::endl;
    print_result(out, rbegin_test(test));
    out << "rend_test :" << std::endl;
    print_result(out, rend_test(test));
    out << "reserve_test :" << std::endl;
    print_result(out, reserve_test(test));
    out << "resize_test :" << std::endl;
    print_result(out, resize_test(test));
    out << "size_test :" << std::endl;
    print_result(out, size_test(test));
    out << "swap_test :" << std::endl;
    print_result(out, swap_test(test));
    out << "allocator_test :" << std::endl;
    allocator_test(test);
    out << "allocator test ok" << std::endl;
    out << "--- done ---" << std::endl;
}
