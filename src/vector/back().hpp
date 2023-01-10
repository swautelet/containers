#include "tester.hpp"
#include "v__service.hpp"

template <typename T>
std::vector<int> back_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(44444, 1);
    g_start1 = timer();
    v.push_back(vector.back());
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> back_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(44444, 1);
    g_start2 = timer();
    v.push_back(vector.back());
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}
