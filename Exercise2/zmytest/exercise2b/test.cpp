#include <iostream>
#include <limits>
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/pq/pq.hpp"
#include "../../vector/vector.hpp"
#include "../../zlasdtest/heap/heap.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../utils/utils.hpp"
#include "../../heap/heap.hpp"
#include "../../pq/pq.hpp"
#include "../../pq/heap/pqheap.hpp"

void PQHeapTestMenu()
{
    lasd::PQHeap<int> pqheap;
    uint choice = 0;
    do
    {
        std::cout << "\n\033[1;34mSelect an operation:\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\33[1;33m\t1 :\033[0m Generate random vector and create a new pqheap\n";
        std::cout << "\33[1;33m\t2 :\033[0m Print the pqheap\n";
        std::cout << "\33[1;33m\t3 :\033[0m Check if the heap is valid\n";
        std::cout << "\33[1;33m\t4 :\033[0m Heapify vector\n";
        std::cout << "\33[1;33m\t5 :\033[0m Sort the heap\n";
        std::cout << "\33[1;33m\t6 :\033[0m Clear the heap\n";
        std::cout << "\33[1;33m\t7 :\033[0m Apply fold function\n";
        std::cout << "\33[1;33m\t8 :\033[0m Apply map function (double elements)\n";
        std::cout << "\33[1;33m\t9 :\033[0m Apply map function (parity invert elements)\n";
        std::cout << "\33[1;33m\t10 :\033[0m Tip\n";
        std::cout << "\33[1;33m\t11 :\033[0m TipNRemove\n";
        std::cout << "\33[1;33m\t12 :\033[0m Change (copy)\n";
        std::cout << "\33[1;33m\t13 :\033[0m Change (move)\n";
        std::cout << "\33[1;33m\t14 :\033[0m Insert (copy)\n";
        std::cout << "\33[1;33m\t15 :\033[0m Insert (move)\n";

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
                std::cout << "\33[1;31mInvalid choice. Please enter a number between 0 and 15.\033[0m" << std::endl;
            }
        } while (choice < 0 || choice > 15);

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
            pqheap = lasd::HeapVec<int>(vec);
            std::cout << "Heap created successfully." << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "\033[1;32mPrinting the pqheap:\033[0m" << std::endl;
            pqheap.Traverse(TraversePrint<int>);
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "\033[1;32mChecking if the heap is valid...\033[0m" << std::endl;
            if (pqheap.IsHeap())
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
            pqheap.Heapify();
            std::cout << "Heapified successfully." << std::endl;
            std::cout << "Heap after heapify: ";
            pqheap.Traverse(TraversePrint<int>);
            std::cout << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "\033[1;32mSorting the heap...\033[0m" << std::endl;
            pqheap.Sort();
            std::cout << "Heap sorted successfully." << std::endl;
            break;
        }
        case 6:
        {
            std::cout << "\033[1;32mClearing the heap...\033[0m" << std::endl;
            pqheap.Clear();
            std::cout << "Heap cleared successfully." << std::endl;
            break;
        }
        case 7:
        {
            std::cout << "\033[1;32mApplying fold function...\033[0m" << std::endl;
            int sum = pqheap.Fold(FoldAdd<int>, 0);
            std::cout << "Sum of elements in the heap: " << sum << std::endl;
            break;
        }
        case 8:
        {
            std::cout << "\033[1;32mApplying map function...\033[0m" << std::endl;
            pqheap.Map(MapDouble<int>);
            std::cout << "Heap after mapping (each element multiplied by 2): ";
            pqheap.Traverse(TraversePrint<int>);
            std::cout << std::endl;
            break;
        }
        case 9:
        {
            std::cout << "\033[1;32mApplying map function (parity invert elements)...\033[0m" << std::endl;
            pqheap.Map(MapParityInvert<int>);
            std::cout << "Heap after mapping (parity invert): ";
            pqheap.Traverse(TraversePrint<int>);
            std::cout << std::endl;
            break;
        }
        case 10:
        {
            std::cout << "\033[1;32mGetting the tip of the pqheap...\033[0m" << std::endl;
            try
            {
                std::cout << "Tip: " << pqheap.Tip() << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\33[1;31mError: " << e.what() << "\033[0m" << std::endl;
            }
            break;
        }
        case 11:
        {
            std::cout << "\033[1;32mRemoving the tip of the pqheap...\033[0m" << std::endl;
            try
            {
                pqheap.TipNRemove();
                std::cout << "Tip removed successfully." << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\33[1;31mError: " << e.what() << "\033[0m" << std::endl;
            }
            break;
        }
        case 12:
        {
            std::cout << "\033[1;32mChanging an element in the pqheap (copy)...\033[0m" << std::endl;
            ulong index;
            int newValue;
            std::cout << "Enter index to change: ";
            std::cin >> index;
            std::cout << "Enter new value: ";
            std::cin >> newValue;
            try
            {
                pqheap.Change(index, newValue);
                std::cout << "Element changed successfully." << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\33[1;31mError: " << e.what() << "\033[0m" << std::endl;
            }
            break;
        }
        case 13:
        {
            std::cout << "\033[1;32mChanging an element in the pqheap (move)...\033[0m" << std::endl;
            ulong indexMove;
            int newValueMove;
            std::cout << "Enter index to change: ";
            std::cin >> indexMove;
            std::cout << "Enter new value: ";
            std::cin >> newValueMove;
            try
            {
                pqheap.Change(indexMove, std::move(newValueMove));
                std::cout << "Element changed successfully." << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\33[1;31mError: " << e.what() << "\033[0m" << std::endl;
            }
            break;
        }
        case 14:
        {
            std::cout << "\033[1;32mInserting an element into the pqheap (copy)...\033[0m" << std::endl;
            int valueToInsert;
            std::cout << "Enter value to insert: ";
            std::cin >> valueToInsert;
            try
            {
                pqheap.Insert(valueToInsert);
                std::cout << "Element inserted successfully." << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\33[1;31mError: " << e.what() << "\033[0m" << std::endl;
            }
            break;
        }
        case 15:
        {
            std::cout << "\033[1;32mInserting an element into the pqheap (move)...\033[0m" << std::endl;
            int valueToInsertMove;
            std::cout << "Enter value to insert: ";
            std::cin >> valueToInsertMove;
            try
            {
                pqheap.Insert(std::move(valueToInsertMove));
                std::cout << "Element inserted successfully." << std::endl;
            }
            catch (const std::length_error &e)
            {
                std::cerr << "\33[1;31mError: " << e.what() << "\033[0m" << std::endl;
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

void Personal_Int_PQHeap(uint &testnum, uint &testerr)
{
    lasd::Vector<int> vint(10);
    vint[0] = 42;
    vint[1] = 17;
    vint[2] = 8;
    vint[3] = 99;
    vint[4] = 23;
    vint[5] = 4;
    vint[6] = 56;
    vint[7] = 1;
    vint[8] = 77;
    vint[9] = 12;
    lasd::PQHeap<int> pqint(vint);
    Traverse(testnum, testerr, pqint, true, TraversePrint<int>);
    Tip(testnum, testerr, pqint, true, 99);
    RemoveTip(testnum, testerr, pqint, true);
    Traverse(testnum, testerr, pqint, true, TraversePrint<int>);
    Insert(testnum, testerr, pqint, 120);
    Traverse(testnum, testerr, pqint, true, TraversePrint<int>);
    TipNRemove(testnum, testerr, pqint, true, 120);
    Traverse(testnum, testerr, pqint, true, TraversePrint<int>);
    Change(testnum, testerr, pqint, 0, 120);
    Traverse(testnum, testerr, pqint, true, TraversePrint<int>);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, true);
    RemoveTip(testnum, testerr, pqint, false);
    Insert(testnum, testerr, pqint, 42);
    Insert(testnum, testerr, pqint, 17);
    Insert(testnum, testerr, pqint, 8);
    Insert(testnum, testerr, pqint, 99);
    Insert(testnum, testerr, pqint, 23);
    Insert(testnum, testerr, pqint, 4);
    Insert(testnum, testerr, pqint, 56);
    Insert(testnum, testerr, pqint, 1);
    Insert(testnum, testerr, pqint, 77);
    Insert(testnum, testerr, pqint, 12);
    Traverse(testnum, testerr, pqint, true, TraversePrint<int>);
    IsHeap(testnum, testerr, pqint, true);

    lasd::Vector<int> vint2(5);
    vint2[0] = 5;
    vint2[1] = 5;
    vint2[2] = 5;
    vint2[3] = 5;
    vint2[4] = 5;
    lasd::PQHeap<int> pqint2(std::move(vint2));
    Traverse(testnum, testerr, pqint2, true, TraversePrint<int>);
    IsHeap(testnum, testerr, pqint2, true);
    GetAt(testnum, testerr, pqint2, true, 0, 5);
    GetAt(testnum, testerr, pqint2, true, 1, 5);
    GetAt(testnum, testerr, pqint2, true, 2, 5);
    GetAt(testnum, testerr, pqint2, true, 3, 5);
    GetAt(testnum, testerr, pqint2, true, 4, 5);
    GetAt(testnum, testerr, pqint2, false, 5, 5);
    SetAt(testnum, testerr, pqint2, true, 2, 10);
    SetAt(testnum, testerr, pqint2, true, 4, 20);
    IsHeap(testnum, testerr, pqint2, false);
    pqint2.Heapify();
    Tip(testnum, testerr, pqint2, true, 20);
    pqint2.Clear();
    Size(testnum, testerr, pqint2, true, 0);
    Empty(testnum, testerr, pqint2, true);

    int newTip = 24;
    pqint2.Insert(std::move(newTip));
    Tip(testnum, testerr, pqint2, true, 24);
    Size(testnum, testerr, pqint2, true, 1);
}

void Personal_Char_PQHeap(uint &testnum, uint &testerr)
{
    lasd::Vector<char> vc1(7);
    SetAt(testnum, testerr, vc1, true, 0, 'z');
    SetAt(testnum, testerr, vc1, true, 1, 'a');
    SetAt(testnum, testerr, vc1, true, 2, 'q');
    SetAt(testnum, testerr, vc1, true, 3, 'b');
    SetAt(testnum, testerr, vc1, true, 4, 'm');
    SetAt(testnum, testerr, vc1, true, 5, 'x');
    SetAt(testnum, testerr, vc1, true, 6, 'c');
    lasd::PQHeap<char> pqchar(vc1);
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    Tip(testnum, testerr, pqchar, true, 'z');
    RemoveTip(testnum, testerr, pqchar, true);
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    Insert(testnum, testerr, pqchar, 'w');
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    TipNRemove(testnum, testerr, pqchar, true, 'x');
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    Change(testnum, testerr, pqchar, 0, 'y');
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    RemoveTip(testnum, testerr, pqchar, true);
    RemoveTip(testnum, testerr, pqchar, true);
    RemoveTip(testnum, testerr, pqchar, true);
    RemoveTip(testnum, testerr, pqchar, true);
    RemoveTip(testnum, testerr, pqchar, true);
    RemoveTip(testnum, testerr, pqchar, true);
    RemoveTip(testnum, testerr, pqchar, false);
    pqchar.Insert('A');
    pqchar.Insert('B');
    pqchar.Insert('C');
    pqchar.Insert('D');
    pqchar.Insert('E');
    pqchar.Insert('F');
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    Change(testnum,testerr,pqchar,0,'a');
    Traverse(testnum, testerr, pqchar, true, TraversePrint<char>);
    IsHeap(testnum, testerr, pqchar, true);
    lasd::Vector<char> vc2(4);
    SetAt(testnum, testerr, vc2, true, 0, 'd');
    SetAt(testnum, testerr, vc2, true, 1, 'd');
    SetAt(testnum, testerr, vc2, true, 2, 'd');
    SetAt(testnum, testerr, vc2, true, 3, 'd');
    lasd::PQHeap<char> pqchar2(std::move(vc2));
    Traverse(testnum, testerr, pqchar2, true, TraversePrint<char>);
    IsHeap(testnum, testerr, pqchar2, true);
    GetAt(testnum, testerr, pqchar2, true, 0, 'd');
    GetAt(testnum, testerr, pqchar2, true, 1, 'd');
    GetAt(testnum, testerr, pqchar2, true, 2, 'd');
    GetAt(testnum, testerr, pqchar2, true, 3, 'd');
    GetAt(testnum, testerr, pqchar2, false, 4, 'd');
    SetAt(testnum, testerr, pqchar2, true, 1, 'h');
    SetAt(testnum, testerr, pqchar2, true, 3, 'k');
    IsHeap(testnum, testerr, pqchar2, false);
    pqchar2.Heapify();
    Tip(testnum, testerr, pqchar2, true, 'k');
    pqchar2.Clear();
    Size(testnum, testerr, pqchar2, true, 0);
    Empty(testnum, testerr, pqchar2, true);

    char newTipChar = 'z';
    pqchar2.Insert(std::move(newTipChar));
    Tip(testnum, testerr, pqchar2, true, 'z');
    Size(testnum, testerr, pqchar2, true, 1);

}

void Personal_String_PQHeap(uint &testnum, uint &testerr)
{
    lasd::Vector<std::string> vs1(7);
    SetAt(testnum,testerr,vs1,true,0,std::string("zebra"));
    SetAt(testnum,testerr,vs1,true,1,std::string("apple"));
    SetAt(testnum,testerr,vs1,true,2,std::string("quail"));
    SetAt(testnum,testerr,vs1,true,3,std::string("banana"));
    SetAt(testnum,testerr,vs1,true,4,std::string("mango"));
    SetAt(testnum,testerr,vs1,true,5,std::string("xylophone"));
    SetAt(testnum,testerr,vs1,true,6,std::string("cat"));
    lasd::PQHeap<std::string> pqstring(vs1);
    Traverse(testnum, testerr, pqstring, true, TraversePrint<std::string>);
    Tip(testnum, testerr, pqstring, true, std::string("zebra"));
    RemoveTip(testnum, testerr, pqstring, true);
    Traverse(testnum, testerr, pqstring, true, TraversePrint<std::string>);
    Insert(testnum, testerr, pqstring, std::string("watermelon"));
    Traverse(testnum, testerr, pqstring, true, TraversePrint<std::string>);
    TipNRemove(testnum, testerr, pqstring, true, std::string("xylophone"));
    Traverse(testnum, testerr, pqstring, true, TraversePrint<std::string>);
    Change(testnum, testerr, pqstring, 0, std::string("yak"));
    Traverse(testnum, testerr, pqstring, true, TraversePrint<std::string>);
    RemoveTip(testnum, testerr, pqstring, true);
    RemoveTip(testnum, testerr, pqstring, true);
}

void PersonalPQHeapTest(unsigned int &testnum, unsigned int &testerr)
{
    std::cout << "\033[1;35mBeginning PQHeap Personal Test.\033[0m" << std::endl;
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing PQHeap of integers>>\033[0m" << std::endl;
    Personal_Int_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing PQHeap of chars>>\033[0m" << std::endl;
    Personal_Char_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    loctest = 0;
    errtest = 0;
    std::cout << "\033[4;36m<<Testing PQHeap of strings>>\033[0m" << std::endl;
    Personal_String_PQHeap(loctest, errtest);
    std::cout << "\033[4;36mEnd of PQHeap<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mPQHeap personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;
}

void myTestExercise2B(unsigned int &testnum, unsigned int &testerr)
{
    PersonalPQHeapTest(testnum, testerr);
    std::cout << std::endl
              << "\033[1;34mExercise 2B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << std::endl;
}