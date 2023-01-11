#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> data_test(std::vector<T> vector) {
    std::vector<int> v;
    std::ostringstream oss;
    g_start = timer();
    oss << &*(vector.data());
    g_end = timer();
    std::string str = oss.str();
    if (!oss.str().rfind("0x", 0))
        v.push_back(1);
    return v;
}

template <typename T>
std::vector<int> data_test(_vector<T> vector) {
    std::vector<int> v;
    std::ostringstream oss;
    g_start = timer();
    oss << &*(vector.data());
    g_end = timer();
    std::string str = oss.str();
    if (!oss.str().rfind("0x", 0))
        v.push_back(1);
    return v;
}
