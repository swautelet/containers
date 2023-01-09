#include "tester.hpp"

void    utility_test(std::ofstream& out){
    out << "--- utility test : ---" << std::endl;
    if (enable_if_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    if (equal_test())
        out << "OK" << std::endl;
    else
        out << "KO" << std::endl;
    if (is_integral_test())
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