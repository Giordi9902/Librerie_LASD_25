
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include <iostream>

void PrintMenu();

void wait()
{
  std::cout << "Press any key to continue..." << std::endl;
  std::cin.ignore();
  std::cin.get();
}

int main(int argc, char *argv[])
{
    std::cout << "Lasd Libraries 2024" << std::endl;
    PrintMenu();
    return 0;
}


void PrintMenu()
{
  int choice = 0;
  do
  {
    std::cout << "Welcome to the main menu!" << std::endl;
    std::cout << std::endl;
    std::cout << "Please, choose a test to run:" << std::endl;
    std::cout << "1 : Lasd Libraries 2025 Test Suite" << std::endl;
    std::cout << "2 : Personal Test Suite" << std::endl;
    std::cout << "0 : Exit" << std::endl;
    std::cout << std::endl;
    printf("Scelta: ");
    scanf("%d",&choice);
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