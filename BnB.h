#ifndef BNB_H
#define BNB_H

const int MAX_CITIES = 20;

class BnB {
public:
    int matrix[MAX_CITIES][MAX_CITIES];
    BnB(int inputCitiesAmount, std::vector<std::vector<int>> inputMatrix);
    void TSP();
    // Stores the final result - value of the shortest path
    int final_res = INT_MAX;
    // visited[] controls visited nodes
    bool visited[MAX_CITIES];
    // finalNodes[] - final solution
    int finalNodes[MAX_CITIES + 1];
    int cities;

    void getResults();

private:
    void copyTab(int curr_path[]);
    int firstMin(int matrix[MAX_CITIES][MAX_CITIES], int i);
    int secondMin(int matrix[MAX_CITIES][MAX_CITIES], int i);
    void TSPRec(int matrix[MAX_CITIES][MAX_CITIES], int curr_bound, int curr_weight, int level, int curr_path[]);
};

#endif // BNB_H
