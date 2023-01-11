#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> erase_test_1(std::vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 9900 * _ratio; ++i)
        vector.push_back(i);
    g_start = timer();
    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio)));
    g_end = timer();
    v.push_back(*(vector.begin() + 82 * _ratio));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> erase_test_1(_vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 9900 * _ratio; ++i)
        vector.push_back(i);
    g_start = timer();
    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio)));
    g_end = timer();
    v.push_back(*(vector.begin() + 82 * _ratio));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
