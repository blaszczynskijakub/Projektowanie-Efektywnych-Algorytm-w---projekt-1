#ifndef PEA_PROJEKT_1_BnB_H
#define PEA_PROJEKT_1_BnB_H

#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class BnB {

public:
    BnB(std::vector<std::vector<int>> graph_matrix);
    int perform_upper_bound();
    int perform_lower_bound();

private:
    std::vector<std::vector<int>> graph;
    std::vector<int> vetexes;
    std::vector<int> upper_bound_path;
    std::vector<std::vector<int>> minimal_spanning_tree;
    int upper_bound_value;
    int lower_bound_value;
    void available_vertexes();
    int greedy_method(int row, std::vector<int> visited_vertexes);
};

#endif //PEA_PROJEKT_1_BnB_H