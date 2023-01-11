#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> erase_test_3(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));

    g_start = timer();
    mp.erase(mp.begin(), --mp.end());
    g_end = timer();
    v.push_back(mp.begin()->first);
    return v;
}

template <class T, class V>
std::vector<int> erase_test_3(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));

    g_start = timer();
    mp.erase(mp.begin(), --mp.end());
    g_end = timer();
    v.push_back(mp.begin()->first);
    return v;
}
