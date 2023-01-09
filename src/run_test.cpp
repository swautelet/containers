#include "tester.hpp"

void    run_test(str name){
    std::ofstream outfile;

    outfile.open(name);
    vector_test(outfile);
    map_test(outfile);
    stack_test(outfile);
    utility_test(outfile);
    outfile.close();
}

void    print_result(std::ofstream& out, std::vector<int>& answer){
    for (size_t i = 0; i < answer.size(); i++){
        out << i << " : " << answer[i] << std::endl;
    }
}