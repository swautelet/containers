#pragma once
// #include "tester.hpp"
// #include "v__service.hpp"

template <typename T>
std::vector<int> constructor_std_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(3, 3);
	std::vector<int> tmp(1000 * _ratio, 4);
	g_start = timer();
	std::vector<int> tmp2(tmp.begin(), tmp.end());
	g_end = timer();
	v.push_back(tmp2.size());
	v.push_back(tmp2.capacity());
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(tmp2[i]);
	return v;
}

template <typename T>
std::vector<int> constructor_std_test(_vector<T> vecto) {
	(void)vecto;
	std::vector<int> v;
	_vector<T> vector(3, 3);
	std::vector<int> tmp(1000 * _ratio, 4);
	g_start = timer();
	_vector<int> tmp2(tmp.begin(), tmp.end());
	g_end = timer();
	v.push_back(tmp2.size());
	v.push_back(tmp2.capacity());
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(tmp2[i]);
	return v;
}
