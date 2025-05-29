#include <iostream>
#include "../../heap/vec/heapvec.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../vector/vector.hpp"

void HeapVecTestMenu()
{

}

void PersonalHeapVecTest(unsigned int& testnum, unsigned int& testerr)
{

}


void myTestExercise2A(unsigned int& testnum, unsigned int& testerr){
    PersonalHeapVecTest(testnum,testerr);

    std::cout << std::endl
         << "\033[1;34mExercise 2A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}