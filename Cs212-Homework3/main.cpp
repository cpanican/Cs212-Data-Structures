// main.cpp by Chris Panican

#include <iostream>
#include "sequence.h"

int main() {
    sequence arr1;

    arr1.insert(1);
    arr1.insert(2);
    arr1.insert(3);
    arr1.insert(4);

    cout << arr1 << endl;

    cout << "arr1 used: " << arr1.size() << endl;
    cout << "arr1 capacity: " << arr1.total_size() << endl;

    cout << endl;
    cout << "** burst input test **" << endl;
    for (int i = 1; i < 33; i++) {
        arr1.insert(i);
    }
    cout << arr1 << endl;
    cout << "arr1 used: " << arr1.size() << endl;
    cout << "arr1 capacity: " << arr1.total_size() << endl;
    cout << "36 is 90% of 40, therefore in next insert, capacity should be doubled." << endl;

    cout << endl;
    cout << "** input one value **" << endl;
    arr1.insert(1);
    cout << arr1 << endl;
    cout << "arr1 used: " << arr1.size() << endl;
    cout << "arr1 capacity: " << arr1.total_size() << endl;

    cout << endl;
    cout << "** erase one value **" << endl;
    arr1.erase_last();
    cout << arr1 << endl;
    cout << "arr1 used: " << arr1.size() << endl;
    cout << "arr1 capacity: " << arr1.total_size() << endl;
    cout << "Since 36/80 is 45% full, capacity will not shrink. It will shrink if 60% empty." << endl;

    cout << endl;
    cout << "** erase to 60% empty **" << endl;
    arr1.erase_last();
    arr1.erase_last();
    arr1.erase_last();
    arr1.erase_last();
    arr1.erase_last();
    cout << arr1 << endl;
    cout << "arr1 used: " << arr1.size() << endl;
    cout << "arr1 capacity: " << arr1.total_size() << endl;
    cout << "Since 31/80 is only 38.7% full, capacity will shrink. Capacity will shrink by 60%." << endl;
}
