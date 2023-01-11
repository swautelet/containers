#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> operator1_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(44444, 1);
    g_start = timer();
    v.push_back(vector[5555]);
    g_end = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> operator1_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(44444, 1);
    g_start = timer();
    v.push_back(vector[5555]);
    g_end = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
