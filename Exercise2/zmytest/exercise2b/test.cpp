#include <iostream>
#include "../../heap/heap.hpp"
#include "../../pq/pq.hpp"
#include "../../pq/heap/pqheap.hpp"

void PQHeapTestMenu()
{

}

void Personal_Int_PQHeap(uint &testnum, uint &testerr){

}

void Personal_Double_PQHeap(uint &testnum, uint &testerr){

}

void Personal_Char_PQHeap(uint &testnum, uint &testerr){

}

void Personal_String_PQHeap(uint &testnum, uint &testerr){

}

void PersonalPQHeapTest(unsigned int& testnum, unsigned int& testerr)
{
 uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing PQHeap of integers>>\033[0m" << std::endl;
    Personal_Int_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing PQHeap of doubles>>\033[0m" << std::endl;
    Personal_Double_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing PQHeap of chars>>\033[0m" << std::endl;
    Personal_Char_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing PQHeap of strings>>\033[0m" << std::endl;
    Personal_String_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mPQHeap personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;
}

void myTestExercise2B(unsigned int& testnum, unsigned int& testerr){
    PersonalPQHeapTest(testnum,testerr);
    std::cout << std::endl
         << "\033[1;34mExercise 2B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}