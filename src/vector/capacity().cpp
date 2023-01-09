#include "tester.hpp"
#include "__service.ipp"

template <typename T>
std::vector<int> capacity_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1200 * _ratio, 1);
    g_start1 = timer();
    v.push_back(vector.capacity());
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> capacity_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1200 * _ratio, 1);
    g_start2 = timer();
    v.push_back(vector.capacity());
    g_end2 = timer();
    return v;
}
