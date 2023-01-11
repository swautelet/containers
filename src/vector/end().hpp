#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> end_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start = timer();
    v.push_back(*(vector.end() - 1));
    v.push_back(*(vector.end() - 2));
    g_end = timer();
    return v;
}

template <typename T>
std::vector<int> end_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start = timer();
    v.push_back(*(vector.end() - 1));
    v.push_back(*(vector.end() - 2));
    g_end = timer();
    return v;
}
