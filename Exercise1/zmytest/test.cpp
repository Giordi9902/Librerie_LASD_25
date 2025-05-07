
#include "test.hpp"
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"

#include <iostream>


using namespace std;

void mytest()
{
  clean();
  std::cout << "~*~#~*~ Welcome to the LASD Personal Test Suite ~*~#~*~ " << std::endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;

  loctestnum = 0; loctesterr = 0;
  myTestExercise1A(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  myTestExercise1B(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  cout << endl
       << "Exercise 1 (Personal Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";

  cout << endl
       << "Goodbye!" << endl;
}

void clean()
{
  std::cout << "\033[H\033[2J\033[3J";
}
