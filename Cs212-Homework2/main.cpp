// main.cpp by Chris Panican

#include <iostream>
#include "sequence.h"

int main() {
    sequence arr1(5);
    sequence arr2(5);
    sequence arr3(5);

    arr1.insert(1);arr1.insert(2);arr1.insert(3);arr1.insert(4);arr1.insert(5);
    arr2.insert(1);arr2.insert(2);arr2.insert(3);arr2.insert(4);arr2.insert(5);

    cout << "arr1: ";
    for (int i = 0; i < arr1.size(); i++) { cout << arr1.seqArr(i) << " "; }
    cout << endl;
    cout << "arr2: ";
    for (int i = 0; i < arr2.size(); i++) { cout << arr2.seqArr(i) << " "; }

    cout << endl;
    arr3 = arr1;
    cout << arr3.seqArr(2);


}
