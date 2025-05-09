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

void test_int_vector(uint &loctestnum, uint &loctesterr)
{
    // Create an empty vector of integers
    lasd::Vector<int> v1;

    // Test if the vector is empty and its size is 0
    Empty(loctestnum, loctesterr, v1, true);
    Size(loctestnum, loctesterr, v1, true, 0);

    // Resize the vector to hold 100 elements and verify its size
    v1.Resize(100);
    Size(loctestnum, loctesterr, v1, true, 100);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);

    // Insert 100 random elements into the vector
    std::cout << " " << ++loctestnum << " (" << loctesterr << ") Attempting to insert 1000 elements :";
    for (ulong index = 0; index < 100; index++)
    {
        SetAt(loctestnum, loctesterr, v1, true, index, dist(gen));
    }

    // Create a sortable vector from the existing vector and verify equality
    lasd::SortableVector<int> sv1(v1);
    EqualVector(loctestnum, loctesterr, v1, sv1, true);

    // Test if the sortable vector is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Resize the sortable vector to 0 and verify its properties
    sv1.Resize(0);
    Empty(loctestnum, loctesterr, sv1, true);
    Size(loctestnum, loctesterr, sv1, true, 0);

    // Attempt to access front and back elements of an empty vector
    GetFront(loctestnum, loctesterr, sv1, false, 0);
    GetBack(loctestnum, loctesterr, sv1, false, 0);

    // Resize the sortable vector to 20 and set the front element
    sv1.Resize(20);
    int num = dist(gen);
    SetFront(loctestnum, loctesterr, sv1, true, num);

    // Verify the front element and attempt invalid access
    GetAt(loctestnum, loctesterr, sv1, true, 0, num);
    GetAt(loctestnum, loctesterr, sv1, false, -1, 0);

    // Reset the first vector to size 0 and copy from another vector with size > 0
    v1.Resize(0);
    lasd::Vector<int> v2(50);
    v1 = v2;

    // Verify the properties of the copied vector
    Size(loctestnum, loctesterr, v1, true, 50);
    Empty(loctestnum, loctesterr, v1, false);
    EqualVector(loctestnum, loctesterr, v1, v2, true);

    // Create an empty sortable vector of integers
    lasd::SortableVector<int> sv2;

    // Assign the empty sortable vector to an existing vector
    v2 = sv2;
    // Verify that the size of v2 is 0' after assignment
    Size(loctestnum, loctesterr, v2, true, 0);

    // Check that v1(size=50) and v2(size=0) are not equal after the assignment
    EqualVector(loctestnum, loctesterr, v1, v2, false);

    // Create a new vector v3 and resize it to hold 5 elements
    lasd::Vector<int> v3;
    v3.Resize(5);
    Size(loctestnum, loctesterr, v3, true, 5);

    // Set values at specific indices in the vector
    SetAt(loctestnum, loctesterr, v3, true, 0, 5);
    SetAt(loctestnum, loctesterr, v3, true, 1, 4);
    SetAt(loctestnum, loctesterr, v3, true, 2, 3);
    SetAt(loctestnum, loctesterr, v3, true, 3, 2);
    SetAt(loctestnum, loctesterr, v3, true, 4, 1);

    // Attempt to set a value at an invalid index (out of bounds)
    SetAt(loctestnum, loctesterr, v3, false, 5, 1);

    // Verify that vector v2 is empty and has size 0
    Empty(loctestnum, loctesterr, v2, true);
    Size(loctestnum, loctesterr, v2, true, 0);

    // Move the contents of v3 to v2 and verify the sizes of both vectors
    v2 = (std::move(v3));
    Size(loctestnum, loctesterr, v3, true, 0); // v3 should now be empty

    // Traverse the vector v2 and print its elements
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<int>);
    // Traverse the vector v2 in pre-order and post-order and print its elements
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<int>);

    // Resize the sortable vector sv1 to 10 and populate it with random elements
    sv1.Resize(10);
    for (ulong ind = 0; ind < 10; ind++) {
        SetAt(loctestnum, loctesterr, sv1, true, ind, dist(gen));
    }

    // Verify if the sortable vector sv1 is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Traverse the sortable vector sv1 and print its elements
    Traverse(loctestnum, loctesterr, sv1, true, TraversePrint<int>);
    TraversePreOrder(loctestnum, loctesterr, sv1, true, TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, sv1, true, TraversePrint<int>);

        // creo vettore vuoto
    lasd::SortableVector<int> vec1;
    // controllo che sia vuoto
    Empty(loctestnum, loctesterr, vec1, true);
    // creo vettore di size 5
    lasd::SortableVector<int> vec2(5);
    // copio vettore di size > 0 in vettore di size 0
    vec1 = vec2;
    // controllo che il vettore copiato non sia vuoto
    Empty(loctestnum, loctesterr, vec1, false);
    // controllo che il vettore copiato e il sorgente siano identici
    EqualVector(loctestnum, loctesterr, vec1, vec2, true);
    // nuovo vettore vuoto
    lasd::SortableVector<int> vec3;
    // copio vettore con size 0 in vettore con size > 0
    vec2 = vec3;
    // controllo size
    Size(loctestnum, loctesterr, vec2, true, 0);
    // controllo che i vettori siano diversi
    EqualVector(loctestnum, loctesterr, vec1, vec2, false);
    // controllo che i vettori siano uguali
    EqualVector(loctestnum, loctesterr, vec2, vec3, true);
    // non posso settare in un vettore di size 0
    SetAt(loctestnum, loctesterr, vec3, false, 0, 0);
    // resize
    vec3.Resize(5);
    Size(loctestnum, loctesterr, vec3, true, 5);
    SetAt(loctestnum, loctesterr, vec3, true, 0, 5);
    SetAt(loctestnum, loctesterr, vec3, true, 1, 4);
    SetAt(loctestnum, loctesterr, vec3, true, 2, 3);
    SetAt(loctestnum, loctesterr, vec3, true, 3, 2);
    SetAt(loctestnum, loctesterr, vec3, true, 4, 1);
    SetAt(loctestnum, loctesterr, vec3, false, 5, 1);
    Empty(loctestnum, loctesterr, vec2, true);
    Size(loctestnum, loctesterr, vec2, true, 0);
    vec2 = (std::move(vec3));
    Size(loctestnum, loctesterr, vec3, true, 0);

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, false, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, false, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, false, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, false, 4, 5);

    Empty(loctestnum, loctesterr, vec3, true);
    vec2.Sort();

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, true, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, true, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, true, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, true, 4, 5);

    vec2.Sort();

    Traverse(loctestnum, loctesterr, vec2, true, TraversePrint<int>);
    GetAt(loctestnum, loctesterr, vec2, true, 0, 1);
    GetAt(loctestnum, loctesterr, vec2, true, 1, 2);
    GetAt(loctestnum, loctesterr, vec2, true, 2, 3);
    GetAt(loctestnum, loctesterr, vec2, true, 3, 4);
    GetAt(loctestnum, loctesterr, vec2, true, 4, 5);

    vec2.Resize(2);
    GetAt(loctestnum, loctesterr, vec2, false, 2, 1);

    lasd::SortableVector<int> vec4(vec2);
    Empty(loctestnum, loctesterr, vec2, false);
    lasd::SortableVector<int> vec5(std::move(vec2));
    Empty(loctestnum, loctesterr, vec2, true);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    lasd::SortableVector<int> vec6;
    EqualVector(loctestnum, loctesterr, vec2, vec6, true);
    vec4.Resize(1);
    EqualVector(loctestnum, loctesterr, vec4, vec5, false);
    vec4.Resize(2);
    SetAt(loctestnum, loctesterr, vec4, true, 1, 2);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, vec5, true, TraversePrint<int>);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    vec4.Resize(10);
    SetAt(loctestnum, loctesterr, vec4, true, 0, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 2, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 3, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 4, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 5, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 6, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 7, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 8, 1);
    SetAt(loctestnum, loctesterr, vec4, true, 9, 1);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldAdd<int>, 0, 10);
    Map(loctestnum, loctesterr, vec4, true, [](int &i) { ++i; });
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldAdd<int>, 0, 20);
    unsigned long int pos{0};
    Map(loctestnum, loctesterr, vec4, true, [&pos](int &i) { i += pos++; });
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    Fold(loctestnum, loctesterr, vec4, true, FoldParity, 0, 1);
    lasd::List<int> lst(vec4);
    lasd::SortableVector<int> vec7(lst);
    EqualVector(loctestnum, loctesterr, vec4, vec7, true);
    Traverse(loctestnum, loctesterr, vec7, true, TraversePrint<int>);
    vec1 = vec5;
    lasd::SortableVector<int> vec8(std::move(lst));
    EqualVector(loctestnum, loctesterr, vec7, vec8, true);
    vec5 = std::move(vec7);
    Traverse(loctestnum, loctesterr, vec7, true, TraversePrint<int>);
    EqualVector(loctestnum, loctesterr, vec4, vec5, true);
    EqualVector(loctestnum, loctesterr, vec4, vec8, true);
    EqualVector(loctestnum, loctesterr, vec5, vec8, true);
    Empty(loctestnum, loctesterr, lst, false);
    Empty(loctestnum, loctesterr, vec7, false);
    EqualVector(loctestnum, loctesterr, vec1, vec7, true);
    NonEqualVector(loctestnum, loctesterr, vec1, vec7, false);
    Exists(loctestnum, loctesterr, vec7, true, 1);
    Exists(loctestnum, loctesterr, vec7, false, 12);
    Traverse(loctestnum, loctesterr, vec4, true, TraversePrint<int>);
    pos = 0;
    FoldPreOrder(
        loctestnum, loctesterr, vec4, true,
        [&pos](const int &i, const double &a) {
          return pos++ % 2 ? a - i : a + i;
        },
        0, -5);
    pos = 0;
    FoldPostOrder(
        loctestnum, loctesterr, vec4, true,
        [&pos](const int &i, const double &a) {
          return pos++ % 2 ? a - i : a + i;
        },
        0, 5);
    vec5.Clear();
    Size(loctestnum, loctesterr, vec5, true, 0);
    EqualVector(loctestnum, loctesterr, vec5, vec7, false);
    NonEqualVector(loctestnum, loctesterr, vec5, vec7, true);
    Exists(loctestnum, loctesterr, vec5, false, 1);
    GetAt(loctestnum, loctesterr, vec5, false, 0, 0);
    SetAt(loctestnum, loctesterr, vec5, false, 0, 0);

    lasd::List<int> lst2;
    InsertAtBack(loctestnum, loctesterr, lst2, true, 1);
    InsertAtBack(loctestnum, loctesterr, lst2, true, 2);
    InsertAtBack(loctestnum, loctesterr, lst2, true, 3);

    lasd::List<int> lst3(lst2);
    lasd::SortableVector<int> vec9(std::move(lst2));

    Traverse(loctestnum, loctesterr, lst2, true, TraversePrint<int>);
    Traverse(loctestnum, loctesterr, lst3, true, TraversePrint<int>);
    NonEqualList(loctestnum, loctesterr, lst2, lst3, true);
}

void test_double_vector(uint &loctestnum, uint &loctesterr)
{
    // Create an empty vector of doubles
    lasd::Vector<double> v1;

    // Test if the vector is empty and its size is 0
    Empty(loctestnum, loctesterr, v1, true);
    Size(loctestnum, loctesterr, v1, true, 0);

    // Resize the vector to hold 100 elements and verify its size
    v1.Resize(100);
    Size(loctestnum, loctesterr, v1, true, 100);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1000.0);

    // Insert 100 random elements into the vector
    std::cout << " " << ++loctestnum << " (" << loctesterr << ") Attempting to insert 1000 elements :";
    for (ulong index = 0; index < 100; index++)
    {
        SetAt(loctestnum, loctesterr, v1, true, index, dist(gen));
    }

    // Create a sortable vector from the existing vector and verify equality
    lasd::SortableVector<double> sv1(v1);
    EqualVector(loctestnum, loctesterr, v1, sv1, true);

    // Test if the sortable vector is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Resize the sortable vector to 0 and verify its properties
    sv1.Resize(0);
    Empty(loctestnum, loctesterr, sv1, true);
    Size(loctestnum, loctesterr, sv1, true, 0);

    // Attempt to access front and back elements of an empty vector
    GetFront(loctestnum, loctesterr, sv1, false, 0.0);
    GetBack(loctestnum, loctesterr, sv1, false, 0.0);


    // Resize the sortable vector to 20 and set the front element
    sv1.Resize(20);
    double num = dist(gen);
    SetFront(loctestnum, loctesterr, sv1, true, num);

    // Verify the front element and attempt invalid access
    GetAt(loctestnum, loctesterr, sv1, true, 0, num);
    GetAt(loctestnum, loctesterr, sv1, false, -1, 0.0);

    // Reset the first vector to size 0 and copy from another vector with size > 0
    v1.Resize(0);
    lasd::Vector<double> v2(50);
    v1 = v2;

    // Verify the properties of the copied vector
    Size(loctestnum, loctesterr, v1, true, 50);
    Empty(loctestnum, loctesterr, v1, false);
    EqualVector(loctestnum, loctesterr, v1, v2, true);

    // Create an empty sortable vector of doubles
    lasd::SortableVector<double> sv2;

    // Assign the empty sortable vector to an existing vector
    v2 = sv2;
    // Verify that the size of v2 is 0' after assignment
    Size(loctestnum, loctesterr, v2, true, 0);

    // Check that v1(size=50) and v2(size=0) are not equal after the assignment
    EqualVector(loctestnum, loctesterr, v1, v2, false);

    // Create a new vector v3 and resize it to hold 5 elements
    lasd::Vector<double> v3;
    v3.Resize(5);
    Size(loctestnum, loctesterr, v3, true, 5);

    // Set values at specific indices in the vector
    SetAt(loctestnum, loctesterr, v3, true, 0, 5.0);
    SetAt(loctestnum, loctesterr, v3, true, 1, 4.0);
    SetAt(loctestnum, loctesterr, v3, true, 2, 3.0);
    SetAt(loctestnum, loctesterr, v3, true, 3, 2.0);
    SetAt(loctestnum, loctesterr, v3, true, 4, 1.0);

    // Attempt to set a value at an invalid index (out of bounds)
    SetAt(loctestnum, loctesterr, v3, false, 5, 1.0);

    // Verify that vector v2 is empty and has size 0
    Empty(loctestnum, loctesterr, v2, true);
    Size(loctestnum, loctesterr, v2, true, 0);

    // Move the contents of v3 to v2 and verify the sizes of both vectors
    v2 = (std::move(v3));
    Size(loctestnum, loctesterr, v3, true, 0); // v3 should now be empty

    // Traverse the vector v2 and print its elements
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<double>);
    // Traverse the vector v2 in pre-order and post-order and print its elements
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<double>);

    // Resize the sortable vector sv1 to 10 and populate it with random elements
    sv1.Resize(10);
    for (ulong ind = 0; ind < 10; ind++) {
        SetAt(loctestnum, loctesterr, sv1, true, ind, dist(gen));
    }

    // Verify if the sortable vector sv1 is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Traverse the sortable vector sv1 and print its elements
    Traverse(loctestnum, loctesterr, sv1, true, TraversePrint<double>);

}


void test_char_vector(uint &loctestnum, uint &loctesterr)
{
    // Create an empty vector of characters
    lasd::Vector<char> v1;

    // Test if the vector is empty and its size is 0
    Empty(loctestnum, loctesterr, v1, true);
    Size(loctestnum, loctesterr, v1, true, 0);

    // Resize the vector to hold 100 elements and verify its size
    v1.Resize(100);
    Size(loctestnum, loctesterr, v1, true, 100);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<char> dist('a', 'z');

    // Insert 100 random elements into the vector
    std::cout << " " << ++loctestnum << " (" << loctesterr << ") Attempting to insert 1000 elements :";
    for (ulong index = 0; index < 100; index++)
    {
        SetAt(loctestnum, loctesterr, v1, true, index, dist(gen));
    }
    // Create a sortable vector from the existing vector and verify equality
    lasd::SortableVector<char> sv1(v1);
    EqualVector(loctestnum, loctesterr, v1, sv1, true);

    // Test if the sortable vector is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Resize the sortable vector to 0 and verify its properties
    sv1.Resize(0);
    Empty(loctestnum, loctesterr, sv1, true);
    Size(loctestnum, loctesterr, sv1, true, 0);

    // Attempt to access front and back elements of an empty vector
    GetFront(loctestnum, loctesterr, sv1, false, ' ');
    GetBack(loctestnum, loctesterr, sv1, false, ' ');

    // Resize the sortable vector to 20 and set the front element
    sv1.Resize(20);
    char num = dist(gen);
    SetFront(loctestnum, loctesterr, sv1, true, num);

    // Verify the front element and attempt invalid access
    GetAt(loctestnum, loctesterr, sv1, true, 0, num);
    GetAt(loctestnum, loctesterr, sv1, false, -1, ' ');

    // Reset the first vector to size 0 and copy from another vector with size > 0
    v1.Resize(0);
    lasd::Vector<char> v2(50);
    v1 = v2;

    // Verify the properties of the copied vector
    Size(loctestnum, loctesterr, v1, true, 50);
    Empty(loctestnum, loctesterr, v1, false);
    EqualVector(loctestnum, loctesterr, v1, v2, true);

    // Create an empty sortable vector of characters
    lasd::SortableVector<char> sv2;

    // Assign the empty sortable vector to an existing vector
    v2 = sv2;

    // Verify that the size of v2 is 0' after assignment
    Size(loctestnum, loctesterr, v2, true, 0);

    // Check that v1(size=50) and v2(size=0) are not equal after the assignment
    EqualVector(loctestnum, loctesterr, v1, v2, false);

    // Create a new vector v3 and resize it to hold 5 elements
    lasd::Vector<char> v3;
    v3.Resize(5);
    Size(loctestnum, loctesterr, v3, true, 5);

    // Set values at specific indices in the vector
    SetAt(loctestnum, loctesterr, v3, true, 0, 'e');
    SetAt(loctestnum, loctesterr, v3, true, 1, 'd');
    SetAt(loctestnum, loctesterr, v3, true, 2, 'c');
    SetAt(loctestnum, loctesterr, v3, true, 3, 'b');
    SetAt(loctestnum, loctesterr, v3, true, 4, 'a');

    // Attempt to set a value at an invalid index (out of bounds)
    SetAt(loctestnum, loctesterr, v3, false, 5, 'a');

    // Verify that vector v2 is empty and has size 0
    Empty(loctestnum, loctesterr, v2, true);
    Size(loctestnum, loctesterr, v2, true, 0);

    // Move the contents of v3 to v2 and verify the sizes of both vectors
    v2 = (std::move(v3));
    Size(loctestnum, loctesterr, v3, true, 0); // v3 should now be empty

    // Traverse the vector v2 and print its elements
    Traverse(loctestnum, loctesterr, v2, true, TraversePrint<char>);
    // Traverse the vector v2 in pre-order and post-order and print its elements
    TraversePreOrder(loctestnum, loctesterr, v2, true, TraversePrint<char>);
    TraversePostOrder(loctestnum, loctesterr, v2, true, TraversePrint<char>);

    // Resize the sortable vector sv1 to 10 and populate it with random elements
    sv1.Resize(10);
    for (ulong ind = 0; ind < 10; ind++) {
        SetAt(loctestnum, loctesterr, sv1, true, ind, dist(gen));
    }

    // Verify if the sortable vector sv1 is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Traverse the sortable vector sv1 and print its elements
    Traverse(loctestnum, loctesterr, sv1, true, TraversePrint<char>);

}

void test_string_vector(uint &loctestnum, uint &loctesterr)
{
    // Create an empty vector of strings
    lasd::Vector<std::string> v1;

    // Test if the vector is empty and its size is 0
    Empty(loctestnum, loctesterr, v1, true);
    Size(loctestnum, loctesterr, v1, true, 0);

    // Resize the vector to hold 100 elements and verify its size
    v1.Resize(100);
    Size(loctestnum, loctesterr, v1, true, 100);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);

    // Fill the vector with random strings
    for (ulong index = 0; index < 100; index++) {
        std::string randomString;
        int length = dist(gen) % 10 + 1; // Random string length between 1 and 10
        for (int i = 0; i < length; i++) {
            randomString += static_cast<char>('a' + (dist(gen) % 26)); // Random lowercase letter
        }
        SetAt(loctestnum, loctesterr, v1, true, index, randomString);
    }

    // Check size
    Size(loctestnum, loctesterr, v1, true, 100);

    // Create a sortable vector from the existing vector and verify equality
    lasd::SortableVector<std::string> sv1(v1);
    EqualVector(loctestnum, loctesterr, v1, sv1, true);

    // Test if the sortable vector is sorted
    SortedLinear(loctestnum, loctesterr, sv1, true);

    // Resize the sortable vector to 0 and verify its properties
    sv1.Clear();
    Empty(loctestnum, loctesterr, sv1, true);
    Size(loctestnum, loctesterr, sv1, true, 0);

    GetFront(loctestnum,loctesterr,sv1,false,std::string{""});
}

void test_int_list(uint &loctestnum, uint &loctesterr)
{
    // Create an empty list of integers
    lasd::List<int> l1;

    // Test if the list is empty and its size is 0
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);

    // Insert elements at the front of the list
    int back = dist(gen);
    InsertAtFront(loctestnum, loctesterr, l1, true, back);
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));

    // Insert another element at the front and verify the front and back elements
    int front = dist(gen);
    InsertAtFront(loctestnum, loctesterr, l1, true, front);
    GetFront(loctestnum, loctesterr, l1, true, front);
    GetBack(loctestnum, loctesterr, l1, true, back);

    // Traverse the list and print its elements
    Traverse(loctestnum, loctesterr, l1, true, TraversePrint<int>);

    // Set a new value at the front of the list and verify it
    int newFront = dist(gen);
    SetAt(loctestnum, loctesterr, l1, true, 0, newFront);
    GetFront(loctestnum, loctesterr, l1, true, newFront);

    // Traverse the list again and print its elements
    Traverse(loctestnum, loctesterr, l1, true, TraversePrint<int>);

    // Verify the size of the list
    Size(loctestnum, loctesterr, l1, true, 8);

    // Clear the list and verify it is empty
    l1.Clear();
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    // Create a vector of integers and populate it with random values
    lasd::Vector<int> v1(100);
    for (int i = 0; i < 100; i++) {
        SetAt(loctestnum, loctesterr, v1, true, i, dist(gen));
    }

    // Create a list from the vector and verify its properties
    lasd::List<int> l2(v1);
    Empty(loctestnum, loctesterr, l2, false);
    Size(loctestnum, loctesterr, l2, true, 100);

    // Move the vector into a new list and verify the properties of both lists
    lasd::List<int> l3(std::move(v1));
    Empty(loctestnum, loctesterr, l2, false);
    Size(loctestnum, loctesterr, l2, true, 100);

    // Verify that the two lists are equal
    EqualList(loctestnum, loctesterr, l2, l3, true);
}

void test_double_list(uint &loctestnum, uint &loctesterr)
{
    // Create an empty list of doubles
    lasd::List<double> l1;

    // Test if the list is empty and its size is 0
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1000.0);

    // Insert elements at the front of the list
    double back = dist(gen);
    InsertAtFront(loctestnum, loctesterr, l1, true, back);
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));

    // Insert another element at the front and verify the front and back elements
    double front = dist(gen);
    InsertAtFront(loctestnum, loctesterr, l1, true, front);
    GetFront(loctestnum, loctesterr, l1, true, front);
    GetBack(loctestnum, loctesterr, l1, true, back);

    // Traverse the list and print its elements
    Traverse(loctestnum, loctesterr, l1, true,TraversePrint<double>);
}

void test_char_list(uint &loctestnum, uint &loctesterr)
{
    // Create an empty list of characters
    lasd::List<char> l1;

    // Test if the list is empty and its size is 0
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<char> dist('a', 'z');

    // Insert elements at the front of the list
    char back = dist(gen);
    InsertAtFront(loctestnum, loctesterr, l1, true, back);
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));
    InsertAtFront(loctestnum, loctesterr, l1, true, dist(gen));

    // Insert another element at the front and verify the front and back elements
    char front = dist(gen);
    InsertAtFront(loctestnum, loctesterr, l1, true, front);
    GetFront(loctestnum, loctesterr, l1, true, front);
    GetBack(loctestnum, loctesterr, l1, true, back);

    // Traverse the list and print its elements
    Traverse(loctestnum, loctesterr,l1,true ,TraversePrint<char>);
}

void test_string_list(uint &loctestnum, uint &loctesterr)
{
    // Create an empty list of strings
    lasd::List<std::string> l1;

    // Test if the list is empty and its size is 0
    Empty(loctestnum, loctesterr, l1, true);
    Size(loctestnum, loctesterr, l1, true, 0);

    // Initialize a random number generator
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);

    // Fill the list with random strings
    for (ulong index = 0; index < 100; index++) {
        std::string randomString;
        int length = dist(gen) % 10 + 1; // Random string length between 1 and 10
        for (int i = 0; i < length; i++) {
            randomString += static_cast<char>('a' + (dist(gen) % 26)); // Random lowercase letter
        }
        InsertAtFront(loctestnum, loctesterr, l1, true, randomString);
    }

    // Check size
    Size(loctestnum, loctesterr, l1, true, 100);

    // Traverse the list and print its elements
    Traverse(loctestnum, loctesterr,l1,true ,TraversePrint<std::string>);
}

void PersonalTestList(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;
    uint loctest = 0;
    uint errtest = 0;

    std::cout << "\033[4;36m<<Testing list of integers>>\033[0m" << std::endl;
    test_int_list(loctest, errtest);
    std::cout << "\033[4;36mEnd of List<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing list of doubles>>\033[0m" << std::endl;
    test_double_list(loctest, errtest);
    std::cout << "\033[4;36mEnd of List<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing list of strings>>\033[0m" << std::endl;
    test_string_list(loctest, errtest);
    std::cout << "\033[4;36mEnd of List<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing list of chars>>\033[0m" << std::endl;
    test_char_list(loctest, errtest);
    std::cout << "\033[4;36mEnd of List<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    std::cout << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mEnd List tests: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum+=tottest;
    testerr+=toterr;
}

void PersonalTestVector(uint &testnum, uint &testerr)
{
    uint tottest = 0;
    uint toterr = 0;
    uint loctest = 0;
    uint errtest = 0;
    std::cout << "\033[4;36m<<Testing vector of integers>>\033[0m" << std::endl;
    test_int_vector(loctest, errtest);
    std::cout << "\033[4;36mEnd of Vector<int> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing vector of doubles>>\033[0m" << std::endl;
    test_double_vector(loctest, errtest);
    std::cout << "\033[4;36mEnd of Vector<double> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing vector of strings>>\033[0m" << std::endl;
    test_string_vector(loctest, errtest);
    std::cout << "\033[4;36mEnd of Vector<string> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;

    tottest += loctest;
    toterr += errtest;
    loctest = 0;
    errtest = 0;
    std::cout << std::endl;
    std::cout << "\033[4;36m<<Testing vector of chars>>\033[0m" << std::endl;
    test_char_vector(loctest, errtest);
    std::cout << "\033[4;36mEnd of Vector<char> Test! (Error/Tests: " << errtest << "/" << loctest << ")\033[0m" << std::endl;
    tottest += loctest;
    toterr += errtest;

    std::cout << std::endl;
    std::cout << "\033[1;35mEnd Vector personal tests: " << toterr << " errors found over " << tottest << " tests.\033[0m" << std::endl;
    testnum+=tottest;
    testerr+=toterr;
    std::cout << std::endl;
}

void myTestExercise1A(uint &testnum, uint &testerr)
{
    std::cout << "\033[1;35mBegin of Vector Personal Tests\033[0m"<<std::endl;
    std::cout << std::endl;
    PersonalTestVector(testnum, testerr);
    std::cout << "\033[1;35mBegin of SetLst Personal Tests\033[0m"<<std::endl;
    std::cout << std::endl;
    PersonalTestList(testnum, testerr);
    cout << endl
         << "\033[1;34mExercise 1A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")\033[0m" << endl;
}
