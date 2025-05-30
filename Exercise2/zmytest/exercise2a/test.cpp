#include <iostream>
#include <limits>
#include <string>
#include "../../heap/vec/heapvec.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../vector/vector.hpp"
#include "../../zlasdtest/heap/heap.hpp"
#include "../../zlasdtest/container/linear.hpp"

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
        std::cout << "\33[1;33m\t7 :\033[0m Set at\n";
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
            if (choice < 0 || choice > 7)
            {
                std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 7.\033[0m" << std::endl;
            }
        } while (choice < 0 || choice > 7);

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
            std::cout << "\033[1;32mSetting element at index...\033[0m" << std::endl;
            ulong index;
            int value;
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Enter value: ";
            std::cin >> value;
            try
            {
                heap[index] = value;
                std::cout << "Element set successfully." << std::endl;
            }
            catch (const std::out_of_range &ex)
            {
                std::cerr << "\033[1;31mError: " << ex.what() << "\033[0m" << std::endl;
            }
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
    h1.Sort();
    Traverse(testnum, testerr, h1, true, TraversePrint<int>);
    IsHeap(testnum, testerr, h1, false);
}

void Personal_Double_HeapVec(uint &testnum, uint &testerr)
{
    lasd::Vector<double> v1(10);
    SetAt(testnum, testerr, v1, true, 0, 4.4);
    SetAt(testnum, testerr, v1, true, 1, 1.1);
    SetAt(testnum, testerr, v1, true, 2, 3.3);
    SetAt(testnum, testerr, v1, true, 3, 2.2);
    SetAt(testnum, testerr, v1, true, 4, 16.16);
    SetAt(testnum, testerr, v1, true, 5, 9.9);
    SetAt(testnum, testerr, v1, true, 6, 10.10);
    SetAt(testnum, testerr, v1, true, 7, 14.14);
    SetAt(testnum, testerr, v1, true, 8, 8.8);
    SetAt(testnum, testerr, v1, true, 9, 7.7);
    lasd::HeapVec<double> h1(v1);
    IsHeap(testnum, testerr, h1, true);
    Traverse(testnum, testerr, v1, true, TraversePrint<double>);
    Traverse(testnum, testerr, h1, true, TraversePrint<double>);
    h1.Sort();
    Traverse(testnum, testerr, h1, true, TraversePrint<double>);
    IsHeap(testnum, testerr, h1, false);
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
}

void PersonalHeapVecTest(unsigned int &testnum, unsigned int &testerr)
{
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
    std::cout << "\033[4;36m<<Testing HeapVec of doubles>>\033[0m" << std::endl;
    Personal_Double_HeapVec(loctest, errtest);
    std::cout << "\033[4;36mEnd of HeapVec<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
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
    std::cout << std::endl;
}

void myTestExercise2A(unsigned int &testnum, unsigned int &testerr)
{
    PersonalHeapVecTest(testnum, testerr);
    std::cout << std::endl
              << "\033[1;34mExercise 2A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}