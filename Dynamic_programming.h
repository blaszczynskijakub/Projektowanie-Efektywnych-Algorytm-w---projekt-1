#ifndef PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H
#define PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <utility>

class Dynamic_programming {

public:
    Dynamic_programming(std::vector<std::vector<int>> graph_matrix);
    int perform_dp(int k, std::vector<int> unvisited, std::string current_path);
    std::unordered_map<std::string, int> get_calulated_path_cost_map();

private:
    std::vector<std::vector<int>> graph;
    std::unordered_map<std::string, int> calculated_path_cost_map;

};


#endif //PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H