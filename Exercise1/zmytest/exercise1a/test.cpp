#include <iostream>
using namespace std;

void PersonalTestVector(unsigned int& testnum, unsigned int& testerr){

}

void PersonalTestList(unsigned int& testnum, unsigned int& testerr){

}


void myTestExercise1A(unsigned int &testnum, unsigned int &testerr)
{
    PersonalTestVector(testnum, testerr);
    PersonalTestList(testnum, testerr);
    cout << endl
         << "Exercise 1A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}