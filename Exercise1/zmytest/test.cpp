
#include "test.hpp"
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"

#include <iostream>

using namespace std;

void clean()
{
    std::cout << "\033[H\033[2J\033[3J";
}
void mytest()
{
    clean();
    std::cout << "\033[1;32m~*~#~*~ Welcome to the LASD Personal Test Suite ~*~#~*~ \033[0m" << std::endl;
    std::cout << std::endl;
    uint loctestnum, loctesterr;
    uint stestnum = 0, stesterr = 0;

    loctestnum = 0;
    loctesterr = 0;
    std::cout << "\033[1;32mExercise 1 (Personal Test) is starting!\033[0m"<<std::endl;
    std::cout << std::endl;
    myTestExercise1A(loctestnum, loctesterr);
    stestnum += loctestnum;
    stesterr += loctesterr;

    loctestnum = 0;
    loctesterr = 0;
    std::cout << std::endl;
    std::cout << "\033[1;32mExercise 2 (Personal Test) is starting!\033[0m"<<std::endl;
    std::cout << std::endl;
    myTestExercise1B(loctestnum, loctesterr);
    stestnum += loctestnum;
    stesterr += loctesterr;

    cout << endl
         << "\033[1;32mExercise 1 (Personal Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")\033[0m";

    cout << endl
         << "Goodbye!" << endl;
}


