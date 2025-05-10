#ifndef MYTRAVERSABLE_HPP
#define MYTRAVERSABLE_HPP
#include "../../container/traversable.hpp"
#include <cmath>

template <typename Data, typename Value>
void FoldDouble(uint &testnum, uint &testerr, lasd::TraversableContainer<Data> &con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value &inival, const Value &finval, const Value &eps)
{
    bool tst;
    testnum++;
    try
    {
        std::cout << " " << testnum << " (" << testerr << ") Executing fold - ";
        Value val = con.Fold(fun, inival);
        std::cout << "obtained value is \"" << val << "\": ";
        tst = (std::abs(val - finval) < eps);
        std::cout << ((tst == chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    catch (std::exception &exc)
    {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint)tst);
};

template <typename Data, typename Value>
void PostOrderFoldDouble(uint &testnum, uint &testerr, lasd::PostOrderTraversableContainer<Data> &con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value &inival, const Value &finval, const Value &eps)
{
    bool tst;
    testnum++;
    try
    {
        std::cout << " " << testnum << " (" << testerr << ") Executing fold in PostOrder - ";
        Value val = con.PostOrderFold(fun, inival);
        std::cout << "obtained value is \"" << val << "\": ";
        tst = (std::abs(val - finval) < eps);
        std::cout << ((tst == chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    catch (std::exception &exc)
    {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint)tst);
};

template <typename Data, typename Value>
void PreOrderFoldDouble(uint &testnum, uint &testerr, lasd::PreOrderTraversableContainer<Data> &con, bool chk, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value &inival, const Value &finval, const Value &eps)
{
    bool tst;
    testnum++;
    try
    {
        std::cout << " " << testnum << " (" << testerr << ") Executing fold in PreOrder - ";
        Value val = con.PreOrderFold(fun, inival);
        std::cout << "obtained value is \"" << val << "\": ";
        tst = (std::abs(val - finval) < eps);
        std::cout << ((tst == chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    catch (std::exception &exc)
    {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint)tst);
};

#endif