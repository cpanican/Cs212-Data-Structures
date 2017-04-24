//
// CSC 212 Assignment 1 (Due on September 24)
// Submitted by : Chris Panican
// main.cpp
//

#include "complex.h"
Complex sum(Complex,Complex);
Complex subtract(Complex,Complex);

int main() {
    Complex ex1(4,1);
    Complex ex2(2,7);
    cout << "addition: ";
    sum(ex1,ex2).print();
    cout << "subtraction: ";
    subtract(ex1,ex2).print();
    return 0;
}