#include <iostream>
#include "Graph.h"
#include "Brute_force.h"



int main() {

    std::vector<std::vector<int>> x;

    Graph graph(x);
    graph.readGraph("../6x6.txt");
    graph.printGraph();
    Brute_force force(graph.getGraph());
    force.perform_brute_force();
    force.showPath();

    return 0;
}