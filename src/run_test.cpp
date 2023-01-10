#include "tester.hpp"

#ifndef STD
    using namespace ft;
#else
    using namespace std;
#endif

void    run_test(std::string name){
    std::ofstream outfile(name);

    outfile.open(name);
    vector_test(outfile);
    map_test(outfile);
    stack_test(outfile);
    utility_test(outfile);
    outfile.close();
}

void    print_result(std::ostream& out, std::vector<int> answer){
    for (size_t i = 0; i < answer.size(); i++){
        out << i << " : " << answer[i] << std::endl;
    }
}

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}