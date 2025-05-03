#include <iostream>
using namespace std;

void stestVectorInt(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVectorDouble(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVectorString(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVector(unsigned int &testnum, unsigned int &testerr)
{
}

void stestListInt(unsigned int &testnum, unsigned int &testerr)
{
}

void stestListDouble(unsigned int &testnum, unsigned int &testerr)
{
}

void stestListString(unsigned int &testnum, unsigned int &testerr)
{
}

void stestList(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVectorListInt(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVectorListDouble(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVectorListString(unsigned int &testnum, unsigned int &testerr)
{
}

void stestVectorList(unsigned int &testnum, unsigned int &testerr)
{
}

void myTestExercise1A(unsigned int &testnum, unsigned int &testerr)
{
    stestVector(testnum, testerr);
    stestList(testnum, testerr);
    stestVectorList(testnum, testerr);
    cout << endl
         << "Exercise 1A (Personal Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}