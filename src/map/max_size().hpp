#include "tester.hpp"
#include "m__service.hpp"

template <class T, class V>
std::vector<int> max_size_test(std::map<T, V> mp) {
    std::vector<int> v;
    g_start1 = timer();
    v.push_back((mp.size() * 0) + 1);
    g_end1 = timer();
    return v;
}

template <class T, class V>
std::vector<int> max_size_test(_map<T, V> mp) {
    std::vector<int> v;
    std::map<int, int> std_mp;
    g_start2 = timer();
    if ((std_mp.max_size() / 2) < mp.max_size())
        v.push_back(1);
    g_end2 = timer();
    return v;
}
