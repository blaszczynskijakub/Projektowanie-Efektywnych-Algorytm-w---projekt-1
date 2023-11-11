#include "Dynamic_programming.h"


Dynamic_programming::Dynamic_programming(std::vector<std::vector<int>> graph_matrix)
{
    this->matrix = graph_matrix;
    this->instance_size = matrix.size();

}

std::vector<int> Dynamic_programming::dp() {

    std::vector<int> route;

    visited_all = (1 << instance_size) - 1;

    for (int i = 0; i < (1 << instance_size); i++) {
        for (int j = 0; j < instance_size; j++) {
            route.push_back(-1);
        }
        dp_memory.push_back(route);
        parents_memory.push_back(route);
        route.clear();
    }


    int cost = dp_recursion(1, 0);
    std::cout << cost;
    route = get_path();

    return route;

}

int Dynamic_programming::dp_recursion(int mask, int current_vertex) {

    if (mask == visited_all) {
        return matrix[current_vertex][0];
    }

    if (dp_memory[mask][current_vertex] != -1) {
        return dp_memory[mask][current_vertex];
    }

    int cost = IMAX;

    for (int city = 0; city < instance_size; city++) {

        if ((mask & (1 << city)) == 0) {

            int current_cost = matrix[current_vertex][city] + dp_recursion(mask | (1 << city), city);
            cost = std::min(cost, current_cost);

            if (current_cost == cost) {
                dp_memory[mask][current_vertex] = cost;
                parents_memory[mask][current_vertex] = city;
            }
        }
    }

    return cost;
}

std::vector<int> Dynamic_programming::get_path()
{
    std::vector<int> best_route;
    int current_vertex = 0;
    int mask = 1;

    best_route.push_back(current_vertex + 1);


    while (mask != visited_all) {
        current_vertex = parents_memory[mask][current_vertex];
        best_route.push_back(current_vertex+1);
        mask = mask | (1 << current_vertex);
    }

    return best_route;
}