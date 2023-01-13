#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> constructor_test(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp0(vector);
    std::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
    tmp = tmp2;
    std::vector<int> tmp3(tmp);
    g_start = timer();
    std::vector<int> tmp4(tmp.begin(), tmp.end());
    g_end = timer();
    v.push_back(tmp4.size());
    v.push_back(tmp4.capacity());
    v.push_back(tmp[2]);
    v.push_back(tmp3[2]);
    v.push_back(tmp4[2]);
    try { std::vector<int> tmp5(-1, -1); }
    catch (std::exception &e) { v.push_back(1); }
    return v;
}

template <typename T>
std::vector<int> constructor_test(_vector<T> vector) {
    std::vector<int> v;
	_vector<int> tmp0(vector);
    _vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
    tmp = tmp2;
    _vector<int> tmp3(tmp);
    g_start = timer();
    _vector<int> tmp4(tmp.begin(), tmp.end());
    g_end = timer();
    v.push_back(tmp4.size());
    v.push_back(tmp4.capacity());
    v.push_back(tmp[2]);
    v.push_back(tmp3[2]);
    v.push_back(tmp4[2]);
    try { _vector<int> tmp5(-1, -1); }
    catch (std::exception &e) { v.push_back(1); }
    return v;
}