#include <iostream>
#include <conio.h>
#include "FileReader.h"
#include <random>
#include <profileapi.h>
#include "DataGenerator.h"
using namespace std;



const int TESTS= 10000;
const int MIN_VALUE=1;
const int  MAX_VALUE = 99999999;
const int REPEAT=10000;
int tab_random[REPEAT];
int tab_random_index[REPEAT];


void displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku i testuj" << endl;
    cout << "2.Usun na pozycji" << endl;
    cout << "3.Dodaj na pozycje" << endl;
    cout << "4.Znajdz liczbe" << endl;
    cout << "5.Dodaj na poczatek" << endl;
    cout << "6.Dodaj na koniec" << endl;
    cout << "7.Usun poczatek" << endl;
    cout << "8.Usun koniec" << endl;
    cout << "9.Wyswietl strukture" << endl;
    cout << "t.Test" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}
void displayMenuHeap(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Wyswietl stukture kopca" << endl;
    cout << "4.Znajdz liczbe" << endl;
    cout << "5.Dodaj do kopca" << endl;
    cout << "6.Usun ze szczytu" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_table(ifstream &infile) {
    char opt;
    string fileName;
    int index, value;

    do {

        displayMenu("--- TABLICA ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': //tutaj wczytytwanie  tablicy z pliku
                int tab[TESTS];
                FileReader::file_read_line(infile, tab, (TESTS));




                infile.close();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;


                break;

            case '5':  //dodanie na poczatek
                cout << "Podaj wartosc:";
                cin >> value;
                break;

            case '6':  //dodwania na koniec
                cout << "Podaj wartosc:";
                cin >> value;
                break;
            case '7':  //dodwania na koniec

                break;

            case '8':  //dodwania na koniec

                break;

            case '9': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                getch();
                break;

            case 't': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                break;



        }

    } while (opt != '0');
}

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void menu_list(ifstream &infile) {
    char opt;
    string fileName;
    int index, value;

    do {

        displayMenu("--- Lista ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': //tutaj wczytytwanie  tablicy z pliku
                int tab[TESTS];
                FileReader::file_read_line(infile, tab, (TESTS+1));
                for(int i=0;i<TESTS;i++)
                {

                }
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;

                break;

            case '5':  //dodanie na poczatek
                cout << "Podaj wartosc:";
                cin >> value;
                break;

            case '6':  //dodwania na koniec
                cout << "Podaj wartosc:";
                cin >> value;
                break;
            case '7':  //dodwania na koniec

                break;

            case '8':  //dodwania na koniec

                break;

            case '9': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                getch();
                break;

        }

    } while (opt != '0');
}

void menu_heap(ifstream &infile) {
    char opt;
    string fileName;
    int index, value;

    do {

        displayMenuHeap("--- Kopiec ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': //tutaj wczytytwanie  tablicy z pliku
                int tab[TESTS];
                FileReader::file_read_line(infile, tab, (TESTS+1));

                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                getch();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
//                cout << " podaj index:";
//                cin >> index;
//                cout << " podaj wartosc:";
//                cin >> value;
//
//                list.addAt(index, value);
//                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                break;

            case '5':  //dodanie na poczatek
                cout << "Podaj wartosc:";
                cin >> value;
                break;

            case '6':  //top usun
                break;
            case '7':  //dodwania na koniec

                break;

            case '8':  //dodwania na koniec

                break;

            case '9': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                getch();
                break;

        }

    } while (opt != '0');
}







int main() {
    //wczytywanie pliku

    //generowanie
//    int val;
//    int max ;
//    int min ;
//    random_device rd; // non-deterministic generator
//    mt19937 gen(rd()); // random engine seeded with rd()
//    uniform_int_distribution<> dist(MIN_VALUE, MAX_VALUE);
//    ofstream outfile("../data.txt");
//
//
//
//    if (outfile.is_open()) { // Check if the file is opened successfully
//        for (int i = 0; i < TESTS; i++)
//        {
//            val = dist(gen); // pass the generator to the distribution
//            if(val < min)
//                min = val;
//            if(val > max)
//                max = val;
//            outfile << val << " "; // Write to the file
//
//
//
//        }
//        outfile.close(); // Close the file stream
//    } else {
//        std::cout << "Failed to open the file." << std::endl;
//    }
    DataGenerator dataGenerator;
    dataGenerator.generateData(0,1000,5);





    ifstream infile;
    string filename = "../data.txt";
    infile.open(filename);

    if (!infile) {
        cerr << "Unable to open file!";
        exit(1);
    }





    char option;
    do {
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;


        switch (option) {
            case '1':
                menu_table(infile);
                break;

            case '2':
                menu_list(infile);
                break;

            case '3':
                menu_heap(infile);
                break;
        }

    } while (option != '0');
    infile.close();
    return 0;
}
