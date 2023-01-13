#pragma once
// #include "tester.hpp"
// #include UTILITIES
#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

bool is_integral_test_() {
	std::vector<int> v;
	bool res = 1;
	g_start = timer(); g_end = timer(); g_start = timer(); g_end = timer();
	(_is_integral<float>() == std::is_integral<float>()) ? 0 : res = 0;
	(_is_integral<int>() == std::is_integral<int>()) ? 0 : res = 0;
	(_is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 0;
	(_is_integral<char>() == std::is_integral<char>()) ? 0 : res = 0;
	(_is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 0;
	(_is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 0;
	(_is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 0;
	(_is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 0;
	(_is_integral<short>() == std::is_integral<short>()) ? 0 : res = 0;
	(_is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 0;
	(_is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 0;
	(_is_integral<long>() == std::is_integral<long>()) ? 0 : res = 0;
	(_is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 0;
	(_is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 0;
	(_is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 0;
	return res;
}

#endif