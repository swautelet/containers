#pragma once
// #include "tester.hpp"
#include "s__service.hpp"

template <class T>
std::vector<int> pop_test(std::stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start1 = timer();
	while (stk.size() > 0)
		stk.pop();
	g_end1 = timer();
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> pop_test(_stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start2 = timer();
	while (stk.size() > 0)
		stk.pop();
	g_end2 = timer();
	v.push_back(stk.size());
	return v;
}
