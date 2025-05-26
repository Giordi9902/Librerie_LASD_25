#ifndef MYTRAVERSABLE_HPP
#define MYTRAVERSABLE_HPP
#include "../../container/traversable.hpp"
#include "../../set/lst/setlst.hpp"
#include <cmath>
#include <algorithm>

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

bool LowerCaseVectorFold(const char &c, const bool &acc)
{
    return acc && std::islower(static_cast<unsigned char>(c));
}

std::string ConcatCharFold(const char &c, const std::string &acc)
{
    return acc + c;
}

unsigned int VowelCountFold(const char &c, const unsigned int &acc)
{
    return acc + (std::string("aeiouAEIOU").find(c) != std::string::npos ? 1 : 0);
}

unsigned int AsciiSumFold(const char &c, const unsigned int &acc)
{
    return acc + static_cast<unsigned int>(c);
}

unsigned int UppercaseCountFold(const char &c, const unsigned int &acc)
{
    return acc + (std::isupper(static_cast<unsigned char>(c)) ? 1 : 0);
}

bool AllDigitsFold(const char &c, const bool &acc)
{
    return acc && std::isdigit(static_cast<unsigned char>(c));
}

lasd::SetLst<char> UniqueCharFold(const char &c, const lasd::SetLst<char> &acc)
{
    lasd::SetLst<char> set = acc;
    set.Insert(c);
    return set;
}

unsigned int TotalLength(const std::string &str, const unsigned int &acc)
{
    return acc + str.length();
}

unsigned int CountAllUpper(const std::string &str, const unsigned int &acc)
{
    bool is_all_upper = !str.empty() &&
                        std::all_of(str.begin(), str.end(),
                                    [](char c)
                                    { return std::isupper(static_cast<unsigned char>(c)); });
    return acc + (is_all_upper ? 1 : 0);
}

bool AllNonEmpty(const std::string &str, const bool &acc)
{
    return acc && !str.empty();
}

lasd::SetLst<std::string> UniqueStrings(const std::string &str, const lasd::SetLst<std::string> &acc)
{
    lasd::SetLst<std::string> result = acc;
    result.Insert(str);
    return result;
}

#endif