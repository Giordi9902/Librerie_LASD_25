
#ifndef SETTEST_HPP
#define SETTEST_HPP

#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"

/* ************************************************************************** */

template <typename Data>
void EqualSetLst(unsigned int & testnum, unsigned int & testerr, const lasd::SetLst<Data> & set1, const lasd::SetLst<Data> & set2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two setlsts are " << ((tst = (set1 == set2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void NonEqualSetLst(unsigned int & testnum, unsigned int & testerr, const lasd::SetLst<Data> & set1, const lasd::SetLst<Data> & set2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two setlsts are " << ((tst = (set1 != set2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

template <typename Data>
void EqualSetVec(unsigned int & testnum, unsigned int & testerr, const lasd::SetVec<Data> & set1, const lasd::SetVec<Data> & set2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two setvecs are " << ((tst = (set1 == set2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void NonEqualSetVec(unsigned int & testnum, unsigned int & testerr, const lasd::SetVec<Data> & set1, const lasd::SetVec<Data> & set2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two setvecs are " << ((tst = (set1 != set2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

#endif
