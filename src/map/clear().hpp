#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> clear_test(std::map<T, V> mp) {
    std::vector<int> v;
    mp.clear();
    for (int i = 0, j = 0; i < 250; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    v.push_back(mp.size());
    g_start = timer();
    mp.clear();
    g_end = timer();
    v.push_back(mp.size());
    typename std::map<T, V>::iterator it = mp.begin();
    if (it == mp.end())
        v.push_back(1);
    return v;
}

template <class T, class V>
std::vector<int> clear_test(_map<T, V> mp) {
    std::vector<int> v;
    mp.clear();
    for (int i = 0, j = 0; i < 250; ++i, ++j)
        mp.insert(_make_pair(i, j));
    v.push_back(mp.size());
    g_start = timer();
    mp.clear();
    g_end = timer();
    v.push_back(mp.size());
    typename _map<T, V>::iterator it = mp.begin();
    if (it == mp.end())
        v.push_back(1);
    return v;
}
