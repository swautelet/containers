#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> at_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start = timer();
    v.push_back(vector.at(354 * _ratio));
    g_end = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> at_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start = timer();
    v.push_back(vector.at(354 * _ratio));
    g_end = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}