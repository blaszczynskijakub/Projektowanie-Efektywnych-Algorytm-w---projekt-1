//
// Created by Jakub on 16.10.2023.
//
#include <iostream>
#include "FileReader.h"
#include <random>
#include <iomanip>
#include "DataGenerator.h"

using namespace std;


void DataGenerator::generateData(int min, int max, int amount) {
    int val;

    random_device rd; // non-deterministic generator
    mt19937 gen(rd()); // random engine seeded with rd()
    uniform_int_distribution<> dist(min, max);
    ofstream outfile("../data.txt");


    if (outfile.is_open()) { // Check if the file is opened successfully
        for (int q = 0; q < amount; q++){
//            outfile << "   ";
            for (int i = 0; i < amount; i++) {
                val = dist(gen); // pass the generator to the distribution
                if (val < min)
                    min = val;
                if (val > max)
                    max = val;
                outfile << setw(15) << right << val; // Write to the file
            }
            outfile<<endl;

            }
        outfile.close(); // Close the file stream
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }


}

