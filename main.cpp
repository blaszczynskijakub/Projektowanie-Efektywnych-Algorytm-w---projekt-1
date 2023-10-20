#include <iostream>
#include "Graph.h"
#include "Brute_force.h"
#include "DataGenerator.h"
#include "Time_measure.h"

int MIN = 1;
int MAX=999;
int CITIES=10;
int main() {

    //generating file
    //DataGenerator dataGenerator;
    //dataGenerator.generateData(MIN,MAX,CITIES);

    Time_measure measure(10);
    measure.test_brute_force(10);

    std::vector<std::vector<int>> x;

    Graph graph(x);
    graph.readGraph("../6x6.txt");
    //graph.printGraph();
    Brute_force force(graph.getGraph());
    force.perform_brute_force();
    //force.show_lowest_path();

    return 0;
}