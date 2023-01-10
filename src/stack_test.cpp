#include "tester.hpp"

#ifndef STD
    using namespace ft;
#else
    using namespace std;
#endif

void    stack_test(std::ostream& out){
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