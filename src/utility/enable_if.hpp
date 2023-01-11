#pragma once
// #include "tester.hpp"
// #include UTILITIES
#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

template <class T> typename _enable_if< std::is_unsigned<T>::value >::type
		foo(T) {
	g_start = -20;
}

template <class T> typename _enable_if< std::is_signed<T>::value >::type
		foo(T) {
	g_start = -20;
}

bool enable_if_test_() {
	std::vector<int> v;
	bool res = 1;
	unsigned int xx = 5;
	int x = 5;
	foo(xx);
	foo(x);
	if (g_start != -20 && g_start != -20)
		res = 0;
	g_start = timer(); g_end = timer(); g_start = timer(); g_end = timer();
	return res;
}
#endif