#include "tester.hpp"

void    run_test(std::string name, std::string name_time){
    std::ofstream outfile(name);
    std::ofstream out_time(name_time);
    out_time << "ft time : " << std::endl;
    if (outfile.is_open() && out_time.is_open()){
        vector_test(outfile, out_time);
        map_test(outfile, out_time);
        stack_test(outfile, out_time);
        utility_test(outfile, out_time);
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


void    stack_test(std::ofstream& out, std::ofstream& out_time){
    ft::Stack<int> test;
    out << "--- constructor test : ---" << std::endl;
    print_result(out, constructor_test(test));
    display_time("stack constructor test", out_time);
    out << "--- empty test : ---" << std::endl;
    print_result(out, empty_test(test));
    display_time("stack empty test", out_time);
    out << "--- stack_not_equal_test : ---" << std::endl;
    if (stack_not_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("stack not equal test", out_time);
    out << "--- stack_less_than_test : ---" << std::endl;
    if (stack_less_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("stack less than test", out_time);
    out << "--- stack_less_or_equal_test : ---" << std::endl;
    if (stack_less_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("stack less or equal test", out_time);
    out << "--- stack_equal_test : ---" << std::endl;
    if (stack_less_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("stack equal test", out_time);
    out << "--- stack_more_than_test : ---" << std::endl;
    if (stack_more_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("stack more than test", out_time);
    out << "--- stack_more_or_equal_test : ---" << std::endl;
    if (stack_more_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("stack more or equal test", out_time);
    out << "--- pop_test : ---" << std::endl;
    print_result(out, pop_test(test));
    display_time("stack pop test", out_time);
    out << "--- push_test : ---" << std::endl;
    print_result(out, push_test(test));
    display_time("stack push test", out_time);
    out << "--- size_test : ---" << std::endl;
    print_result(out, size_test(test));
    display_time("stack size test", out_time);
    out << "--- top_test : ---" << std::endl;
    print_result(out, top_test(test));
    display_time("stack top test", out_time);
    std::cout << "--- stack done ---" << std::endl;
}

void    map_test(std::ofstream& out, std::ofstream& out_time){
    ft::Map<int, int> test;
    ft::Map<int, int>::iterator b = test.begin();
    ft::Map<int, int>::const_iterator c = test.begin();
    if (b == c)
        std::cout << " i can compare map iterator and map const_iterator and they're the same " << std::endl;
    out << "--- assign overload test : ---" << std::endl;
    print_result(out, assign_overload_test(test));
    display_time("map assign overload test", out_time);
    out << "--- at test : ---" << std::endl;
    print_result(out, at_test(test));
    display_time("map at test", out_time);
    out << "--- clear test : ---" << std::endl;
    print_result(out, clear_test(test));
    display_time("map clear test", out_time);
    out << "--- comparator test : ---" << std::endl;
    print_result(out, comparator_test(test));
    display_time("map comparator test", out_time);
    out << "--- copy constructor test : ---" << std::endl;
    print_result(out, copy_constructor_test(test));
    display_time("map copy constructor test", out_time);
    out << "--- count test : ---" << std::endl;
    print_result(out, count_test(test));
    display_time("map count test", out_time);
    out << "--- empty test : ---" << std::endl;
    print_result(out, empty_test(test));
    display_time("map empty test", out_time);
    out << "--- equal range test : ---" << std::endl;
    print_result(out, equal_range_test(test));
    display_time("map equal range test", out_time);
    out << "--- erase 3 test : ---" << std::endl;
    print_result(out, erase_test_3(test));
    display_time("map erase 3 test", out_time);
    out << "--- erase 1 test : ---" << std::endl;
    print_result(out, erase_test_1(test));
    display_time("map erase 1 test", out_time);
    out << "--- erase 2 test : ---" << std::endl;
    print_result(out, erase_test_2(test));
    display_time("map erase 2 test", out_time);
    out << "--- find test : ---" << std::endl;
    print_result(out, find_test(test));
    display_time("map find test", out_time);
    out << "--- insert 3 test : ---" << std::endl;
    print_result(out, insert_test_3(test));
    display_time("map insert 3 test", out_time);
    out << "--- insert 2 test : ---" << std::endl;
    print_result(out, insert_test_2(test));
    display_time("map insert 2 test", out_time);
    out << "--- insert test : ---" << std::endl;
    print_result(out, insert_test(test));
    display_time("map insert 1 test", out_time);
    out << "--- iterators test : ---" << std::endl;
    print_result(out, iterators_test(test));
    display_time("map iterators test", out_time);
    out << "--- key comp test : ---" << std::endl;
    print_result(out, key_comp_test(test));
    display_time("map key comp test", out_time);
    out << "--- lower bound test : ---" << std::endl;
    print_result(out, lower_bound_test(test));
    display_time("map lower bound test", out_time);
    out << "--- max size test : ---" << std::endl;
    print_result(out, max_size_test(test));
    display_time("map max_size test", out_time);
    out << "--- map not equal test : ---" << std::endl;
    if (map_not_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("map not equal test", out_time);
    out << "--- map less than test : ---" << std::endl;
    if (map_less_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("map less than test", out_time);
    out << "--- map less or equal test : ---" << std::endl;
    if (map_less_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("map less or equal test", out_time);
    out << "--- map equal test : ---" << std::endl;
    if (map_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("map equal test", out_time);
    out << "--- map more than test : ---" << std::endl;
    if (map_more_than_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("map more than test", out_time);
    out << "--- map more or equal test : ---" << std::endl;
    if (map_more_or_equal_test())
        out << " OK" << std::endl;
    else 
        out << " KO" << std::endl;
    display_time("map more or equal test", out_time);
    out << "--- operator sq test : ---" << std::endl;
    print_result(out, operator_sq_test(test));
    display_time("map sq test", out_time);
    out << "--- reverse iterators test : ---" << std::endl;
    print_result(out, reverse_iterators_test(test));
    display_time("map reserve iterators test", out_time);
    out << "--- size test : ---" << std::endl;
    print_result(out, size_test(test));
    display_time("map size test", out_time);
    out << "--- swap test : ---" << std::endl;
    print_result(out, swap_test(test));
    display_time("map swap test", out_time);
    out << "--- upper bound test : ---" << std::endl;
    print_result(out, upper_bound_test(test));
    display_time("map upper bound test", out_time);
    out << "--- allocator test : ---" << std::endl;
    display_time("map allocator test", out_time);
    out << "allocator test ok" << std::endl;
    std::cout << "--- map done --- " << std::endl;

}

void    utility_test(std::ofstream& out, std::ofstream& out_time){
    out << "--- utility test : ---" << std::endl;
    if (enable_if_test_())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("utility enable if test", out_time);
    if (equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("utility equal test", out_time);
    if (is_integral_test_())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("utility is integral test", out_time);
    if (iterator_traits_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("utility iterator traits test", out_time);
    if (lexicographical_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("utility lexicographical test", out_time);
    std::cout << "--- utility done ---" << std::endl;
}

void    vector_test(std::ofstream& out, std::ofstream& out_time){
    ft::Vector<int> test;
    ft::Vector<int>::iterator b = test.begin();
    ft::Vector<int>::const_iterator c = test.begin();
    if (b == c)
        std::cout << " i can compare Vector iterator and Vector const_iterator and they're the same " << std::endl;
    out << "--- vector test : ---" << std::endl;
    out << "assign test :" << std::endl;
    print_result(out, assign_test(test));
    display_time("vector assign test", out_time);
    out << "assign_std_test :" << std::endl;
    print_result(out, assign_std_test(test));
    display_time("vector assign std test", out_time);
    out << "at_test :" << std::endl;
    print_result(out, at_test(test));
    display_time("vector at test", out_time);
    out << "back_test :" << std::endl;
    print_result(out, back_test(test));
    display_time("vector back test", out_time);
    out << "begin_test :" << std::endl;
    print_result(out, begin_test(test));
    display_time("vector begin test", out_time);
    out << "capacity_test :" << std::endl;
    print_result(out, capacity_test(test));
    display_time("vector capacity test", out_time);
    out << "clear_test :" << std::endl;
    print_result(out, clear_test(test));
    display_time("vector clear test", out_time);
    out << "constructor_test :" << std::endl;
    print_result(out, constructor_test(test));
    display_time("vector constructor test", out_time);
    out << "constructor_std_test :" << std::endl;
    print_result(out, constructor_std_test(test));
    display_time("vector constructor std test", out_time);
    out << "data_test :" << std::endl;
    print_result(out, data_test(test));
    display_time("vector data test", out_time);
    out << "empty_test :" << std::endl;
    print_result(out, empty_test(test));
    display_time("vector empty test", out_time);
    out << "end_test :" << std::endl;
    print_result(out, end_test(test));
    display_time("vector end test", out_time);
    out << "erase_test_2 :" << std::endl;
    print_result(out, erase_test_2(test));
    display_time("vector erase 2 test", out_time);
    out << "erase_test_1 :" << std::endl;
    print_result(out, erase_test_1(test));
    display_time("vector erase 1 test", out_time);
    out << "front_test :" << std::endl;
    print_result(out, front_test(test));
    display_time("vector front test", out_time);
    out << "insert_test_2 :" << std::endl;
    print_result(out, insert_test_2(test));
    display_time("vector insert 2 test", out_time);
    out << "insert_test_3 :" << std::endl;
    print_result(out, insert_test_3(test));
    display_time("vector insert 3 test", out_time);
    out << "insert_std_test :" << std::endl;
    print_result(out, insert_std_test(test));
    display_time("vector insert std test", out_time);
    out << "insert_test_1 :" << std::endl;
    print_result(out, insert_test_1(test));
    display_time("vector insert 1 test", out_time);
    out << "iterator_test :" << std::endl;
    print_result(out, iterator_test(test));
    display_time("vector iterator test", out_time);
    out << "max_size_test :" << std::endl;
    print_result(out, maxsize_test(test));
    display_time("vector max size test", out_time);
    out << "operator_not_equal_test :" << std::endl;
    if (operator_not_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("vector not equal test", out_time);
    out << "operator_less_test :" << std::endl;
    if (operator_less_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("vector less than test", out_time);
    out << "operator_less_equal_test :" << std::endl;
    if (operator_less_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("vector less or equal test", out_time);
    out << "operator_equal_test :" << std::endl;
    if (operator_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("vector equal test", out_time);
    out << "operator_more_test :" << std::endl;
    if (operator_more_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("vector more test", out_time);
    out << "operator_more_equal_test :" << std::endl;
    if (operator_more_equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    display_time("vector more or equal test", out_time);
    out << "operator1_test :" << std::endl;
    print_result(out, operator1_test(test));
    display_time("vector operator 1 test", out_time);
    out << "pop_back_test :" << std::endl;
    print_result(out, pop_back_test(test));
    display_time("vector pop back test", out_time);
    out << "push_back_test :" << std::endl;
    print_result(out, push_back_test(test));
    display_time("vector push_back test", out_time);
    out << "rbegin_test :" << std::endl;
    print_result(out, rbegin_test(test));
    display_time("vector rbegin test", out_time);
    out << "rend_test :" << std::endl;
    print_result(out, rend_test(test));
    display_time("vector rend test", out_time);
    out << "reserve_test :" << std::endl;
    print_result(out, reserve_test(test));
    display_time("vector reserve test", out_time);
    out << "resize_test :" << std::endl;
    print_result(out, resize_test(test));
    display_time("vector resize test", out_time);
    out << "size_test :" << std::endl;
    print_result(out, size_test(test));
    display_time("vector size test", out_time);
    out << "swap_test :" << std::endl;
    print_result(out, swap_test(test));
    display_time("vector swap test", out_time);
    out << "allocator_test :" << std::endl;
    display_time("vector allocator test", out_time);
    out << "allocator test ok" << std::endl;
    std::cout << "--- vector done ---" << std::endl;
}

void    display_time(std::string message, std::ofstream& out_time){
    out_time << message << " done in " << g_end - g_start << " ms " << std::endl;
}