#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

bool operator_equal_test() {
    g_start = timer(); g_end = timer(); g_start = timer(); g_end = timer();
    std::vector<int> result, result_2;
    std::vector<int> v_int1, v_int2, v_int3;	_vector<int> V_int1, V_int2, V_int3;
    std::vector<std::string> v_str1, v_str2;			_vector<std::string> V_str1, V_str2;
    v_int1.push_back(1);						V_int1.push_back(1);
    v_int3.push_back(1);						V_int3.push_back(1);
    v_str1.push_back("aa");						V_str1.push_back("aa");
    v_str2.push_back("ab");						V_str2.push_back("ab");
    result.push_back(v_int1 == v_int2);			result_2.push_back(V_int1 == V_int2);
    v_int2.push_back(2);						V_int2.push_back(2);
    result.push_back(v_int1 == v_int2);			result_2.push_back(V_int1 == V_int2);
    result.push_back(v_int1 == v_int3);			result_2.push_back(V_int1 == V_int3);
    result.push_back(v_str1 == v_str2);			result_2.push_back(V_str1 == V_str2);
    return result == result_2;
}
