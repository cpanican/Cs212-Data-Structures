//
// Created by Chris on 10/14/2016.
//

/*
 * To professor:
 * In Homework 3, I created a new function called 'void sizeCheck()'. I also corrected my homework 2 as well by following your advice in the email you sent.
 * I included an explanation in my main.cpp file on how the new function works.
 */

#ifndef HOMEWORK2_SEQUENCE_H
#define HOMEWORK2_SEQUENCE_H


#include <w32api/tchar.h>
#include <iostream>
using namespace std;

class sequence {
public:
    static const size_t INITIAL_CAPACITY = 5;
    sequence(size_t initCapacity = INITIAL_CAPACITY); // creates a dynamic array with initial capacity of 5
    ~sequence(); // destructor for sequence

    //Precondition: A value exists in this sequence
    //Postcondition: Erases first element in this sequence
    void erase_first();

    //Precondition: A value exists in this sequence
    //Postcondition: Erases last element in this sequence
    void erase_last();

    //Precondition: Value exist in this occurrence of sequence
    //Postcondition: Erases the nth value in this occurrence and n > 0
    void erase_occurrence(int target, int place);

    //Precondition: Input should be n > 0 and n < used.
    //Postcondition: Erases element at index n
    void erase_from(size_t index);

    //Precondition: Input should be an integer
    //Postcondition: Inserts a value at the first element in the sequence
    void insert_first(int element);

    //Precondition: Inputs should be size_t and int
    //Postcondition: Inserts a value in sequence at specified index
    void insert_at(size_t index, int value);

    //Precondition: Input should be an integer
    //Postcondition: Inserts an element at the end of sequence
    void insert(int new_entry);

    //Precondition: Input should be an integer
    //Postcondition: Counts number of occurrence of input
    int count(int target);

    //Precondition: None
    //Postcondition: Returns the number of elements in sequence
    size_t size();

    //Precondition: None
    //Postcondition: Returns the total capacity of sequence
    size_t total_size();

    void operator += (const sequence& array1); // add a sequence into this sequence
    void operator += (const int& input); // add an int into this sequence
    sequence& operator = (const sequence& array1); // returns a sequence, ex: x = y
    bool operator == (const sequence& array1); // check if array1 and array2 are equal
    friend ostream& operator<<(ostream& output,const sequence& array1);; // output a sequence
    friend istream& operator>>(istream& input, sequence& array1); // takes sequence as input

private:
    size_t used; // how many spots are used in array
    size_t capacity; // total capacity of array
    int * array; // dynamic array
    void sizeCheck(); // Assignment 3: check array size and see if array needs to be bigger or small depending on inputs.
};

sequence operator + (const sequence& array1, const sequence& array2); // connects two sequences and makes new sequence with the use of +
sequence operator + (const sequence& array1, const int& array2); // adds int value to array if + is used instead of insert

#endif //HOMEWORK2_SEQUENCE_H
