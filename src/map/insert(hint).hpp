#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> insert_test_3(std::map<T, V> mp) {
    std::vector<int> v;
    typename std::map<T, V>::iterator it = mp.end();
    g_start = timer();
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp.insert(it, std::make_pair(i, j));
    }
    g_end = timer();
    typename std::map<T, V>::iterator it2 = mp.begin();
    for (; it2 != mp.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> insert_test_3(_map<T, V> mp) {
    std::vector<int> v;
    typename _map<T, V>::iterator it = mp.end();
    g_start = timer();
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp.insert(it, _make_pair(i, j));
    }
    g_end = timer();
    typename _map<T, V>::iterator it2 = mp.begin();
    for (; it2 != mp.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}
