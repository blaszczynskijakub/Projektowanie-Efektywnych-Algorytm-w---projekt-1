#ifndef PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H
#define PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

class Dynamic_programming {

public:

    Dynamic_programming(std::vector<std::vector<int>> graph_matrix);

    std::vector<int> dp();

    int dp_recursion(int mask, int current_vertex);

    std::vector<int> get_path();

private:

    int instance_size;

    std::vector<std::vector<int>> parents_memory;

    std::vector<std::vector<int>> matrix;

    int IMAX = INT_MAX;

    int visited_all;

    std::vector<std::vector<int>> dp_memory;

};


#endif //PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H