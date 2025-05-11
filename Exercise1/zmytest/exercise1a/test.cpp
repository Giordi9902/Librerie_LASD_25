#include <iostream>
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../mycontainer/mylinear.hpp"
#include "../mycontainer/mytraversable.hpp"
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
    // Container tests

    // Declaring first vector
    lasd::Vector<int> v1;
    // Empty
    Empty(loctestnum, loctesterr, v1, true);
    // Size
    Size(loctestnum, loctesterr, v1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);
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

    // Testing TestableContainer features

    // Declaring new vector for testing if TestableContainer features work
    lasd::Vector<int> v2(5);
    SetAt(loctestnum, loctesterr, v2, true, 0, 6);
    SetAt(loctestnum, loctesterr, v2, true, 1, 5);
    SetAt(loctestnum, loctesterr, v2, true, 2, 4);
    SetAt(loctestnum, loctesterr, v2, true, 3, 3);
    SetAt(loctestnum, loctesterr, v2, true, 4, 2);
    Exists(loctestnum, loctesterr, v2, false, 9);
    Exists(loctestnum, loctesterr, v2, false, 29);
    Exists(loctestnum, loctesterr, v2, false, 21);
    Exists(loctestnum, loctesterr, v2, false, 2342);
    Exists(loctestnum, loctesterr, v2, true, 2);
    Exists(loctestnum, loctesterr, v2, true, 3);
    Exists(loctestnum, loctesterr, v2, true, 4);
    Exists(loctestnum, loctesterr, v2, true, 5);
    Exists(loctestnum, loctesterr, v2, true, 6);

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<int>);

    // Declaring new vector with random size
    newDim = dist(gen);
    lasd::Vector<int> v3(newDim);
    for (ulong index = 0; index < newDim; index++)
    {
        v3[index] = dist(gen);
    }

    // Traversing v3 in PreOrder and PostOrder
    Traverse(loctestnum, loctesterr, v3, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, v3, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<int>);

    // Declaring new vector with 10 elements
    lasd::Vector<long> v4(10);

    // Adding first 10 odd numbers
    for (int i = 0, odd = 1; i < 10; ++i, odd += 2)
    {
        v4[i] = odd;
    }
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<int>);

    // Attempting Fold operations on v4
    Fold(loctestnum, loctesterr, v4, true, FoldAdd<int>, 0, 100);
    FoldPreOrder(loctestnum, loctesterr, v4, true, FoldAdd<int>, 0, 100);
    FoldPostOrder(loctestnum, loctesterr, v4, true, FoldAdd<int>, 0, 100);
    Fold(loctestnum, loctesterr, v4, true, FoldMultiply<int>, 1, 654729075);
    FoldPreOrder(loctestnum, loctesterr, v4, true, FoldMultiply<int>, 1, 654729075);
    FoldPostOrder(loctestnum, loctesterr, v4, true, FoldMultiply<int>, 1, 654729075);

    // Testing MappableContainer features

    // Increment all elements in the vector by 1 and print the vector
    Map(loctestnum, loctesterr, v4, true, MapIncrement<long>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);

    // Fold the vector by summing all elements, expecting a total of 110
    Fold(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 110);

    // Decrement all elements in the vector by 1 and print the vector
    Map(loctestnum, loctesterr, v4, true, MapDecrement<long>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);

    // Fold the vector by summing all elements, expecting a total of 100
    Fold(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 100);
    FoldPreOrder(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 100);
    FoldPostOrder(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 100);

    // Increment all elements in the vector by 1 again and print the vector
    Map(loctestnum, loctesterr, v4, true, MapIncrement<long>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);

    // Fold the vector by multiplying all elements, expecting a product of 3715891200
    Fold(loctestnum, loctesterr, v4, true, FoldMultiply<long>, (long)1, 3715891200);
    FoldPreOrder(loctestnum, loctesterr, v4, true, FoldMultiply<long>, (long)1, 3715891200);
    FoldPostOrder(loctestnum, loctesterr, v4, true, FoldMultiply<long>, (long)1, 3715891200);

    // Halve all elements in the vector
    Map(loctestnum, loctesterr, v4, true, MapHalf<long>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);

    // Fold the vector by summing all elements, expecting a total of 55
    Fold(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 55);
    FoldPreOrder(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 55);
    FoldPostOrder(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 55);

    // Double all elements in the vector
    Map(loctestnum, loctesterr, v4, true, MapDouble<long>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);

    // Fold the vector by summing all elements, expecting a total of 110
    Fold(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 110);
    FoldPreOrder(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 110);
    FoldPostOrder(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, 110);

    // Invert the sign of all elements in the vector
    Map(loctestnum, loctesterr, v4, true, MapInvert<long>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<long>);

    // Fold the vector by summing all elements, expecting a total of -110
    Fold(loctestnum, loctesterr, v4, true, FoldAdd<long>, 0, -110);

    // Testing PreOrderMap and PostOrderMap

    // Declaring a new vector with 10 elements (1,...,9)
    lasd::Vector<int> v5(10);
    for (int i = 0; i < 10; ++i)
    {
        v5[i] = i + 1;
    }
    MapPreOrder(loctestnum, loctesterr, v5, true, MapDoubleNPrint<int>);
    MapPostOrder(loctestnum, loctesterr, v5, true, MapInvertNPrint<int>);

    // Testing LinearContainer features

    // Create a new vector v6 as a copy of v5
    lasd::Vector<int> v6 = v5;
    // Check the size of v6 (should be 10)
    Size(loctestnum, loctesterr, v6, true, 10);
    // Verify that v5 and v6 are equal
    EqualLinear(loctestnum, loctesterr, v5, v6, true);
    // Verify that v1 and v3 are not equal
    EqualLinear(loctestnum, loctesterr, v1, v3, false);
    // Verify that v1 and v5 are not equal
    NonEqualLinear(loctestnum, loctesterr, v1, v5, true);

    // Move v6 into a new sortable vector v7
    lasd::SortableVector<int> v7(std::move(v6));
    Size(loctestnum, loctesterr, v7, true, 10);
    Size(loctestnum, loctesterr, v6, true, 10);
    NonEqualLinear(loctestnum, loctesterr, v6, v7, true);
    Empty(loctestnum, loctesterr, v6, false);
    Traverse(loctestnum, loctesterr, v6, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, v7, true, TraversePrint<int>);

    // Check if v7 is sorted (should be true since v6 was sorted)
    SortedLinear(loctestnum, loctesterr, v7, true);
    // Create a new sortable vector v8 as a copy of v1
    lasd::SortableVector<int> v8(v1);
    // Check if v8 is not sorted (should be true since v1 might not be sorted)
    NonSortedLinear(loctestnum, loctesterr, v8, true);
    // Verify the content of v5 by checking each element
    Traverse(loctestnum, loctesterr, v5, true, TraversePrint<int>);
    // Check the first element of v5 (should be -2)
    GetFront(loctestnum, loctesterr, v5, true, -2);
    // Check the last element of v5 (should be -20)
    GetBack(loctestnum, loctesterr, v5, true, -20);
    // Set the first element of v7 to 12
    SetFront(loctestnum, loctesterr, v7, true, 12);
    // Verify that v7 is no longer sorted
    NonSortedLinear(loctestnum, loctesterr, v7, true);
    // Set the last element of v5 to 0
    SetBack(loctestnum, loctesterr, v5, true, 0);
    GetAt(loctestnum, loctesterr, v7, false, 33, 0);
    GetAt(loctestnum, loctesterr, v7, false, -1, 3);
    GetAt(loctestnum, loctesterr, v7, false, 10, 32);

    // Test Vector features
    lasd::Vector<int> v9 = v7;
    EqualVector(loctestnum, loctesterr, v9, v7, true);
    NonEqualVector(loctestnum, loctesterr, v9, v6, true);

    // Move assigment from v2 containing 5 elements
    v9 = std::move(v2);
    Size(loctestnum, loctesterr, v9, true, 5);
    Size(loctestnum, loctesterr, v2, true, 10);

    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<int> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalDoubleVectorTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector of doubles>>\033[0m" << std::endl;
    // Container tests
    // Declaring first vector
    lasd::Vector<double> v1;
    // Empty
    Empty(loctestnum, loctesterr, v1, true);
    // Size
    Size(loctestnum, loctesterr, v1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0, 20.0);
    // Resizing vector with random size and checking new Size
    ulong newDim = gen() % 20 + 1;
    v1.Resize(newDim);
    Empty(loctestnum, loctesterr, v1, false);
    Size(loctestnum, loctesterr, v1, true, newDim);
    // Insert some elements into the vector
    for (ulong i = 0; i < newDim; i++)
    {
        SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
    }
    newDim = gen() % 20 + 1;
    v1.Resize(newDim);
    Empty(loctestnum, loctesterr, v1, false);
    Size(loctestnum, loctesterr, v1, true, newDim);
    // Insert some elements into the vector
    for (ulong i = 0; i < newDim; i++)
    {
        SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
    }

    // Testing TestableContainer features

    // Declaring new vector for testing if TestableContainer features work
    lasd::Vector<double> v2(5);
    SetAt(loctestnum, loctesterr, v2, true, 0, 6.5);
    SetAt(loctestnum, loctesterr, v2, true, 1, 5.5);
    SetAt(loctestnum, loctesterr, v2, true, 2, 4.5);
    SetAt(loctestnum, loctesterr, v2, true, 3, 3.5);
    SetAt(loctestnum, loctesterr, v2, true, 4, 2.5);
    Exists(loctestnum, loctesterr, v2, false, 9.0);
    Exists(loctestnum, loctesterr, v2, false, 29.0);
    Exists(loctestnum, loctesterr, v2, false, 21.0);
    Exists(loctestnum, loctesterr, v2, false, 2342.0);
    Exists(loctestnum, loctesterr, v2, true, 2.5);
    Exists(loctestnum, loctesterr, v2, true, 3.5);
    Exists(loctestnum, loctesterr, v2, true, 4.5);
    Exists(loctestnum, loctesterr, v2, true, 5.5);
    Exists(loctestnum, loctesterr, v2, true, 6.5);

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<double>);

    // Declaring new vector with random size
    newDim = gen() % 20 + 1;
    lasd::Vector<double> v3(newDim);
    for (ulong index = 0; index < newDim; index++)
    {
        v3[index] = dist(gen);
    }

    // Traversing v3 in PreOrder and PostOrder
    Traverse(loctestnum, loctesterr, v3, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, v3, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<double>);

    // Declaring new vector with 10 elements
    lasd::Vector<double> v4(10);

    // Adding first 10 odd numbers
    for (int i = 0; i < 10; ++i)
    {
        v4[i] = static_cast<double>(i + 1) * 1.1;
    }
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<double>);

    // Attempting Fold operations on v4
    FoldDouble(loctestnum, loctesterr, v4, true, FoldAdd<double>, 0.0, 60.50, 1e-9);
    PreOrderFoldDouble(loctestnum, loctesterr, v4, true, FoldAdd<double>, 0.0, 60.50, 1e-9);
    PostOrderFoldDouble(loctestnum, loctesterr, v4, true, FoldAdd<double>, 0.0, 60.50, 1e-9);

    // Testing MappableContainer features

    // Increment all elements in the vector by 1 and print the vector
    Map(loctestnum, loctesterr, v4, true, MapIncrement<double>);
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<double>);

    // Testing PreOrderMap and PostOrderMap
    MapPreOrder(loctestnum, loctesterr, v4, true, MapDoubleNPrint<double>);
    MapPostOrder(loctestnum, loctesterr, v4, true, MapInvertNPrint<double>);

    // Testing LinearContainer features

    // Create a new vector v6 as a copy of v5
    lasd::Vector<double> v6 = v4;
    // Check the size of v6 (should be 10)
    Size(loctestnum, loctesterr, v6, true, 10);
    // Verify that v5 and v6 are equal
    EqualLinear(loctestnum, loctesterr, v4, v6, true);
    // Verify that v1 and v3 are not equal
    EqualLinear(loctestnum, loctesterr, v1, v3, false);
    // Verify that v1 and v5 are not equal
    NonEqualLinear(loctestnum, loctesterr, v1, v4, true);

    // Move v6 into a new sortable vector v7
    lasd::SortableVector<double> v7(std::move(v6));
    Size(loctestnum, loctesterr, v7, true, 10);
    Size(loctestnum, loctesterr, v6, true, 10);
    NonEqualLinear(loctestnum, loctesterr, v6, v7, true);
    Empty(loctestnum, loctesterr, v6, false);
    Traverse(loctestnum, loctesterr, v6, true, TraversePrint<double>);
    Traverse(loctestnum, loctesterr, v7, true, TraversePrint<double>);

    // Check if v7 is sorted (should be true since v6 was sorted)
    SortedLinear(loctestnum, loctesterr, v7, true);
    // Create a new sortable vector v8 as a copy of v1
    lasd::SortableVector<double> v8(v1);
    // Check if v8 is not sorted (should be true since v1 might not be sorted)
    NonSortedLinear(loctestnum, loctesterr, v8, true);
    // Verify the content of v5 by checking each element
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<double>);
    // Check the first element of v5 (should be -2)
    GetFrontDouble(loctestnum, loctesterr, v4, true, -4.2, 1e-9);
    // Check the last element of v5 (should be -20)
    GetBackDouble(loctestnum, loctesterr, v4, true, -24.0, 1e-9);
    // Set the first element of v7 to 12
    SetFront(loctestnum, loctesterr, v7, true, 12.0);
    // Verify that v7 is no longer sorted
    NonSortedLinear(loctestnum, loctesterr, v7, true);
    // Set the last element of v5 to 0
    SetBack(loctestnum, loctesterr, v4, true, 0.0);
    GetAt(loctestnum, loctesterr, v7, false, 33, 0.0);
    GetAt(loctestnum, loctesterr, v7, false, -1, 3.3);
    GetAt(loctestnum, loctesterr, v7, false, 10, 32.0);

    // Test Vector features
    lasd::Vector<double> v9 = v7;
    EqualVector(loctestnum, loctesterr, v9, v7, true);
    NonEqualVector(loctestnum, loctesterr, v9, v6, true);

    // Move assigment from v2 containing 5 elements
    v9 = std::move(v2);
    Size(loctestnum, loctesterr, v9, true, 5);
    Size(loctestnum, loctesterr, v2, true, 10);

    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<double> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalCharVectorTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector of chars>>\033[0m" << std::endl;

    // Container tests

    // Declaring first vector with random chars
    lasd::Vector<char> v1;
    // Empty
    Empty(loctestnum, loctesterr, v1, true);
    // Size
    Size(loctestnum, loctesterr, v1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(97, 122);
    // Resizing vector with random size and checking new Size
    ulong newDim = gen() % 100 + 1;
    v1.Resize(newDim);
    Empty(loctestnum, loctesterr, v1, false);
    Size(loctestnum, loctesterr, v1, true, newDim);
    // Insert some elements into the vector
    for (ulong i = 0; i < newDim; i++)
    {
        SetAt(loctestnum, loctesterr, v1, true, i, static_cast<char>(dist(gen)));
    }
    newDim = gen() % 20 + 1;
    v1.Resize(newDim);
    Empty(loctestnum, loctesterr, v1, false);
    Size(loctestnum, loctesterr, v1, true, newDim);
    // Insert some elements into the vector
    for (ulong i = 0; i < newDim; i++)
    {
        SetAt(loctestnum, loctesterr, v1, true, i, static_cast<char>(dist(gen)));
    }

    // Testing TestableContainer features
    // Declaring new vector for testing if TestableContainer features work
    lasd::Vector<char> v2(5);
    SetAt(loctestnum, loctesterr, v2, true, 0, 'f');
    SetAt(loctestnum, loctesterr, v2, true, 1, 'e');
    SetAt(loctestnum, loctesterr, v2, true, 2, 'd');
    SetAt(loctestnum, loctesterr, v2, true, 3, 'c');
    SetAt(loctestnum, loctesterr, v2, true, 4, 'b');

    Exists(loctestnum, loctesterr, v2, false, 'i');
    Exists(loctestnum, loctesterr, v2, false, 'y');
    Exists(loctestnum, loctesterr, v2, false, 'u');
    Exists(loctestnum, loctesterr, v2, false, ' ');
    Exists(loctestnum, loctesterr, v2, true, 'b');
    Exists(loctestnum, loctesterr, v2, true, 'c');
    Exists(loctestnum, loctesterr, v2, true, 'd');
    Exists(loctestnum, loctesterr, v2, true, 'e');
    Exists(loctestnum, loctesterr, v2, true, 'f');

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<char>);
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<char>);

    // Declaring new vector with random size
    newDim = gen() % 100 + 1;
    lasd::Vector<char> v3(newDim);
    for (ulong index = 0; index < newDim; index++)
    {
        v3[index] = static_cast<char>(dist(gen));
    }

    // Traversing v3 in PreOrder and PostOrder
    Traverse(loctestnum, loctesterr, v3, true, TraversePrint<char>);
    TraversePreOrder(loctestnum, loctesterr, v3, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<char>);

    // Declaring new vector with 10 elements
    lasd::Vector<char> v4(24);

    // Adding first 24 chars
    for (int i = 0; i < 24; ++i)
    {
        v4[i] = static_cast<char>(i + 97);
    }
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<char>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<char>);

    // Fold and Map feature

    // Testing LinearContainer features

    // Create a new vector v6 as a copy of v5
    lasd::Vector<char> v6 = v4;
    // Check the size of v6 (should be 10)
    Size(loctestnum, loctesterr, v6, true, 24);
    // Verify that v5 and v6 are equal
    EqualLinear(loctestnum, loctesterr, v4, v6, true);
    // Verify that v1 and v3 are not equal
    EqualLinear(loctestnum, loctesterr, v1, v3, false);
    // Verify that v1 and v5 are not equal
    NonEqualLinear(loctestnum, loctesterr, v1, v4, true);

    // Move v6 into a new sortable vector v7
    lasd::SortableVector<char> v7(std::move(v6));
    Size(loctestnum, loctesterr, v7, true, 24);
    Size(loctestnum, loctesterr, v6, true, 24);
    NonEqualLinear(loctestnum, loctesterr, v6, v7, true);
    Empty(loctestnum, loctesterr, v6, false);
    Traverse(loctestnum, loctesterr, v6, true, TraversePrint<char>);
    Traverse(loctestnum, loctesterr, v7, true, TraversePrint<char>);

    // Check if v7 is sorted (should be true since v6 was sorted)
    SortedLinear(loctestnum, loctesterr, v7, true);

    // Create a new sortable vector v8 as a copy of v1 (with random elements)
    lasd::SortableVector<char> v8(v1);
    // Check if v8 is not sorted (should be true since v1 might not be sorted)
    v8.Sort();
    SortedLinear(loctestnum, loctesterr, v8, true);
    // Verify the content of v5 by checking each element
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<char>);
    // Set the first element of v7 to 12
    SetFront(loctestnum, loctesterr, v7, true, 'l');
    // Verify that v7 is no longer sorted
    NonSortedLinear(loctestnum, loctesterr, v7, true);
    // Set the last element of v5 to 0
    SetBack(loctestnum, loctesterr, v4, true, ' ');
    GetAt(loctestnum, loctesterr, v7, false, 33, ' ');
    GetAt(loctestnum, loctesterr, v7, false, -1, ' ');
    GetAt(loctestnum, loctesterr, v7, false, 10, ' ');

    // Test Vector features
    lasd::Vector<char> v9 = v7;
    EqualVector(loctestnum, loctesterr, v9, v7, true);
    NonEqualVector(loctestnum, loctesterr, v9, v6, true);

    // Move assigment from v2 containing 5 elements, v2 now contains 24 elements
    v9 = std::move(v2);
    Size(loctestnum, loctesterr, v9, true, 5);
    Size(loctestnum, loctesterr, v2, true, 24);
    Traverse(loctestnum, loctesterr, v9, true, TraversePrint<char>);
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<char>);

    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<char> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalStringVectorTest(uint &testnum, uint &testerr)
{

    std::cout << "\033[4;36m<<Testing vector of strings>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;
    // Container tests

    // Declaring first vector with random strings
    lasd::Vector<std::string> v1;
    // Empty
    Empty(loctestnum, loctesterr, v1, true);
    // Size
    Size(loctestnum, loctesterr, v1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 26);
    // Resizing vector with random size and checking new Size
    ulong newDim = gen() % 100 + 1;
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
    newDim = gen() % 100 + 1;
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

    // Testing TestableContainer features
    // Declaring new vector for testing if TestableContainer features work

    lasd::Vector<std::string> v2(5);
    SetAt(loctestnum, loctesterr, v2, true, 0, std::string("fiver"));
    SetAt(loctestnum, loctesterr, v2, true, 1, std::string("four"));
    SetAt(loctestnum, loctesterr, v2, true, 2, std::string("three"));
    SetAt(loctestnum, loctesterr, v2, true, 3, std::string("two"));
    SetAt(loctestnum, loctesterr, v2, true, 4, std::string("one"));

    Exists(loctestnum, loctesterr, v2, false, std::string("nine"));
    Exists(loctestnum, loctesterr, v2, false, std::string("twenty"));
    Exists(loctestnum, loctesterr, v2, false, std::string("eleven"));
    Exists(loctestnum, loctesterr, v2, false, std::string(" "));
    Exists(loctestnum, loctesterr, v2, true, std::string("one"));
    Exists(loctestnum, loctesterr, v2, true, std::string("two"));
    Exists(loctestnum, loctesterr, v2, true, std::string("three"));
    Exists(loctestnum, loctesterr, v2, true, std::string("four"));
    Exists(loctestnum, loctesterr, v2, true, std::string("fiver"));

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<std::string>);
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<std::string>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<std::string>);

    // Declaring new vector with random size
    newDim = gen() % 100 + 1;
    lasd::Vector<std::string> v3(newDim);
    for (ulong index = 0; index < newDim; index++)
    {
        std::string temp;

        for (int j = 0; j < 5; j++)
        {
            temp += static_cast<char>(dist(gen) + 96);
        }
        v3[index] = temp;
    }

    // Traversing v3 in PreOrder and PostOrder
    Traverse(loctestnum, loctesterr, v3, true, TraversePrint<std::string>);
    TraversePreOrder(loctestnum, loctesterr, v3, true, TraversePrint<std::string>);
    TraversePostOrder(loctestnum, loctesterr, v3, true, TraversePrint<std::string>);

    // Declaring new vector with 10 elements
    lasd::Vector<std::string> v4(5);

    // Adding first 5 strings
    v4[0] = std::string("apple");
    v4[1] = std::string("banana");
    v4[2] = std::string("cherry");
    v4[3] = std::string("date");
    v4[4] = std::string("elderberry");

    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<std::string>);
    TraversePreOrder(loctestnum, loctesterr, v4, true, TraversePrint<std::string>);
    TraversePostOrder(loctestnum, loctesterr, v4, true, TraversePrint<std::string>);
    Map(loctestnum, loctesterr, v4, true, [](string &str)
        { MapStringAppend(str, string(" ")); });

    // Testing LinearContainer features

    // Create a new vector v6 as a copy of v5
    lasd::Vector<std::string> v6 = v4;
    // Check the size of v6 (should be 10)
    Size(loctestnum, loctesterr, v6, true, 5);
    // Verify that v5 and v6 are equal
    EqualLinear(loctestnum, loctesterr, v4, v6, true);
    // Verify that v1 and v3 are not equal
    EqualLinear(loctestnum, loctesterr, v1, v3, false);
    // Verify that v1 and v5 are not equal
    NonEqualLinear(loctestnum, loctesterr, v1, v4, true);

    // Move v6 into a new sortable vector v7
    lasd::SortableVector<std::string> v7(std::move(v6));
    Size(loctestnum, loctesterr, v7, true, 5);
    Size(loctestnum, loctesterr, v6, true, 5);
    NonEqualLinear(loctestnum, loctesterr, v6, v7, true);
    Empty(loctestnum, loctesterr, v6, false);
    Traverse(loctestnum, loctesterr, v6, true, TraversePrint<std::string>);
    Traverse(loctestnum, loctesterr, v7, true, TraversePrint<std::string>);

    // Check if v7 is sorted (should be true since v6 was sorted)
    SortedLinear(loctestnum, loctesterr, v7, true);
    // Create a new sortable vector v8 as a copy of v1 (with random elements)
    lasd::SortableVector<std::string> v8(v1);
    // Check if v8 is not sorted (should be true since v1 might not be sorted)
    v8.Sort();
    SortedLinear(loctestnum, loctesterr, v8, true);
    // Verify the content of v5 by checking each element
    Traverse(loctestnum, loctesterr, v4, true, TraversePrint<std::string>);
    // Set the first element of v7 to 12
    SetFront(loctestnum, loctesterr, v7, true, std::string("lemon"));
    // Verify that v7 is no longer sorted
    NonSortedLinear(loctestnum, loctesterr, v7, true);
    // Set the last element of v5 to 0
    SetBack(loctestnum, loctesterr, v4, true, std::string(" "));

    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<string> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}
/*****************************************************************************************/
void PersonalIntListTest(uint &testnum, uint &testerr)
{
    std::cout << "\033[4;36m<<Testing list of integers>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;

    // Container features testing
    // Declaring first list
    lasd::List<int> l1;
    // Empty
    Empty(loctestnum, loctesterr, l1, true);
    // Size
    Size(loctestnum, loctesterr, l1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 20);

    l1.Clear();
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    ulong newDim = dist(gen);
    // Insert some elements into the list
    for (ulong i = 0; i < newDim; i++)
    {
        InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    }
    Empty(loctestnum, loctesterr, l1, false);
    Size(loctestnum, loctesterr, l1, true, newDim);

    // Testing TestableContainer features
    // Declaring new list for testing if TestableContainer features work
    lasd::List<int> l2;
    l2.InsertAtFront(6);
    l2.InsertAtFront(5);
    l2.InsertAtFront(4);
    l2.InsertAtFront(3);
    l2.InsertAtFront(2);
    Exists(loctestnum, loctesterr, l2, false, 9);
    Exists(loctestnum, loctesterr, l2, false, 29);
    Exists(loctestnum, loctesterr, l2, false, 21);
    Exists(loctestnum, loctesterr, l2, false, 2342);
    Exists(loctestnum, loctesterr, l2, true, 2);
    Exists(loctestnum, loctesterr, l2, true, 3);
    Exists(loctestnum, loctesterr, l2, true, 4);
    Exists(loctestnum, loctesterr, l2, true, 5);
    Exists(loctestnum, loctesterr, l2, true, 6);

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, l2, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, l2, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, l2, true, TraversePrint<int>);

    // Declaring new list with random size
    newDim = dist(gen);
    lasd::List<int> l3;
    for (ulong index = 0; index < newDim; index++)
    {
        l3.InsertAtFront(dist(gen));
    }

    // Traversing l3 in PreOrder and PostOrder
    Traverse(loctestnum, loctesterr, l3, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, l3, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<int>);

    // Declaring new list with 10 elements
    lasd::List<long> l4;

    // Adding first 10 odd numbers
    for (int i = 0, odd = 1; i < 10; ++i, odd += 2)
    {
        l4.InsertAtFront(odd);
    }
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<int>);

    // Attempting Fold operations on l4
    Fold(loctestnum, loctesterr, l4, true, FoldAdd<int>, 0, 100);
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldAdd<int>, 0, 100);
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldAdd<int>, 0, 100);
    Fold(loctestnum, loctesterr, l4, true, FoldMultiply<int>, 1, 654729075);
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldMultiply<int>, 1, 654729075);
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldMultiply<int>, 1, 654729075);

    // Testing MappableContainer features

    // Increment all elements in the list by 1 and print the list
    Map(loctestnum, loctesterr, l4, true, MapIncrement<long>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);

    // Fold the list by summing all elements, expecting a total of 110
    Fold(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 110);

    // Decrement all elements in the list by 1 and print the list
    Map(loctestnum, loctesterr, l4, true, MapDecrement<long>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);

    // Fold the list by summing all elements, expecting a total of 100
    Fold(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 100);
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 100);
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 100);

    // Increment all elements in the list by 1 again and print the list
    Map(loctestnum, loctesterr, l4, true, MapIncrement<long>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);

    // Fold the list by multiplying all elements, expecting a product of 3715891200
    Fold(loctestnum, loctesterr, l4, true, FoldMultiply<long>, (long)1, 3715891200);
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldMultiply<long>, (long)1, 3715891200);
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldMultiply<long>, (long)1, 3715891200);

    // Halve all elements in the list
    Map(loctestnum, loctesterr, l4, true, MapHalf<long>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);

    // Fold the list by summing all elements, expecting a total of 55
    Fold(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 55);
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 55);
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 55);

    // Double all elements in the list
    Map(loctestnum, loctesterr, l4, true, MapDouble<long>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);

    // Fold the list by summing all elements, expecting a total of 110
    Fold(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 110);
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 110);
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, 110);

    // Invert the sign of all elements in the list
    Map(loctestnum, loctesterr, l4, true, MapInvert<long>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<long>);

    // Fold the list by summing all elements, expecting a total of -110
    Fold(loctestnum, loctesterr, l4, true, FoldAdd<long>, 0, -110);

    // Testing PreOrderMap and PostOrderMap

    // Declaring a new list with 10 elements (1,...,9)
    lasd::List<int> l5;
    for (int i = 0; i < 10; ++i)
    {
        l5.InsertAtBack(i + 1);
    }
    MapPreOrder(loctestnum, loctesterr, l5, true, MapDoubleNPrint<int>);
    MapPostOrder(loctestnum, loctesterr, l5, true, MapInvertNPrint<int>);

    // Testing LinearContainer features

    // Create a new list l6 as a copy of l5
    lasd::List<int> l6 = l5;
    // Check the size of l6 (should be 10)
    Size(loctestnum, loctesterr, l6, true, 10);
    // Verify that l5 and l6 are equal
    EqualLinear(loctestnum, loctesterr, l5, l6, true);
    // Verify that l1 and l3 are not equal
    EqualLinear(loctestnum, loctesterr, l1, l3, false);
    // Verify that l1 and l5 are not equal
    NonEqualLinear(loctestnum, loctesterr, l1, l5, true);

    // Move l6 into a new list l7
    lasd::List<int> l7(std::move(l6));
    Size(loctestnum, loctesterr, l7, true, 10);
    Size(loctestnum, loctesterr, l6, true, 0);
    NonEqualLinear(loctestnum, loctesterr, l6, l7, true);
    Empty(loctestnum, loctesterr, l6, true);

    Traverse(loctestnum, loctesterr, l5, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, l6, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, l7, true, TraversePrint<int>);

    // Check the first element of l5 (should be -2)
    GetFront(loctestnum, loctesterr, l5, true, -2);
    // Check the last element of l5 (should be -20)
    GetBack(loctestnum, loctesterr, l5, true, -20);
    // Set the first element of l7 to 12
    SetFront(loctestnum, loctesterr, l7, true, 12);
    // Set the last element of l5 to 0
    SetBack(loctestnum, loctesterr, l5, true, 0);

    // Test List features
    lasd::List<int> l9 = l7;
    EqualList(loctestnum, loctesterr, l9, l7, true);
    NonEqualList(loctestnum, loctesterr, l9, l6, true);

    // Move assigment from l2 containing 5 elements
    l9 = std::move(l2);
    Size(loctestnum, loctesterr, l9, true, 5);
    Size(loctestnum, loctesterr, l2, true, 10);
    Traverse(loctestnum, loctesterr, l9, true, TraversePrint<int>);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, false);
    Empty(loctestnum, loctesterr, l9, true);

    lasd::List<int> l10;
    for (int i = 0; i < 10; i++)
    {
        if ((i % 2) == 0)
        {
            InsertAtFront(loctestnum, loctesterr, l10, true, i);
        }
        else
        {
            InsertAtBack(loctestnum, loctesterr, l10, true, i);
        }
    }
    Traverse(loctestnum, loctesterr, l10, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, l10, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, l10, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, l10, true, FoldAdd<int>, 0, 45);
    FoldPreOrder(loctestnum, loctesterr, l10, true, FoldAdd<int>, 0, 45);
    FoldPostOrder(loctestnum, loctesterr, l10, true, FoldAdd<int>, 0, 45);
    GetFront(loctestnum, loctesterr, l10, true, 8);
    FrontNRemove(loctestnum, loctesterr, l10, true, 8);
    GetBack(loctestnum, loctesterr, l10, true, 9);
    BackNRemove(loctestnum, loctesterr, l10, true, 9);
    Traverse(loctestnum, loctesterr, l10, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, l10, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, l10, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, l10, true, FoldAdd<int>, 0, 28);
    FoldPreOrder(loctestnum, loctesterr, l10, true, FoldAdd<int>, 0, 28);
    FoldPostOrder(loctestnum, loctesterr, l10, true, FoldAdd<int>, 0, 28);
    Map(loctestnum, loctesterr, l10, true, MapIncrementNPrint<int>);

    lasd::List<int> l11;
    l11 = l10;
    EqualList(loctestnum,loctesterr,l10,l11,true);
    l10.Clear();
    Empty(loctestnum,loctesterr,l10,true);
    std::cout << "\033[4;36mEnd of List<int> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void PersonalDoubleListTest(uint &testnum, uint &testerr)
{
    std::cout << "\033[4;36m<<Testing list of doubles>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;

    // Container features testing
    // Declaring first list
    lasd::List<double> l1;
    // Empty
    Empty(loctestnum, loctesterr, l1, true);
    // Size
    Size(loctestnum, loctesterr, l1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0, 20.0);

    l1.Clear();
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    ulong newDim = gen() % 20 + 1;
    // Insert some elements into the list
    for (ulong i = 0; i < newDim; i++)
    {
        InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    }
    Empty(loctestnum, loctesterr, l1, false);
    Size(loctestnum, loctesterr, l1, true, newDim);

    // Testing TestableContainer features
    // Declaring new list for testing if TestableContainer features work
    lasd::List<double> l2;
    l2.InsertAtFront(6.5);
    l2.InsertAtFront(5.5);
    l2.InsertAtFront(4.5);
    l2.InsertAtFront(3.5);
    l2.InsertAtFront(2.5);
    Exists(loctestnum, loctesterr, l2, false, 9.0);
    Exists(loctestnum, loctesterr, l2, false, 29.0);
    Exists(loctestnum, loctesterr, l2, false, 21.0);
    Exists(loctestnum, loctesterr, l2, false, 2342.0);
    Exists(loctestnum, loctesterr, l2, true, 2.5);
    Exists(loctestnum, loctesterr, l2, true, 3.5);
    Exists(loctestnum, loctesterr, l2, true, 4.5);
    Exists(loctestnum, loctesterr, l2, true, 5.5);
    Exists(loctestnum, loctesterr, l2, true, 6.5);

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, l2, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, l2, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, l2, true, TraversePrint<double>);

    // Declaring new list with random size
    newDim = gen() % 100 + 1;
    lasd::List<double> l3;
    for (ulong index = 0; index < newDim; index++)
    {
        l3.InsertAtFront(dist(gen));
    }

    // Traversing l3 in PostOrder
    TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<double>);

    // Declaring new list with 10 elements
    lasd::List<double> l4;

    // Adding first 10 odd numbers
    for (int i = 0; i < 10; ++i)
    {
        l4.InsertAtFront(static_cast<double>(i + 1) * 1.1);
    }
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, l4, true,TraversePrint<double>);

    // Attempting Fold operations on l4
    FoldDouble(loctestnum, loctesterr, l4, true, FoldAdd<double>, 0.0, 60.50, 1e-9);
    PreOrderFoldDouble(loctestnum, loctesterr, l4, true, FoldAdd<double>, 0.0, 60.50, 1e-9);
    PostOrderFoldDouble(loctestnum, loctesterr, l4, true, FoldAdd<double>, 0.0, 60.50, 1e-9);

    // Testing MappableContainer features

    // Increment all elements in the list by 1 and print the list
    Map(loctestnum, loctesterr, l4, true, MapIncrement<double>);
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<double>);

    // Testing PreOrderMap and PostOrderMap
    MapPreOrder(loctestnum, loctesterr, l4, true, MapDoubleNPrint<double>);
    MapPostOrder(loctestnum, loctesterr, l4, true, MapInvertNPrint<double>);

    // Testing LinearContainer features

    // Create a new list l6 as a copy of l5
    lasd::List<double> l6 = l4;
    // Check the size of l6 (should be 10)
    Size(loctestnum, loctesterr, l6, true, 10);
    // Verify that l5 and l6 are equal
    EqualLinear(loctestnum, loctesterr, l4, l6, true);
    // Verify that l1 and l3 are not equal
    EqualLinear(loctestnum, loctesterr, l1, l3, false);
    // Verify that l1 and l5 are not equal
    NonEqualLinear(loctestnum, loctesterr, l1, l4, true);
    // Move l6 into a new sortable list l7
    lasd::List<double> l7(std::move(l6));
    Size(loctestnum, loctesterr, l7, true, 10);
    Size(loctestnum, loctesterr, l6, true, 0);
    NonEqualLinear(loctestnum, loctesterr, l6, l7, true);
    Empty(loctestnum, loctesterr, l6, true);

    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<double>);
    Traverse(loctestnum, loctesterr, l6, true, TraversePrint<double>);
    Traverse(loctestnum, loctesterr, l7, true, TraversePrint<double>);

    // Test List features
    GetBackDouble(loctestnum, loctesterr, l4, true, -4.2, 1e-9);
    GetFrontDouble(loctestnum, loctesterr, l4, true, -24.0, 1e-9);
    SetFront(loctestnum, loctesterr, l7, true, 12.0);
    SetBack(loctestnum, loctesterr, l4, true, 0.0);
    lasd::List<double> l9 = l7;
    EqualList(loctestnum, loctesterr, l9, l7, true);
    NonEqualList(loctestnum, loctesterr, l9, l6, true);

    // Move assigment from l2 containing 5 elements
    l9 = std::move(l2);
    Size(loctestnum, loctesterr, l9, true, 5);
    Size(loctestnum, loctesterr, l2, true, 10);

    Traverse(loctestnum, loctesterr, l9, true, TraversePrint<double>);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    Empty(loctestnum, loctesterr, l9, true);

    lasd::List<double> l10;
    for (int i = 0; i < 10; i++)
    {
        if ((i % 2) == 0)
        {
            InsertAtFront(loctestnum, loctesterr, l10, true, static_cast<double>(i) * 1.1);
        }
        else
        {
            InsertAtBack(loctestnum, loctesterr, l10, true, static_cast<double>(i) * 1.1);
        }
    }
    Traverse(loctestnum, loctesterr, l10, true, TraversePrint<double>);
    TraversePreOrder(loctestnum, loctesterr, l10, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, l10, true, TraversePrint<double>);
    FoldDouble(loctestnum, loctesterr, l10, true, FoldAdd<double>, 0.0, 49.50, 1e-9);
    PreOrderFoldDouble(loctestnum, loctesterr, l10, true, FoldAdd<double>, 0.0, 49.50, 1e-9);
    PostOrderFoldDouble(loctestnum, loctesterr, l10, true, FoldAdd<double>, 0.0, 49.50, 1e-9);
    GetFrontDouble(loctestnum, loctesterr, l10, true, 8.8, 1e-9);
    GetBackDouble(loctestnum,loctesterr,l10,true,9.9,1e-9);

    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of List<double> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalCharListTest(uint &testnum, uint &testerr)
{
    std::cout << "\033[4;36m<<Testing list of chars>>\033[0m" << std::endl;
    uint loctestnum = 0, loctesterr = 0;

    // Container features testing
    // Declaring first list
    lasd::List<char> l1;
    // Empty
    Empty(loctestnum, loctesterr, l1, true);
    // Size
    Size(loctestnum, loctesterr, l1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(97, 122);

    l1.Clear();
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    ulong newDim = gen() % 100 + 1;
    // Insert some elements into the list
    for (ulong i = 0; i < newDim; i++)
    {
        InsertAtFront(loctestnum, loctesterr, l1, true, static_cast<char>(dist(gen)));
    }
    Empty(loctestnum, loctesterr, l1, false);
    Size(loctestnum, loctesterr, l1, true, newDim);

    // Testing TestableContainer features
    // Declaring new list for testing if TestableContainer features work
    lasd::List<char> l2;
    l2.InsertAtFront('f');
    l2.InsertAtFront('e');
    l2.InsertAtFront('d');
    l2.InsertAtFront('c');
    l2.InsertAtFront('b');
    Exists(loctestnum, loctesterr, l2, false, 'i');
    Exists(loctestnum, loctesterr, l2, false, 'y');
    Exists(loctestnum, loctesterr, l2, false, 'u');
    Exists(loctestnum, loctesterr, l2, false, ' ');
    Exists(loctestnum, loctesterr, l2, true, 'b');
    Exists(loctestnum, loctesterr, l2, true, 'c');
    Exists(loctestnum, loctesterr, l2, true, 'd');
    Exists(loctestnum, loctesterr, l2, true, 'e');
    Exists(loctestnum, loctesterr, l2, true, 'f');

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, l2, true, TraversePrint<char>);
    TraversePreOrder(loctestnum, loctesterr, l2, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, l2, true, TraversePrint<char>);

    // Declaring new list with random size
    newDim = gen() % 100 + 1;
    lasd::List<char> l3;
    for (ulong index = 0; index < newDim; index++)
    {
        l3.InsertAtFront(static_cast<char>(dist(gen)));
    }

    // Traversing l3 in PostOrder
    TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<char>);

    // Declaring new list with 24 elements
    lasd::List<char> l4;

    // Adding first 24 chars
    for (int i = 0; i < 26; ++i)
    {
        l4.InsertAtFront(static_cast<char>(i + 97));
    }
    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<char>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<char>);

    // Testing LinearContainer features

    // Create a new list l6 as a copy of l5
    lasd::List<char> l6 = l4;
    // Check the size of l6 (should be 10)
    Size(loctestnum, loctesterr, l6, true, 26);
    // Verify that l5 and l6 are equal
    EqualLinear(loctestnum, loctesterr, l4, l6, true);
    // Verify that l1 and l3 are not equal
    EqualLinear(loctestnum, loctesterr, l1, l3, false);
    // Verify that l1 and l5 are not equal
    NonEqualLinear(loctestnum, loctesterr, l1, l4, true);
    // Move l6 into a new list l7
    lasd::List<char> l7(std::move(l6));
    Size(loctestnum, loctesterr, l7, true, 26);
    Size(loctestnum, loctesterr, l6, true, 0);
    NonEqualLinear(loctestnum, loctesterr, l6, l7, true);
    Empty(loctestnum, loctesterr, l6, true);

    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<char>);
    Traverse(loctestnum, loctesterr, l6, true, TraversePrint<char>);
    Traverse(loctestnum, loctesterr, l7, true, TraversePrint<char>);

    // Test List features
    GetBack(loctestnum, loctesterr, l4, true, 'a');
    GetFront(loctestnum, loctesterr, l4, true, 'z');
    SetFront(loctestnum, loctesterr, l7, true, 'A');
    SetBack(loctestnum, loctesterr, l4, true, ' ');
    lasd::List<char> l9 = l7;
    EqualList(loctestnum, loctesterr, l9, l7, true);
    NonEqualList(loctestnum, loctesterr, l9, l6, true);

    // Move assigment from l2 containing 5 elements
    l9 = std::move(l2);
    Size(loctestnum, loctesterr, l9, true, 5);
    Size(loctestnum, loctesterr, l2, true, 26);

    Traverse(loctestnum, loctesterr, l9, true, TraversePrint<char>);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, true);
    RemoveFromFront(loctestnum, loctesterr, l9, false);
    Empty(loctestnum, loctesterr, l9, true);

    lasd::List<char> l10;
    for (int i = 0; i < 10; i++)
    {
        if ((i % 2) == 0)
        {
            InsertAtFront(loctestnum, loctesterr, l10, true, static_cast<char>(i + 97));
        }
        else
        {
            InsertAtBack(loctestnum, loctesterr, l10, true, static_cast<char>(i + 97));
        }
    }
    Traverse(loctestnum, loctesterr, l10, true, TraversePrint<char>);
    TraversePreOrder(loctestnum, loctesterr, l10, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, l10, true, TraversePrint<char>);
    GetFront(loctestnum, loctesterr, l10, true, 'i');
    GetBack(loctestnum, loctesterr, l10, true, 'j');
    SetFront(loctestnum, loctesterr, l10, true, 'A');
    SetBack(loctestnum, loctesterr, l10, true, 'B');


    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of List<char> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalStringList(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing list of strings>>\033[0m" << std::endl;
    // Container features testing

    // Declaring first list
    lasd::List<std::string> l1;
    // Empty
    Empty(loctestnum, loctesterr, l1, true);
    // Size
    Size(loctestnum, loctesterr, l1, true, 0);
    // Random number generator setup
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 26);

    l1.Clear();
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    ulong newDim = 45;
    // Insert some elements into the list
    for (ulong i = 0; i < newDim; i++)
    {
        std::string temp;
        for (int j = 0; j < 5; j++)
        {
            temp += static_cast<char>(dist(gen) + 96);
        }
        InsertAtFront(loctestnum, loctesterr, l1, true, temp);
    }
    Empty(loctestnum, loctesterr, l1, false);
    Size(loctestnum, loctesterr, l1, true, newDim);

    // Testing TestableContainer features
    // Declaring new list for testing if TestableContainer features work
    lasd::List<std::string> l2;
    l2.InsertAtFront(std::string("fiver"));
    l2.InsertAtFront(std::string("four"));
    l2.InsertAtFront(std::string("three"));
    l2.InsertAtFront(std::string("two"));
    l2.InsertAtFront(std::string("one"));
    Exists(loctestnum, loctesterr, l2, false, std::string("nine"));
    Exists(loctestnum, loctesterr, l2, false, std::string("twenty"));
    Exists(loctestnum, loctesterr, l2,false,std::string("Napoli"));
    Exists(loctestnum, loctesterr, l2,false,std::string("Roma"));
    Exists(loctestnum, loctesterr, l2,false,std::string(" "));
    Exists(loctestnum, loctesterr, l2, true, std::string("one"));
    Exists(loctestnum, loctesterr, l2, true, std::string("two"));
    Exists(loctestnum, loctesterr, l2, true, std::string("three"));
    Exists(loctestnum, loctesterr, l2, true, std::string("four"));
    Exists(loctestnum, loctesterr, l2, true, std::string("fiver"));

    // Testing TraversableContainer features
    Traverse(loctestnum, loctesterr, l2, true, TraversePrint<std::string>);
    TraversePreOrder(loctestnum, loctesterr, l2, true, TraversePrint<std::string>);
    TraversePostOrder(loctestnum, loctesterr, l2, true, TraversePrint<std::string>);

    // Declaring new list
    lasd::List<std::string> l3;
    for (ulong index = 0; index < newDim; index++)
    {
        std::string temp;
        for (int j = 0; j < 5; j++)
        {
            temp += static_cast<char>(dist(gen) + 96);
        }
        l3.InsertAtFront(temp);
    }
    // Traversing l3 in PostOrder
    TraversePostOrder(loctestnum, loctesterr, l3, true, TraversePrint<std::string>);

    // Declaring new list with 5 elements
    lasd::List<std::string> l4;

    // Adding first 5 strings
    l4.InsertAtFront(std::string("apple"));
    l4.InsertAtFront(std::string("banana"));
    l4.InsertAtFront(std::string("cherry"));
    l4.InsertAtFront(std::string("date"));
    l4.InsertAtFront(std::string("elderberry"));

    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<std::string>);
    TraversePreOrder(loctestnum, loctesterr, l4, true, TraversePrint<std::string>);
    TraversePostOrder(loctestnum, loctesterr, l4, true, TraversePrint<std::string>);
    Map(loctestnum, loctesterr, l4, true, [](string &str)
        { MapStringAppend(str, string(" ")); });

    // Testing fold functions
    Fold(loctestnum, loctesterr, l4, true, FoldStringConcatenate, std::string(""), std::string("elderberry date cherry banana apple "));
    FoldPreOrder(loctestnum, loctesterr, l4, true, FoldStringConcatenate, std::string(""), std::string("elderberry date cherry banana apple "));
    FoldPostOrder(loctestnum, loctesterr, l4, true, FoldStringConcatenate, std::string(""), std::string("apple banana cherry date elderberry "));



    // Testing LinearContainer features

    // Create a new list l6 as a copy of l4
    lasd::List<std::string> l5(l4);
    // Check the size of l6 (should be 10)
    Size(loctestnum, loctesterr, l5, true, 5);
    // Verify that l5 and l6 are equal
    EqualLinear(loctestnum, loctesterr, l4, l5, true);
    // Verify that l1 and l5 are not equal
    NonEqualLinear(loctestnum, loctesterr, l1, l4, true);

    // Move l5 into a new list l7
    lasd::List<std::string> l7(std::move(l5));
    Size(loctestnum, loctesterr, l7, true, 5);
    Size(loctestnum, loctesterr, l5, true, 0);
    NonEqualLinear(loctestnum, loctesterr, l5, l7, true);
    Empty(loctestnum, loctesterr, l5, true);

    Traverse(loctestnum, loctesterr, l4, true, TraversePrint<std::string>);
    Traverse(loctestnum, loctesterr, l5, true, TraversePrint<std::string>);
    Traverse(loctestnum, loctesterr, l7, true, TraversePrint<std::string>);

    // Test List features
    GetBack(loctestnum, loctesterr, l4, true, std::string("apple "));
    GetFront(loctestnum, loctesterr, l4, true, std::string("elderberry "));
    SetFront(loctestnum, loctesterr, l7, true, std::string("lemon"));
    SetBack(loctestnum, loctesterr, l4, true, std::string(" "));


    lasd::List<std::string> l9;
    l9 = l7;
    EqualList(loctestnum, loctesterr, l9, l7, true);
    NonEqualList(loctestnum, loctesterr, l9, l5, true);

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
