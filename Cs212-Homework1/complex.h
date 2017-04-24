//
// CSC 212 Assignment 1 (Due on September 24)
// Submitted by : Chris Panican
// complex.h
//

#ifndef HOMEWORK1_COMPLEX_H
#define HOMEWORK1_COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    int realPart;
    int imaginaryPart;
public:
    Complex(int, int);
    int RealPart(){
        return this->realPart;
    }
    int ImaginaryPart(){
        return this->imaginaryPart;
    }
    void print();
};

#endif //HOMEWORK1_COMPLEX_H
