#include <iostream>
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../set/set.hpp"
#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include <string>
#include <random>

using namespace std;
// void test_int_set(lasd::Set<int> &set, uint &testnum, uint &testerr)
// {
//     uint loctestnum = 0, loctesterr = 0;

//     testnum += loctestnum;
//     testerr += loctesterr;
// }

// void test_double_set(lasd::Set<double> &set, uint &testnum, uint &testerr)
// {
//     uint loctestnum = 0, loctesterr = 0;

//     testnum += loctestnum;
//     testerr += loctesterr;
// }

// void test_string_set(lasd::Set<string> &set, uint &testnum, uint &testerr)
// {
//     uint loctestnum = 0, loctesterr = 0;

//     testnum += loctestnum;
//     testerr += loctesterr;
// }

// void test_char_set(lasd::Set<char> &set, uint &testnum, uint &testerr)
// {
//     uint loctestnum = 0, loctesterr = 0;

//     testnum += loctestnum;
//     testerr += loctesterr;
// }

// void SetLstTest(uint &testnum, uint &testerr)
// {
//     uint tottest = 0;
//     uint toterr = 0;

//     uint loctest = 0;
//     uint errtest = 0;
//     std::cout << std::endl;
//     std::cout << "Begin of SetLst<int> test" <<std::endl;
//     lasd::SetLst<int> l1;
//     //test_int_set(l1,loctest,errtest);
//     std::cout << "End of SetLst<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
//     tottest += loctest;
//     toterr += errtest;

//     std::cout << std::endl;
//     std::cout << "End SetLst tests: " << toterr << " errors found over " << tottest << " tests." << std::endl;
//     testnum+=tottest;
//     testerr+=toterr;
// }

// void SetVecTest(uint &testnum, uint& testerr){
//     uint tottest = 0;
//     uint toterr = 0;

//     uint loctest = 0;
//     uint errtest = 0;
//     std::cout << std::endl;
//     std::cout << "Begin of SetVec<int> test" <<std::endl;
//     lasd::SetVec<int> l1;
//     //test_int_set(l1,loctest,errtest);
//     std::cout << "End of SetVec<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
//     tottest += loctest;
//     toterr += errtest;

//     std::cout << std::endl;
//     std::cout << "End SetVec tests: " << toterr << " errors found over " << tottest << " tests." << std::endl;
//     testnum+=tottest;
//     testerr+=toterr;
// }
template <typename Data>
void PrintSetDetails(lasd::SetVec<Data> ls)
{
    std::cout << "size: " << ls.GetCapacity() << std::endl;
    std::cout << "tail: " << ls.GetTail() << std::endl;
    std::cout << "head: " << ls.GetHead() << std::endl;
    std::cout << "n° elements: " << ls.Size() << std::endl;
    std::cout << std::endl;
}
void myTestExercise1B(uint &testnum, uint &testerr)
{
    // SetLstTest(testnum, testerr);
    // SetVecTest(testnum,testerr);
    // std::cout << std::endl
    //      << "Exercise 1B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << std::endl;
    lasd::Vector<int> v1(5);
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);
    for (int i = 0; i < 5; i++)
    {
        v1[i] = dist(gen);
    }
    lasd::SetVec<int> sv(v1);
    std::cout << "Declared a new SetVec!" << std::endl;
    PrintSetDetails(sv);
    std::cout << "Printing Set: ";
    sv.Traverse(TraversePrint<int>);
    std::cout << std::endl;
    PrintSetDetails(sv);
    std::cout << "Inserisci un numero del set del quale vuoi ottenere informazioni: ";
    int num;
    std::cin >> num;
    try{
    int prev = sv.Predecessor(num);
    std::cout << "L'elemento che precede " << num << " è il numero " << prev << std::endl;
    int succ = sv.Successor(num);
    std::cout << "L'elemento che succede " << num << " è il numero " << succ << std::endl;
    std::cout << "Rimuovo il predecessore di " << num << std::endl;
    sv.RemovePredecessor(num);
    std::cout << "Ho rimosso " << prev << std::endl;
    std::cout << "Printing Set: ";
    sv.Traverse(TraversePrint<int>);
    std::cout << std::endl;
    PrintSetDetails(sv);
    std::cout << "Rimuovo il massimo del set."<<std::endl;
    sv.RemoveMax();
    sv.Traverse(TraversePrint<int>);
    std::cout << std::endl;
    PrintSetDetails(sv);
    std::cout << "Inserisci un numero :";
    std::cin >> num;
    sv.Insert(num);
    sv.Traverse(TraversePrint<int>);
    std::cout << std::endl;
    PrintSetDetails(sv);
    }catch(...){
        std::cout << "Beh che dire" <<std::endl;
    }
}
