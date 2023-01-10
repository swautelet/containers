#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <class T, class A>
void allocator_test(_vector<T, A> vector) {

    for (int i = 0; i < 10; ++i) {
        vector.push_back(i);
    }
}
