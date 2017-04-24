//
// CSC 212 Assignment 1 (Due on September 24)
// Submitted by : Chris Panican
// complex.cpp
//

#include "complex.h"

Complex::Complex(int a, int b) {
    realPart = a;
    imaginaryPart = b;
}

void Complex::print() {
    if(imaginaryPart < 0) {
        cout << realPart << imaginaryPart << "i";
    }
    else {
        cout << realPart << "+" << imaginaryPart << "i" << endl;
    }
}

//Addition
Complex sum(Complex ex1, Complex ex2) {
    return Complex(ex1.RealPart() + ex2.RealPart(), ex1.ImaginaryPart() + ex2.ImaginaryPart());
}
//Subtraction
Complex subtract(Complex ex1, Complex ex2) {
    return Complex(ex1.RealPart() - ex2.RealPart(), ex1.ImaginaryPart() - ex2.ImaginaryPart());
}