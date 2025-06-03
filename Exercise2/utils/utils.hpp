#ifndef MYUTILS_HPP
#define MYUTILS_HPP

#include <iostream>
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"

#include "../zlasdtest/container/traversable.hpp"
#include "../zlasdtest/container/mappable.hpp"

#include <limits>



void PrintHeader();
void PrintPersonalTestHeader();
void finalGreet();
void wait();
void clean();

template <typename Data>
Data FoldMin(const Data& elem, const Data& acc)
{
    return std::min(elem, acc);
}

template <typename Data>
Data FoldMax(const Data& elem, const Data& acc)
{
    return std::max(elem, acc);
}

void FoldFunctionsMenuTest(lasd::TraversableContainer<int>&);
void MapFunctionsMenuTest(lasd::MappableContainer<int>&);

#endif