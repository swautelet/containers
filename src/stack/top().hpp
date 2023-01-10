#include "tester.hpp"
#include "s__service.hpp"

template <class T>
std::vector<int> top_test(std::stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start1 = timer();
	v.push_back(stk.top());
	g_end1 = timer();
	stk.pop();
	v.push_back(stk.top());
	stk.push(7);
	v.push_back(stk.top());
	return v;
}

template <class T>
std::vector<int> top_test(_stack<T> stk) {
	std::vector<int> v;
	for (int i = 0; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start2 = timer();
	v.push_back(stk.top());
	g_end2 = timer();
	stk.pop();
	v.push_back(stk.top());
	stk.push(7);
	v.push_back(stk.top());
	return v;
}
