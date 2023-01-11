#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> assign_test(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
    g_start = timer();
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    g_end = timer();
    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> assign_test(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
    g_start = timer();
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    g_end = timer();
    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
