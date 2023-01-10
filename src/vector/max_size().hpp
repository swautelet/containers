#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> maxsize_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1, 1);
    g_start1 = timer();
    v.push_back(vector.max_size());
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> maxsize_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1, 1);
    g_start2 = timer();
    v.push_back(vector.max_size());
    g_end2 = timer();
    return v;
}
