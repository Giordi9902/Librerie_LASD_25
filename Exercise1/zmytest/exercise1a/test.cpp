#include <iostream>
#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../mycontainer/mylinear.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include <random>
#include <string>
#include "test.hpp"
using namespace std;

void test_int_vector(uint &loctest, uint &errtest)
{
    // Create an empty vector of integers
    lasd::Vector<int> v1;

    // Test if the vector is empty and its size is 0
    Empty(loctest, errtest, v1, true);
    Size(loctest, errtest, v1, true, 0);

    // Resize the vector to hold 100 elements and verify its size
    v1.Resize(100);
    Size(loctest, errtest, v1, true, 100);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);

    // Insert 100 random elements into the vector
    std::cout << " " << ++loctest << " (" << errtest << ") Attempting to insert 1000 elements :";
    for (ulong index = 0; index < 100; index++)
    {
        SetAt(loctest, errtest, v1, true, index, dist(gen));
    }

    // Create a sortable vector from the existing vector and verify equality
    lasd::SortableVector<int> sv1(v1);
    EqualVector(loctest, errtest, v1, sv1, true);

    // Test if the sortable vector is sorted
    SortedLinear(loctest, errtest, sv1, true);

    // Resize the sortable vector to 0 and verify its properties
    sv1.Resize(0);
    Empty(loctest, errtest, sv1, true);
    Size(loctest, errtest, sv1, true, 0);

    // Attempt to access front and back elements of an empty vector
    GetFront(loctest, errtest, sv1, false, 0);
    GetBack(loctest, errtest, sv1, false, 0);

    // Resize the sortable vector to 20 and set the front element
    sv1.Resize(20);
    int num = dist(gen);
    SetFront(loctest, errtest, sv1, true, num);

    // Verify the front element and attempt invalid access
    GetAt(loctest, errtest, sv1, true, 0, num);
    GetAt(loctest, errtest, sv1, false, -1, 0);

    // Reset the first vector to size 0 and copy from another vector with size > 0
    v1.Resize(0);
    lasd::Vector<int> v2(50);
    v1 = v2;

    // Verify the properties of the copied vector
    Size(loctest, errtest, v1, true, 50);
    Empty(loctest, errtest, v1, false);
    EqualVector(loctest, errtest, v1, v2, true);

    // Create an empty sortable vector of integers
    lasd::SortableVector<int> sv2;

    // Assign the empty sortable vector to an existing vector
    v2 = sv2;
    // Verify that the size of v2 is 0' after assignment
    Size(loctest, errtest, v2, true, 0);

    // Check that v1(size=50) and v2(size=0) are not equal after the assignment
    EqualVector(loctest, errtest, v1, v2, false);

    // Create a new vector v3 and resize it to hold 5 elements
    lasd::Vector<int> v3;
    v3.Resize(5);
    Size(loctest, errtest, v3, true, 5);

    // Set values at specific indices in the vector
    SetAt(loctest, errtest, v3, true, 0, 5);
    SetAt(loctest, errtest, v3, true, 1, 4);
    SetAt(loctest, errtest, v3, true, 2, 3);
    SetAt(loctest, errtest, v3, true, 3, 2);
    SetAt(loctest, errtest, v3, true, 4, 1);

    // Attempt to set a value at an invalid index (out of bounds)
    SetAt(loctest, errtest, v3, false, 5, 1);

    // Verify that vector v2 is empty and has size 0
    Empty(loctest, errtest, v2, true);
    Size(loctest, errtest, v2, true, 0);

    // Move the contents of v3 to v2 and verify the sizes of both vectors
    v2 = (std::move(v3));
    Size(loctest, errtest, v3, true, 0); // v3 should now be empty

    // Traverse the vector v2 and print its elements
    Traverse(loctest, errtest, v2, true, TraversePrint<int>);
    // Traverse the vector v2 in pre-order and post-order and print its elements
    TraversePreOrder(loctest, errtest, v2, true, TraversePrint<int>);
    TraversePostOrder(loctest, errtest, v2, true, TraversePrint<int>);

    // Resize the sortable vector sv1 to 10 and populate it with random elements
    sv1.Resize(10);
    for (ulong ind = 0; ind < 10; ind++) {
        SetAt(loctest, errtest, sv1, true, ind, dist(gen));
    }

    // Verify if the sortable vector sv1 is sorted
    SortedLinear(loctest, errtest, sv1, true);

    // Traverse the sortable vector sv1 and print its elements
    Traverse(loctest, errtest, sv1, true, TraversePrint<int>);
    TraversePreOrder(loctest, errtest, sv1, true, TraversePrint<int>);
    TraversePostOrder(loctest, errtest, sv1, true, TraversePrint<int>);

}

void test_double_vector(uint &loctest, uint &errtest)
{
}


void test_char_vector(uint &loctest, uint &errtest)
{
}

void test_string_vector(uint &loctest, uint &errtest)
{
}

void test_int_list(uint &loctest, uint &errtest)
{
    // Create an empty list of integers
    lasd::List<int> l1;

    // Test if the list is empty and its size is 0
    Empty(loctest, errtest, l1, true);
    Size(loctest, errtest, l1, true, 0);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);

    // Insert elements at the front of the list
    int back = dist(gen);
    InsertAtFront(loctest, errtest, l1, true, back);
    InsertAtFront(loctest, errtest, l1, true, dist(gen));
    InsertAtFront(loctest, errtest, l1, true, dist(gen));
    InsertAtFront(loctest, errtest, l1, true, dist(gen));
    InsertAtFront(loctest, errtest, l1, true, dist(gen));
    InsertAtFront(loctest, errtest, l1, true, dist(gen));
    InsertAtFront(loctest, errtest, l1, true, dist(gen));

    // Insert another element at the front and verify the front and back elements
    int front = dist(gen);
    InsertAtFront(loctest, errtest, l1, true, front);
    GetFront(loctest, errtest, l1, true, front);
    GetBack(loctest, errtest, l1, true, back);

    // Traverse the list and print its elements
    Traverse(loctest, errtest, l1, true, TraversePrint<int>);

    // Set a new value at the front of the list and verify it
    int newFront = dist(gen);
    SetAt(loctest, errtest, l1, true, 0, newFront);
    GetFront(loctest, errtest, l1, true, newFront);

    // Traverse the list again and print its elements
    Traverse(loctest, errtest, l1, true, TraversePrint<int>);

    // Verify the size of the list
    Size(loctest, errtest, l1, true, 8);

    // Clear the list and verify it is empty
    l1.Clear();
    Empty(loctest, errtest, l1, true);
    Size(loctest, errtest, l1, true, 0);

    // Create a vector of integers and populate it with random values
    lasd::Vector<int> v1(100);
    for (int i = 0; i < 100; i++) {
        SetAt(loctest, errtest, v1, true, i, dist(gen));
    }

    // Create a list from the vector and verify its properties
    lasd::List<int> l2(v1);
    Empty(loctest, errtest, l2, false);
    Size(loctest, errtest, l2, true, 100);

    // Move the vector into a new list and verify the properties of both lists
    lasd::List<int> l3(std::move(v1));
    Empty(loctest, errtest, l2, false);
    Size(loctest, errtest, l2, true, 100);

    // Verify that the two lists are equal
    EqualList(loctest, errtest, l2, l3, true);
}

void test_double_list(uint &loctest, uint &errtest)
{
}

void test_char_list(uint &loctest, uint &errtest)
{
}

void test_string_list(uint &loctest, uint &errtest)
{


}

void PersonalTestList(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;
    uint loctest = 0;
    uint errtest = 0;

    std::cout << "<<Testing list of integers>>" << std::endl;
    test_int_list(loctest, errtest);
    std::cout << "End of List<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "<<Testing list of doubles>>" << std::endl;
    test_double_list(loctest, errtest);
    std::cout << "End of List<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "<<Testing list of strings>>" << std::endl;
    test_string_list(loctest, errtest);
    std::cout << "End of List<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << "<<Testing list of chars>>" << std::endl;
    test_char_list(loctest, errtest);
    std::cout << "End of List<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "End List tests: " << toterr << " errors found over " << tottest << " tests." << std::endl;
    testnum+=tottest;
    testerr+=toterr;
}

void PersonalTestVector(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;
    uint loctest = 0;
    uint errtest = 0;
    std::cout << "<<Testing vector of integers>>" << std::endl;
    test_int_vector(loctest, errtest);
    std::cout << "End of Vector<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "<<Testing vector of doubles>>" << std::endl;
    test_double_vector(loctest, errtest);
    std::cout << "End of Vector<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "<<Testing vector of strings>>" << std::endl;
    test_string_vector(loctest, errtest);
    std::cout << "End of Vector<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "<<Testing vector of chars>>" << std::endl;
    test_char_vector(loctest, errtest);
    std::cout << "End of Vector<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "End Vector tests: " << toterr << " errors found over " << tottest << " tests." << std::endl;
    testnum+=tottest;
    testerr+=toterr;
}

void myTestExercise1A(uint &testnum, uint &testerr)
{
    PersonalTestVector(testnum, testerr);
    PersonalTestList(testnum, testerr);
    cout << endl
         << "Exercise 1A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
