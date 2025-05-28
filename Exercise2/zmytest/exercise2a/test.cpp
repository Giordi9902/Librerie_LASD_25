#include <iostream>
#include "../../heap/vec/heapvec.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../vector/vector.hpp"

void HeapVecTestMenu()
{
    lasd::Vector<int> vec(12);
    vec[0] = 45;
    vec[1] = 34;
    vec[2] = 28;
    vec[3] = 30;
    vec[4] = 25;
    vec[5] = 22;
    vec[6] = 12;
    vec[7] = 14;
    vec[8] = 21;
    vec[9] = 15;
    vec[10] = 16;
    vec[11] = 20;
    lasd::HeapVec<int> hp1(vec);
    if(hp1.IsHeap()){
        std::cout << "It's a heap!\n";
    }else{
        std::cout << "It's not a heap!\n";
    }
    std::cout  << "HeapVec elements: ";
    hp1.Traverse(TraversePrint<int>);
    // std::cout << std::endl;
    // hp1.Heapify();
    // if(hp1.IsHeap()){
    //     std::cout << "It's a heap!\n";
    // }else{
    //     std::cout << "It's not a heap!\n";
    // }
    // std::cout  << "HeapVec elements: ";
    // hp1.Traverse(TraversePrint<int>);
    std::cout << std::endl;
}