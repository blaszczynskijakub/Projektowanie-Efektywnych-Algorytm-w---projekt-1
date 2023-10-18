//
// Created by 1312 on 10/18/2023.
//

#ifndef PEA_PROJEKT_1_GRAPH_H
#define PEA_PROJEKT_1_GRAPH_H

#include <vector>

class Graph {

public:
    Graph(std::vector<std::vector<int>> graph);
    ~Graph();

    bool readGraph(std::string file);
    void setGraph(std::vector<std::vector<int>> new_graph);
    void printGraph();
    std::vector<std::vector<int>> getGraph();

private:
    std::vector<std::vector<int>> graph_matrix;
    int num_of_vertices;
};

#endif //PEA_PROJEKT_1_GRAPH_H
