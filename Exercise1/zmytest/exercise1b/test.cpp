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


void test_int_set(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    Empty(loctestnum,loctesterr,set,false);
    set.Clear();
    Empty(loctestnum,loctesterr,set,true);
    Size(loctestnum,loctesterr,set,true,0);
    testnum += loctestnum;
    testerr += loctesterr;
}

void test_double_set(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    testnum += loctestnum;
    testerr += loctesterr;
}

void test_string_set(lasd::Set<string> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    testnum += loctestnum;
    testerr += loctesterr;
}

void test_char_set(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    testnum += loctestnum;
    testerr += loctesterr;
}

void SetLstTest(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "Begin of SetLst<int> test" <<std::endl;
    lasd::Vector<int> v1(5);
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);
    for (int i = 0; i < 5; i++)
    {
        v1[i] = dist(gen);
    }
    lasd::SetLst<int> l1(v1);
    //test_int_set(l1,loctest,errtest);
    std::cout << "End of SetLst<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "End SetLst tests: " << toterr << " errors found over " << tottest << " tests." << std::endl;
    testnum+=tottest;
    testerr+=toterr;
}

void SetVecTest(uint &testnum, uint& testerr){
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "Begin of SetVec<int> test" <<std::endl;
    lasd::Vector<int> v1(5);
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);
    for (int i = 0; i < 5; i++)
    {
        v1[i] = dist(gen);
    }
    lasd::SetVec<int> sv(v1);
    test_int_set(sv,loctest,errtest);
    std::cout << "End of SetVec<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "End SetVec tests: " << toterr << " errors found over " << tottest << " tests." << std::endl;
    testnum+=tottest;
    testerr+=toterr;
}

void myTestExercise1B(uint &testnum, uint &testerr)
{
    SetLstTest(testnum, testerr);
    SetVecTest(testnum,testerr);
    std::cout << std::endl
         << "Exercise 1B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << std::endl;
}