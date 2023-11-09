#include <climits>
#include <cstring>
#include <iostream>
#include "BnB.h"

using namespace std;



//number of cities





// Function to copy temporary solution to
// the final solution
void BnB:: copyTab(int curr_path[]) {
    for (int i = 0; i < cities; i++)
        this->finalNodes[i] = curr_path[i];
    this->finalNodes[cities] = curr_path[0];
}

// Function to find the minimum edge cost from the vertex i
int BnB::  firstMin(int matrix[MAX_CITIES][MAX_CITIES], int i) {
    int min = INT_MAX;
    for (int k = 0; k < cities; k++)
        if (matrix[i][k] < min && i != k)
            min = matrix[i][k];
    return min;
}

// Function to find the second minimum edge cost from the vertex i

int BnB:: secondMin(int matrix[MAX_CITIES][MAX_CITIES], int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < cities; j++) {
        if (i == j)
            continue;

        if (matrix[i][j] <= first) {
            second = first;
            first = matrix[i][j];
        } else if (matrix[i][j] <= second &&
                   matrix[i][j] != first)
            second = matrix[i][j];
    }
    return second;
}

// function that takes as arguments:
// curr_bound -> lower bound of the root node
// curr_weight-> stores the weight of the path so far
// level-> current level while moving in the search
//		 space tree
// curr_path[] -> where the solution is being stored which
//			 would later be copied to finalNodes[]
void BnB:: TSPRec(int matrix[MAX_CITIES][MAX_CITIES], int curr_bound, int curr_weight,
            int level, int curr_path[]) {
    // base case is when we have reached level MAX_CITIES which
    // means we have covered all the nodes once

    if (level == cities) {
        // check if there is an edge from last vertex in
        // path back to the first vertex
        if (matrix[curr_path[level - 1]][curr_path[0]] != 0) {
            // curr_res has the total weight of the
            // solution we got
            int curr_res = curr_weight +
                           matrix[curr_path[level - 1]][curr_path[0]];

            // Update final result and final path if
            // current result is better.
            if (curr_res < this->final_res) {
                copyTab(curr_path);
                this->final_res = curr_res;
            }
        }
        return;
    }

    // for any other level iterate for all vertices to
    // build the search space tree recursively
    for (int i = 0; i < cities; i++) {
        // Consider next vertex if it is not same (diagonal
        // entry in adjacency matrix and not visited
        // already)
        if (matrix[curr_path[level - 1]][i] != 0 &&
            visited[i] == false) {
            int temp = curr_bound;
            curr_weight += matrix[curr_path[level - 1]][i];

            // different computation of curr_bound for
            // level 2 from the other levels
            if (level == 1)
                curr_bound -= ((firstMin(matrix, curr_path[level - 1]) +
                                firstMin(matrix, i)) / 2);
            else
                curr_bound -= ((secondMin(matrix, curr_path[level - 1]) +
                                firstMin(matrix, i)) / 2);

            // curr_bound + curr_weight is the actual lower bound
            // for the node that we have arrived on
            // If current lower bound < final_res, we need to explore
            // the node further
            if (curr_bound + curr_weight < this->final_res) {
                curr_path[level] = i;
                visited[i] = true;

                // call TSPRec for the next level
                TSPRec(matrix, curr_bound, curr_weight, level + 1,
                       curr_path);
            }

            // Else we have to prune the node by resetting
            // all changes to curr_weight and curr_bound
            curr_weight -= matrix[curr_path[level - 1]][i];
            curr_bound = temp;

            // Also reset the visited array
            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

// This function sets up finalNodes[]
void BnB:: TSP() {
    int curr_path[MAX_CITIES + 1];

    // Calculate initial lower bound for the root node
    // using the formula 1/2 * (sum of first min +
    // second min) for all edges.
    // Also initialize the curr_path and visited array
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));

    // Compute initial bound
    for (int i = 0; i < MAX_CITIES; i++)
        curr_bound += (firstMin(matrix, i) +
                       secondMin(matrix, i));

    // Rounding off the lower bound to an integer
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 :
                 curr_bound / 2;

    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    visited[0] = true;
    curr_path[0] = 0;

    // getting first level node
    TSPRec(matrix, curr_bound, 0, 1, curr_path);
    cout<<"::"<<this->final_res;
}



BnB::BnB(int inputCitiesAmount, int inputMatrix[MAX_CITIES][MAX_CITIES]) {
    while (1)
    {
        if(inputCitiesAmount<3){
            cout<<"To nie jest problem TSP. Podaj prawidlowa liczbe miast";
            cin>>inputCitiesAmount;


        } else {
            cities = inputCitiesAmount;
            for(int i=0;i<cities;i++)
            {
                for(int j=0;j<cities;j++)
                {
                    matrix[i][j]=inputMatrix[i][j];
                }
            }
            break;
        }
    }
}
