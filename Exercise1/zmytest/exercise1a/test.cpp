#include <iostream>
using namespace std;

void PersonalTestVector(uint& testnum, uint& testerr){

}

void PersonalTestList(uint& testnum, uint& testerr){

}


void myTestExercise1A(uint &testnum, uint &testerr)
{
    PersonalTestVector(testnum, testerr);
    PersonalTestList(testnum, testerr);
    cout << endl
         << "Exercise 1A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}