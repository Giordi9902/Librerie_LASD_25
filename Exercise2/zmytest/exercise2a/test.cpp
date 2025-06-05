#include <iostream>
#include <limits>
#include <random>
#include <string>
#include "../../heap/vec/heapvec.hpp"
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../mycontainer/mylinear.hpp"
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

    lasd::List<int> l1(v1);

    lasd::HeapVec<int> h1(v1);

    // Container tests
    Empty(testnum,testerr,h1,false);
    Size(testnum,testerr,h1,true,10);

    // Testable tests
    Exists(testnum,testerr,h1,true,4);
    Exists(testnum,testerr,h1,true,1);
    Exists(testnum,testerr,h1,true,3);
    Exists(testnum,testerr,h1,true,2);
    Exists(testnum,testerr,h1,true,16);
    Exists(testnum,testerr,h1,true,9);
    Exists(testnum,testerr,h1,true,10);
    Exists(testnum,testerr,h1,true,14);
    Exists(testnum,testerr,h1,true,8);
    Exists(testnum,testerr,h1,true,7);
    Exists(testnum,testerr,h1,false,40);
    Exists(testnum,testerr,h1,false,12);

    // Traversable tests
    Traverse(testnum,testerr,h1,true,TraversePrint<int>);
    TraversePostOrder(testnum,testerr,h1,true,TraversePrint<int>);
    Fold(testnum,testerr,h1,true,FoldAdd<int>,0,74);
    FoldPostOrder(testnum,testerr,h1,true,FoldAdd<int>,0,74);
    Fold(testnum,testerr,h1,true,FoldMultiply<int>,1,27095040);
    FoldPostOrder(testnum,testerr,h1,true,FoldMultiply<int>,1,27095040);

    // LinearContainer tests
    lasd::HeapVec<int>h2(v1);
    EqualLinear(testnum,testerr,h1,h2,true);
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


    // MappableContainer tests
    Map(testnum,testerr,h1,true,MapIncrement<int>);
    GetAt(testnum,testerr,h1,true,0,17);
    GetAt(testnum,testerr,h1,true,1,15);
    GetAt(testnum,testerr,h1,true,2,11);
    GetAt(testnum,testerr,h1,true,3,9);
    GetAt(testnum,testerr,h1,true,4,8);
    GetAt(testnum,testerr,h1,true,5,10);
    GetAt(testnum,testerr,h1,true,6,4);
    GetAt(testnum,testerr,h1,true,7,3);
    GetAt(testnum,testerr,h1,true,8,5);
    GetAt(testnum,testerr,h1,true,9,2);

    // MutableLinear Container tests
    for(ulong index = 0; index < 10; index++){
        SetAt(testnum,testerr,h1,true,index,v1[index]);
    }

    // Heap tests
    IsHeap(testnum,testerr,h1,false);
    h1.Heapify();
    IsHeap(testnum,testerr,h1,true);
    h1.Sort();
    SortedLinear(testnum,testerr,h1,true);
    NonEqualLinear(testnum,testerr,h1,h2,true);

    // Check move constructor
    lasd::HeapVec<int> h3(std::move(h1));
    IsHeap(testnum,testerr,h3,false);

    // Check copy constructor
    lasd::HeapVec<int> h4(h3);
    EqualLinear(testnum,testerr,h3,h4,true);
    Empty(testnum, testerr, h4, false);
    Size(testnum, testerr, h4, true, 10);
    IsHeap(testnum,testerr,h4,false);

    // Check constructor from mappablecontainer
    lasd::HeapVec<int> h5(std::move(l1));
    IsHeap(testnum,testerr,h5,true);

    // Operator= checks
    lasd::HeapVec<int> h6;
    h6 = h3;
    Traverse(testnum,testerr,h6,true,TraversePrint<int>);
    Size(testnum,testerr,h6,true,10);
    IsHeap(testnum,testerr,h6,false);
    h6.Heapify();

    lasd::HeapVec<int> h7 = std::move(h6);
    Traverse(testnum,testerr,h7,true,TraversePrint<int>);
    Size(testnum,testerr,h7,true,10);
    IsHeap(testnum,testerr,h7,true);
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

    // Container tests
    Empty(testnum,testerr,h1,false);
    Size(testnum,testerr,h1,true,10);

    // Testable tests
    Exists(testnum,testerr,h1,true,'d');
    Exists(testnum,testerr,h1,true,'a');
    Exists(testnum,testerr,h1,true,'c');
    Exists(testnum,testerr,h1,true,'b');
    Exists(testnum,testerr,h1,true,'p');
    Exists(testnum,testerr,h1,true,'i');
    Exists(testnum,testerr,h1,true,'j');
    Exists(testnum,testerr,h1,true,'n');
    Exists(testnum,testerr,h1,true,'h');
    Exists(testnum,testerr,h1,true,'g');
    Exists(testnum,testerr,h1,false,'z');
    Exists(testnum,testerr,h1,false,'m');

    // Traversable tests
    Traverse(testnum,testerr,h1,true,TraversePrint<char>);
    TraversePostOrder(testnum,testerr,h1,true,TraversePrint<char>);

    // LinearContainer tests
    lasd::HeapVec<char>h2(v1);
    EqualLinear(testnum,testerr,h1,h2,true);
    GetAt(testnum,testerr,h1,true,0,'p');
    GetAt(testnum,testerr,h1,true,1,'n');
    GetAt(testnum,testerr,h1,true,2,'j');
    GetAt(testnum,testerr,h1,true,3,'h');
    GetAt(testnum,testerr,h1,true,4,'g');
    GetAt(testnum,testerr,h1,true,5,'i');
    GetAt(testnum,testerr,h1,true,6,'c');
    GetAt(testnum,testerr,h1,true,7,'b');
    GetAt(testnum,testerr,h1,true,8,'d');
    GetAt(testnum,testerr,h1,true,9,'a');
    GetFront(testnum,testerr,h1,true,'p');
    GetBack(testnum,testerr,h1,true,'a');

    // MappableContainer tests
    Map(testnum,testerr,h1,true,MapIncrement<char>);
    GetAt(testnum,testerr,h1,true,0,'q');
    GetAt(testnum,testerr,h1,true,1,'o');
    GetAt(testnum,testerr,h1,true,2,'k');
    GetAt(testnum,testerr,h1,true,3,'i');
    GetAt(testnum,testerr,h1,true,4,'h');
    GetAt(testnum,testerr,h1,true,5,'j');
    GetAt(testnum,testerr,h1,true,6,'d');
    GetAt(testnum,testerr,h1,true,7,'c');
    GetAt(testnum,testerr,h1,true,8,'e');
    GetAt(testnum,testerr,h1,true,9,'b');

    // MutableLinear Container tests
    for(ulong index = 0; index < 10; index++){
        SetAt(testnum,testerr,h1,true,index,v1[index]);
    }

    // Heap tests
    IsHeap(testnum,testerr,h1,false);
    h1.Heapify();
    IsHeap(testnum,testerr,h1,true);
    h1.Sort();
    SortedLinear(testnum,testerr,h1,true);
    NonEqualLinear(testnum,testerr,h1,h2,true);

    // Check move constructor
    lasd::HeapVec<char> h3(std::move(h1));
    IsHeap(testnum,testerr,h3,false);

    // Check copy constructor
    lasd::HeapVec<char> h4(h3);
    EqualLinear(testnum,testerr,h3,h4,true);
    Empty(testnum, testerr, h4, false);
    Size(testnum, testerr, h4, true, 10);
    IsHeap(testnum,testerr,h4,false);

    // Check constructor from mappablecontainer
    lasd::List<char> l1(v1);
    lasd::HeapVec<char> h5(std::move(l1));
    IsHeap(testnum,testerr,h5,true);

    // Operator= checks
    lasd::HeapVec<char> h6;
    h6 = h3;
    Traverse(testnum,testerr,h6,true,TraversePrint<char>);
    Size(testnum,testerr,h6,true,10);
    IsHeap(testnum,testerr,h6,false);
    h6.Heapify();

    lasd::HeapVec<char> h7 = std::move(h6);
    Traverse(testnum,testerr,h7,true,TraversePrint<char>);
    Size(testnum,testerr,h7,true,10);
    IsHeap(testnum,testerr,h7,true);

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

    // Container tests
    Empty(testnum,testerr,h1,false);
    Size(testnum,testerr,h1,true,10);

    // Testable tests
    Exists(testnum,testerr,h1,true,std::string("d"));
    Exists(testnum,testerr,h1,true,std::string("a"));
    Exists(testnum,testerr,h1,true,std::string("c"));
    Exists(testnum,testerr,h1,true,std::string("b"));
    Exists(testnum,testerr,h1,true,std::string("p"));
    Exists(testnum,testerr,h1,true,std::string("i"));
    Exists(testnum,testerr,h1,true,std::string("j"));
    Exists(testnum,testerr,h1,true,std::string("n"));
    Exists(testnum,testerr,h1,true,std::string("h"));
    Exists(testnum,testerr,h1,true,std::string("g"));
    Exists(testnum,testerr,h1,false,std::string("z"));
    Exists(testnum,testerr,h1,false,std::string("m"));

    // Traversable tests
    Traverse(testnum,testerr,h1,true,TraversePrint<std::string>);
    TraversePostOrder(testnum,testerr,h1,true,TraversePrint<std::string>);

    // LinearContainer tests
    lasd::HeapVec<std::string>h2(v1);
    EqualLinear(testnum,testerr,h1,h2,true);
    GetAt(testnum,testerr,h1,true,0,std::string("p"));
    GetAt(testnum,testerr,h1,true,1,std::string("n"));
    GetAt(testnum,testerr,h1,true,2,std::string("j"));
    GetAt(testnum,testerr,h1,true,3,std::string("h"));
    GetAt(testnum,testerr,h1,true,4,std::string("g"));
    GetAt(testnum,testerr,h1,true,5,std::string("i"));
    GetAt(testnum,testerr,h1,true,6,std::string("c"));
    GetAt(testnum,testerr,h1,true,7,std::string("b"));
    GetAt(testnum,testerr,h1,true,8,std::string("d"));
    GetAt(testnum,testerr,h1,true,9,std::string("a"));
    GetFront(testnum,testerr,h1,true,std::string("p"));
    GetBack(testnum,testerr,h1,true,std::string("a"));

    // MappableContainer tests
    Map(testnum,testerr,h1,true,[](std::string& str){
        str.append("X");
    });
    GetAt(testnum,testerr,h1,true,0,std::string("pX"));
    GetAt(testnum,testerr,h1,true,1,std::string("nX"));
    GetAt(testnum,testerr,h1,true,2,std::string("jX"));
    GetAt(testnum,testerr,h1,true,3,std::string("hX"));
    GetAt(testnum,testerr,h1,true,4,std::string("gX"));
    GetAt(testnum,testerr,h1,true,5,std::string("iX"));
    GetAt(testnum,testerr,h1,true,6,std::string("cX"));
    GetAt(testnum,testerr,h1,true,7,std::string("bX"));
    GetAt(testnum,testerr,h1,true,8,std::string("dX"));
    GetAt(testnum,testerr,h1,true,9,std::string("aX"));

    // MutableLinear Container tests
    for(ulong index = 0; index < 10; index++){
        SetAt(testnum,testerr,h1,true,index,v1[index]);
    }

    // Heap tests
    IsHeap(testnum,testerr,h1,false);
    h1.Heapify();
    IsHeap(testnum,testerr,h1,true);
    h1.Sort();
    SortedLinear(testnum,testerr,h1,true);
    NonEqualLinear(testnum,testerr,h1,h2,true);

    // Check move constructor
    lasd::HeapVec<std::string> h3(std::move(h1));
    IsHeap(testnum,testerr,h3,false);

    // Check copy constructor
    lasd::HeapVec<std::string> h4(h3);
    EqualLinear(testnum,testerr,h3,h4,true);
    Empty(testnum, testerr, h4, false);
    Size(testnum, testerr, h4, true, 10);
    IsHeap(testnum,testerr,h4,false);

    // Check constructor from mappablecontainer
    lasd::List<std::string> l1(v1);
    lasd::HeapVec<std::string> h5(std::move(l1));
    IsHeap(testnum,testerr,h5,true);

    // Operator= checks
    lasd::HeapVec<std::string> h6;
    h6 = h3;
    Traverse(testnum,testerr,h6,true,TraversePrint<std::string>);
    Size(testnum,testerr,h6,true,10);
    IsHeap(testnum,testerr,h6,false);
    h6.Heapify();

    lasd::HeapVec<std::string> h7 = std::move(h6);
    Traverse(testnum,testerr,h7,true,TraversePrint<std::string>);
    Size(testnum,testerr,h7,true,10);
    IsHeap(testnum,testerr,h7,true);

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