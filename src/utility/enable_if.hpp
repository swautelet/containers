#include "tester.hpp"
// #include UTILITIES

template <class T> typename _enable_if< std::is_unsigned<T>::value >::type
		foo(T) {
	g_start1 = -20;
}

template <class T> typename _enable_if< std::is_signed<T>::value >::type
		foo(T) {
	g_start2 = -20;
}

bool enable_if_test_() {
	std::vector<int> v;
	bool res = 1;
	unsigned int xx = 5;
	int x = 5;
	foo(xx);
	foo(x);
	if (g_start1 != -20 && g_start2 != -20)
		res = 0;
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	return res;
}
