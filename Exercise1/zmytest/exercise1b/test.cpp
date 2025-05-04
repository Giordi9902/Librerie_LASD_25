#include <iostream>
using namespace std;

void PersonalTestSet(unsigned int& testnum, unsigned int& testerr){

}

void myTestExercise1B(unsigned int &testnum, unsigned int &testerr){
    PersonalTestSet(testnum,testerr);
    cout << endl
         << "Exercise 1B (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}