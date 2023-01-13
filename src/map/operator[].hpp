#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
        std::vector<int> operator_sq_test(std::map<T, V> mp) {
    std::vector<int> v;
    mp.insert(std::make_pair(3, 3));
    typename std::map<T, V>::iterator it = mp.begin();
    g_start = timer();
    v.push_back(it->first);
    v.push_back(it->second);
    mp[3] = 10;
    v.push_back(it->first);
    v.push_back(it->second);
    mp[2] = 9;
    it = mp.begin();
    v.push_back(it->first);
    v.push_back(it->second);
    it++;
    v.push_back(it->first);
    v.push_back(it->second);
    v.push_back(mp.size());
    g_end = timer();
    return v;
}

template <class T, class V>
        std::vector<int> operator_sq_test(_map<T, V> mp) {
    std::vector<int> v;
    mp.insert(_make_pair(3, 3));
    typename _map<T, V>::iterator it = mp.begin();
    g_start = timer();
    v.push_back(it->first);
    v.push_back(it->second);
    mp[3] = 10;
    v.push_back(it->first);
    v.push_back(it->second);
    mp[2] = 9;
    it = mp.begin();
    v.push_back(it->first);
    v.push_back(it->second);
    it++;
    v.push_back(it->first);
    v.push_back(it->second);
    v.push_back(mp.size());
    g_end = timer();
    return v;
}