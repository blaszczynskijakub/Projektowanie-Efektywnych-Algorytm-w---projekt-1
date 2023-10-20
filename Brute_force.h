#ifndef PEA_PROJEKT_1_BRUTE_FORCE_H
#define PEA_PROJEKT_1_BRUTE_FORCE_H

#include <vector>

class Brute_force {

public:
    Brute_force(std::vector<std::vector<int>> graph_matrix);
    void perform_brute_force();
    void show_lowest_path();

private:
    int lowest_cost;
    int num_of_vertices;
    std::vector<int> lowest_path;
    std::vector<std::vector<int>> graph;

};

#endif //PEA_PROJEKT_1_BRUTE_FORCE_H
