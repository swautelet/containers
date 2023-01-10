#include "tester.hpp"
#include "v__service.hpp"

template <typename T>
std::vector<int> begin_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start1 = timer();
    v.push_back(*vector.begin());
    v.push_back(*++vector.begin());
    g_end1 = timer();
    return v;
}

template <typename T>
std::vector<int> begin_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    g_start2 = timer();
    v.push_back(*vector.begin());
    v.push_back(*++vector.begin());
    g_end2 = timer();
    return v;
}
