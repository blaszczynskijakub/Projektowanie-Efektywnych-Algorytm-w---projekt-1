#include "Brute_force.h"
#include <climits>
#include <algorithm>
#include <iostream>

Brute_force::Brute_force(std::vector<std::vector<int>> graph_matrix) {

    this->graph = graph_matrix;
    this->num_of_vertices = graph_matrix.size();
    this->lowest_cost = INT_MAX;

}

void Brute_force::perform_brute_force() {
    this->lowest_path = std::vector<int>(this->num_of_vertices,0);
    std::vector<int>permutations(this->num_of_vertices - 1, 0);
    int current_cost = 0;

    for (int i = 0; i < num_of_vertices - 1; ++i) {
        permutations[i] = i;
    }

    do {
        current_cost = 0;
        current_cost += graph[0][permutations[0] + 1];
        for (int i = 0; i < num_of_vertices - 2; ++i) {
            current_cost += graph[(permutations[i] + 1)][(permutations[i + 1] + 1)];
        }
        current_cost += graph[permutations.back() + 1][0];

        if (current_cost < lowest_cost) {
            this->lowest_cost = current_cost;
            this->lowest_path = permutations;


        }

    } while (std::next_permutation(permutations.begin(), permutations.end()));

    std::cout << this-> lowest_cost << "\n";
    for (int i : lowest_path) {
        std::cout << i << " ";
    }

}

void Brute_force::showPath() {

    if (lowest_cost != INT_MAX)
    {
        std::cout << "Brute force shortest path: \n";
        std::cout << "0 ->";
        for (int i = 0; i < this->num_of_vertices - 1; i++)
        {
            std::cout << (lowest_path[i] + 1) << " -> ";
        }
        std::cout << "0\n";
        std::cout << "Cost = " << lowest_cost << "\n";
    }
}


