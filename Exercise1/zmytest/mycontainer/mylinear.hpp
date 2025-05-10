#ifndef MYLINEARTEST_HPP
#define MYLINEARTEST_HPP
#include "../../container/linear.hpp"
#include <cmath>

template <typename Data>
void SortedLinear(uint &testnum, uint &testerr, lasd::SortableLinearContainer<Data> &con, bool chk)
{
    bool tst;
    testnum++;
    try
    {
        std::cout << " " << testnum << " (" << testerr << ") Checking if the container is sorted - ";
        tst = true;
        for (ulong idx = 0; idx < con.Size() - 1; idx++)
        {
            if (con[idx] > con[idx + 1])
            {
                tst = false;
                break;
            }
        }
        std::cout << ((tst = chk) ? "The container is sorted : Correct!" : "The container is not sorted: Error!") << std::endl;
    }
    catch (std::exception &exc)
    {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint)tst);
};

template <typename Data>
void NonSortedLinear(uint &testnum, uint &testerr, lasd::SortableLinearContainer<Data> &con, bool chk)
{
    bool tst = false;
    testnum++;
    try
    {
        std::cout << " " << testnum << " (" << testerr << ") Checking if the container is not sorted: ";
        size_t i = 1;

        while (i < con.Size())
        {
            if (con[i - 1] > con[i])
            {
                tst = true;
                break;
            }
            ++i;
        }
        std::cout << ((tst = (tst == chk)) ? "The container is not sorted" : "The container is sorted") << "!" << std::endl;
    }
    catch (std::exception &exc)
    {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint)tst);
};

template <typename Data>
void GetFrontDouble(uint& testnum,uint& testerr, const lasd::LinearContainer<Data>& con, bool chk, const Data& val,const double& eps)
{
bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The front of the linear container is \"" << con.Front() << "\": ";
    tst = (std::abs(con.Front()-val)<eps);
    std::cout << ((tst == chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
};

template <typename Data>
void GetBackDouble(uint& testnum,uint& testerr, const lasd::LinearContainer<Data>& con, bool chk, const Data& val,const double& eps)
{
bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The back of the linear container is \"" << con.Back() << "\": ";
    tst = (std::abs(con.Back()-val)<eps);
    std::cout << ((tst == chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::length_error & exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (uint) tst);
};

#endif