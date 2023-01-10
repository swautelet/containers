#include "tester.hpp"

#ifndef STD
    using namespace ft;
#else
    using namespace std;
#endif


void    vector_test(std::ostream& out){
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
