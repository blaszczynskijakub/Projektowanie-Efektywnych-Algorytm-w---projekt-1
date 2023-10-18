cmake_minimum_required(VERSION 3.24)
project(pea_projekt_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(pea_projekt_1 main.cpp FileReader.cpp OptionMenu.cpp OptionMenu.h DataGenerator.cpp DataGenerator.h
        Data_parser.h
        Data_parser.cpp
        Graph.h
        Graph.cpp
        Brute_force.h
        Brute_force.cpp)
