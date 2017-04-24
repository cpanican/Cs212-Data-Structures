//
// Created by Chris on 10/14/2016.
//

#ifndef HOMEWORK2_SEQUENCE_H
#define HOMEWORK2_SEQUENCE_H


#include <w32api/tchar.h>
#include <iostream>
using namespace std;

class sequence {
private:
    int used; // how many spots are used in array
    int capacity; // capacity of array
    int * array;

public:
    sequence(int capacity);
    ~sequence(); // destructor

    int seqArr(int i);

    void erase_first(); // remove first occurrence
    void erase_last(); // remove last occurrence
    void erase_occurrence(int target, int place); // remove occurrence of value, ex: remove second occurrence of 4
    void erase_from(int index); // remove value from index (index >= 0)

    void insert_first(int element); // insert element at first index
    void insert_at(int index, int value); // insert element at specific index

    void insert(int new_entry); // insert at end of sequence
    int count(int target); // count number of occurence
    int size(); // returns number of elements
    int size2(); // returns capacity of array

    void operator += (sequence array1); // add parameter into this sequence
    sequence operator = (sequence array1); // returns a sequence, ex: x = y
    bool operator == (sequence array1); // check if array1 and array2 are equal
    friend ostream& operator<<(ostream& output,const sequence& array1);
    friend istream& operator>>(istream& input, sequence& array1);
};

sequence operator + (sequence array1, sequence array2); // connects two sequences and makes new sequence


#endif //HOMEWORK2_SEQUENCE_H
