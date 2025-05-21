#include <iostream>
#include "test.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/set/set.hpp"
#include "../../set/set.hpp"
#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include <string>
#include <limits>
#include <random>

using namespace std;

void Check_Insertion_Set_Int(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    InsertC(testnum, testerr, set, true, 4);
    InsertC(testnum, testerr, set, true, 1);
    InsertC(testnum, testerr, set, true, 2);
    InsertC(testnum, testerr, set, true, 3);
    InsertC(testnum, testerr, set, false, 4);
    InsertC(testnum, testerr, set, true, 5);
    InsertC(testnum, testerr, set, true, 6);
    InsertC(testnum, testerr, set, true, 7);
    Remove(testnum, testerr, set, true, 1);
    Remove(testnum, testerr, set, true, 2);
    Remove(testnum, testerr, set, true, 3);
    Remove(testnum, testerr, set, true, 4);
    Remove(testnum, testerr, set, true, 5);
    Remove(testnum, testerr, set, true, 6);
    Remove(testnum, testerr, set, true, 7);
    Remove(testnum, testerr, set, false, 8);
}

void Check_Insertion_Set_Double(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    InsertC(testnum, testerr, set, true, 4.4);
    InsertC(testnum, testerr, set, true, 1.1);
    InsertC(testnum, testerr, set, true, 2.2);
    InsertC(testnum, testerr, set, true, 3.3);
    InsertC(testnum, testerr, set, false, 4.4);
    InsertC(testnum, testerr, set, true, 5.5);
    InsertC(testnum, testerr, set, true, 6.6);
    InsertC(testnum, testerr, set, true, 7.7);
    Remove(testnum, testerr, set, true, 1.1);
    Remove(testnum, testerr, set, true, 2.2);
    Remove(testnum, testerr, set, true, 3.3);
    Remove(testnum, testerr, set, true, 4.4);
    Remove(testnum, testerr, set, true, 5.5);
    Remove(testnum, testerr, set, true, 6.6);
    Remove(testnum, testerr, set, true, 7.7);
    Remove(testnum, testerr, set, false, 8.8);
}

void Check_Insertion_Set_Char(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    InsertC(testnum, testerr, set, true, 'd');
    InsertC(testnum, testerr, set, true, 'a');
    InsertC(testnum, testerr, set, true, 'b');
    InsertC(testnum, testerr, set, true, 'c');
    InsertC(testnum, testerr, set, false, 'd');
    InsertC(testnum, testerr, set, true, 'e');
    InsertC(testnum, testerr, set, true, 'f');
    InsertC(testnum, testerr, set, true, 'g');
    Remove(testnum, testerr, set, true, 'a');
    Remove(testnum, testerr, set, true, 'b');
    Remove(testnum, testerr, set, true, 'c');
    Remove(testnum, testerr, set, true, 'd');
    Remove(testnum, testerr, set, true, 'e');
    Remove(testnum, testerr, set, true, 'f');
    Remove(testnum, testerr, set, true, 'g');
    Remove(testnum, testerr, set, false, 'h');
}

void Check_Insertion_Set_String(lasd::Set<std::string> &set, uint &testnum, uint &testerr)
{
    InsertC(testnum, testerr, set, true, std::string("date"));
    InsertC(testnum, testerr, set, true, std::string("apple"));
    InsertC(testnum, testerr, set, true, std::string("banana"));
    InsertC(testnum, testerr, set, true, std::string("cherry"));
    InsertC(testnum, testerr, set, false, std::string("date"));
    InsertC(testnum, testerr, set, true, std::string("elderberry"));
    InsertC(testnum, testerr, set, true, std::string("fig"));
    InsertC(testnum, testerr, set, true, std::string("grape"));
    Remove(testnum, testerr, set, true, std::string("apple"));
    Remove(testnum, testerr, set, true, std::string("banana"));
    Remove(testnum, testerr, set, true, std::string("cherry"));
    Remove(testnum, testerr, set, true, std::string("date"));
    Remove(testnum, testerr, set, true, std::string("elderberry"));
    Remove(testnum, testerr, set, true, std::string("fig"));
    Remove(testnum, testerr, set, true, std::string("grape"));
    Remove(testnum, testerr, set, false, std::string("honeydew"));
}

void Check_Min_Max_Set_Int(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    Min(testnum, testerr, set, true, 1);
    Max(testnum, testerr, set, true, 7);
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 2);
    Max(testnum, testerr, set, true, 6);
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3);
    Max(testnum, testerr, set, true, 5);
    MinNRemove(testnum, testerr, set, true, 3);
    MaxNRemove(testnum, testerr, set, true, 5);
    Min(testnum, testerr, set, true, 4);
    Max(testnum, testerr, set, true, 4);
}

void Check_Min_Max_Set_Double(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    Min(testnum, testerr, set, true, 1.1);
    Max(testnum, testerr, set, true, 7.7);
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 2.2);
    Max(testnum, testerr, set, true, 6.6);
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 3.3);
    Max(testnum, testerr, set, true, 5.5);
    MinNRemove(testnum, testerr, set, true, 3.3);
    MaxNRemove(testnum, testerr, set, true, 5.5);
    Min(testnum, testerr, set, true, 4.4);
    Max(testnum, testerr, set, true, 4.4);
}

void Check_Min_Max_Set_Char(lasd::Set<char> &set, uint &testnum, uint &testerr)
{

    Min(testnum, testerr, set, true, 'a');
    Max(testnum, testerr, set, true, 'g');
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 'b');
    Max(testnum, testerr, set, true, 'f');
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, 'c');
    Max(testnum, testerr, set, true, 'e');
    MinNRemove(testnum, testerr, set, true, 'c');
    MaxNRemove(testnum, testerr, set, true, 'e');
    Min(testnum, testerr, set, true, 'd');
    Max(testnum, testerr, set, true, 'd');
}

void Check_Min_Max_Set_String(lasd::Set<std::string> &set, uint &testnum, uint &testerr)
{
    Min(testnum, testerr, set, true, std::string("apple"));
    Max(testnum, testerr, set, true, std::string("grape"));
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, std::string("banana"));
    Max(testnum, testerr, set, true, std::string("fig"));
    RemoveMax(testnum, testerr, set, true);
    RemoveMin(testnum, testerr, set, true);
    Min(testnum, testerr, set, true, std::string("cherry"));
    Max(testnum, testerr, set, true, std::string("elderberry"));
    MinNRemove(testnum, testerr, set, true, std::string("cherry"));
    MaxNRemove(testnum, testerr, set, true, std::string("elderberry"));
    Min(testnum, testerr, set, true, std::string("date"));
    Max(testnum, testerr, set, true, std::string("date"));
}

void Check_PredecessorNSuccessor_Int_Set(lasd::Set<int> &set, uint &testnum, uint &testerr)
{

    Predecessor(testnum, testerr, set, false, 1, 3);
    Predecessor(testnum, testerr, set, true, 2, 1);
    Predecessor(testnum, testerr, set, true, 3, 2);
    Predecessor(testnum, testerr, set, true, 4, 3);
    Predecessor(testnum, testerr, set, true, 5, 4);
    Predecessor(testnum, testerr, set, true, 6, 5);
    Predecessor(testnum, testerr, set, true, 7, 6);
    Predecessor(testnum, testerr, set, true, 8, 7);
    Predecessor(testnum, testerr, set, true, 9, 7);
    Successor(testnum, testerr, set, true, 0, 1);
    Successor(testnum, testerr, set, true, 1, 2);
    Successor(testnum, testerr, set, true, 2, 3);
    Successor(testnum, testerr, set, true, 3, 4);
    Successor(testnum, testerr, set, true, 5, 6);
    Successor(testnum, testerr, set, false, 7, 1);
    // 1 2 3 4 5 6 7
    PredecessorNRemove(testnum, testerr, set, false, 1, 1);
    PredecessorNRemove(testnum, testerr, set, true, 2, 1);
    // 2 3 4 5 6 7
    Predecessor(testnum, testerr, set, false, 2, 3);
    RemovePredecessor(testnum, testerr, set, false, 2);
    RemoveSuccessor(testnum, testerr, set, true, 2);
    // 2 4 5 6 7
    SuccessorNRemove(testnum, testerr, set, false, 7, 3);
    Successor(testnum, testerr, set, true, 2, 4);
    Successor(testnum, testerr, set, true, 4, 5);
    Successor(testnum, testerr, set, true, 6, 7);
    Successor(testnum, testerr, set, false, 7, 8);
    Predecessor(testnum, testerr, set, true, 10, 7);
    PredecessorNRemove(testnum, testerr, set, true, 10, 7);
    // 2 4 5 6
    Successor(testnum, testerr, set, false, 6, 7);
    SuccessorNRemove(testnum, testerr, set, true, 0, 2);
    // 4 5 6
    RemoveSuccessor(testnum, testerr, set, true, 0);
    // 5 6
    RemovePredecessor(testnum, testerr, set, false, 0);
    RemovePredecessor(testnum, testerr, set, true, 10);
    // 5
}

void Check_PredecessorNSuccessor_Double_Set(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    Predecessor(testnum, testerr, set, false, 1.1, 3.3);
    Predecessor(testnum, testerr, set, true, 2.2, 1.1);
    Predecessor(testnum, testerr, set, true, 3.3, 2.2);
    Predecessor(testnum, testerr, set, true, 4.4, 3.3);
    Predecessor(testnum, testerr, set, true, 5.5, 4.4);
    Predecessor(testnum, testerr, set, true, 6.6, 5.5);
    Predecessor(testnum, testerr, set, true, 7.7, 6.6);
    Predecessor(testnum, testerr, set, true, 8.8, 7.7);
    Predecessor(testnum, testerr, set, true, 9.9, 7.7);
    Successor(testnum, testerr, set, true, 1.1, 2.2);
    Successor(testnum, testerr, set, true, 2.2, 3.3);
    Successor(testnum, testerr, set, true, 3.3, 4.4);
    Successor(testnum, testerr, set, true, 5.5, 6.6);
    Successor(testnum, testerr, set, false, 7.7, 1.1);
    // 1.1 2.2 3.3 4.4 5.5 6.6 7.7
    PredecessorNRemove(testnum, testerr, set, false, 1.1, 1.1);
    PredecessorNRemove(testnum, testerr, set, true, 2.2, 1.1);
    // 2.2 3.3 4.4 5.5 6.6 7.7
    Predecessor(testnum, testerr, set, false, 2.2, 3.3);
    RemovePredecessor(testnum, testerr, set, false, 2.2);
    RemoveSuccessor(testnum, testerr, set, true, 2.2);
    // 2.2 4.4 5.5 6.6 7.7
    SuccessorNRemove(testnum, testerr, set, false, 7.7, 3.3);
    SuccessorNRemove(testnum, testerr, set, true, 1.1, 2.2);
    // 4.4 5.5 6.6 7.7
    Successor(testnum, testerr, set, true, 2.2, 4.4);
    Successor(testnum, testerr, set, true, 4.4, 5.5);
    Successor(testnum, testerr, set, true, 6.6, 7.7);
    Successor(testnum, testerr, set, false, 7.7, 8.8);
    Predecessor(testnum, testerr, set, true, 10.10, 7.7);
    PredecessorNRemove(testnum, testerr, set, true, 10.10, 7.7);
    // 4.4 5.5 6.6
    Successor(testnum, testerr, set, false, 6.6, 7.7);
    SuccessorNRemove(testnum, testerr, set, true, 1.1, 4.4);
    // 5.5 6.6
    RemoveSuccessor(testnum, testerr, set, true, 1.1);
    // 6.6
    RemovePredecessor(testnum, testerr, set, false, 1.1);
    RemovePredecessor(testnum, testerr, set, true, 10.10);
    // 5.5
}

void Check_PredecessorNSuccessor_Char_Set(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    Predecessor(testnum, testerr, set, false, 'a', 'c');
    Predecessor(testnum, testerr, set, true, 'b', 'a');
    Predecessor(testnum, testerr, set, true, 'c', 'b');
    Predecessor(testnum, testerr, set, true, 'd', 'c');
    Predecessor(testnum, testerr, set, true, 'e', 'd');
    Predecessor(testnum, testerr, set, true, 'f', 'e');
    Predecessor(testnum, testerr, set, true, 'g', 'f');
    Predecessor(testnum, testerr, set, true, 'h', 'g');
    Predecessor(testnum, testerr, set, true, 'i', 'g');
    Successor(testnum, testerr, set, true, 'a', 'b');
    Successor(testnum, testerr, set, true, 'b', 'c');
    Successor(testnum, testerr, set, true, 'c', 'd');
    Successor(testnum, testerr, set, true, 'e', 'f');
    Successor(testnum, testerr, set, false, 'g', 'a');
    // a b c d e f g
    PredecessorNRemove(testnum, testerr, set, false, 'a', 'a');
    PredecessorNRemove(testnum, testerr, set, true, 'b', 'a');
    // b c d e f g
    Predecessor(testnum, testerr, set, false, 'b', 'c');
    RemovePredecessor(testnum, testerr, set, false, 'b');
    RemoveSuccessor(testnum, testerr, set, true, 'b');
    // b d e f g
    SuccessorNRemove(testnum, testerr, set, false, 'g', 'c');
    SuccessorNRemove(testnum, testerr, set, true, 'a', 'b');
    // d e f g
    Successor(testnum, testerr, set, true, 'b', 'd');
    Successor(testnum, testerr, set, true, 'd', 'e');
    Successor(testnum, testerr, set, true, 'f', 'g');
    Successor(testnum, testerr, set, false, 'g', 'h');
    Predecessor(testnum, testerr, set, true, 'z', 'g');
    PredecessorNRemove(testnum, testerr, set, true, 'z', 'g');
    // d e f
    Successor(testnum, testerr, set, false, 'f', 'g');
    SuccessorNRemove(testnum, testerr, set, true, 'b', 'd');
    // e f
    RemoveSuccessor(testnum, testerr, set, true, 'b');
    // f
    RemovePredecessor(testnum, testerr, set, false, 'b');
    RemovePredecessor(testnum, testerr, set, true, 'z');
    // e
}

void Check_PredecessorNSuccessor_String_Set(lasd::Set<std::string> &set, uint &testnum, uint &testerr)
{
    Predecessor(testnum, testerr, set, false, std::string("apple"), std::string("cherry"));
    Predecessor(testnum, testerr, set, true, std::string("banana"), std::string("apple"));
    Predecessor(testnum, testerr, set, true, std::string("cherry"), std::string("banana"));
    Predecessor(testnum, testerr, set, true, std::string("date"), std::string("cherry"));
    Predecessor(testnum, testerr, set, true, std::string("elderberry"), std::string("date"));
    Predecessor(testnum, testerr, set, true, std::string("fig"), std::string("elderberry"));
    Predecessor(testnum, testerr, set, true, std::string("grape"), std::string("fig"));
    Predecessor(testnum, testerr, set, true, std::string("honeydew"), std::string("grape"));
    Predecessor(testnum, testerr, set, true, std::string("kiwi"), std::string("grape"));
    Successor(testnum, testerr, set, true, std::string(""), std::string("apple"));
    Successor(testnum, testerr, set, true, std::string("apple"), std::string("banana"));
    Successor(testnum, testerr, set, true, std::string("banana"), std::string("cherry"));
    Successor(testnum, testerr, set, true, std::string("cherry"), std::string("date"));
    Successor(testnum, testerr, set, true, std::string("elderberry"), std::string("fig"));
    Successor(testnum, testerr, set, false, std::string("grape"), std::string("apple"));
    // apple banana cherry date elderberry fig grape
    PredecessorNRemove(testnum, testerr, set, false, std::string("apple"), std::string("apple"));
    PredecessorNRemove(testnum, testerr, set, true, std::string("banana"), std::string("apple"));
    // banana cherry date elderberry fig grape
    Predecessor(testnum, testerr, set, false, std::string("banana"), std::string("cherry"));
    RemovePredecessor(testnum, testerr, set, false, std::string("banana"));
    RemoveSuccessor(testnum, testerr, set, true, std::string("banana"));
    // banana date elderberry fig grape
    SuccessorNRemove(testnum, testerr, set, false, std::string("grape"), std::string("cherry"));
}

void Personal_Int_SetLst(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<int> vec1(10);
    lasd::List<int> list1;

    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;
    vec1[3] = 1;
    vec1[4] = 4;
    vec1[5] = 5;
    vec1[6] = 2;
    vec1[7] = 6;
    vec1[8] = 7;
    vec1[9] = 3;

    list1.InsertAtBack(1);
    list1.InsertAtBack(2);
    list1.InsertAtBack(3);
    list1.InsertAtBack(1);
    list1.InsertAtBack(4);
    list1.InsertAtBack(5);
    list1.InsertAtBack(2);
    list1.InsertAtBack(6);
    list1.InsertAtBack(7);
    list1.InsertAtBack(3);

    lasd::Vector<int> vec2(vec1);

    {
        lasd::SetLst<int> setlst1(vec1);
        lasd::SetLst<int> setlst2(list1);

        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);

        lasd::SetLst<int> setlst3(std::move(vec1));
        lasd::SetLst<int> setlst4(std::move(list1));

        EqualSetLst(loctestnum, loctesterr, setlst3, setlst4, true);
        EqualSetLst(loctestnum, loctesterr, setlst1, setlst3, true);
        EqualSetLst(loctestnum, loctesterr, setlst2, setlst3, true);

        lasd::SetLst<int> setlst5(setlst1);
        lasd::SetLst<int> setlst6(std::move(setlst2));
        EqualSetLst(loctestnum, loctesterr, setlst5, setlst1, true);
        EqualSetLst(loctestnum, loctesterr, setlst6, setlst5, true);
    }

    {
        lasd::SetLst<int> setlst1;
        InsertSomeC(loctestnum, loctesterr, setlst1, true, vec1);
        lasd::SetLst<int> setlst2;
        InsertSomeM(loctestnum, loctesterr, setlst2, true, std::move(vec1));
        lasd::SetLst<int> setlst3;
        InsertAllC(loctestnum, loctesterr, setlst1, false, list1);
        lasd::SetLst<int> setlst4;
        InsertAllM(loctestnum, loctesterr, setlst2, false, std::move(list1));

        lasd::Vector<int> vec2(10);

        vec2[0] = 10;
        vec2[1] = 20;
        vec2[2] = 30;
        vec2[3] = 10;
        vec2[4] = 40;
        vec2[5] = 50;
        vec2[6] = 20;
        vec2[7] = 60;
        vec2[8] = 70;
        vec2[9] = 30;

        RemoveAll(loctestnum, loctesterr, setlst1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setlst1, true, setlst2);
    }

    {
        lasd::SetLst<int> setlst(vec2);
        Check_Min_Max_Set_Int(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<int> setlst(vec2);
        Check_PredecessorNSuccessor_Int_Set(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<int> setlst;
        Check_Insertion_Set_Int(setlst, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Double_SetLst(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<double> vec1(10);
    lasd::List<double> list1;

    vec1[0] = 1.1;
    vec1[1] = 2.2;
    vec1[2] = 3.3;
    vec1[3] = 1.1;
    vec1[4] = 4.4;
    vec1[5] = 5.5;
    vec1[6] = 2.2;
    vec1[7] = 6.6;
    vec1[8] = 7.7;
    vec1[9] = 3.3;

    list1.InsertAtBack(1.1);
    list1.InsertAtBack(2.2);
    list1.InsertAtBack(3.3);
    list1.InsertAtBack(1.1);
    list1.InsertAtBack(4.4);
    list1.InsertAtBack(5.5);
    list1.InsertAtBack(2.2);
    list1.InsertAtBack(6.6);
    list1.InsertAtBack(7.7);
    list1.InsertAtBack(3.3);

    lasd::Vector<double> vec2(vec1);

    {

        lasd::SetLst<double> setlst1(vec1);
        lasd::SetLst<double> setlst2(list1);

        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);

        lasd::SetLst<double> setlst3(std::move(vec1));
        lasd::SetLst<double> setlst4(std::move(list1));

        EqualSetLst(loctestnum, loctesterr, setlst3, setlst4, true);
        EqualSetLst(loctestnum, loctesterr, setlst1, setlst3, true);
        EqualSetLst(loctestnum, loctesterr, setlst2, setlst3, true);

        lasd::SetLst<double> setlst5(setlst1);
        lasd::SetLst<double> setlst6(std::move(setlst2));
        EqualSetLst(loctestnum, loctesterr, setlst5, setlst1, true);
        EqualSetLst(loctestnum, loctesterr, setlst6, setlst5, true);
    }

    {
        lasd::SetLst<double> setlst1;
        InsertSomeC(loctestnum, loctesterr, setlst1, true, vec1);
        lasd::SetLst<double> setlst2;
        InsertSomeM(loctestnum, loctesterr, setlst2, true, std::move(vec1));
        lasd::SetLst<double> setlst3;
        InsertAllC(loctestnum, loctesterr, setlst1, false, list1);
        lasd::SetLst<double> setlst4;
        InsertAllM(loctestnum, loctesterr, setlst2, false, std::move(list1));

        lasd::Vector<double> vec2(10);
        vec2[0] = 10.10;
        vec2[1] = 20.20;
        vec2[2] = 30.30;
        vec2[3] = 10.10;
        vec2[4] = 40.40;
        vec2[5] = 50.50;
        vec2[6] = 20.20;
        vec2[7] = 60.60;
        vec2[8] = 70.70;
        vec2[9] = 30.30;

        RemoveAll(loctestnum, loctesterr, setlst1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setlst1, true, setlst2);
    }

    {
        lasd::SetLst<double> setlst(vec2);
        Check_Min_Max_Set_Double(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<double> setlst(vec2);
        Check_PredecessorNSuccessor_Double_Set(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<double> setlst;
        Check_Insertion_Set_Double(setlst, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Char_SetLst(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<char> vec1(10);
    lasd::List<char> list1;

    vec1[0] = 'a';
    vec1[1] = 'b';
    vec1[2] = 'c';
    vec1[3] = 'a';
    vec1[4] = 'd';
    vec1[5] = 'e';
    vec1[6] = 'b';
    vec1[7] = 'f';
    vec1[8] = 'g';
    vec1[9] = 'c';

    list1.InsertAtBack('a');
    list1.InsertAtBack('b');
    list1.InsertAtBack('c');
    list1.InsertAtBack('a');
    list1.InsertAtBack('d');
    list1.InsertAtBack('e');
    list1.InsertAtBack('b');
    list1.InsertAtBack('f');
    list1.InsertAtBack('g');
    list1.InsertAtBack('c');

    lasd::Vector<char> vec2(vec1);
    {

        lasd::SetLst<char> setlst1(vec1);
        lasd::SetLst<char> setlst2(list1);

        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
        lasd::SetLst<char> setlst3(std::move(vec1));
        lasd::SetLst<char> setlst4(std::move(list1));

        EqualSetLst(loctestnum, loctesterr, setlst3, setlst4, true);
        EqualSetLst(loctestnum, loctesterr, setlst1, setlst3, true);
        EqualSetLst(loctestnum, loctesterr, setlst2, setlst3, true);

        lasd::SetLst<char> setlst5(setlst1);
        lasd::SetLst<char> setlst6(std::move(setlst2));
        EqualSetLst(loctestnum, loctesterr, setlst5, setlst1, true);
        EqualSetLst(loctestnum, loctesterr, setlst6, setlst5, true);
    }

    {
        lasd::SetLst<char> setlst1;
        InsertSomeC(loctestnum, loctesterr, setlst1, true, vec1);
        lasd::SetLst<char> setlst2;
        InsertSomeM(loctestnum, loctesterr, setlst2, true, std::move(vec1));
        lasd::SetLst<char> setlst3;
        InsertAllC(loctestnum, loctesterr, setlst1, false, list1);
        lasd::SetLst<char> setlst4;
        InsertAllM(loctestnum, loctesterr, setlst2, false, std::move(list1));

        lasd::Vector<char> vec2(10);

        vec2[0] = 'x';
        vec2[1] = 'y';
        vec2[2] = 'z';
        vec2[3] = 'x';
        vec2[4] = 'w';
        vec2[5] = 'v';
        vec2[6] = 'y';
        vec2[7] = 'u';
        vec2[8] = 't';
        vec2[9] = 'z';

        RemoveAll(loctestnum, loctesterr, setlst1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setlst1, true, setlst2);
    }

    {
        lasd::SetLst<char> setlst(vec2);
        Check_Min_Max_Set_Char(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<char> setlst(vec2);
        Check_PredecessorNSuccessor_Char_Set(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<char> setlst;
        Check_Insertion_Set_Char(setlst, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_String_SetLst(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<std::string> vec1(10);
    lasd::List<std::string> list1;

    vec1[0] = std::string("apple");
    vec1[1] = std::string("banana");
    vec1[2] = std::string("cherry");
    vec1[3] = std::string("apple");
    vec1[4] = std::string("date");
    vec1[5] = std::string("elderberry");
    vec1[6] = std::string("banana");
    vec1[7] = std::string("fig");
    vec1[8] = std::string("grape");
    vec1[9] = std::string("cherry");

    list1.InsertAtBack(std::string("apple"));
    list1.InsertAtBack(std::string("banana"));
    list1.InsertAtBack(std::string("cherry"));
    list1.InsertAtBack(std::string("apple"));
    list1.InsertAtBack(std::string("date"));
    list1.InsertAtBack(std::string("elderberry"));
    list1.InsertAtBack(std::string("banana"));
    list1.InsertAtBack(std::string("fig"));
    list1.InsertAtBack(std::string("grape"));
    list1.InsertAtBack(std::string("cherry"));

    lasd::Vector<std::string> vec2(vec1);

    {
        lasd::SetLst<std::string> setlst1(vec1);
        lasd::SetLst<std::string> setlst2(list1);

        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
        lasd::SetLst<std::string> setlst3(std::move(vec1));
        lasd::SetLst<std::string> setlst4(std::move(list1));

        EqualSetLst(loctestnum, loctesterr, setlst3, setlst4, true);
        EqualSetLst(loctestnum, loctesterr, setlst1, setlst3, true);
        EqualSetLst(loctestnum, loctesterr, setlst2, setlst3, true);

        lasd::SetLst<std::string> setlst5(setlst1);
        lasd::SetLst<std::string> setlst6(std::move(setlst2));
        EqualSetLst(loctestnum, loctesterr, setlst5, setlst1, true);
        EqualSetLst(loctestnum, loctesterr, setlst6, setlst5, true);
    }

    {
        lasd::SetLst<std::string> setlst1;
        InsertSomeC(loctestnum, loctesterr, setlst1, true, vec1);
        lasd::SetLst<std::string> setlst2;
        InsertSomeM(loctestnum, loctesterr, setlst2, true, std::move(vec1));
        lasd::SetLst<std::string> setlst3;
        InsertAllC(loctestnum, loctesterr, setlst1, false, list1);
        lasd::SetLst<std::string> setlst4;
        InsertAllM(loctestnum, loctesterr, setlst2, false, std::move(list1));

        lasd::Vector<std::string> vec2(10);

        vec2[0] = std::string("orange");
        vec2[1] = std::string("peach");
        vec2[2] = std::string("plum");
        vec2[3] = std::string("orange");
        vec2[4] = std::string("quince");
        vec2[5] = std::string("raspberry");
        vec2[6] = std::string("peach");
        vec2[7] = std::string("strawberry");
        vec2[8] = std::string("tangerine");
        vec2[9] = std::string("plum");

        RemoveAll(loctestnum, loctesterr, setlst1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setlst1, true, setlst2);
    }

    {
        lasd::SetLst<std::string> setlst(vec2);
        Check_Min_Max_Set_String(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<std::string> setlst(vec2);
        Check_PredecessorNSuccessor_String_Set(setlst, loctestnum, loctesterr);
    }

    {
        lasd::SetLst<std::string> setlst;
        Check_Insertion_Set_String(setlst, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Int_SetVec(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    lasd::Vector<int> vec1(10);
    lasd::List<int> list1;

    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;
    vec1[3] = 1;
    vec1[4] = 4;
    vec1[5] = 5;
    vec1[6] = 2;
    vec1[7] = 6;
    vec1[8] = 7;
    vec1[9] = 3;

    list1.InsertAtBack(1);
    list1.InsertAtBack(2);
    list1.InsertAtBack(3);
    list1.InsertAtBack(1);
    list1.InsertAtBack(4);
    list1.InsertAtBack(5);
    list1.InsertAtBack(2);
    list1.InsertAtBack(6);
    list1.InsertAtBack(7);
    list1.InsertAtBack(3);

    lasd::Vector<int> vec2(vec1);

    {

        lasd::SetVec<int> setvec1(vec1);
        lasd::SetVec<int> setvec2(list1);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        lasd::SetVec<int> setvec3(std::move(vec1));
        lasd::SetVec<int> setvec4(std::move(list1));

        EqualSetVec(loctestnum, loctesterr, setvec3, setvec4, true);
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, true);
        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, true);

        lasd::SetVec<int> setvec5(setvec1);
        lasd::SetVec<int> setvec6(std::move(setvec2));
        EqualSetVec(loctestnum, loctesterr, setvec5, setvec1, true);
        EqualSetVec(loctestnum, loctesterr, setvec6, setvec5, true);
    }

    {
        lasd::SetVec<int> setvec1;
        InsertSomeC(loctestnum, loctesterr, setvec1, true, vec1);
        lasd::SetVec<int> setvec2;
        InsertSomeM(loctestnum, loctesterr, setvec2, true, std::move(vec1));
        lasd::SetVec<int> setvec3;
        InsertAllC(loctestnum, loctesterr, setvec1, false, list1);
        lasd::SetVec<int> setvec4;
        InsertAllM(loctestnum, loctesterr, setvec2, false, std::move(list1));

        lasd::Vector<int> vec2(10);

        vec2[0] = 10;
        vec2[1] = 20;
        vec2[2] = 30;
        vec2[3] = 10;
        vec2[4] = 40;
        vec2[5] = 50;
        vec2[6] = 20;
        vec2[7] = 60;
        vec2[8] = 70;
        vec2[9] = 30;

        RemoveAll(loctestnum, loctesterr, setvec1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setvec1, true, setvec2);
    }

    {
        lasd::SetVec<int> setvec(vec2);
        Check_Min_Max_Set_Int(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<int> setvec(vec2);
        Check_PredecessorNSuccessor_Int_Set(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<int> setvec;
        Check_Insertion_Set_Int(setvec, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Double_SetVec(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    lasd::Vector<double> vec1(10);
    lasd::List<double> list1;

    vec1[0] = 1.1;
    vec1[1] = 2.2;
    vec1[2] = 3.3;
    vec1[3] = 1.1;
    vec1[4] = 4.4;
    vec1[5] = 5.5;
    vec1[6] = 2.2;
    vec1[7] = 6.6;
    vec1[8] = 7.7;
    vec1[9] = 3.3;

    list1.InsertAtBack(1.1);
    list1.InsertAtBack(2.2);
    list1.InsertAtBack(3.3);
    list1.InsertAtBack(1.1);
    list1.InsertAtBack(4.4);
    list1.InsertAtBack(5.5);
    list1.InsertAtBack(2.2);
    list1.InsertAtBack(6.6);
    list1.InsertAtBack(7.7);
    list1.InsertAtBack(3.3);

    lasd::Vector<double> vec2(vec1);

    {
        lasd::SetVec<double> setvec1(vec1);
        lasd::SetVec<double> setvec2(list1);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        lasd::SetVec<double> setvec3(std::move(vec1));
        lasd::SetVec<double> setvec4(std::move(list1));

        EqualSetVec(loctestnum, loctesterr, setvec3, setvec4, true);
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, true);
        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, true);

        lasd::SetVec<double> setvec5(setvec1);
        lasd::SetVec<double> setvec6(std::move(setvec2));
        EqualSetVec(loctestnum, loctesterr, setvec5, setvec1, true);
        EqualSetVec(loctestnum, loctesterr, setvec6, setvec5, true);
    }

    {
        lasd::SetVec<double> setvec1;
        InsertSomeC(loctestnum, loctesterr, setvec1, true, vec1);
        lasd::SetVec<double> setvec2;
        InsertSomeM(loctestnum, loctesterr, setvec2, true, std::move(vec1));
        lasd::SetVec<double> setvec3;
        InsertAllC(loctestnum, loctesterr, setvec1, false, list1);
        lasd::SetVec<double> setvec4;
        InsertAllM(loctestnum, loctesterr, setvec2, false, std::move(list1));

        lasd::Vector<double> vec2(10);

        vec2[0] = 10.10;
        vec2[1] = 20.20;
        vec2[2] = 30.30;
        vec2[3] = 10.10;
        vec2[4] = 40.40;
        vec2[5] = 50.50;
        vec2[6] = 20.20;
        vec2[7] = 60.60;
        vec2[8] = 70.70;
        vec2[9] = 30.30;

        RemoveAll(loctestnum, loctesterr, setvec1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setvec1, true, setvec2);
    }

    {
        lasd::SetVec<double> setvec(vec2);
        Check_Min_Max_Set_Double(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<double> setvec(vec2);
        Check_PredecessorNSuccessor_Double_Set(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<double> setvec;
        Check_Insertion_Set_Double(setvec, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_Char_SetVec(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<char> vec1(10);
    lasd::List<char> list1;

    vec1[0] = 'a';
    vec1[1] = 'b';
    vec1[2] = 'c';
    vec1[3] = 'a';
    vec1[4] = 'd';
    vec1[5] = 'e';
    vec1[6] = 'b';
    vec1[7] = 'f';
    vec1[8] = 'g';
    vec1[9] = 'c';

    list1.InsertAtBack('a');
    list1.InsertAtBack('b');
    list1.InsertAtBack('c');
    list1.InsertAtBack('a');
    list1.InsertAtBack('d');
    list1.InsertAtBack('e');
    list1.InsertAtBack('b');
    list1.InsertAtBack('f');
    list1.InsertAtBack('g');
    list1.InsertAtBack('c');

    lasd::Vector<char> vec2(vec1);

    {
        lasd::SetVec<char> setvec1(vec1);
        lasd::SetVec<char> setvec2(list1);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        lasd::SetVec<char> setvec3(std::move(vec1));
        lasd::SetVec<char> setvec4(std::move(list1));

        EqualSetVec(loctestnum, loctesterr, setvec3, setvec4, true);
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, true);
        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, true);

        lasd::SetVec<char> setvec5(setvec1);
        lasd::SetVec<char> setvec6(std::move(setvec2));
        EqualSetVec(loctestnum, loctesterr, setvec5, setvec1, true);
        EqualSetVec(loctestnum, loctesterr, setvec6, setvec5, true);
    }

    {
        lasd::SetVec<char> setvec1;
        InsertSomeC(loctestnum, loctesterr, setvec1, true, vec1);
        lasd::SetVec<char> setvec2;
        InsertSomeM(loctestnum, loctesterr, setvec2, true, std::move(vec1));
        lasd::SetVec<char> setvec3;
        InsertAllC(loctestnum, loctesterr, setvec1, false, list1);
        lasd::SetVec<char> setvec4;
        InsertAllM(loctestnum, loctesterr, setvec2, false, std::move(list1));

        lasd::Vector<char> vec2(10);
        vec2[0] = 'x';
        vec2[1] = 'y';
        vec2[2] = 'z';
        vec2[3] = 'x';
        vec2[4] = 'w';
        vec2[5] = 'v';
        vec2[6] = 'y';
        vec2[7] = 'u';
        vec2[8] = 't';
        vec2[9] = 'z';

        RemoveAll(loctestnum, loctesterr, setvec1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setvec1, true, setvec2);
    }

    {
        lasd::SetVec<char> setvec(vec2);
        Check_Min_Max_Set_Char(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<char> setvec(vec2);
        Check_PredecessorNSuccessor_Char_Set(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<char> setvec;
        Check_Insertion_Set_Char(setvec, loctestnum, loctesterr);
    }
    testnum += loctestnum;
    testerr += loctesterr;
}

void Personal_String_SetVec(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    lasd::Vector<std::string> vec1(10);
    lasd::List<std::string> list1;

    vec1[0] = std::string("apple");
    vec1[1] = std::string("banana");
    vec1[2] = std::string("cherry");
    vec1[3] = std::string("apple");
    vec1[4] = std::string("date");
    vec1[5] = std::string("elderberry");
    vec1[6] = std::string("banana");
    vec1[7] = std::string("fig");
    vec1[8] = std::string("grape");
    vec1[9] = std::string("cherry");

    list1.InsertAtBack(std::string("apple"));
    list1.InsertAtBack(std::string("banana"));
    list1.InsertAtBack(std::string("cherry"));
    list1.InsertAtBack(std::string("apple"));
    list1.InsertAtBack(std::string("date"));
    list1.InsertAtBack(std::string("elderberry"));
    list1.InsertAtBack(std::string("banana"));
    list1.InsertAtBack(std::string("fig"));
    list1.InsertAtBack(std::string("grape"));
    list1.InsertAtBack(std::string("cherry"));

    lasd::Vector<std::string> vec2(vec1);

    {
        lasd::SetVec<std::string> setvec1(vec1);
        lasd::SetVec<std::string> setvec2(list1);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        lasd::SetVec<std::string> setvec3(std::move(vec1));
        lasd::SetVec<std::string> setvec4(std::move(list1));

        EqualSetVec(loctestnum, loctesterr, setvec3, setvec4, true);
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec3, true);
        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, true);
        lasd::SetVec<std::string> setvec5(setvec1);
        lasd::SetVec<std::string> setvec6(std::move(setvec2));
        EqualSetVec(loctestnum, loctesterr, setvec5, setvec1, true);
        EqualSetVec(loctestnum, loctesterr, setvec6, setvec5, true);
    }

    {
        lasd::SetVec<std::string> setvec1;
        InsertSomeC(loctestnum, loctesterr, setvec1, true, vec1);
        lasd::SetVec<std::string> setvec2;
        InsertSomeM(loctestnum, loctesterr, setvec2, true, std::move(vec1));
        lasd::SetVec<std::string> setvec3;
        InsertAllC(loctestnum, loctesterr, setvec1, false, list1);
        lasd::SetVec<std::string> setvec4;
        InsertAllM(loctestnum, loctesterr, setvec2, false, std::move(list1));

        lasd::Vector<std::string> vec2(10);

        vec2[0] = std::string("orange");
        vec2[1] = std::string("peach");
        vec2[2] = std::string("plum");
        vec2[3] = std::string("orange");
        vec2[4] = std::string("quince");
        vec2[5] = std::string("raspberry");
        vec2[6] = std::string("peach");
        vec2[7] = std::string("strawberry");
        vec2[8] = std::string("tangerine");
        vec2[9] = std::string("plum");

        RemoveAll(loctestnum, loctesterr, setvec1, false, vec2);
        RemoveAll(loctestnum, loctesterr, setvec1, true, setvec2);
    }

    {
        lasd::SetVec<std::string> setvec(vec2);
        Check_Min_Max_Set_String(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<std::string> setvec(vec2);
        Check_PredecessorNSuccessor_String_Set(setvec, loctestnum, loctesterr);
    }

    {
        lasd::SetVec<std::string> setvec;
        Check_Insertion_Set_String(setvec, loctestnum, loctesterr);
    }
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
    Personal_Int_SetLst(loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of doubles>>\033[0m" << std::endl;
    Personal_Double_SetLst(loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of chars>>\033[0m" << std::endl;
    Personal_Char_SetLst(loctest, errtest);
    std::cout << "\033[4;36mEnd of SetLst<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetLst of strings>>\033[0m" << std::endl;
    Personal_String_SetLst(loctest, errtest);
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
    Personal_Int_SetVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetVec of doubles>>\033[0m" << std::endl;
    lasd::SetVec<double> sv2;
    Personal_Double_SetVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetVec of chars>>\033[0m" << std::endl;
    lasd::SetVec<char> sv3;
    Personal_Char_SetVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of SetVec<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing SetVec of strings>>\033[0m" << std::endl;
    Personal_String_SetVec(loctest, errtest);
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

void SetLstTestMenu()
{
    lasd::SetLst<int> setlst;
    uint choice = 0;
    do
    {
        std::cout << "\n\033[1;34mSelect an operation:\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\33[1;33m\t1 :\033[0m Print set\n";
        std::cout << "\33[1;33m\t2 :\033[0m Insert an element\n";
        std::cout << "\33[1;33m\t3 :\033[0m Remove an element\n";
        std::cout << "\33[1;33m\t4 :\033[0m Check if an element exists\n";
        std::cout << "\33[1;33m\t5 :\033[0m Find minimum element\n";
        std::cout << "\33[1;33m\t6 :\033[0m Find maximum element\n";
        std::cout << "\33[1;33m\t7 :\033[0m Find predecessor of an element\n";
        std::cout << "\33[1;33m\t8 :\033[0m Find successor of an element\n";
        std::cout << "\33[1;33m\t9 :\033[0m Remove minimum element\n";
        std::cout << "\33[1;33m\t10:\033[0m Remove maximum element\n";
        std::cout << "\33[1;33m\t11:\033[0m Remove predecessor of an element\n";
        std::cout << "\33[1;33m\t12:\033[0m Remove successor of an element\n";
        std::cout << "\33[1;33m\t13:\033[0m Clear the set\n";
        std::cout << "\33[1;33m\t14:\033[0m Find predecessor of and element and delete it\n";
        std::cout << "\33[1;33m\t15:\033[0m Find successor of and element and delete it\n";
        std::cout << "\33[1;33m\t16:\033[0m Print vector\n";
        std::cout << "\33[1;33m\t0 :\033[0m Exit\n";

        do
        {
            std::cout << "\n\033[1;34mChoice:\033[0m ";
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                choice = -1;
            }
            if (choice < 0 || choice > 15)
            {
                std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 3.\033[0m" << std::endl;
            }
        } while (choice < 0 || choice > 15);

        switch (choice)
        {
        case 1:
            std::cout << "\n Printing set: ";
            try{
                setlst.Traverse(TraversePrint<int>);
                std::cout << std::endl;
            }catch(std::exception & exc){
                std::cout << exc.what() << std::endl;
            }
            break;
        case 2:
            int element;
            std::cout << "\n Enter element to insert: ";
            std::cin >> element;
            if (setlst.Insert(element))
            {
                std::cout << "\n Element inserted successfully." << std::endl;
            }
            else
            {
                std::cout << "\n Element already exists in the set." << std::endl;
            }
            break;
        case 3:
            int elementToRemove;
            std::cout << "\n Enter element to remove: ";
            std::cin >> elementToRemove;
            if (setlst.Remove(elementToRemove))
            {
                std::cout << "\n Element removed successfully." << std::endl;
            }
            else
            {
                std::cout << "\n Element not found in the set." << std::endl;
            }
            break;
        case 4:
            int elementToCheck;
            std::cout << "\n Enter element to check: ";
            std::cin >> elementToCheck;
            if (setlst.Exists(elementToCheck))
            {
                std::cout << "\n Element exists in the set." << std::endl;
            }
            else
            {
                std::cout << "\n Element does not exist in the set." << std::endl;
            }
            break;
        case 5:
            try
            {
                std::cout << "\n Minimum element: " << setlst.Min() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 6:
            try
            {
                std::cout << "\n Maximum element: " << setlst.Max() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }


            break;
        case 7:
            int elementForPredecessor;
            std::cout << "\n Enter element to find predecessor: ";
            std::cin >> elementForPredecessor;
            try
            {
                std::cout << "\n Predecessor of " << elementForPredecessor << ": " << setlst.Predecessor(elementForPredecessor) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 8:
            int elementForSuccessor;
            std::cout << "\n Enter element to find successor: ";
            std::cin >> elementForSuccessor;
            try
            {
                std::cout << "\n Successor of " << elementForSuccessor << ": " << setlst.Successor(elementForSuccessor) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 9:
            try
            {
                std::cout << "\n Removing minimum element: "  << std::endl;
                setlst.RemoveMin();
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }
            break;
        case 10:
            try
            {
                std::cout << "\n Removing maximum element: " << std::endl;
                setlst.RemoveMax();
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }
            break;
        case 11:
            int elementForRemovePredecessor;
            std::cout << "\n Enter element to remove predecessor: ";
            std::cin >> elementForRemovePredecessor;
            try
            {
                std::cout << "\n Removing predecessor of " << elementForRemovePredecessor << std::endl;
                setlst.RemovePredecessor(elementForRemovePredecessor);

            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 12:
            int elementForRemoveSuccessor;
            std::cout << "\n Enter element to remove successor: ";
            std::cin >> elementForRemoveSuccessor;
            try
            {
                std::cout << "\n Removing successor of " << elementForRemoveSuccessor << std::endl;
                setlst.RemoveSuccessor(elementForRemoveSuccessor);
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 13:
            setlst.Clear();
            std::cout << "\n Set cleared." << std::endl;
            break;
        case 14:
            int elementForRemovePredecessorAndDelete;
            std::cout << "\n Enter element to remove predecessor and delete: ";
            std::cin >> elementForRemovePredecessorAndDelete;
            try
            {
                std::cout << "\n Removing predecessor of " << elementForRemovePredecessorAndDelete << " and deleting it: " << setlst.PredecessorNRemove(elementForRemovePredecessorAndDelete) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 15:
            int elementForRemoveSuccessorAndDelete;
            std::cout << "\n Enter element to remove successor and delete: ";
            std::cin >> elementForRemoveSuccessorAndDelete;
            try
            {
                std::cout << "\n Removing successor of " << elementForRemoveSuccessorAndDelete << " and deleting it: " << setlst.SuccessorNRemove(elementForRemoveSuccessorAndDelete) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }
            break;
        case 0:
            std::cout << "Exiting...Goodbye!" << std::endl;
            break;
        }
    } while (choice != 0);
}

void SetVecTestMenu()
{
    lasd::SetVec<int> setvec;
    uint choice = 0;
    do
    {
        std::cout << "\n\033[1;34mSelect an operation:\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\33[1;33m\t1 :\033[0m Print set\n";
        std::cout << "\33[1;33m\t2 :\033[0m Insert an element\n";
        std::cout << "\33[1;33m\t3 :\033[0m Remove an element\n";
        std::cout << "\33[1;33m\t4 :\033[0m Check if an element exists\n";
        std::cout << "\33[1;33m\t5 :\033[0m Find minimum element\n";
        std::cout << "\33[1;33m\t6 :\033[0m Find maximum element\n";
        std::cout << "\33[1;33m\t7 :\033[0m Find predecessor of an element\n";
        std::cout << "\33[1;33m\t8 :\033[0m Find successor of an element\n";
        std::cout << "\33[1;33m\t9 :\033[0m Remove minimum element\n";
        std::cout << "\33[1;33m\t10:\033[0m Remove maximum element\n";
        std::cout << "\33[1;33m\t11:\033[0m Remove predecessor of an element\n";
        std::cout << "\33[1;33m\t12:\033[0m Remove successor of an element\n";
        std::cout << "\33[1;33m\t13:\033[0m Clear the set\n";
        std::cout << "\33[1;33m\t14:\033[0m Find predecessor of and element and delete it\n";
        std::cout << "\33[1;33m\t15:\033[0m Find successor of and element and delete it\n";
        std::cout << "\33[1;33m\t16:\033[0m Print vector\n";
        std::cout << "\33[1;33m\t0 :\033[0m Exit\n";

        do
        {
            std::cout << "\n\033[1;34mChoice:\033[0m ";
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                choice = -1;
            }
            if (choice < 0 || choice > 16)
            {
                std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 16.\033[0m" << std::endl;
            }
        } while (choice < 0 || choice > 16);

        switch (choice)
        {
        case 1:
            std::cout << "\n Printing set: ";
            try{
                setvec.Traverse(TraversePrint<int>);
                std::cout << std::endl;
            }catch(std::exception & exc){
                std::cout << exc.what() << std::endl;
            }
            break;
        case 2:
            int element;
            std::cout << "\n Enter element to insert: ";
            std::cin >> element;
            if (setvec.Insert(element))
            {
                std::cout << "\n Element inserted successfully." << std::endl;
            }
            else
            {
                std::cout << "\n Element already exists in the set." << std::endl;
            }
            break;
        case 3:
            int elementToRemove;
            std::cout << "\n Enter element to remove: ";
            std::cin >> elementToRemove;
            if (setvec.Remove(elementToRemove))
            {
                std::cout << "\n Element removed successfully." << std::endl;
            }
            else
            {
                std::cout << "\n Element not found in the set." << std::endl;
            }
            break;
        case 4:
            int elementToCheck;
            std::cout << "\n Enter element to check: ";
            std::cin >> elementToCheck;
            if (setvec.Exists(elementToCheck))
            {
                std::cout << "\n Element exists in the set." << std::endl;
            }
            else
            {
                std::cout << "\n Element does not exist in the set." << std::endl;
            }
            break;
        case 5:
            try
            {
                std::cout << "\n Minimum element: " << setvec.Min() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 6:
            try
            {
                std::cout << "\n Maximum element: " << setvec.Max() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }


            break;
        case 7:
            int elementForPredecessor;
            std::cout << "\n Enter element to find predecessor: ";
            std::cin >> elementForPredecessor;
            try
            {
                std::cout << "\n Predecessor of " << elementForPredecessor << ": " << setvec.Predecessor(elementForPredecessor) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 8:
            int elementForSuccessor;
            std::cout << "\n Enter element to find successor: ";
            std::cin >> elementForSuccessor;
            try
            {
                std::cout << "\n Successor of " << elementForSuccessor << ": " << setvec.Successor(elementForSuccessor) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 9:
            try
            {
                std::cout << "\n Removing minimum element: "  << std::endl;
                setvec.RemoveMin();
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }
            break;
        case 10:
            try
            {
                std::cout << "\n Removing maximum element: " << std::endl;
                setvec.RemoveMax();
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }
            break;
        case 11:
            int elementForRemovePredecessor;
            std::cout << "\n Enter element to remove predecessor: ";
            std::cin >> elementForRemovePredecessor;
            try
            {
                std::cout << "\n Removing predecessor of " << elementForRemovePredecessor << std::endl;
                setvec.RemovePredecessor(elementForRemovePredecessor);

            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 12:
            int elementForRemoveSuccessor;
            std::cout << "\n Enter element to remove successor: ";
            std::cin >> elementForRemoveSuccessor;
            try
            {
                std::cout << "\n Removing successor of " << elementForRemoveSuccessor << std::endl;
                setvec.RemoveSuccessor(elementForRemoveSuccessor);
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 13:
            setvec.Clear();
            std::cout << "\n Set cleared." << std::endl;
            break;
        case 14:
            int elementForRemovePredecessorAndDelete;
            std::cout << "\n Enter element to remove predecessor and delete: ";
            std::cin >> elementForRemovePredecessorAndDelete;
            try
            {
                std::cout << "\n Removing predecessor of " << elementForRemovePredecessorAndDelete << " and deleting it: " << setvec.PredecessorNRemove(elementForRemovePredecessorAndDelete) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }

            break;
        case 15:
            int elementForRemoveSuccessorAndDelete;
            std::cout << "\n Enter element to remove successor and delete: ";
            std::cin >> elementForRemoveSuccessorAndDelete;
            try
            {
                std::cout << "\n Removing successor of " << elementForRemoveSuccessorAndDelete << " and deleting it: " << setvec.SuccessorNRemove(elementForRemoveSuccessorAndDelete) << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\n Error: " << e.what() << std::endl;
            }
            break;
        case 16:
            std::cout << "\n Printing vector: ";
            setvec.PrintVector();
            break;
        case 0:
            std::cout << "Exiting...Goodbye!" << std::endl;
            break;
        }
    } while (choice != 0);
}
