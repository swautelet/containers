#pragma once
// #include "tester.hpp"
#include "s__service.hpp"

template <class T>
std::vector<int> constructor_test(std::stack<T> stk) {
	std::vector<int> v;
	std::deque<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start = timer();
	std::stack<int> stack(deque);
	std::stack<int> stack2(stk);
	std::stack<int> stack3;
	stack3 = stack2;
	g_end = timer();
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

template <class T>
std::vector<int> constructor_test(_stack<T> stk) {
	std::vector<int> v;
	_vector<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	g_start = timer();
	_stack<int> stack(deque);
	_stack<int> stack2(stk);
	_stack<int> stack3;
	stack3 = stack2;
	g_end = timer();
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}
