#include <iostream>
using namespace std;

void PersonalTestSet(uint& testnum, uint& testerr){

}

void myTestExercise1B(uint &testnum, uint &testerr){
    PersonalTestSet(testnum,testerr);
    cout << endl
         << "Exercise 1B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}