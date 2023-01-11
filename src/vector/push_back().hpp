#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> push_back_test(std::vector<T> vector) {
    std::vector<int> v;
    g_start = timer();
    for (int i = 0; i < 5500 * _ratio; ++i)
        vector.push_back(i);
    g_end = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> push_back_test(_vector<T> vector) {
    std::vector<int> v;
    g_start = timer();
    for (int i = 0; i < 5500 * _ratio; ++i) {
        vector.push_back(i);
    }
    g_end = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
