#include <iostream>
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../mycontainer/mylinear.hpp"
#include "../mycontainer/mytraversable.hpp"
#include "../mycontainer/mymappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include <random>
#include <string>
#include "./test.hpp"

using namespace std;

/*****************************************************************************************/
void PersonalIntVectorTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector of integers>>\033[0m" << std::endl;
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);
    // Container tests
    {
        lasd::Vector<int> v1;
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);

        // Resizing vector with random size and checking new Size
        ulong newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
        }
        newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
        }
        v1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::Vector<int> v2(10);
        int elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            elements[index] = dist(gen);
            SetAt(loctestnum, loctesterr, v2, true, index, elements[index]);
        }
        int num;
        for (ulong n = 0; n < 20; n++)
        {
            num = dist(gen) % 20;
            if (num < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, elements[num]);
            }
        }
        v2.Clear();
        v2.Resize(10);
        for (ulong index = 0; index < 10; index++)
        {
            v2[index] = (index + 1) * 10;
        }
        // Checks for non existence
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, (int)((n + 1) * 10));
            }
            else if (n > 10)
            {
                Exists(loctestnum, loctesterr, v2, false, (int)(n * 10));
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::Vector<int> v3(20);
        for (ulong index = 0; index < 20; index++)
        {
            v3[index] = dist(gen);
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<int>);

        ulong newDim = dist(gen);
        // v3 = [1,2,...,newDim]
        v3.Resize(newDim);
        for (ulong index = 0; index < newDim; index++)
        {
            v3[index] = index + 1;
        }

        // Using fold fun using known mathematical formulas:
        int sum = (newDim * (newDim + 1)) / 2;
        Fold(loctestnum, loctesterr, v3, true, FoldAdd<int>, 0, sum);
        FoldPostOrder(loctestnum, loctesterr, v3, true, FoldAdd<int>, 0, sum);
        int sum2 = (newDim * (newDim + 1) * (newDim * 2 + 1)) / 6;
        Fold(loctestnum, loctesterr, v3, true, [](const int &dat, const int &sum)
             { return (sum + dat * dat); }, 0, sum2);
    }

    // MappableContainer features testing
    {
        lasd::Vector<int> v4(3);
        v4[0] = 1;
        v4[1] = 2;
        v4[2] = 3;
        Map(loctestnum, loctesterr, v4, true, IncrementInt);
        // v4 = [2,3,4]
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<int>);
        MapPostOrder(loctestnum, loctesterr, v4, true, SquareInt);
        // v4 = [4,9,16];
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<int>);
    }

    // LinearContainer features testing
    {
        lasd::Vector<int> vec(5);
        for (ulong i = 0; i < 5; ++i)
        {
            vec[i] = i + 1;
        }
        GetFront(loctestnum, loctesterr, vec, true, 1);
        GetBack(loctestnum, loctesterr, vec, true, 5);
        for (ulong i = 0; i < 5; ++i)
        {
            GetAt(loctestnum, loctesterr, vec, true, i, (int)i + 1);
        }
        SetAt(loctestnum, loctesterr, vec, true, 2, 10);
        GetAt(loctestnum, loctesterr, vec, true, 2, 10);
        SetFront(loctestnum, loctesterr, vec, true, 100);
        SetBack(loctestnum, loctesterr, vec, true, 200);
        GetFront(loctestnum, loctesterr, vec, true, 100);
        GetBack(loctestnum, loctesterr, vec, true, 200);

        {
            lasd::SortableVector<int> vec(5);
            vec[0] = 5;
            vec[1] = 3;
            vec[2] = 4;
            vec[3] = 1;
            vec[4] = 2;

            NonSortedLinear(loctestnum, loctesterr, vec, true);
            vec.Sort();
            SortedLinear(loctestnum, loctesterr, vec, true);
            GetFront(loctestnum, loctesterr, vec, true, 1);
            GetBack(loctestnum, loctesterr, vec, true, 5);
        }
    }

    // Vector features testing
    {
        std::uniform_int_distribution<ulong> sizeDist(10, 50);

        ulong size = sizeDist(gen);
        lasd::Vector<int> originalVec(size);
        for (ulong i = 0; i < size; ++i)
        {
            originalVec[i] = dist(gen);
        }

        // Copy constructor
        lasd::Vector<int> copiedVec(originalVec);
        EqualVector(loctestnum,loctesterr,copiedVec,originalVec,true);
        
        // Move constructor
        lasd::Vector<int> movedVec(std::move(originalVec));
        for (ulong i = 0; i < size; ++i)
        {
            GetAt(loctestnum, loctesterr, movedVec, true, i, copiedVec[i]);
        }
        NonEqualVector(loctestnum,loctesterr,movedVec,originalVec,true);
        Empty(loctestnum, loctesterr, originalVec, true); // originalVec should now be empty

        // Copy assignment
        lasd::Vector<int> assignedVec;
        assignedVec = copiedVec;
        EqualVector(loctestnum,loctesterr,assignedVec,copiedVec,true);

        // Move assignment
        lasd::Vector<int> moveAssignedVec;
        moveAssignedVec = std::move(copiedVec);
        NonEqualVector(loctestnum,loctesterr,moveAssignedVec,copiedVec,true);
        Empty(loctestnum, loctesterr, copiedVec, true);
        
        // SortableVectors copyConstructor
        lasd::SortableVector<int> sortedVectorByCopy(moveAssignedVec);
        EqualVector(loctestnum,loctesterr,moveAssignedVec,sortedVectorByCopy,true);
        
    }
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<int> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalDoubleVectorTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector of doubles>>\033[0m" << std::endl;
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0, 20.0);
    // Container tests
    {
        lasd::Vector<double> v1;
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);

        // Resizing vector with random size and checking new Size
        ulong newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
        }
        newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
        }
        v1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::Vector<double> v2(10);
        double elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            elements[index] = dist(gen);
            SetAt(loctestnum, loctesterr, v2, true, index, elements[index]);
        }
        std::uniform_real_distribution<double> dist2(200.0, 400.0);
        double num;
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, elements[n]);
            }
            else
            {
                num = dist2(gen);
                Exists(loctestnum, loctesterr, v2, false, num);
            }
        }
        v2.Clear();
        v2.Resize(10);
        for (ulong index = 0; index < 10; index++)
        {
            // Add double numbers 1.1, 2.2, 3.3
            v2[index] = (index + 1) * 1.1;
        }
        // Checks for non existence
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, (double)((n + 1) * 1.1));
            }
            else if (n > 10)
            {
                Exists(loctestnum, loctesterr, v2, false, (double)(n * 1.1));
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::Vector<double> v3(20);
        for (ulong index = 0; index < 20; index++)
        {
            v3[index] = dist(gen);
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<double>);

        ulong newDim = dist(gen);
        // v3 = [1.1,2.2,...,newDim]
        v3.Resize(newDim);
        for (ulong index = 0; index < newDim; index++)
        {
            v3[index] = (index + 1) * 1.1;
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<double>);
    }

    // MappableContainer features testing
    {
        lasd::Vector<double> v4(3);
        v4[0] = 2.6;
        v4[1] = 3.1;
        v4[2] = 4.5;
        Map(loctestnum, loctesterr, v4, true, RoundDouble);
        // v4 = [3,3,5]
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<double>);
        MapPostOrder(loctestnum, loctesterr, v4, true, Reciprocal);
        // v4 = [0.3,0.3,0.5]
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<double>);
    }

    // LinearContainer features testing
    {
        lasd::Vector<double> vec(5);
        vec[0] = 1.1;
        vec[1] = 2.2;
        vec[2] = 3.3;
        vec[3] = 4.4;
        vec[4] = 5.5;

        GetFrontDouble(loctestnum, loctesterr, vec, true, 1.1, 0.001);
        GetBackDouble(loctestnum, loctesterr, vec, true, 5.5, 0.001);

        for (ulong i = 0; i < 5; ++i)
        {
            GetAt(loctestnum, loctesterr, vec, true, i, vec[i]);
        }

        SetAt(loctestnum, loctesterr, vec, true, 2, 10.5);
        GetAtDouble(loctestnum, loctesterr, vec, true, 2, 10.5, 1e-9);
        {
            lasd::SortableVector<double> vec(5);
            vec[0] = 5.5;
            vec[1] = 3.3;
            vec[2] = 4.4;
            vec[3] = 1.1;
            vec[4] = 2.2;

            NonSortedLinear(loctestnum, loctesterr, vec, true);
            vec.Sort();
            SortedLinear(loctestnum, loctesterr, vec, true);
            GetFrontDouble(loctestnum, loctesterr, vec, true, 1.1, 0.001);
            GetBackDouble(loctestnum, loctesterr, vec, true, 5.5, 0.001);
        }
    }
    
    // Vector features testing
    {
        std::uniform_int_distribution<ulong> sizeDist(10, 50);

        ulong size = sizeDist(gen);
        lasd::Vector<double> originalVec(size);
        for (ulong i = 0; i < size; ++i)
        {
            originalVec[i] = dist(gen);
        }

        // Copy constructor
        lasd::Vector<double> copiedVec(originalVec);
        EqualLinear(loctestnum,loctesterr,originalVec,copiedVec,true);

        // Move constructor
        lasd::Vector<double> movedVec(std::move(originalVec));
        NonEqualLinear(loctestnum,loctesterr,movedVec,originalVec,true);
        Empty(loctestnum, loctesterr, originalVec, true); // originalVec should now be empty

        // Copy assignment
        lasd::Vector<double> assignedVec;
        assignedVec = copiedVec;
        EqualVector(loctestnum,loctesterr,assignedVec,copiedVec,true);

        // Move assignment
        lasd::Vector<double> moveAssignedVec;
        moveAssignedVec = std::move(copiedVec);
        NonEqualVector(loctestnum,loctesterr,moveAssignedVec,copiedVec,true);
        Empty(loctestnum, loctesterr, copiedVec, true); // copiedVec should now be empty

        // SortableVector


    }
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<double> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalCharVectorTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector of chars>>\033[0m" << std::endl;
    // Random char generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(97, 122);

    // Container tests
    {
        lasd::Vector<char> v1;
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);

        // Resizing vector with random size and checking new Size
        ulong newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            SetAt(loctestnum, loctesterr, v1, true, i, (char)dist(gen));
        }
        newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            SetAt(loctestnum, loctesterr, v1, true, i, (char)dist(gen));
        }
        v1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::Vector<char> v2(10);
        char elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            elements[index] = (char)dist(gen);
            SetAt(loctestnum, loctesterr, v2, true, index, elements[index]);
        }
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, elements[n]);
            }
        }
        v2.Clear();
        v2.Resize(26);
        for (ulong index = 0; index < 26; index++)
        {
            // Add chars 'a', 'b', 'c'
            v2[index] = (char)(index + 96);
        }
        // Check for non existence of values in v2
        ulong num;
        for (ulong n = 0; n < 20; n++)
        {
            num = dist(gen) % 50;
            if (num < 26)
            {
                Exists(loctestnum, loctesterr, v2, true, (char)(num + 96));
            }
            else
            {
                Exists(loctestnum, loctesterr, v2, false, (char)(num + 96));
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::Vector<char> v3(20);
        for (ulong index = 0; index < 20; index++)
        {
            v3[index] = (char)dist(gen);
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<char>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<char>);

        // v3 = ['a','b',...,'z']
        v3.Resize(26);
        for (ulong index = 0; index < 26; index++)
        {
            v3[index] = (char)(index + 97);
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<char>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<char>);

        // Fold functions
        Fold(loctestnum, loctesterr, v3, true, LowerCaseVectorFold, true, true);
        FoldPostOrder(loctestnum, loctesterr, v3, true, LowerCaseVectorFold, true, true);

        lasd::Vector<char> v4(7);
        v4[0] = 'A';
        v4[1] = 'b';
        v4[2] = 'c';
        v4[3] = 'D';
        v4[4] = 'e';
        v4[5] = '1';
        v4[6] = 'z';
        Fold(loctestnum, loctesterr, v4, true, ConcatCharFold, std::string(""), std::string("AbcDe1z"));
        FoldPostOrder(loctestnum, loctesterr, v4, true, VowelCountFold, 0, 2);
        FoldPreOrder(loctestnum, loctesterr, v4, true, AsciiSumFold, 0, 602);
    }

    // MappableContainer features testing
    {
        lasd::Vector<char> v4(26);
        for (ulong index = 0; index < 26; index++)
        {
            v4[index] = (char)(index + 97);
        }
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<char>);
        Map(loctestnum, loctesterr, v4, true, ToUpperChar);
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<char>);
    }

    // LinearContainer features testing
    {
        lasd::Vector<char> vec(26);
        for (ulong index = 0; index < 26; index++)
        {
            SetAt(loctestnum, loctesterr, vec, true, index, (char)(index + 97));
        }
        GetFront(loctestnum, loctesterr, vec, true, 'a');
        GetBack(loctestnum, loctesterr, vec, true, 'z');

        for (ulong i = 0; i < 26; i++)
        {
            GetAt(loctestnum, loctesterr, vec, true, i, (char)(i + 97));
        }

        for (ulong i = 0; i < 26; i++)
        {
            SetAt(loctestnum, loctesterr, vec, true, i, (char)((dist(gen) % 10) + 97));
        }
        SetFront(loctestnum, loctesterr, vec, true, (char)((dist(gen) % 10) + 97));
        SetBack(loctestnum, loctesterr, vec, true, (char)((dist(gen) % 10) + 97));
        {
            lasd::SortableVector<char> vec(5);
            vec[0] = 'e';
            vec[1] = 'a';
            vec[2] = 'd';
            vec[3] = 'c';
            vec[4] = 'b';
            NonSortedLinear(loctestnum, loctesterr, vec, true);
            vec.Sort();
            SortedLinear(loctestnum, loctesterr, vec, true);
            GetAt(loctestnum, loctesterr, vec, true, 0, 'a');
            GetAt(loctestnum, loctesterr, vec, true, 4, 'e');
            GetFront(loctestnum, loctesterr, vec, true, 'a');
            GetBack(loctestnum, loctesterr, vec, true, 'e');
            SetBack(loctestnum, loctesterr, vec, true, '1');
            NonSortedLinear(loctestnum, loctesterr, vec, true);
        }
    }

    // Vector features testing
    {
        std::uniform_int_distribution<ulong> sizeDist(10, 50);

        ulong size = sizeDist(gen);
        lasd::Vector<char> originalVec(size);
        for (ulong i = 0; i < size; ++i)
        {
            originalVec[i] = (char)(dist(gen));
        }

        // Copy constructor
        lasd::Vector<char> copiedVec(originalVec);
        EqualVector(loctestnum,loctesterr,copiedVec,originalVec,true);
        
        // Move constructor
        lasd::Vector<char> movedVec(std::move(originalVec));
        for (ulong i = 0; i < size; ++i)
        {
            GetAt(loctestnum, loctesterr, movedVec, true, i, copiedVec[i]);
        }
        NonEqualVector(loctestnum,loctesterr,movedVec,originalVec,true);
        Empty(loctestnum, loctesterr, originalVec, true); 

        // Copy assignment
        lasd::Vector<char> assignedVec;
        assignedVec = copiedVec;
        EqualVector(loctestnum,loctesterr,assignedVec,copiedVec,true);

        // Move assignment
        lasd::Vector<char> moveAssignedVec;
        moveAssignedVec = std::move(copiedVec);
        NonEqualVector(loctestnum,loctesterr,moveAssignedVec,copiedVec,true);
        Empty(loctestnum, loctesterr, copiedVec, true);
        
        // SortableVectors copyConstructor
        lasd::SortableVector<char> sortedVectorByCopy(moveAssignedVec);
        EqualVector(loctestnum,loctesterr,moveAssignedVec,sortedVectorByCopy,true);
    }
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<char> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalStringVectorTest(uint &testnum, uint &testerr)
{

    std::cout << "\033[4;36m<<Testing vector of strings>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 26);

    // Container tests
    {
        lasd::Vector<string> v1;
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);

        // Resizing vector with random size and checking new Size
        ulong newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(dist(gen) + 96);
            }
            SetAt(loctestnum, loctesterr, v1, true, i, temp);
        }
        newDim = dist(gen);
        v1.Resize(newDim);
        Empty(loctestnum, loctesterr, v1, false);
        Size(loctestnum, loctesterr, v1, true, newDim);
        // Insert some elements into the vector
        for (ulong i = 0; i < newDim; i++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(dist(gen) + 96);
            }
            SetAt(loctestnum, loctesterr, v1, true, i, temp);
        }
        v1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, v1, true);
        // Size
        Size(loctestnum, loctesterr, v1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::Vector<string> v2(10);
        string elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(dist(gen) + 96);
            }
            elements[index] = temp;
            SetAt(loctestnum, loctesterr, v2, true, index, elements[index]);
        }
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, elements[n]);
            }
        }
        v2.Clear();
        v2.Resize(10);
        for (ulong index = 0; index < 10; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(dist(gen) + 96);
            }
            v2[index] = temp;
        }
        // Check for non existence of values in v2
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, v2, true, v2[n]);
            }
            else
            {
                std::string temp;
                for (int j = 0; j < 5; j++)
                {
                    temp += static_cast<char>(dist(gen) + 96);
                }
                Exists(loctestnum, loctesterr, v2, false, temp);
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::Vector<string> v3(20);
        for (ulong index = 0; index < 20; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(dist(gen) + 96);
            }
            v3[index] = temp;
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<string>);

        // v3 = ["a","b",...,"z"]
        v3.Resize(26);
        for (ulong index = 0; index < 26; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(index + 97);
            }
            v3[index] = temp;
        }
        Traverse(loctestnum, loctesterr, v3, true, TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<string>);

        lasd::Vector<string> v4(7);
        v4[0] = std::string("Hello");
        v4[1] = std::string("world");
        v4[2] = std::string("123");
        v4[3] = std::string("C++");
        v4[4] = std::string("");
        v4[5] = std::string("HELLO");
        Fold(loctestnum, loctesterr, v4, true, FoldStringConcatenate, std::string(""), std::string("Helloworld123C++HELLO"));
        FoldPostOrder(loctestnum, loctesterr, v4, true, TotalLength, 0, 21);
        FoldPreOrder(loctestnum, loctesterr, v4, true, CountAllUpper, 0, 1);
    }

    // MappableContainer features testing
    {
        lasd::Vector<string> v4(26);
        for (ulong index = 0; index < 26; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(index + 97);
            }
            v4[index] = temp;
        }
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<string>);
        Map(loctestnum, loctesterr, v4, true, ToLowerStr);
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<string>);
        MapPostOrder(loctestnum, loctesterr, v4, true, AppendDot);
        Traverse(loctestnum, loctesterr, v4, true, TraversePrint<string>);
    }

    // LinearContaiener features testing
    {
        lasd::Vector<string> vec(5);
        for (ulong index = 0; index < 5; ++index)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += static_cast<char>(index + 97);
            }
            vec[index] = temp;
        }
        GetFront(loctestnum, loctesterr, vec, true, std::string("aaaaa"));
        GetBack(loctestnum, loctesterr, vec, true, std::string("eeeee"));

        for (ulong i = 0; i < 5; ++i)
        {
            GetAt(loctestnum, loctesterr, vec, true, i, vec[i]);
        }

        {
            lasd::SortableVector<std::string> vec(5);
            vec[0] = "apple";
            vec[1] = "orange";
            vec[2] = "banana";
            vec[3] = "grape";
            vec[4] = "pear";
            NonSortedLinear(loctestnum, loctesterr, vec, true);
            vec.Sort();
            SortedLinear(loctestnum, loctesterr, vec, true);
            GetFront(loctestnum, loctesterr, vec, true, std::string("apple"));
            GetBack(loctestnum, loctesterr, vec, true, std::string("pear"));

            SetFront(loctestnum, loctesterr, vec, true, std::string("kiwi"));
            NonSortedLinear(loctestnum, loctesterr, vec, true);
        }
    }
    
    // Vector features testing
    {
        std::uniform_int_distribution<ulong> sizeDist(10, 50);

        ulong size = sizeDist(gen);
        lasd::Vector<string> originalVec(size);
        for (ulong i = 0; i < size; ++i)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
            temp += static_cast<char>(dist(gen) + 96);
            }
            originalVec[i] = temp;
        }

        // Copy constructor
        lasd::Vector<string> copiedVec(originalVec);
        for (ulong i = 0; i < size; ++i)
        {
            GetAt(loctestnum, loctesterr, copiedVec, true, i, originalVec[i]);
        }
        EqualVector(loctestnum, loctesterr, copiedVec, originalVec, true);

        // Move constructor
        lasd::Vector<string> movedVec(std::move(originalVec));
        for (ulong i = 0; i < size; ++i)
        {
            GetAt(loctestnum, loctesterr, movedVec, true, i, copiedVec[i]);
        }
        EqualVector(loctestnum, loctesterr, movedVec, copiedVec, true);
        NonEqualVector(loctestnum, loctesterr, movedVec, originalVec, true);
        Empty(loctestnum, loctesterr, originalVec, true); // originalVec should now be empty

        // Copy assignment
        lasd::Vector<string> assignedVec;
        assignedVec = copiedVec;
        for (ulong i = 0; i < size; ++i)
        {
            GetAt(loctestnum, loctesterr, assignedVec, true, i, copiedVec[i]);
        }
        EqualVector(loctestnum, loctesterr, assignedVec, copiedVec, true);

        // Move assignment
        lasd::Vector<string> moveAssignedVec;
        moveAssignedVec = std::move(copiedVec);
        for (ulong i = 0; i < size; ++i)
        {
            GetAt(loctestnum, loctesterr, moveAssignedVec, true, i, movedVec[i]);
        }
        EqualVector(loctestnum, loctesterr, moveAssignedVec, assignedVec, true);
        NonEqualVector(loctestnum, loctesterr, moveAssignedVec, copiedVec, true);
        Empty(loctestnum, loctesterr, copiedVec, true); // copiedVec should now be empty
    }
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<string> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}
/*****************************************************************************************/
void PersonalIntListTest(uint &testnum, uint &testerr)
{
    std::cout << "\033[4;36m<<Testing list of integers>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);

    // Container features testing
    {
        lasd::List<int> l1;
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);

        // Insert some elements into the list
        ulong newDim = dist(gen);
        for (ulong i = 0; i < newDim; i++)
        {
            InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
        }
        Empty(loctestnum, loctesterr, l1, false);
        Size(loctestnum, loctesterr, l1, true, newDim);
        l1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::List<int> l2;
        int elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            elements[index] = dist(gen);
            InsertAtFront(loctestnum, loctesterr, l2, true, elements[index]);
        }
        int num;
        for (ulong n = 0; n < 20; n++)
        {
            num = dist(gen) % 20;
            if (num < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, elements[num]);
            }
        }
        l2.Clear();
        for (ulong index = 0; index < 10; index++)
        {
            l2.InsertAtBack((index + 1) * 10);
        }
        // Checks for non existence
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, (int)((n + 1) * 10));
            }
            else if (n > 10)
            {
                Exists(loctestnum, loctesterr, l2, false, (int)(n * 10));
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::List<int> l3;
        for (ulong index = 0; index < 20; index++)
        {
            l3.InsertAtBack(dist(gen));
        }
        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<int>);

        ulong newDim = dist(gen);
        // l3 = [1,2,...,newDim]
        l3.Clear();
        for (ulong index = 0; index < newDim; index++)
        {
            l3.InsertAtFront(index + 1);
        }

        // Using fold fun using known mathematical formulas:
        int sum = (newDim * (newDim + 1)) / 2;
        Fold(loctestnum, loctesterr, l3, true, FoldAdd<int>, 0, sum);
        FoldPostOrder(loctestnum, loctesterr, l3, true, FoldAdd<int>, 0, sum);
        FoldPostOrder(loctestnum, loctesterr, l3, true, FoldAdd<int>, 0, sum);
        int sum2 = (newDim * (newDim + 1) * (newDim * 2 + 1)) / 6;
        Fold(loctestnum, loctesterr, l3, true, [](const int &dat, const int &sum)
             { return (sum + dat * dat); }, 0, sum2);
    }

    // MappableContainer
    {
        lasd::List<int> l4;
        l4.InsertAtBack(1);
        l4.InsertAtBack(2);
        l4.InsertAtBack(3);
        Map(loctestnum, loctesterr, l4, true, IncrementInt);
        // l4 = [2,3,4]
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<int>);
        MapPostOrder(loctestnum, loctesterr, l4, true, SquareInt);
        // l4 = [4,9,16];
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<int>);
    }

    // LinearContainer features testing
    {
        lasd::List<int> l1;
        for (ulong index = 0; index < 5; ++index)
        {
            l1.InsertAtBack(index + 1);
        }
        GetFront(loctestnum, loctesterr, l1, true, 1);
        GetBack(loctestnum, loctesterr, l1, true, 5);

        for (ulong i = 0; i < 5; ++i)
        {
            GetAt(loctestnum, loctesterr, l1, true, i, (int)(i + 1));
        }

        SetAt(loctestnum, loctesterr, l1, true, 2, 10);
        GetAt(loctestnum, loctesterr, l1, true, 2, 10);

        SetFront(loctestnum, loctesterr, l1, true, 100);
        SetBack(loctestnum, loctesterr, l1, true, 200);
        GetFront(loctestnum, loctesterr, l1, true, 100);
        GetBack(loctestnum, loctesterr, l1, true, 200);
    }

    // List features testing
    {
        
    }
    std::cout << "\033[4;36mEnd of List<int> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void PersonalDoubleListTest(uint &testnum, uint &testerr)
{
    std::cout << "\033[4;36m<<Testing list of doubles>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0, 20.0);

    // Container features testing
    {
        lasd::List<double> l1;
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);

        // Insert some elements into the list
        ulong newDim = dist(gen);
        for (ulong i = 0; i < newDim; i++)
        {
            InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
        }
        Empty(loctestnum, loctesterr, l1, false);
        Size(loctestnum, loctesterr, l1, true, newDim);
        l1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::List<double> l2;
        double elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            elements[index] = dist(gen);
            InsertAtFront(loctestnum, loctesterr, l2, true, elements[index]);
        }
        std::uniform_real_distribution<double> dist2(200.0, 400.0);
        double num;
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, elements[n]);
            }
            else
            {
                num = dist2(gen);
                Exists(loctestnum, loctesterr, l2, false, num);
            }
        }
        l2.Clear();
        for (ulong index = 0; index < 10; index++)
        {
            // Add double numbers 1.1, 2.2, 3.3
            l2.InsertAtBack((index + 1) * 1.1);
        }
        // Checks for non existence
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, (double)((n + 1) * 1.1));
            }
            else if (n > 10)
            {
                Exists(loctestnum, loctesterr, l2, false, (double)(n * 1.1));
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::List<double> l3;
        for (ulong index = 0; index < 20; index++)
        {
            l3.InsertAtBack(dist(gen));
        }
        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<double>);

        ulong newDim = dist(gen);
        // l3 = [1.1,2.2,...,newDim]
        for (ulong index = 0; index < newDim; index++)
        {
            l3[index] = (index + 1) * 1.1;
        }

        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<double>);
    }

    // MappableContainer features testing
    {
        lasd::List<double> l4;
        l4.InsertAtBack(2.6);
        l4.InsertAtBack(3.1);
        l4.InsertAtBack(4.5);
        Map(loctestnum, loctesterr, l4, true, RoundDouble);
        // l4 = [3,3,5]
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<double>);
        MapPostOrder(loctestnum, loctesterr, l4, true, Reciprocal);
        // l4 = [0.3,0.3,0.5]
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<double>);
    }

    // LinearContainer features testing
    {
        lasd::List<double> l1;
        for (ulong index = 0; index < 5; ++index)
        {
            l1.InsertAtBack((index + 1) * 1.1);
        }
        GetFrontDouble(loctestnum, loctesterr, l1, true, 1.1, 0.001);
        GetBackDouble(loctestnum, loctesterr, l1, true, 5.5, 0.001);

        for (ulong i = 0; i < 5; ++i)
        {
            GetAtDouble(loctestnum, loctesterr, l1, true, i, (double)((i + 1) * 1.1), 0.001);
        }

        SetAt(loctestnum, loctesterr, l1, true, 2, 10.5);
        GetAtDouble(loctestnum, loctesterr, l1, true, 2, 10.5, 0.001);

        SetFront(loctestnum, loctesterr, l1, true, 100.5);
        SetBack(loctestnum, loctesterr, l1, true, 200.5);
        GetFrontDouble(loctestnum, loctesterr, l1, true, 100.5, 0.001);
        GetBackDouble(loctestnum, loctesterr, l1, true, 200.5, 0.001);
    }
    std::cout << "\033[4;36mEnd of List<double> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void PersonalCharListTest(uint &testnum, uint &testerr)
{
    std::cout << "\033[4;36m<<Testing list of chars>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;
    // Random char generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(97, 122);

    // Container features testing
    {
        lasd::List<char> l1;
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);

        // Insert some elements into the list
        ulong newDim = dist(gen);
        for (ulong i = 0; i < newDim; i++)
        {
            InsertAtFront(loctestnum, loctesterr, l1, true, (char)dist(gen));
        }
        Empty(loctestnum, loctesterr, l1, false);
        Size(loctestnum, loctesterr, l1, true, newDim);
        l1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::List<char> l2;
        char elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            elements[index] = (char)dist(gen);
            InsertAtFront(loctestnum, loctesterr, l2, true, elements[index]);
        }
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, elements[n]);
            }
        }
        l2.Clear();
        for (ulong index = 0; index < 26; index++)
        {
            // Add chars 'a', 'b', 'c'
            l2.InsertAtBack((char)(index + 96));
        }
        // Check for non existence of values in v2
        ulong num;
        for (ulong n = 0; n < 20; n++)
        {
            num = dist(gen) % 50;
            if (num < 26)
            {
                Exists(loctestnum, loctesterr, l2, true, (char)(num + 96));
            }
            else
            {
                Exists(loctestnum, loctesterr, l2, false, (char)(num + 96));
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::List<char> l3;
        for (ulong index = 0; index < 20; index++)
        {
            l3.InsertAtBack((char)dist(gen));
        }
        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<char>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<char>);

        // l3 = ['a','b',...,'z']
        l3.Clear();
        for (ulong index = 0; index < 26; index++)
        {
            l3.InsertAtBack((char)(index + 97));
        }
        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<char>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<char>);

        // Fold functions
        Fold(loctestnum, loctesterr, l3, true, LowerCaseVectorFold, true, true);
        FoldPostOrder(loctestnum, loctesterr, l3, true, LowerCaseVectorFold, true, true);

        lasd::List<char> l4;
        l4.InsertAtBack('A');
        l4.InsertAtBack('b');
        l4.InsertAtBack('c');
        l4.InsertAtBack('D');
        l4.InsertAtBack('e');
        l4.InsertAtBack('1');
        l4.InsertAtBack('z');
        Fold(loctestnum, loctesterr, l4, true, ConcatCharFold, std::string(""), std::string("AbcDe1z"));
        FoldPostOrder(loctestnum, loctesterr, l4, true, VowelCountFold, 0, 2);
        FoldPreOrder(loctestnum, loctesterr, l4, true, AsciiSumFold, 0, 602);
    }

    // MappableContainer features testing
    {
        lasd::List<char> l4;
        for (ulong index = 0; index < 26; index++)
        {
            l4.InsertAtBack((char)(index + 97));
        }
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<char>);
        Map(loctestnum, loctesterr, l4, true, ToUpperChar);
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<char>);
    }

    // LinearContainer features testing
    {
        lasd::List<char> l1;
        for (ulong index = 0; index < 5; ++index)
        {
            l1.InsertAtBack((char)(index + 97));
        }
        GetFront(loctestnum, loctesterr, l1, true, 'a');
        GetBack(loctestnum, loctesterr, l1, true, 'e');

        for (ulong i = 0; i < 5; ++i)
        {
            GetAt(loctestnum, loctesterr, l1, true, i, (char)(i + 97));
        }

        SetAt(loctestnum, loctesterr, l1, true, 2, 'z');
        GetAt(loctestnum, loctesterr, l1, true, 2, 'z');

        SetFront(loctestnum, loctesterr, l1, true, 'Z');
        SetBack(loctestnum, loctesterr, l1, true, 'Y');
        GetFront(loctestnum, loctesterr, l1, true, 'Z');
        GetBack(loctestnum, loctesterr, l1, true, 'Y');
    }
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of List<char> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalStringList(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing list of strings>>\033[0m" << std::endl;
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 26);

    // Container test features
    {
        lasd::List<string> l1;
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);

        // Insert some elements into the list
        ulong newDim = dist(gen);
        for (ulong i = 0; i < newDim; i++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(dist(gen) + 96);
            }
            InsertAtFront(loctestnum, loctesterr, l1, true, temp);
        }
        Empty(loctestnum, loctesterr, l1, false);
        Size(loctestnum, loctesterr, l1, true, newDim);
        l1.Clear();
        // Empty
        Empty(loctestnum, loctesterr, l1, true);
        // Size
        Size(loctestnum, loctesterr, l1, true, 0);
    }

    // TestableContainer features testing
    {
        lasd::List<string> l2;
        string elements[10];
        for (ulong index = 0; index < 10; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(dist(gen) + 96);
            }
            elements[index] = temp;
            InsertAtFront(loctestnum, loctesterr, l2, true, elements[index]);
        }
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, elements[n]);
            }
        }
        l2.Clear();
        for (ulong index = 0; index < 10; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(dist(gen) + 96);
            }
            l2.InsertAtBack(temp);
        }
        // Check for non existence of values in v2
        for (ulong n = 0; n < 20; n++)
        {
            if (n < 10)
            {
                Exists(loctestnum, loctesterr, l2, true, l2[n]);
            }
            else
            {
                std::string temp;
                for (int j = 0; j < 5; j++)
                {
                    temp += (char)(dist(gen) + 96);
                }
                Exists(loctestnum, loctesterr, l2, false, temp);
            }
        }
    }

    // TraversableContainer features testing
    {
        lasd::List<string> l3;
        for (ulong index = 0; index < 20; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(dist(gen) + 96);
            }
            l3.InsertAtBack(temp);
        }
        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<string>);

        // l3 = ["a","b",...,"z"]
        for (ulong index = 0; index < 26; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(index + 97);
            }
            l3.InsertAtBack(temp);
        }
        Traverse(loctestnum, loctesterr, l3, true, TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<string>);

        lasd::List<string> l4;
        l4.InsertAtBack("Hello");
        l4.InsertAtBack("world");
        l4.InsertAtBack("123");
        l4.InsertAtBack("C++");
        l4.InsertAtBack("");
        l4.InsertAtBack("HELLO");
        Fold(loctestnum, loctesterr, l4, true, FoldStringConcatenate, std::string(""), std::string("Helloworld123C++HELLO"));
        FoldPostOrder(loctestnum, loctesterr, l4, true, TotalLength, 0, 21);
        FoldPreOrder(loctestnum, loctesterr, l4, true, CountAllUpper, 0, 1);
    }

    // MappableContainer features testing
    {
        lasd::List<string> l4;
        for (ulong index = 0; index < 26; index++)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(index + 97);
            }
            l4.InsertAtBack(temp);
        }
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<string>);
        Map(loctestnum, loctesterr, l4, true, ToLowerStr);
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<string>);
        MapPostOrder(loctestnum, loctesterr, l4, true, AppendDot);
        Traverse(loctestnum, loctesterr, l4, true, TraversePrint<string>);
    }

    // LinearContainer features testing
    {
        lasd::List<string> l1;
        for (ulong index = 0; index < 5; ++index)
        {
            std::string temp;
            for (int j = 0; j < 5; j++)
            {
                temp += (char)(index + 97);
            }
            l1.InsertAtBack(temp);
        }
        GetFront(loctestnum, loctesterr, l1, true, std::string("aaaaa"));
        GetBack(loctestnum, loctesterr, l1, true, std::string("eeeee"));

        for (ulong i = 0; i < 5; ++i)
        {
            GetAt(loctestnum, loctesterr, l1, true, i, l1[i]);
        }

        SetAt(loctestnum, loctesterr, l1, true, 2, std::string("zzzzz"));
        GetAt(loctestnum, loctesterr, l1, true, 2, std::string("zzzzz"));

        SetFront(loctestnum, loctesterr, l1, true, std::string("ZZZZZ"));
        SetBack(loctestnum, loctesterr, l1, true, std::string("YYYYY"));
        GetFront(loctestnum, loctesterr, l1, true, std::string("ZZZZZ"));
        GetBack(loctestnum, loctesterr, l1, true, std::string("YYYYY"));
    }
    std::cout << "\033[4;36mEnd of List<string> Pesonal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
/*****************************************************************************************/
void PersonalIntVectorListTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector & lists of integers>>\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector&List<int> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalDoubleVectorList(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector & lists of doubles>>\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector&List<double> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalCharVectorList(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector & lists of chars>>\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector&List<char> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

/*****************************************************************************************/
void PersonalTestVector(uint &testnum, uint &testerr)
{
    std::cout << std::endl;
    std::cout << "\033[1;4;35mBegin of Vector Personal Tests\033[0m" << std::endl;
    uint tottest = 0;
    uint toterr = 0;
    uint loctest = 0;
    uint errtest = 0;
    PersonalIntVectorTest(loctest, errtest);
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    PersonalDoubleVectorTest(loctest, errtest);
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    PersonalStringVectorTest(loctest, errtest);
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    PersonalCharVectorTest(loctest, errtest);
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;4;35mVector personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;
}

void PersonalTestList(uint &testnum, uint &testerr)
{
    std::cout << std::endl;
    std::cout << "\033[1;35mBegin of List Personal Tests\033[0m" << std::endl;
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;

    PersonalIntListTest(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;

    PersonalDoubleListTest(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;

    PersonalStringList(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;

    PersonalCharListTest(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mList personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    std::cout << std::endl;
    testnum += tottest;
    testerr += toterr;
}

void PersonalVectorListTest(uint &testnum, uint &testerr)
{
    std::cout << std::endl;
    std::cout << "\033[1;35mBegin of Vector/List Personal Tests\033[0m" << std::endl;
    uint tottest = 0;
    uint toterr = 0;

    uint loctest = 0;
    uint errtest = 0;
    std::cout << std::endl;
    PersonalIntVectorListTest(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;

    PersonalDoubleVectorList(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;

    PersonalCharVectorList(loctest, errtest);

    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mVector & Lists personal tests ended: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum += tottest;
    testerr += toterr;
    std::cout << std::endl;
}
/*****************************************************************************************/
void myTestExercise1A(unsigned int &testnum, unsigned int &testerr)
{
    PersonalTestVector(testnum, testerr);
    PersonalTestList(testnum, testerr);
    PersonalVectorListTest(testnum, testerr);

    cout << endl
         << "\033[1;34mExercise 1A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << endl;
}
