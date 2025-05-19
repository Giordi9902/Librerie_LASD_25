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
#include <random>

using namespace std;

void Check_Insertion_Set_Int(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    InsertC(loctestnum,loctesterr,set,true,4);
    InsertC(loctestnum,loctesterr,set,true,1);
    InsertC(loctestnum,loctesterr,set,true,2);
    InsertC(loctestnum,loctesterr,set,true,3);
    InsertC(loctestnum,loctesterr,set,false,4);
    InsertC(loctestnum,loctesterr,set,true,5);
    InsertC(loctestnum,loctesterr,set,true,6);
    InsertC(loctestnum,loctesterr,set,true,7);
    Remove(loctestnum,loctesterr,set,true,1);
    Remove(loctestnum,loctesterr,set,true,2);
    Remove(loctestnum,loctesterr,set,true,3);
    Remove(loctestnum,loctesterr,set,true,4);
    Remove(loctestnum,loctesterr,set,true,5);
    Remove(loctestnum,loctesterr,set,true,6);
    Remove(loctestnum,loctesterr,set,true,7);
    Remove(loctestnum,loctesterr,set,false,8);
    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Insertion_Set_Double(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    InsertC(loctestnum,loctesterr,set,true,4.4);
    InsertC(loctestnum,loctesterr,set,true,1.1);
    InsertC(loctestnum,loctesterr,set,true,2.2);
    InsertC(loctestnum,loctesterr,set,true,3.3);
    InsertC(loctestnum,loctesterr,set,false,4.4);
    InsertC(loctestnum,loctesterr,set,true,5.5);
    InsertC(loctestnum,loctesterr,set,true,6.6);
    InsertC(loctestnum,loctesterr,set,true,7.7);
    Remove(loctestnum,loctesterr,set,true,1.1);
    Remove(loctestnum,loctesterr,set,true,2.2);
    Remove(loctestnum,loctesterr,set,true,3.3);
    Remove(loctestnum,loctesterr,set,true,4.4);
    Remove(loctestnum,loctesterr,set,true,5.5);
    Remove(loctestnum,loctesterr,set,true,6.6);
    Remove(loctestnum,loctesterr,set,true,7.7);
    Remove(loctestnum,loctesterr,set,false,8.8);

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Insertion_Set_Char(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    InsertC(loctestnum,loctesterr,set,true,'d');
    InsertC(loctestnum,loctesterr,set,true,'a');
    InsertC(loctestnum,loctesterr,set,true,'b');
    InsertC(loctestnum,loctesterr,set,true,'c');
    InsertC(loctestnum,loctesterr,set,false,'d');
    InsertC(loctestnum,loctesterr,set,true,'e');
    InsertC(loctestnum,loctesterr,set,true,'f');
    InsertC(loctestnum,loctesterr,set,true,'g');
    Remove(loctestnum,loctesterr,set,true,'a');
    Remove(loctestnum,loctesterr,set,true,'b');
    Remove(loctestnum,loctesterr,set,true,'c');
    Remove(loctestnum,loctesterr,set,true,'d');
    Remove(loctestnum,loctesterr,set,true,'e');
    Remove(loctestnum,loctesterr,set,true,'f');
    Remove(loctestnum,loctesterr,set,true,'g');
    Remove(loctestnum,loctesterr,set,false,'h');


    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Insertion_Set_String(lasd::Set<std::string> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    InsertC(loctestnum,loctesterr,set,true,std::string("date"));
    InsertC(loctestnum,loctesterr,set,true,std::string("apple"));
    InsertC(loctestnum,loctesterr,set,true,std::string("banana"));
    InsertC(loctestnum,loctesterr,set,true,std::string("cherry"));
    InsertC(loctestnum,loctesterr,set,false,std::string("date"));
    InsertC(loctestnum,loctesterr,set,true,std::string("elderberry"));
    InsertC(loctestnum,loctesterr,set,true,std::string("fig"));
    InsertC(loctestnum,loctesterr,set,true,std::string("grape"));
    Remove(loctestnum,loctesterr,set,true,std::string("apple"));
    Remove(loctestnum,loctesterr,set,true,std::string("banana"));
    Remove(loctestnum,loctesterr,set,true,std::string("cherry"));
    Remove(loctestnum,loctesterr,set,true,std::string("date"));
    Remove(loctestnum,loctesterr,set,true,std::string("elderberry"));
    Remove(loctestnum,loctesterr,set,true,std::string("fig"));
    Remove(loctestnum,loctesterr,set,true,std::string("grape"));
    Remove(loctestnum,loctesterr,set,false,std::string("honeydew"));

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Min_Max_Set_Int(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    Min(loctestnum, loctesterr, set, true, 1);
    Max(loctestnum, loctesterr, set, true, 7);
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, 2);
    Max(loctestnum, loctesterr, set, true, 6);
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, 3);
    Max(loctestnum, loctesterr, set, true, 5);
    MinNRemove(loctestnum, loctesterr, set, true, 3);
    MaxNRemove(loctestnum, loctesterr, set, true, 5);
    Min(loctestnum, loctesterr, set, true, 4);
    Max(loctestnum, loctesterr, set, true, 4);

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Min_Max_Set_Double(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    Min(loctestnum, loctesterr, set, true, 1.1);
    Max(loctestnum, loctesterr, set, true, 7.7);
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, 2.2);
    Max(loctestnum, loctesterr, set, true, 6.6);
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, 3.3);
    Max(loctestnum, loctesterr, set, true, 5.5);
    MinNRemove(loctestnum, loctesterr, set, true, 3.3);
    MaxNRemove(loctestnum, testerr, set, true, 5.5);
    Min(loctestnum, testerr, set, true, 4.4);
    Max(loctestnum, testerr, set, true, 4.4);

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Min_Max_Set_Char(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    Min(loctestnum, loctesterr, set, true, 'a');
    Max(loctestnum, loctesterr, set, true, 'g');
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, 'b');
    Max(loctestnum, loctesterr, set, true, 'f');
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, 'c');
    Max(loctestnum, loctesterr, set, true, 'e');
    MinNRemove(loctestnum, loctesterr, set, true, 'c');
    MaxNRemove(loctestnum, loctesterr, set, true, 'e');
    Min(loctestnum, loctesterr, set, true, 'd');
    Max(loctestnum, loctesterr, set, true, 'd');

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_Min_Max_Set_String(lasd::Set<std::string> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    Min(loctestnum, loctesterr, set, true, std::string("apple"));
    Max(loctestnum, loctesterr, set, true, std::string("grape"));
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, std::string("banana"));
    Max(loctestnum, loctesterr, set, true, std::string("fig"));
    RemoveMax(loctestnum, loctesterr, set, true);
    RemoveMin(loctestnum, loctesterr, set, true);
    Min(loctestnum, loctesterr, set, true, std::string("cherry"));
    Max(loctestnum, loctesterr, set, true, std::string("elderberry"));
    MinNRemove(loctestnum, loctesterr, set, true, std::string("cherry"));
    MaxNRemove(loctestnum, loctesterr, set, true, std::string("elderberry"));
    Min(loctestnum, loctesterr, set, true, std::string("date"));
    Max(loctestnum, loctesterr, set, true, std::string("date"));

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_PredecessorNSuccessor_Int_Set(lasd::Set<int> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    Predecessor(loctestnum, loctesterr, set, false, 1, 3);
    Predecessor(loctestnum, loctesterr, set, true, 2, 1);
    Predecessor(loctestnum, loctesterr, set, true, 3, 2);
    Predecessor(loctestnum, loctesterr, set, true, 4, 3);
    Predecessor(loctestnum, loctesterr, set, true, 5, 4);
    Predecessor(loctestnum, loctesterr, set, true, 6, 5);
    Predecessor(loctestnum, loctesterr, set, true, 7, 6);
    Predecessor(loctestnum, loctesterr, set, true, 8, 7);
    Predecessor(loctestnum, loctesterr, set, true, 9, 7);
    Successor(loctestnum, loctesterr, set, true, 0, 1);
    Successor(loctestnum, loctesterr, set, true, 1, 2);
    Successor(loctestnum, loctesterr, set, true, 2, 3);
    Successor(loctestnum, loctesterr, set, true, 3, 4);
    Successor(loctestnum, loctesterr, set, true, 5, 6);
    Successor(loctestnum, loctesterr, set, false, 7, 1);
    // 1 2 3 4 5 6 7
    PredecessorNRemove(loctestnum, loctesterr, set, false, 1, 1);
    PredecessorNRemove(loctestnum, loctesterr, set, true, 2, 1);
    // 2 3 4 5 6 7
    Predecessor(loctestnum, loctesterr, set, false, 2, 3);
    RemovePredecessor(loctestnum, loctesterr, set, false, 2);
    RemoveSuccessor(loctestnum, loctesterr, set, true, 2);
    // 2 4 5 6 7
    SuccessorNRemove(loctestnum, loctesterr, set, false, 7, 3);
    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_PredecessorNSuccessor_Double_Set(lasd::Set<double> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    Predecessor(loctestnum, loctesterr, set, false, 1.1, 3.3);
    Predecessor(loctestnum, loctesterr, set, true, 2.2, 1.1);
    Predecessor(loctestnum, loctesterr, set, true, 3.3, 2.2);
    Predecessor(loctestnum, loctesterr, set, true, 4.4, 3.3);
    Predecessor(loctestnum, loctesterr, set, true, 5.5, 4.4);
    Predecessor(loctestnum, loctesterr, set, true, 6.6, 5.5);
    Predecessor(loctestnum, loctesterr, set, true, 7.7, 6.6);
    Predecessor(loctestnum, loctesterr, set, true, 8.8, 7.7);
    Predecessor(loctestnum, loctesterr, set, true, 9.9, 7.7);
    Successor(loctestnum, loctesterr, set, true, 0.0, 1.1);
    Successor(loctestnum, loctesterr, set, true, 1.1, 2.2);
    Successor(loctestnum, loctesterr, set, true, 2.2, 3.3);
    Successor(loctestnum, loctesterr, set, true, 3.3, 4.4);
    Successor(loctestnum, loctesterr, set, true, 5.5, 6.6);
    Successor(loctestnum, loctesterr, set, false, 7.7, 1.1);
    // 1.1 2.2 3.3 4.4 5.5 6.6 7.7
    PredecessorNRemove(loctestnum, loctesterr, set, false, 1.1, 1.1);
    PredecessorNRemove(loctestnum, loctesterr, set, true, 2.2, 1.1);
    // 2.2 3.3 4.4 5.5 6.6 7.7
    Predecessor(loctestnum, loctesterr, set, false, 2.2, 3.3);
    RemovePredecessor(loctestnum, loctesterr, set, false, 2.2);
    RemoveSuccessor(loctestnum, loctesterr, set, true, 2.2);
    // 2.2 4.4 5.5 6.6 7.7
    SuccessorNRemove(loctestnum, loctesterr, set, false, 7.7, 3.3);
    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_PredecessorNSuccessor_Char_Set(lasd::Set<char> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    Predecessor(loctestnum, loctesterr, set, false, 'a', 'c');
    Predecessor(loctestnum, loctesterr, set, true, 'b', 'a');
    Predecessor(loctestnum, loctesterr, set, true, 'c', 'b');
    Predecessor(loctestnum, loctesterr, set, true, 'd', 'c');
    Predecessor(loctestnum, loctesterr, set, true, 'e', 'd');
    Predecessor(loctestnum, loctesterr, set, true, 'f', 'e');
    Predecessor(loctestnum, loctesterr, set, true, 'g', 'f');
    Predecessor(loctestnum, loctesterr, set, true, 'h', 'g');
    Predecessor(loctestnum, loctesterr, set, true, 'i', 'g');
    Successor(loctestnum, loctesterr, set, true, '`', 'a');
    Successor(loctestnum, loctesterr, set, true, 'a', 'b');
    Successor(loctestnum, loctesterr, set, true, 'b', 'c');
    Successor(loctestnum, loctesterr, set, true, 'c', 'd');
    Successor(loctestnum, loctesterr, set, true, 'e', 'f');
    Successor(loctestnum, loctesterr, set, false, 'g', 'a');
    // a b c d e f g
    PredecessorNRemove(loctestnum, loctesterr, set, false, 'a', 'a');
    PredecessorNRemove(loctestnum, loctesterr, set, true, 'b', 'a');
    // b c d e f g
    Predecessor(loctestnum, loctesterr, set, false, 'b', 'c');
    RemovePredecessor(loctestnum, loctesterr, set, false, 'b');
    RemoveSuccessor(loctestnum, loctesterr, set, true, 'b');
    // b d e f g
    SuccessorNRemove(loctestnum, loctesterr, set, false, 'g', 'c');

    testnum += loctestnum;
    testerr += loctesterr;
}

void Check_PredecessorNSuccessor_String_Set(lasd::Set<std::string> &set, uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;

    Predecessor(loctestnum, loctesterr, set, false, std::string("apple"), std::string("cherry"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("banana"), std::string("apple"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("cherry"), std::string("banana"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("date"), std::string("cherry"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("elderberry"), std::string("date"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("fig"), std::string("elderberry"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("grape"), std::string("fig"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("honeydew"), std::string("grape"));
    Predecessor(loctestnum, loctesterr, set, true, std::string("kiwi"), std::string("grape"));
    Successor(loctestnum, loctesterr, set, true, std::string(""), std::string("apple"));
    Successor(loctestnum, loctesterr, set, true, std::string("apple"), std::string("banana"));
    Successor(loctestnum, loctesterr, set, true, std::string("banana"), std::string("cherry"));
    Successor(loctestnum, loctesterr, set, true, std::string("cherry"), std::string("date"));
    Successor(loctestnum, loctesterr, set, true, std::string("elderberry"), std::string("fig"));
    Successor(loctestnum, loctesterr, set, false, std::string("grape"), std::string("apple"));
    // apple banana cherry date elderberry fig grape
    PredecessorNRemove(loctestnum, loctesterr, set, false, std::string("apple"), std::string("apple"));
    PredecessorNRemove(loctestnum, loctesterr, set, true, std::string("banana"), std::string("apple"));
    // banana cherry date elderberry fig grape
    Predecessor(loctestnum, loctesterr, set, false, std::string("banana"), std::string("cherry"));
    RemovePredecessor(loctestnum, loctesterr, set, false, std::string("banana"));
    RemoveSuccessor(loctestnum, loctesterr, set, true, std::string("banana"));
    // banana date elderberry fig grape
    SuccessorNRemove(loctestnum, loctesterr, set, false, std::string("grape"), std::string("cherry"));

    testnum += loctestnum;
    testerr += loctesterr;
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