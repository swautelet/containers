#pragma once
// #include "tester.hpp"
// #include UTILITIES

bool lexicographical_test() {
	std::vector<int> result, result2;
	std::vector<char> v1, v2;
	std::vector<char> b1, b2;
	v1.assign(5000 * _ratio, 'f');
	v1.push_back('e');
	v2.assign(5000 * _ratio, 'f');
	v2.push_back('e');
	b1.assign(5000 * _ratio, 'f');
	b1.push_back('e');
	b2.assign(5000 * _ratio, 'f');
	b2.push_back('e');
	g_start = timer();
	result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
	g_end = timer();
	g_start = timer();
	result2.push_back(_lexicographical(b1.begin(), b1.end(), b2.begin(), b2.end()));
	g_end = timer();
	return result == result2;
}
