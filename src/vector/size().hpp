#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> size_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1200 * _ratio, 1);
    g_start = timer();
    v.push_back(vector.size());
    g_end = timer();
    return v;
}

template <typename T>
std::vector<int> size_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1200 * _ratio, 1);
    g_start = timer();
    v.push_back(vector.size());
    g_end = timer();
    return v;
}