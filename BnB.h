#ifndef BNB_H
#define BNB_H

const int MAX_CITIES=20;

class BnB {

public:
    BnB(int inputCitiesAmount, int inputMatrix[MAX_CITIES][MAX_CITIES]);
    void TSP(int matrix[MAX_CITIES][MAX_CITIES]);

private:
    bool visited[MAX_CITIES];
    int final_res;
    int finalNodes[MAX_CITIES + 1];
    void copyTab(int curr_path[]);
    int firstMin(int matrix[MAX_CITIES][MAX_CITIES], int i);
    int secondMin(int matrix[MAX_CITIES][MAX_CITIES], int i);
    void TSPRec(int matrix[MAX_CITIES][MAX_CITIES], int curr_bound, int curr_weight, int level, int curr_path[]);
};

#endif //BNB_H
