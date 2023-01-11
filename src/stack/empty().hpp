#pragma once
// #include "tester.hpp"
#include "s__service.hpp"

template <class T>
std::vector<int> empty_test(std::stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	v.push_back(stk.empty());
	while (stk.size() > 0)
		stk.pop();
	g_start = timer();
	v.push_back(stk.empty());
	g_end = timer();
	return v;
}

template <class T>
std::vector<int> empty_test(_stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	v.push_back(stk.empty());
	while (stk.size() > 0)
		stk.pop();
	g_start = timer();
	v.push_back(stk.empty());
	g_end = timer();
	return v;
}
