#include <iostream>
#include "../../heap/heap.hpp"
#include "../../pq/pq.hpp"
#include "../../pq/heap/pqheap.hpp"

void PQHeapTestMenu()
{

}

void PersonalPQHeapTest(unsigned int& testnum, unsigned int& testerr)
{

}

void myTestExercise2B(unsigned int& testnum, unsigned int& testerr){
    PersonalPQHeapTest(testnum,testerr);
    std::cout << std::endl
         << "\033[1;34mExercise 2A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}