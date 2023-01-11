#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> find_test(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = -75 * _ratio, j = 0; i < 75 * _ratio; ++i, ++j) {
        mp.insert(std::make_pair(i, j));
    }
    g_start = timer();
    typename std::map<T, V>::iterator it = mp.find(34 * _ratio);
    g_end = timer();
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-34 * _ratio);
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-75 * _ratio);
    if (it == mp.end())
        v.push_back(1);
    return v;
}

template <class T, class V>
std::vector<int> find_test(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = -75 * _ratio, j = 0; i < 75 * _ratio; ++i, ++j) {
        mp.insert(_make_pair(i, j));
    }
    g_start = timer();
    typename _map<T, V>::iterator it = mp.find(34 * _ratio);
    g_end = timer();
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-34 * _ratio);
    v.push_back(it->first);
    v.push_back(it->second);
    it = mp.find(-75 * _ratio);
    if (it == mp.end())
        v.push_back(1);
    return v;
}
