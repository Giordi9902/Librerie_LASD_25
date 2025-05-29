
#include "test.hpp"
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"
#include "./exercise2a/test.hpp"
#include "./exercise2b/test.hpp"
#include <iostream>
#include <limits>
#include "../utils/utils.hpp"
using namespace std;

void mytest()
{
    clean();
    PrintPersonalTestHeader();

    std::cout << std::endl;
    uint loctestnum, loctesterr;
    uint stestnum = 0, stesterr = 0;

    loctestnum = 0;
    loctesterr = 0;
    std::cout << "\033[1;32mExercise 1A (Personal Test) is starting!\033[0m" << std::endl;
    std::cout << std::endl;
    myTestExercise1A(loctestnum, loctesterr);
    stestnum += loctestnum;
    stesterr += loctesterr;

    loctestnum = 0;
    loctesterr = 0;
    std::cout << std::endl;
    std::cout << "\033[1;32mExercise 1B (Personal Test) is starting!\033[0m" << std::endl;
    std::cout << std::endl;
    myTestExercise1B(loctestnum, loctesterr);
    stestnum += loctestnum;
    stesterr += loctesterr;

    cout << endl
         << "\033[1;32mExercise 1 (Personal Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")\033[0m";
    cout << endl;
    std::cout << std::endl;

    loctestnum = 0;
    loctesterr = 0;
    std::cout << "\033[1;32mExercise 2A (Personal Test) is starting!\033[0m" << std::endl;
    std::cout << std::endl;
    myTestExercise2A(loctestnum, loctesterr);
    stestnum += loctestnum;
    stesterr += loctesterr;

    loctestnum = 0;
    loctesterr = 0;
    std::cout << std::endl;
    std::cout << "\033[1;32mExercise 2B (Personal Test) is starting!\033[0m" << std::endl;
    std::cout << std::endl;
    myTestExercise2B(loctestnum, loctesterr);
    stestnum += loctestnum;
    stesterr += loctesterr;


     cout << endl
         << "\033[1;32mExercise 2 (Personal Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")\033[0m";
    cout << endl;
    std::cout << std::endl;
    finalGreet();
}

void RuntimeChecks()
{
    clean();
    unsigned int choice = 0;

    do
    {
        std::cout << "\n\033[1;34mSelect the data structure to test:\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\33[1;33m\t1 :\033[0m Vector" << std::endl;
        std::cout << "\33[1;33m\t2 :\033[0m Sortable Vector" << std::endl;
        std::cout << "\33[1;33m\t3 :\033[0m List" << std::endl;
        std::cout << "\33[1;33m\t4 :\033[0m Set (List based)" << std::endl;
        std::cout << "\33[1;33m\t5 :\033[0m Set (Vector based)" << std::endl;
        std::cout << "\33[1;33m\t6 :\033[0m HeapVec" << std::endl;
        std::cout << "\33[1;33m\t0 :\033[0m Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input. Please enter a number.\033[0m" << std::endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            VectorTestMenu();
            wait();
            clean();
            break;
        case 2:
            SortableVectorTestMenu();
            wait();
            break;
        case 3:
            ListTestMenu();
            wait();
            break;
        case 4:
            SetLstTestMenu();
            wait();
            clean();
            break;
        case 5:
            SetVecTestMenu();
            wait();
            break;
        case 6:
            HeapVecTestMenu();
            wait();
            break;
        case 0:
            std::cout << "\nExiting test menu." << std::endl;
            break;
        default:
            std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m" << std::endl;
            break;
        }
    } while (choice != 0);
}
