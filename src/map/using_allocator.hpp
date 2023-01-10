#pragma once
// #include "tester.hpp"
#include "m__service.hpp"

template <class T, class V, class C, class A>
void allocator_test(_map<T, V, C, A> mp) {

    for (int i = 0, j = 10; i < 10; ++i, ++j) {
        mp.insert(_make_pair(i, j));
    }
}
