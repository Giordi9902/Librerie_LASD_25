#include <iostream>
#include <string>
#include "../../heap/vec/heapvec.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../vector/vector.hpp"
#include "../../zlasdtest/heap/heap.hpp"
#include "../../zlasdtest/container/linear.hpp"

void HeapVecTestMenu()
{

}

void Personal_Int_HeapVec(uint &testnum, uint &testerr)
{
    lasd::Vector<int> v1(10);
    SetAt(testnum,testerr,v1,true,0,4);
    SetAt(testnum,testerr,v1,true,1,1);
    SetAt(testnum,testerr,v1,true,2,3);
    SetAt(testnum,testerr,v1,true,3,2);
    SetAt(testnum,testerr,v1,true,4,16);
    SetAt(testnum,testerr,v1,true,5,9);
    SetAt(testnum,testerr,v1,true,6,10);
    SetAt(testnum,testerr,v1,true,7,14);
    SetAt(testnum,testerr,v1,true,8,8);
    SetAt(testnum,testerr,v1,true,9,7);
    lasd::HeapVec<int> h1(v1);
    IsHeap(testnum,testerr,h1,true);
    Traverse(testnum,testerr,v1,true,TraversePrint<int>);
    Traverse(testnum,testerr,h1,true,TraversePrint<int>);
    h1.Sort();
    Traverse(testnum,testerr,h1,true,TraversePrint<int>);
    IsHeap(testnum,testerr,h1,false);
}

void Personal_Double_HeapVec(uint &testnum, uint &testerr)
{
    lasd::Vector<double> v1(10);
    SetAt(testnum,testerr,v1,true,0,4.4);
    SetAt(testnum,testerr,v1,true,1,1.1);
    SetAt(testnum,testerr,v1,true,2,3.3);
    SetAt(testnum,testerr,v1,true,3,2.2);
    SetAt(testnum,testerr,v1,true,4,16.16);
    SetAt(testnum,testerr,v1,true,5,9.9);
    SetAt(testnum,testerr,v1,true,6,10.10);
    SetAt(testnum,testerr,v1,true,7,14.14);
    SetAt(testnum,testerr,v1,true,8,8.8);
    SetAt(testnum,testerr,v1,true,9,7.7);
    lasd::HeapVec<double> h1(v1);
    IsHeap(testnum,testerr,h1,true);
    Traverse(testnum,testerr,v1,true,TraversePrint<double>);
    Traverse(testnum,testerr,h1,true,TraversePrint<double>);
    h1.Sort();
    Traverse(testnum,testerr,h1,true,TraversePrint<double>);
    IsHeap(testnum,testerr,h1,false);
}

void Personal_Char_HeapVec(uint &testnum, uint &testerr)
{
    lasd::Vector<char> v1(10);
    SetAt(testnum,testerr,v1,true,0,'d');
    SetAt(testnum,testerr,v1,true,1,'a');
    SetAt(testnum,testerr,v1,true,2,'c');
    SetAt(testnum,testerr,v1,true,3,'b');
    SetAt(testnum,testerr,v1,true,4,'p');
    SetAt(testnum,testerr,v1,true,5,'i');
    SetAt(testnum,testerr,v1,true,6,'j');
    SetAt(testnum,testerr,v1,true,7,'n');
    SetAt(testnum,testerr,v1,true,8,'h');
    SetAt(testnum,testerr,v1,true,9,'g');
    lasd::HeapVec<char> h1(v1);
    IsHeap(testnum,testerr,h1,true);
    Traverse(testnum,testerr,v1,true,TraversePrint<char>);
    Traverse(testnum,testerr,h1,true,TraversePrint<char>);
    h1.Sort();
    Traverse(testnum,testerr,h1,true,TraversePrint<char>);
    IsHeap(testnum,testerr,h1,false);

}

void Personal_String_HeapVec(uint &testnum, uint &testerr)
{
    lasd::Vector<std::string> v1(10);
    SetAt(testnum,testerr,v1,true,0,std::string("d"));
    SetAt(testnum,testerr,v1,true,1,std::string("a"));
    SetAt(testnum,testerr,v1,true,2,std::string("c"));
    SetAt(testnum,testerr,v1,true,3,std::string("b"));
    SetAt(testnum,testerr,v1,true,4,std::string("p"));
    SetAt(testnum,testerr,v1,true,5,std::string("i"));
    SetAt(testnum,testerr,v1,true,6,std::string("j"));
    SetAt(testnum,testerr,v1,true,7,std::string("n"));
    SetAt(testnum,testerr,v1,true,8,std::string("h"));
    SetAt(testnum,testerr,v1,true,9,std::string("g"));
    lasd::HeapVec<std::string> h1(v1);
    IsHeap(testnum,testerr,h1,true);
    Traverse(testnum,testerr,v1,true,TraversePrint<std::string>);
    Traverse(testnum,testerr,h1,true,TraversePrint<std::string>);
    h1.Sort();
    Traverse(testnum,testerr,h1,true,TraversePrint<std::string>);
    IsHeap(testnum,testerr,h1,false);
}

void PersonalHeapVecTest(unsigned int& testnum, unsigned int& testerr)
{
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing HeapVec of integers>>\033[0m" << std::endl;
    Personal_Int_HeapVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of HeapVec<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing HeapVec of doubles>>\033[0m" << std::endl;
    Personal_Double_HeapVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of HeapVec<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of chars>>\033[0m" << std::endl;
    Personal_Char_HeapVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of HeapVec<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing HeapVec of strings>>\033[0m" << std::endl;
    Personal_String_HeapVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of HeapVec<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mHeapVec personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;

}


void myTestExercise2A(unsigned int& testnum, unsigned int& testerr){
    PersonalHeapVecTest(testnum,testerr);
    std::cout << std::endl
         << "\033[1;34mExercise 2A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}