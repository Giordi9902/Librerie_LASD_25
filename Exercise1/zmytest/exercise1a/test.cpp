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
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100);
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

    testnum += loctestnum;
    testerr += loctesterr;
    std::cout << "\033[4;36mEnd of Vector<int> Personal Test! (Error/Tests: " << loctesterr << "/" << loctestnum << ")\033[0m" << std::endl;
}

void PersonalDoubleVectorTest(uint &testnum, uint &testerr)
{
    uint loctestnum = 0, loctesterr = 0;
    std::cout << "\033[4;36m<<Testing vector of doubles>>\033[0m" << std::endl;
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0, 100.0);
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
    std::uniform_int_distribution<int> dist(1, 100);

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
            l2[index] = (index + 1) * 10;
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
    std::uniform_real_distribution<double> dist(1.0, 100.0);

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
