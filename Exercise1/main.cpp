
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include <iostream>
#include <limits>

void PrintMenu();

void PrintHeader()
{
    std::cout << "\033[36m"
              << R"( /$$        /$$$$$$   /$$$$$$  /$$$$$$$         /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$
| $$       /$$__  $$ /$$__  $$| $$__  $$       /$$__  $$ /$$$_  $$ /$$__  $$| $$____/
| $$      | $$  \ $$| $$  \__/| $$  \ $$      |__/  \ $$| $$$$\ $$|__/  \ $$| $$
| $$      | $$$$$$$$|  $$$$$$ | $$  | $$        /$$$$$$/| $$ $$ $$  /$$$$$$/| $$$$$$$
| $$      | $$__  $$ \____  $$| $$  | $$       /$$____/ | $$\ $$$$ /$$____/ |_____  $$
| $$      | $$  | $$ /$$  \ $$| $$  | $$      | $$      | $$ \ $$$| $$       /$$  \ $$
| $$$$$$$$| $$  | $$|  $$$$$$/| $$$$$$$/      | $$$$$$$$|  $$$$$$/| $$$$$$$$|  $$$$$$/
|________/|__/  |__/ \______/ |_______/       |________/ \______/ |________/ \______/
)" << "\033[0m"
              << std::endl;
}

void wait()
{
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

int main(int argc, char *argv[])
{
    PrintMenu();
    return 0;
}

void PrintMenu()
{
    int choice = 0;
    do
    {
        PrintHeader();
        std::cout << std::endl;
        std::cout << "Welcome to the main menu!" << std::endl;
        std::cout << std::endl;
        std::cout << "Please, choose a test to run:" << std::endl;
        std::cout << "\33[1;33m\t1 :\033[0m Lasd Libraries 2025 Test Suite" << std::endl;
        std::cout << "\33[1;33m\t2 :\033[0m Personal Test Suite" << std::endl;
        std::cout << "\33[1;33m\t0 :\033[0m Exit" << std::endl;
        std::cout << std::endl;
        do
        {
            std::cout << "Choice: ";
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                choice = -1;
            }
            if (choice < 0 || choice > 2)
            {
                std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 2.\033[0m" << std::endl;
            }
        } while (choice < 0 || choice > 2);

        switch (choice)
        {
        case 1:
            lasdtest();
            wait();
            clean();
            break;
        case 2:
            mytest();
            wait();
            clean();
            break;
        case 0:
            std::cout << "Exiting...Goodbye!" << std::endl;
            break;
        }
    } while (choice != 0);
}