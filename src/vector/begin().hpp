#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> begin_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start = timer();
    v.push_back(*vector.begin());
    v.push_back(*++vector.begin());
    g_end = timer();
    return v;
}

template <typename T>
std::vector<int> begin_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start = timer();
    v.push_back(*vector.begin());
    v.push_back(*++vector.begin());
    g_end = timer();
    return v;
}
