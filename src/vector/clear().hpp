#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> clear_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(5000 * _ratio, 1);
    g_start = timer();
    vector.clear();
    g_end = timer();
    v.push_back(vector.capacity());
    v.push_back(vector.size());
    return v;
}

template <typename T>
std::vector<int> clear_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(5000 * _ratio, 1);
    g_start = timer();
    vector.clear();
    g_end = timer();
    v.push_back(vector.capacity());
    v.push_back(vector.size());
    return v;
}