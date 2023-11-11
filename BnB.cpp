#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include "BnB.h"

using namespace std;

// Function to copy temporary solution to
// the final solution
void BnB::copyTab(int current_path[]) {
    for (int i = 0; i < cities; i++)
        this->finalNodes[i] = current_path[i];
    this->finalNodes[cities] = current_path[0];
}

// Function to find the minimum edge cost from the vertex i
int BnB::firstMin(int matrix[MAX_CITIES][MAX_CITIES], int i) {
    int min = INT_MAX;
    for (int k = 0; k < cities; k++)
        if (matrix[i][k] < min && i != k)
            min = matrix[i][k];
    return min;
}

// Function to find the second minimum edge cost from the vertex i
int BnB::secondMin(int matrix[MAX_CITIES][MAX_CITIES], int i) {
    int first = INT_MAX;
    int second = INT_MAX;
    for (int j = 0; j < cities; j++) {
        if (i == j)
            continue;
        if (matrix[i][j] <= first) {
            second = first;
            first = matrix[i][j];
        } else if (matrix[i][j] <= second && matrix[i][j] != first)
            second = matrix[i][j];
    }
    return second;
}


void BnB::TSPRec(int matrix[MAX_CITIES][MAX_CITIES], int curr_bound, int curr_weight,
                 int level, int curr_path[]) {
    //moment we covered all nodes
    if (level == cities) {
        //checking for last edge from last node to first
        if (matrix[curr_path[level - 1]][curr_path[0]] != 0) {
            //adding to our solution the last edge
            int curr_res = curr_weight + matrix[curr_path[level - 1]][curr_path[0]];

            // Update final result if current solution is better
            if (curr_res < this->final_res) {
                copyTab(curr_path);
                this->final_res = curr_res;
            }
        }
        return;
    }


    for (int i = 0; i < cities; i++) {

        if (matrix[curr_path[level - 1]][i] != 0 &&
            visited[i] == false) {
            int temp = curr_bound;
            curr_weight += matrix[curr_path[level - 1]][i];
            if (level == 1)
                curr_bound -= ((firstMin(matrix, curr_path[level - 1]) +
                                firstMin(matrix, i)) / 2);
            else
                curr_bound -= ((secondMin(matrix, curr_path[level - 1]) +
                                firstMin(matrix, i)) / 2);

            if (curr_bound + curr_weight < this->final_res) {
                curr_path[level] = i;
                visited[i] = true;

                // next level now
                TSPRec(matrix, curr_bound, curr_weight, level + 1,
                       curr_path);
            }

            // Else we go back
            curr_weight -= matrix[curr_path[level - 1]][i];
            curr_bound = temp;

            // reset
            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void BnB::TSP() {
    int curr_path[MAX_CITIES + 1];


    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));

    // inital lower bound
    for (int i = 0; i < MAX_CITIES; i++)
        curr_bound += (firstMin(matrix, i) +
                       secondMin(matrix, i));

    // Rounding
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 :
                 curr_bound / 2;


    visited[0] = true;
    curr_path[0] = 0;

    // first level node as start
    TSPRec(matrix, curr_bound, 0, 1, curr_path);

}


BnB::BnB(int inputCitiesAmount, std::vector<std::vector<int>> inputMatrix) {
    while (1) {
        if (inputCitiesAmount < 3) {
            cout << "To nie jest problem TSP. Podaj prawidlowa liczbe miast";
            cin >> inputCitiesAmount;


        } else {
            cities = inputCitiesAmount;
            for (int i = 0; i < cities; i++) {
                for (int j = 0; j < cities; j++) {
                    matrix[i][j] = inputMatrix[i][j];
                }
            }
            break;
        }
    }
}

void BnB::getResults() {
    cout << "koszt: " << final_res << endl << "sciezka: ";
    for (int i = 0; i < cities + 1; i++) {
        cout << finalNodes[i] << " ";
    }
    cout << endl;
}
