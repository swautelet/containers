#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> pop_back_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start = timer();
    vector.pop_back();
    g_end = timer();
    v.push_back(vector[vector.size() - 1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> pop_back_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start = timer();
    vector.pop_back();
    g_end = timer();
    v.push_back(vector[vector.size() - 1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
