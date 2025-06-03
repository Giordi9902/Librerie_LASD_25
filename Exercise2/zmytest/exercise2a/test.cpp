#include <iostream>
#include <limits>
#include <string>
#include "../../heap/vec/heapvec.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"
#include "../../zlasdtest/heap/heap.hpp"
#include "../../utils/utils.hpp"

void HeapVecTestMenu()
{
    lasd::HeapVec<int> heap;
    uint choice = 0;
    do
    {
        std::cout << "\n\033[1;34mSelect an operation:\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\33[1;33m\t1 :\033[0m Generate random vector and create a new heap\n";
        std::cout << "\33[1;33m\t2 :\033[0m Print the heap\n";
        std::cout << "\33[1;33m\t3 :\033[0m Check if the heap is valid\n";
        std::cout << "\33[1;33m\t4 :\033[0m Heapify vector\n";
        std::cout << "\33[1;33m\t5 :\033[0m Sort the heap\n";
        std::cout << "\33[1;33m\t6 :\033[0m Clear the heap\n";
        std::cout << "\33[1;33m\t7 :\033[0m Apply fold function\n";
        std::cout << "\33[1;33m\t8 :\033[0m Apply map function\n";
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
            if (choice < 0 || choice > 8)
            {
                std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 8.\033[0m" << std::endl;
            }
        } while (choice < 0 || choice > 8);

        switch (choice)
        {
        case 1:
        {
            std::cout << "\033[1;32mGenerating random vector and creating a new heap...\033[0m" << std::endl;
            lasd::Vector<int> vec(10);
            for (ulong i = 0; i < vec.Size(); ++i)
            {
                vec[i] = rand() % 100;
            }
            heap = lasd::HeapVec<int>(vec);
            std::cout << "Heap created successfully." << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "\033[1;32mPrinting the heap:\033[0m" << std::endl;
            heap.Traverse(TraversePrint<int>);
            break;
        }
        case 3:
        {
            std::cout << "\033[1;32mChecking if the heap is valid...\033[0m" << std::endl;
            if (heap.IsHeap())
            {
                std::cout << "The heap is valid." << std::endl;
            }
            else
            {
                std::cout << "The heap is not valid." << std::endl;
            }
            break;
        }
        case 4:
        {
            std::cout << "\033[1;32mHeapifying the vector...\033[0m" << std::endl;
            heap.Heapify();
            std::cout << "Heapified successfully." << std::endl;
            std::cout << "Heap after heapify: ";
            heap.Traverse(TraversePrint<int>);
            break;
        }
        case 5:
        {
            std::cout << "\033[1;32mSorting the heap...\033[0m" << std::endl;
            heap.Sort();
            std::cout << "Heap sorted successfully." << std::endl;
            break;
        }
        case 6:
        {
            std::cout << "\033[1;32mClearing the heap...\033[0m" << std::endl;
            heap.Clear();
            std::cout << "Heap cleared successfully." << std::endl;
            break;
        }
        case 7:
        {
            FoldFunctionsMenuTest(heap);
            break;
        }
        case 8:
        {
            MapFunctionsMenuTest(heap);
            break;
        }
        case 0:
        {
            std::cout << "\033[1;32mExiting menu.\033[0m" << std::endl;
            break;
        }
        default:
        {
            std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 7.\033[0m" << std::endl;
            break;
        }
        }
    } while (choice != 0);
}

void Personal_Int_HeapVec(uint &testnum, uint &testerr)
{
    lasd::Vector<int> v1(10);
    SetAt(testnum, testerr, v1, true, 0, 4);
    SetAt(testnum, testerr, v1, true, 1, 1);
    SetAt(testnum, testerr, v1, true, 2, 3);
    SetAt(testnum, testerr, v1, true, 3, 2);
    SetAt(testnum, testerr, v1, true, 4, 16);
    SetAt(testnum, testerr, v1, true, 5, 9);
    SetAt(testnum, testerr, v1, true, 6, 10);
    SetAt(testnum, testerr, v1, true, 7, 14);
    SetAt(testnum, testerr, v1, true, 8, 8);
    SetAt(testnum, testerr, v1, true, 9, 7);

    lasd::HeapVec<int> h1(v1);
    IsHeap(testnum, testerr, h1, true);
    Traverse(testnum, testerr, v1, true, TraversePrint<int>);
    Traverse(testnum, testerr, h1, true, TraversePrint<int>);
    lasd::HeapVec<int> h2(std::move(v1));
    Size(testnum,testerr,h2,true,10);
    EqualLinear(testnum,testerr,h1,h2,true);
    h1.Sort();
    Traverse(testnum, testerr, h1, true, TraversePrint<int>);
    IsHeap(testnum, testerr, h1, false);
    NonEqualLinear(testnum,testerr,h1,h2,true);

    lasd::List<int> l1(std::move(h2));
    Size(testnum,testerr,h2,true,10);
    h2.Clear();
    Empty(testnum,testerr,h2,true);
    Size(testnum,testerr,h2,true,0);
    Traverse(testnum, testerr, h2, true, TraversePrint<int>);
    Empty(testnum,testerr,l1,false);
    Traverse(testnum, testerr, l1, true, TraversePrint<int>);

    h1 = l1;
    GetAt(testnum,testerr,h1,true,0,16);
    GetAt(testnum,testerr,h1,true,1,14);
    GetAt(testnum,testerr,h1,true,2,10);
    GetAt(testnum,testerr,h1,true,3,8);
    GetAt(testnum,testerr,h1,true,4,7);
    GetAt(testnum,testerr,h1,true,5,9);
    GetAt(testnum,testerr,h1,true,6,3);
    GetAt(testnum,testerr,h1,true,7,2);
    GetAt(testnum,testerr,h1,true,8,4);
    GetAt(testnum,testerr,h1,true,9,1);

    GetFront(testnum,testerr,h1,true,16);
    GetBack(testnum,testerr,h1,true,1);
    Exists(testnum,testerr,h1,true,16);
    Exists(testnum,testerr,h1,false,40);
    Exists(testnum,testerr,h1,true,1);

    Fold(testnum,testerr,h1,true,FoldAdd<int>,0,74);
    Fold(testnum,testerr,h1,true,FoldMultiply<int>,1,27095040);

    Traverse(testnum,testerr,h1,true,TraversePrint<int>);
    IsHeap(testnum,testerr,h1,true);

    h1.Heapify();
    IsHeap(testnum,testerr,h1,true);
    Traverse(testnum,testerr,h1,true,TraversePrint<int>);

    Fold(testnum,testerr,h1,true,FoldAdd<int>,0,74);
    Fold(testnum,testerr,h1,true,FoldMultiply<int>,1,27095040);

    lasd::Vector<int> v2(5);
    SetAt(testnum,testerr,v2,true,0,5);
    SetAt(testnum,testerr,v2,true,1,4);
    SetAt(testnum,testerr,v2,true,2,3);
    SetAt(testnum,testerr,v2,true,3,2);
    SetAt(testnum,testerr,v2,true,4,1);

    lasd::HeapVec<int> h3(v2);
    IsHeap(testnum,testerr,h3,true);
    Traverse(testnum,testerr,v2,true,TraversePrint<int>);
    Traverse(testnum,testerr,h3,true,TraversePrint<int>);
}

void Personal_Char_HeapVec(uint &testnum, uint &testerr)
{

    lasd::Vector<char> v1(10);
    SetAt(testnum, testerr, v1, true, 0, 'd');
    SetAt(testnum, testerr, v1, true, 1, 'a');
    SetAt(testnum, testerr, v1, true, 2, 'c');
    SetAt(testnum, testerr, v1, true, 3, 'b');
    SetAt(testnum, testerr, v1, true, 4, 'p');
    SetAt(testnum, testerr, v1, true, 5, 'i');
    SetAt(testnum, testerr, v1, true, 6, 'j');
    SetAt(testnum, testerr, v1, true, 7, 'n');
    SetAt(testnum, testerr, v1, true, 8, 'h');
    SetAt(testnum, testerr, v1, true, 9, 'g');
    lasd::HeapVec<char> h1(v1);
    IsHeap(testnum, testerr, h1, true);
    Traverse(testnum, testerr, v1, true, TraversePrint<char>);
    Traverse(testnum, testerr, h1, true, TraversePrint<char>);
    h1.Sort();
    Traverse(testnum, testerr, h1, true, TraversePrint<char>);
    IsHeap(testnum, testerr, h1, false);

    lasd::List<char> l1(std::move(h1));
    Size(testnum, testerr, h1, true, 10);
    h1.Clear();
    Empty(testnum, testerr, h1, true);
    Size(testnum, testerr, h1, true, 0);
    Traverse(testnum, testerr, h1, true, TraversePrint<char>);
    Empty(testnum, testerr, l1, false);
    Traverse(testnum, testerr, l1, true, TraversePrint<char>);

    h1 = l1;
    Traverse(testnum, testerr, h1, true, TraversePrint<char>);
    GetAt(testnum, testerr, h1, true, 0, 'p');
    GetAt(testnum, testerr, h1, true, 1, 'n');
    GetAt(testnum, testerr, h1, true, 2, 'i');
    GetAt(testnum, testerr, h1, true, 3, 'j');
    GetAt(testnum, testerr, h1, true, 4, 'g');
    GetAt(testnum, testerr, h1, true, 5, 'h');
    GetAt(testnum, testerr, h1, true, 6, 'c');
    GetAt(testnum, testerr, h1, true, 7, 'a');
    GetAt(testnum, testerr, h1, true, 8, 'd');
    GetAt(testnum, testerr, h1, true, 9, 'b');

    GetFront(testnum, testerr, h1, true, 'p');
    GetBack(testnum, testerr, h1, true, 'b');
    Exists(testnum, testerr, h1, true, 'p');
    Exists(testnum, testerr, h1, false, 'z');
    Exists(testnum, testerr, h1, true, 'a');

}

void Personal_String_HeapVec(uint &testnum, uint &testerr)
{

    lasd::Vector<std::string> v1(10);
    SetAt(testnum, testerr, v1, true, 0, std::string("d"));
    SetAt(testnum, testerr, v1, true, 1, std::string("a"));
    SetAt(testnum, testerr, v1, true, 2, std::string("c"));
    SetAt(testnum, testerr, v1, true, 3, std::string("b"));
    SetAt(testnum, testerr, v1, true, 4, std::string("p"));
    SetAt(testnum, testerr, v1, true, 5, std::string("i"));
    SetAt(testnum, testerr, v1, true, 6, std::string("j"));
    SetAt(testnum, testerr, v1, true, 7, std::string("n"));
    SetAt(testnum, testerr, v1, true, 8, std::string("h"));
    SetAt(testnum, testerr, v1, true, 9, std::string("g"));
    lasd::HeapVec<std::string> h1(v1);
    IsHeap(testnum, testerr, h1, true);
    Traverse(testnum, testerr, v1, true, TraversePrint<std::string>);
    Traverse(testnum, testerr, h1, true, TraversePrint<std::string>);
    h1.Sort();
    Traverse(testnum, testerr, h1, true, TraversePrint<std::string>);
    IsHeap(testnum, testerr, h1, false);

    lasd::List<std::string> l1(std::move(h1));
    Size(testnum, testerr, h1, true, 10);
    h1.Clear();
    Empty(testnum, testerr, h1, true);
    Size(testnum, testerr, h1, true, 0);
    Traverse(testnum, testerr, h1, true, TraversePrint<std::string>);
    Empty(testnum, testerr, l1, false);
    Traverse(testnum, testerr, l1, true, TraversePrint<std::string>);

    h1 = l1;
    Traverse(testnum, testerr, h1, true, TraversePrint<std::string>);
    GetAt(testnum, testerr, h1, true, 0, std::string("p"));
    GetAt(testnum, testerr, h1, true, 1, std::string("n"));
    GetAt(testnum, testerr, h1, true, 2, std::string("i"));
    GetAt(testnum, testerr, h1, true, 3, std::string("j"));
    GetAt(testnum, testerr, h1, true, 4, std::string("g"));
    GetAt(testnum, testerr, h1, true, 5, std::string("h"));
    GetAt(testnum, testerr, h1, true, 6, std::string("c"));
    GetAt(testnum, testerr, h1, true, 7, std::string("a"));
    GetAt(testnum, testerr, h1, true, 8, std::string("d"));
    GetAt(testnum, testerr, h1, true, 9, std::string("b"));

    GetFront(testnum, testerr, h1, true, std::string("p"));
    GetBack(testnum, testerr, h1, true, std::string("b"));
    Exists(testnum, testerr, h1, true, std::string("p"));
    Exists(testnum, testerr, h1, false, std::string("z"));

    lasd::Vector<std::string> v2(5);
    SetAt(testnum,testerr,v2,true,0,std::string("apple"));
    SetAt(testnum,testerr,v2,true,1,std::string("banana"));
    SetAt(testnum,testerr,v2,true,2,std::string("cherry"));
    SetAt(testnum,testerr,v2,true,3,std::string("date"));
    SetAt(testnum,testerr,v2,true,4,std::string("elderberry"));

    lasd::HeapVec<std::string> h2(v2);
    IsHeap(testnum,testerr,h2,true);
    Traverse(testnum,testerr,v2,true,TraversePrint<std::string>);
    Traverse(testnum,testerr,h2,true,TraversePrint<std::string>);
    h2.Sort();
    Traverse(testnum,testerr,h2,true,TraversePrint<std::string>);
    IsHeap(testnum,testerr,h2,false);

    Fold(testnum,testerr,h2,true,FoldAdd<std::string>,std::string(""),std::string("applebananacherrydateelderberry"));
    h2.Heapify();
    IsHeap(testnum,testerr,h2,true);
    Fold(testnum,testerr,h2,true,FoldAdd<std::string>,std::string(""),std::string("elderberrydatecherryapplebanana"));
}

void PersonalHeapVecTest(unsigned int &testnum, unsigned int &testerr)
{
    std::cout << "\033[1;35mBeginning HeapVec Personal Test.\033[0m" << std::endl;
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
}

void myTestExercise2A(unsigned int &testnum, unsigned int &testerr)
{
    PersonalHeapVecTest(testnum, testerr);
    std::cout << std::endl
              << "\033[1;34mExercise 2A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}