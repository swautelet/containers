#include "tester.hpp"
#include "__service.ipp"

template <class T>
std::vector<int> size_test(std::stack<T> stk) {
	std::vector<int> v;
	g_start1 = timer();
	for (int i = 0; i < 800 * _ratio; ++i)
		stk.push(i);
	g_end1 = timer();
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> size_test(_stack<T> stk) {
	std::vector<int> v;
	g_start2 = timer();
	for (int i = 0; i < 800 * _ratio; ++i)
		stk.push(i);
	g_end2 = timer();
	v.push_back(stk.size());
	return v;
}
