#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> count_test(std::map<T, V> mp) {
    std::vector<int> v;
    g_start = g_end = timer();
    v.push_back(mp.count(0));
    mp.insert(std::make_pair(0, 0));
    v.push_back(mp.count(0));
    return v;
}

template <class T, class V>
std::vector<int> count_test(_map<T, V> mp) {
    std::vector<int> v;
    g_start = g_end = timer();
    v.push_back(mp.count(0));
    mp.insert(_make_pair(0, 0));
    v.push_back(mp.count(0));
    return v;
}
