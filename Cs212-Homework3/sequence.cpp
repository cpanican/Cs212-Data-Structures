//
// Created by Chris on 10/14/2016.
//

/*
 * To professor:
 * In Homework 3, I created a new function called 'void sizeCheck()'. I also corrected my homework 2 as well by following your advice in the email you sent.
 * I included an explanation in my main.cpp file on how the new function works.
 */

#include "sequence.h"


sequence::sequence(size_t init_capacity) {
    array = new int [init_capacity];
    capacity = init_capacity;
    used = 0;
}

sequence::~sequence() {
    delete [] array;
}

/*
 * Homework 3. This function doubles the value of array if it is 90% full. It also shrinks the capacity buy 60% if the array is only 40% full.
 */
void sequence::sizeCheck() {
    if(used/(double)capacity <= 0.4 || used/(double)capacity >= 0.9) {
        if ((used) / (double) capacity >= 0.9) {
            capacity *= 2;
        }
        else if ((used) / (double) capacity <= 0.4){
            capacity *= 0.6;
        }
        int* newArr = new int[capacity];
        copy(array, array+used, newArr);
        delete[] array;
        array = newArr;
    }
}

void sequence::erase_first() {
    if(used==0 || capacity==0) {
        cout << "There is no element to erase" << endl;
        return;
    }
    else {
        sizeCheck();
        for (int i = 0; i < used; ++i) {
            array[i] = array[i + 1];
        }
        --used;
    }
}

void sequence::erase_last() {
    if(used == 0 || capacity == 0) {
        cout << "There is no element to erase" << endl;
        return;
    }
    else if (used == capacity){
        sizeCheck();
        for(size_t k = used-1; k <= used; k++) {
            array[k]=array[k+1];
        }
        --used;
        --capacity;
        return;
    }
    else {
        sizeCheck();
        for(size_t k = used-1; k <= used; k++) {
            array[k]=array[k+1];
        }
        --used;
        return;
    }
}

void sequence::erase_occurrence(int target, int place) {
    if (used ==0) {
        cout << "Array is empty" << endl;
        return;
    }

    int occurrence = 0; // "second" occurrence of 3
    bool tracker=false;

    sizeCheck();
    for(int i = 0; i < capacity; i++) {
        if (array[i] == target && !tracker) {
            occurrence++;
        }
        if (occurrence == place) {
            tracker = true;
            used--;
            // shift stuff from right to left
            for(int k = i; k < used; k++) {
                array[k]=array[k+1];
            }
        }
    }
    if (!tracker){
        {
            if (place == 1) {
                cout << "1st occurrence of " << target << " not found" << endl;
            }
            else if (place == 2) {
                cout << "2nd occurrence of " << target << " not found" << endl;
            }
            else if (place == 3) {
                cout << "3rd occurrence of " << target << " not found" << endl;
            }
            else if (place >= 4) {
                cout << place <<"th occurrence of " << target << " not found" << endl;
            }
        }
    }
}

void sequence::erase_from(size_t index) {
    if (capacity == used) {
        capacity--;
    }
    if (used == 0) {
        cout << "Array is empty" << endl;
    }

    if (index < 0 || index > used) {
        cout << "Index is out of bounds" << endl;
    }

    sizeCheck();
    for(size_t i = index; i < used; i++) {
        array[i]=array[i+1];
    }
    --used;
}

void sequence::insert_first(int element) {
    if (used == capacity) {
        capacity++;
    }
    for(size_t i = used-1; i > 0 ; --i) {
        array[i] = array[i-1];
    }
    sizeCheck();
    array[0] = element;
    used++;
}

void sequence::insert_at(size_t index, int value) {
    if(index < 0) {
        cout << "Index should be greater than or equal to 0" << endl;
    }
    if (used == capacity) {
        capacity++;
    }
    else if (index > (used + capacity)) {
        for(size_t i = used; i <= index; ++i ) {
            insert(0);
            if (i==index){
                array[i]=value;
            }
        }
        used = index+1;
        capacity = index+1;

    } else {
        for(size_t i = used; i > index ; --i) {
            array[i] = array[i-1];
        }
        array[index] = value;
        used++;
    }
    sizeCheck();
}

//assignment 3 functions used here
void sequence::insert(int new_entry) {
    if (used == capacity) {
        capacity++;
    }
    sizeCheck();
    array[used] = new_entry;
    used++;
}

int sequence::count(int target) {
    int counter = 0;
    for(int i = 0; i < used; i++) {
        if (array[i] == target) {
            counter++;
        }
    }
    return counter;
}

size_t sequence::size() {
    return used;
}

size_t sequence::total_size() {
    return capacity;
}

sequence operator + (sequence array1, sequence array2) {
    sequence array3(array1.size() + array2.size());
    array3 += array1;
    array3 += array2;
    return array3;
}

sequence operator + (sequence array1, int input) {
    sequence array2(array1.size() + 1);
    array2 += array1;
    array2.insert(input);
    return array2;
}

void sequence::operator+=(const sequence& array1) {
    for(int i = 0; i < array1.capacity; i++) {
        array[capacity++] = array1.array[i];
        used++;
    }
}

void sequence::operator+=(const int& input) {
    capacity++;
    used++;
    array[used-1] = input;
}

sequence& sequence::operator=(const sequence& array1) {
    delete [] array;
    array = new int[array1.capacity];
    for(int i = 0; i < array1.used; ++i) {
        array[i] = array1.array[i];
    }
    used = array1.used;
    capacity = array1.capacity;
    return * this;
}

bool sequence::operator == (const sequence& array1) {
    if(array1.capacity != capacity) {
        cout << "This array has different capacity" << endl;
        return false;
    }
    if(array1.used != used) {
        cout << "This array has different number of values" << endl;
        return false;
    }
    for(int i = 0; i < used; ++i) {
        if(array1.array[i] != array[i]) {
            cout << "First array has value of " << array1.array[i] << " at " << i << ". While second array has "
                    "a value of " << array[i] << "." << endl;
            return false;
        }
    }
    cout << "Both arrays are equal" << endl;
    return true;
}

ostream& operator<<(ostream& output,const sequence& array1) {
    for(int i = 0; i < array1.used; i++) {
        output << array1.array[i];
        if(i != array1.used-1)
            output << ", ";
    }
    return output;
}

istream& operator >> (istream& input, sequence& array1) {
    cout << "Enter the size of the sequence" << endl;
    size_t capacity;
    input >> capacity;
    array1 = sequence(capacity);
    cout << "Enter " << capacity << " number of element(s) to fill up the sequence" << endl;
    for(size_t i = 0; i < capacity; i++) {
        int element;
        input >> element;
        array1.insert(element);
    }
    return input;
}