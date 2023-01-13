#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> key_comp_test(std::map<T, V> mp) {

    std::vector<int> v;
    g_start = g_end = timer();
    std::map<int, int, std::greater<int> > mp2;
    std::map<int, int, std::equal_to<int> > mp3;
    v.push_back(mp.key_comp()(1, 2));
    v.push_back(mp2.key_comp()(1, 2));
    v.push_back(mp3.key_comp()(1, 2));
    return v;
}

template <class T, class V>
std::vector<int> key_comp_test(_map<T, V> mp) {

    std::vector<int> v;
    g_start = g_end = timer();
    _map<int, int, std::greater<int> > mp2;
    _map<int, int, std::equal_to<int> > mp3;
    v.push_back(mp.key_comp()(1, 2));
    v.push_back(mp2.key_comp()(1, 2));
    v.push_back(mp3.key_comp()(1, 2));
    return v;
}