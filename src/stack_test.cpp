#include "tester.hpp"

void    stack_test(std::ofstream& out){
    stack test;
    out << "--- constructor test : ---" << std::endl;
    print_result(out, constructor_test(test));
    out << "--- empty test : ---" << std::endl;
    print_result(out, empty_test(test));
    out << "--- stack_not_equal_test test : ---" << std::endl;
    print_result(out, stack_not_equal_test_test(test));
    out << "--- stack_less_than_test test : ---" << std::endl;
    print_result(out, stack_less_than_test_test(test));
    out << "--- stack_less_or_equal_test test : ---" << std::endl;
    print_result(out, stack_less_or_equal_test_test(test));
    out << "--- stack_equal_test test : ---" << std::endl;
    print_result(out, stack_equal_test_test(test));
    out << "--- stack_more_than_test test : ---" << std::endl;
    print_result(out, stack_more_than_test_test(test));
    out << "--- stack_more_or_equal_test test : ---" << std::endl;
    print_result(out, stack_more_or_equal_test_test(test));
    out << "--- pop_test test : ---" << std::endl;
    print_result(out, pop_test_test(test));
    out << "--- size_test test : ---" << std::endl;
    print_result(out, size_test_test(test));
    out << "--- size_test test : ---" << std::endl;
    print_result(out, size_test_test(test));
    out << "--- top_test test : ---" << std::endl;
    print_result(out, top_test_test(test));
    out << "--- done ---" << std::endl;
}