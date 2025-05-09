#ifndef MYLINEARTEST_HPP
#define MYLINEARTEST_HPP
#include "../../container/linear.hpp"

template <typename Data>
void SortedLinear(uint& testnum, uint& testerr, lasd::SortableLinearContainer<Data>& con, bool chk){
    bool tst;
    testnum++;
    try{
        std::cout << " " << testnum << " (" << testerr << ") Sorting the linear container: ";
        con.Sort();
        tst = true;
        for(ulong idx=0; idx < con.Size() - 1; idx++) {
          if(con[idx] > con[idx + 1]) {
            tst = false;
            break;
          }
        }
        std::cout << ((tst = chk) ? "The container is sorted" : "The container is not sorted") << "!" << std::endl;
    } catch (std::exception& exc){
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint) tst);
};

#endif