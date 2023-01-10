#include "tester.hpp"
#include "v__service.hpp"

template <typename T>
std::vector<int> assign_std_test(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	g_start1 = timer();
	vector.assign(tmp.begin(), tmp.end());
	g_end1 = timer();
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(vector[i]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> assign_std_test(_vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	g_start2 = timer();
	vector.assign(tmp.begin(), tmp.end());
	g_end2 = timer();
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(vector[i]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}
