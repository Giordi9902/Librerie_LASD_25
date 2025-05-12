#include <iostream>
#include "test.hpp"
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

void Personal_Int_Set(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    InsertC(loctestnum, loctesterr, set, true, 10);
    InsertC(loctestnum, loctesterr, set, true, 20);
    InsertC(loctestnum, loctesterr, set, true, 30);
    InsertC(loctestnum, loctesterr, set, true, 40);
    InsertC(loctestnum, loctesterr, set, true, 50);
    InsertC(loctestnum, loctesterr, set, true, 25);
    Remove(loctestnum, loctesterr, set, true, 30);
    Exists(loctestnum, loctesterr, set, true, 25);
    Exists(loctestnum, loctesterr, set, false, 100);
    Min(loctestnum, loctesterr, set, true, 10);
    Max(loctestnum, loctesterr, set, true, 50);
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<int>);
    RemoveMin(loctestnum, loctesterr, set, true);
    RemoveMax(loctestnum, loctesterr, set, true);
    Predecessor(loctestnum, loctesterr, set, true, 25, 20);
    Successor(loctestnum, loctesterr, set, true, 25, 40);
    Predecessor(loctestnum, loctesterr, set, false, 20, 0);
    Successor(loctestnum, loctesterr, set, false, 40, 0);
    PredecessorNRemove(loctestnum, loctesterr, set, true, 40, 25);
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<int>);
    SuccessorNRemove(loctestnum, loctesterr, set, true, 20, 40);
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<int>);
    InsertC(loctestnum, loctesterr, set, true, 5);
    InsertC(loctestnum, loctesterr, set, true, 10);
    InsertC(loctestnum, loctesterr, set, true, 15);
    InsertC(loctestnum, loctesterr, set, false, 20);
    InsertC(loctestnum, loctesterr, set, true, 25);
    InsertC(loctestnum, loctesterr, set, true, 30);
    InsertC(loctestnum, loctesterr, set, true, 35);
    InsertC(loctestnum, loctesterr, set, true, 40);
    MaxNRemove(loctestnum, loctesterr, set, true, 40);
    MinNRemove(loctestnum, loctesterr, set, true, 5);

    set.Clear();
    lasd::Vector<int> vector(10);
    for (int i = 0; i < 10; ++i)
    {
        vector[i] = i % 5; // Insert elements 0, 1, 2, 3, 4, 0, 1, 2, 3, 4
    }
    InsertAllC(loctestnum, loctesterr, set, false, vector);
    Min(loctestnum, loctesterr, set, true, 0);
    Max(loctestnum, loctesterr, set, true, 4);
    set.Clear();
    InsertSomeC(loctestnum, loctesterr, set, true, vector);
    Min(loctestnum, loctesterr, set, true, 0);
    Max(loctestnum, loctesterr, set, true, 4);
    set.Clear();

    InsertAllM(loctestnum, loctesterr, set, false, std::move(vector));
    Min(loctestnum, loctesterr, set, true, 0);
    Max(loctestnum, loctesterr, set, true, 4);
    set.Clear();
    lasd::Vector<int> vector2(10);
    for (int i = 0; i < 10; ++i)
    {
        vector2[i] = i % 5; // Insert elements 0, 1, 2, 3, 4, 0, 1, 2, 3, 4
    }
    InsertSomeM(loctestnum, loctesterr, set, true, std::move(vector2));
    Min(loctestnum, loctesterr, set, true, 0);
    Max(loctestnum, loctesterr, set, true, 4);
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Double_Set(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    InsertC(loctestnum, loctesterr, set, true, 10.5);
    InsertC(loctestnum, loctesterr, set, true, 20.5);
    InsertC(loctestnum, loctesterr, set, true, 30.5);
    InsertC(loctestnum, loctesterr, set, true, 40.5);
    InsertC(loctestnum, loctesterr, set, true, 50.5);
    Remove(loctestnum, loctesterr, set, true, 30.5);
    Exists(loctestnum, loctesterr, set, true, 20.5);
    Exists(loctestnum, loctesterr, set, false, 100.5);
    Min(loctestnum, loctesterr, set, true, 10.5);
    Max(loctestnum, loctesterr, set, true, 50.5);
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<double>);
    RemoveMin(loctestnum, loctesterr, set, true);
    RemoveMax(loctestnum, loctesterr, set, true);

    Predecessor(loctestnum, loctesterr, set, false, 20.5, 10.5);
    Successor(loctestnum, loctesterr, set, true, 20.5, 40.5);
    Predecessor(loctestnum, loctesterr, set, false, 10.5, 0.0);
    Successor(loctestnum, loctesterr, set, false, 50.5, 0.0);
    PredecessorNRemove(loctestnum, loctesterr, set, true, 40.5, 20.5);
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<double>);
    SuccessorNRemove(loctestnum, loctesterr, set, true, 20.5, 40.5);
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<double>);
    InsertC(loctestnum, loctesterr, set, true, 5.5);
    InsertC(loctestnum, loctesterr, set, true, 10.5);
    InsertC(loctestnum, loctesterr, set, true, 15.5);
    InsertC(loctestnum, loctesterr, set, true, 20.5);
    InsertC(loctestnum, loctesterr, set, true, 25.5);
    InsertC(loctestnum, loctesterr, set, true, 30.5);
    InsertC(loctestnum, loctesterr, set, true, 35.5);
    InsertC(loctestnum, loctesterr, set, true, 40.5);
    MaxNRemove(loctestnum, loctesterr, set, true, 40.5);
    MinNRemove(loctestnum, loctesterr, set, true, 5.5);

    set.Clear();
    lasd::Vector<double> vector(10);
    for (int i = 0; i < 10; ++i)
    {
        vector[i] = (i % 5) + 0.5; // Insert elements 0.5, 1.5, 2.5, 3.5, 4.5, 0.5, 1.5, 2.5, 3.5, 4.5
    }
    InsertAllC(loctestnum, loctesterr, set, false, vector);
    Min(loctestnum, loctesterr, set, true, 0.5);
    Max(loctestnum, loctesterr, set, true, 4.5);
    set.Clear();
    InsertSomeC(loctestnum, loctesterr, set, true, vector);
    Min(loctestnum, loctesterr, set, true, 0.5);
    Max(loctestnum, loctesterr, set, true, 4.5);
    set.Clear();

    InsertAllM(loctestnum, loctesterr, set, false, std::move(vector));
    Min(loctestnum, loctesterr, set, true, 0.5);
    Max(loctestnum, loctesterr, set, true, 4.5);
    set.Clear();
    lasd::Vector<double> vector2(10);
    for (int i = 0; i < 10; ++i)
    {
        vector2[i] = (i % 5) + 0.5; // Insert elements 0.5, 1.5, 2.5, 3.5, 4.5, 0.5, 1.5, 2.5, 3.5, 4.5
    }
    InsertSomeM(loctestnum, loctesterr, set, true, std::move(vector2));
    Min(loctestnum, loctesterr, set, true, 0.5);
    Max(loctestnum, loctesterr, set, true, 4.5);

    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Char_Set(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    InsertC(loctestnum, loctesterr, set, true, 'a');
    InsertC(loctestnum, loctesterr, set, true, 'b');
    InsertC(loctestnum, loctesterr, set, true, 'c');
    InsertC(loctestnum, loctesterr, set, true, 'd');
    InsertC(loctestnum, loctesterr, set, true, 'e');
    Remove(loctestnum, loctesterr, set, true, 'c');
    Exists(loctestnum, loctesterr, set, true, 'b');
    Exists(loctestnum, loctesterr, set, false, 'z');
    Min(loctestnum, loctesterr, set, true, 'a');
    Max(loctestnum, loctesterr, set, true, 'e');
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<char>);
    RemoveMin(loctestnum, loctesterr, set, true);
    RemoveMax(loctestnum, loctesterr, set, true);

    Predecessor(loctestnum, loctesterr, set, false, 'b', 'a');
    Successor(loctestnum, loctesterr, set, true, 'b', 'd');
    Predecessor(loctestnum, loctesterr, set, false, 'a', 'a');
    Successor(loctestnum, loctesterr, set, false, 'e', 'd');
    PredecessorNRemove(loctestnum, loctesterr, set, true, 'd', 'b');
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<char>);
    SuccessorNRemove(loctestnum, loctesterr, set, true, 'b', 'd');
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<char>);

    InsertC(loctestnum, loctesterr, set, true, 'm');
    InsertC(loctestnum, loctesterr, set, true, 'n');
    InsertC(loctestnum, loctesterr, set, true, 'o');
    InsertC(loctestnum, loctesterr, set, true, 'p');
    InsertC(loctestnum, loctesterr, set, false, 'n');
    InsertC(loctestnum, loctesterr, set, true, 'q');
    InsertC(loctestnum, loctesterr, set, true, 'r');
    InsertC(loctestnum, loctesterr, set, true, 's');
    InsertC(loctestnum, loctesterr, set, true, 't');
    InsertC(loctestnum, loctesterr, set, true, 'u');
    MaxNRemove(loctestnum, loctesterr, set, true, 'u');
    MinNRemove(loctestnum, loctesterr, set, true, 'm');

    set.Clear();
    lasd::Vector<char> vector(10);
    for (int i = 0; i < 10; ++i)
    {
        vector[i] = 'a' + (i % 5); // Insert elements 'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'
    }
    InsertAllC(loctestnum, loctesterr, set, false, vector);
    Min(loctestnum, loctesterr, set, true, 'a');
    Max(loctestnum, loctesterr, set, true, 'e');
    set.Clear();
    InsertSomeC(loctestnum, loctesterr, set, true, vector);
    Min(loctestnum, loctesterr, set, true, 'a');
    Max(loctestnum, loctesterr, set, true, 'e');
    set.Clear();

    InsertAllM(loctestnum, loctesterr, set, false, std::move(vector));
    Min(loctestnum, loctesterr, set, true, 'a');
    Max(loctestnum, loctesterr, set, true, 'e');
    set.Clear();
    lasd::Vector<char> vector2(10);
    for (int i = 0; i < 10; ++i)
    {
        vector2[i] = (char) 'a' + (i % 5); // Insert elements 'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'
    }
    InsertSomeM(loctestnum, loctesterr, set, true, std::move(vector2));
    Min(loctestnum, loctesterr, set, true, 'a');
    Max(loctestnum, loctesterr, set, true, 'e');

    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_String_Set(lasd::Set<string> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    InsertC(loctestnum, loctesterr, set, true, std::string("apple"));
    InsertC(loctestnum, loctesterr, set, true, std::string("banana"));
    InsertC(loctestnum, loctesterr, set, true, std::string("cherry"));
    InsertC(loctestnum, loctesterr, set, true, std::string("date"));
    InsertC(loctestnum, loctesterr, set, true, std::string("fig"));
    InsertC(loctestnum, loctesterr, set, true, std::string("grape"));
    InsertC(loctestnum, loctesterr, set, true, std::string("kiwi"));
    InsertC(loctestnum, loctesterr, set, true, std::string("lemon"));
    InsertC(loctestnum, loctesterr, set, true, std::string("mango"));
    InsertC(loctestnum, loctesterr, set, true, std::string("orange"));
    InsertC(loctestnum, loctesterr, set, true, std::string("peach"));
    InsertC(loctestnum, loctesterr, set, true, std::string("pear"));
    InsertC(loctestnum, loctesterr, set, true, std::string("plum"));
    InsertC(loctestnum, loctesterr, set, true, std::string("quince"));
    InsertC(loctestnum, loctesterr, set, true, std::string("raspberry"));
    InsertC(loctestnum, loctesterr, set, true, std::string("strawberry"));
    InsertC(loctestnum, loctesterr, set, true, std::string("watermelon"));

    Remove(loctestnum, loctesterr, set, true, std::string("banana"));
    Exists(loctestnum, loctesterr, set, true, std::string("cherry"));
    Exists(loctestnum, loctesterr, set, false, std::string("coconut"));
    Min(loctestnum, loctesterr, set, true, std::string("apple"));
    Max(loctestnum, loctesterr, set, true, std::string("watermelon"));
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<string>);
    RemoveMin(loctestnum, loctesterr, set, true);
    RemoveMax(loctestnum, loctesterr, set, true);

    Predecessor(loctestnum, loctesterr, set, false, std::string("cherry"), std::string("apple"));
    Successor(loctestnum, loctesterr, set, true, std::string("cherry"), std::string("date"));
    Predecessor(loctestnum, loctesterr, set, false, std::string("apple"), std::string("apple"));
    Successor(loctestnum, loctesterr, set, false, std::string("watermelon"), std::string("date"));
    PredecessorNRemove(loctestnum, loctesterr, set, true, std::string("date"), std::string("cherry"));
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<string>);
    SuccessorNRemove(loctestnum, loctesterr, set, true, std::string("apple"), std::string("date"));
    Traverse(loctestnum, loctesterr, set, true, TraversePrint<string>);

    InsertC(loctestnum, loctesterr, set, false, std::string("kiwi"));
    InsertC(loctestnum, loctesterr, set, false, std::string("lemon"));
    InsertC(loctestnum, loctesterr, set, false, std::string("mango"));
    InsertC(loctestnum, loctesterr, set, false, std::string("orange"));
    InsertC(loctestnum, loctesterr, set, false, std::string("peach"));

    testnum += loctestnum;
    testerr += loctesterr;
}

void PersonalSetLstTest(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing SetLst of integers>>\033[0m" << std::endl;
    lasd::SetLst<int> l1;
    Personal_Int_Set(l1, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of doubles>>\033[0m" << std::endl;
    lasd::SetLst<double> l2;
    Personal_Double_Set(l2, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of chars>>\033[0m" << std::endl;
    lasd::SetLst<char> l3;
    Personal_Char_Set(l3, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of strings>>\033[0m" << std::endl;
    lasd::SetLst<string> l4;
    Personal_String_Set(l4, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mSetLst personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;
}

void PersonalSetVecTest(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing SetVec of integers>>\033[0m" << std::endl;
    lasd::SetVec<int> sv1;
    Personal_Int_Set(sv1, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetVec of doubles>>\033[0m" << std::endl;
    lasd::SetVec<double> sv2;
    Personal_Double_Set(sv2, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetVec of chars>>\033[0m" << std::endl;
    lasd::SetVec<char> sv3;
    Personal_Char_Set(sv3, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetVec of strings>>\033[0m" << std::endl;
    lasd::SetVec<string> sv4;
    Personal_String_Set(sv4, loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mSetVec personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;
}

void myTestExercise1B(unsigned int &testnum, unsigned int &testerr)
{
    std::cout << "\033[1;35mBegin of SetLst Personal Tests\033[0m" << std::endl;
    PersonalSetLstTest(testnum, testerr);

    std::cout << "\033[1;35mBegin of SetVec Personal Tests\033[0m" << std::endl;
    PersonalSetVecTest(testnum, testerr);

    std::cout << std::endl
              << "\033[1;34mExercise 1B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}