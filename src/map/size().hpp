#include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
        std::vector<int> size_test(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 100 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    g_start1 = timer();
    v.push_back(mp.size());
    g_end1 = timer();
    for (int i = 0; i < 43 * _ratio; ++i)
        mp.erase(i);
    v.push_back(mp.size());
    return v;
}

template <class T, class V>
        std::vector<int> size_test(_map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 100 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
    g_start2 = timer();
    v.push_back(mp.size());
    g_end2 = timer();
    for (int i = 0; i < 43 * _ratio; ++i)
        mp.erase(i);
    v.push_back(mp.size());
    return v;
}
