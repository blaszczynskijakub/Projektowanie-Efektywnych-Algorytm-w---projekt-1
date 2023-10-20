#ifndef PEA_PROJEKT_1_TIME_MEASURE_H
#define PEA_PROJEKT_1_TIME_MEASURE_H

class Time_measure {

public:
    Time_measure(int num_of_tests);

    long long test_brute_force(int matrix_size);
private:
    int num_of_tests;

};

#endif //PEA_PROJEKT_1_TIME_MEASURE_H
