#include "tester.hpp"

#ifndef STD
    using namespace ft;
#else
    using namespace std;
#endif

void    map_test(std::ostream& out){
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