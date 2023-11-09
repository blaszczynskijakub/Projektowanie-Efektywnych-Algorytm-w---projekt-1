#include "Menu.h"
#include "BnB.h"

void Menu::show_menu() {
    using namespace std;
    std::vector<std::vector<int>> init_vector;
    DataGenerator generator;
    Graph graph(init_vector);

    std::string fromFile;
    std::string choice_s;

    while (true) {
        std::cout << "Problem komiwojazera rozwiazywany metoda przegladu zupelnego.\nAutor: Jakub Blaszczynski #263966\n\n";
        std::cout << "0 - Wyjdz z programu\n";
        std::cout << "1 - Wczytaj macierz z pliku\n";
        std::cout << "2 - Wygeneruj macierz\n";
        std::cout << "3 - Wyswietl ostatnio wczytana z pliku lub wygenerowana macierz\n";
        std::cout << "4 - Uruchom przeglad zupleny dla ostatnio wczytanej lub wygenerowanej macierzy i wyswietl wyniki\n";
        std::cout << "5 - Uruchom bnb dla ostatnio wczytanej lub wygenerowanej macierzy i wyswietl wyniki\n";

        std::cout << ">";

        std::cin >> choice_s;
        while (!is_digit(choice_s)) {
            std::cout << "Podany ciag znakow nie jest liczba!\nWpisz liczbe\n>";
            std::cin >> choice_s;
        }
        int choice = std::stoi(choice_s);

        switch (choice) {
            case 0:
                exit(0);
            case 1:

                std::cout << "Podaj nazwe pliku do wczytania\n>";
                std::cin >> choice_s;
                graph.readGraph(choice_s);

                break;
            case 2:
                std::cout << "Podaj wielkosc macierzy (rozmiar MAX_CITIES)\n>";
                std::cin >> choice_s;
                while (!is_digit(choice_s)) {
                    std::cout << "Podany ciag znakow nie jest liczba!\nWpisz liczbe\n>";
                    std::cin >> choice_s;
                }
                graph.setGraph(generator.generate_data(atoi(choice_s.c_str())));
                break;
            case 3:

                graph.printGraph();
                break;
            case 4:
                {
                    if(!graph.getGraph().empty())
                    {
                        cout<<1111;

                    Brute_force bf(graph.getGraph());
                    auto start = std::chrono::high_resolution_clock::now();

                    bf.perform_brute_force();
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                    std::cout << "Time taken by function: " << duration.count() << " microseconds" << "\n";
                    bf.show_lowest_path();

                } else
                    {
                        cout<<"BRAK ostatnio wczytanej lub wygenerowanej macierzy!"<<endl;
                    }
                }

                break;
            case 5:
            {
                int adj[20][20] = { {0, 10, 15, 20},
                                  {10, 0, 35, 25},
                                  {15, 35, 0, 30},
                                  {20, 25, 30, 0}
                };
                //table must be 20x20(MAX_CITIES), first number informs of real nr o cities in task
                BnB bnb(4,adj );
                bnb.TSP();
            }


                break;
            default:
                std::cout << "Program nie zawiera funkcji dla podanej liczby!\n";
                break;
        }
    }

}

bool Menu::is_digit(std::string input) {

    for (int i = 0; i<input.size(); i++) {
        if (isdigit(input[i]) == false) {
            return false;
        }
    }
    return true;

}