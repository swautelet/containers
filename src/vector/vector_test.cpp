#include "tester.hpp"

void    vector_test(){
    vector test;
    out << "--- vector test : ---" << std::endl;
    out << "assign test :" << std::endl;
    print_result(out, assign_test());
    out << "assign_std_test test :" << std::endl;
    print_result(out, assign_std_test());
    out << "at_test test :" << std::endl;
    print_result(out, at_test());
    out << "back_test test :" << std::endl;
    print_result(out, back_test());
    out << "begin_test test :" << std::endl;
    print_result(out, begin_test());
    out << "capacity_test test :" << std::endl;
    print_result(out, capacity_test());
    out << "clear_test test :" << std::endl;
    print_result(out, clear_test());
    out << "constructor_test test :" << std::endl;
    print_result(out, constructor_test());
    out << "constructor_std_test test :" << std::endl;
    print_result(out, constructor_std_test());
    out << "data_test test :" << std::endl;
    print_result(out, data_test());
    out << "empty_test test :" << std::endl;
    print_result(out, empty_test());
    out << "end_test test :" << std::endl;
    print_result(out, end_test());
    out << "erase_test_2 test :" << std::endl;
    print_result(out, erase_test_2());
    out << "erase_test_1 test :" << std::endl;
    print_result(out, erase_test_1());
    out << "front_test test :" << std::endl;
    print_result(out, front_test());
    out << "insert_test_2 test :" << std::endl;
    print_result(out, insert_test_2());
    out << "insert_test_3 test :" << std::endl;
    print_result(out, insert_test_3());
    out << "insert_std_test test :" << std::endl;
    print_result(out, insert_std_test());
    out << "insert_test_1 test :" << std::endl;
    print_result(out, insert_test_1());
    out << "iterator_test test :" << std::endl;
    print_result(out, iterator_test());
    out << "maxsize_test test :" << std::endl;
    print_result(out, maxsize_test());
    out << "operator_not_equal_test test :" << std::endl;
    print_result(out, operator_not_equal_test());
    out << "operator_less_test test :" << std::endl;
    print_result(out, operator_less_test());
    out << "operator_less_equal_test test :" << std::endl;
    print_result(out, operator_less_equal_test());
    out << "operator_equal_test test :" << std::endl;
    print_result(out, operator_equal_test());
    out << "operator_more_test test :" << std::endl;
    print_result(out, operator_more_test());
    out << "operator_more_equal_test test :" << std::endl;
    print_result(out, operator_more_equal_test());
    out << "operator1_test test :" << std::endl;
    print_result(out, operator1_test());
    out << "pop_back_test test :" << std::endl;
    print_result(out, pop_back_test());
    out << "push_back_test test :" << std::endl;
    print_result(out, push_back_test());
    out << "rbegin_test test :" << std::endl;
    print_result(out, rbegin_test());
    out << "rend_test test :" << std::endl;
    print_result(out, rend_test());
    out << "reserve_test test :" << std::endl;
    print_result(out, reserve_test());
    out << "resize_test test :" << std::endl;
    print_result(out, resize_test());
    out << "size_test test :" << std::endl;
    print_result(out, size_test());
    out << "swap_test test :" << std::endl;
    print_result(out, swap_test());
    out << "allocator_test test :" << std::endl;
    print_result(out, allocator_test());
    out << "--- done ---" << std::endl;
}
