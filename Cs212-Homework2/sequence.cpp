//
// Created by Chris on 10/14/2016.
//

#include "sequence.h"


sequence::sequence(int init_capacity) {
    array = new int [init_capacity];
    capacity = init_capacity;
    used = 0;
}

sequence::~sequence() {
    delete [] array;
}

int sequence::seqArr(int i) {
    return array[i];
}

void sequence::erase_first() {
    for(int i = 0; i < used; ++i) {
        array[i] = array[i+1];
    }
    array[used-1] = -1;
    --used;
}

void sequence::erase_last() {
    array[used-1] = -1;
    --used;
}

void sequence::erase_occurrence(int target, int place) {
    if (used ==0) {
        cout << "Array is empty" << endl;
        return;
    }
    int occurrence = 0; // "second" occurrence of 3
    bool tracker=false;

    for(int i = 0; i < capacity; i++) {
        if (array[i] == target && !tracker) {
            occurrence++;
            if (occurrence == place) {
                tracker = true;
                used--;
                // shift stuff from right to left
                for(int k = i; k < used; k++) {
                    array[k]=array[k+1];
                }
            }
        }
    }
    if (!tracker){
        cout << "Occurrence of " << target << " not found" << endl;
    }
}

void sequence::erase_from(int index) {
    for(int i = index; i < used; i++) {
        array[i]=array[i+1];
    }
    --used;
}

void sequence::insert_first(int element) {
    if (used == capacity) {
        capacity++;
    }
    for(int i = used; i > 0 ; --i) {
        array[i] = array[i-1];
    }
    array[0] = element;
    used++;
}

void sequence::insert_at(int index, int value) {
    if (used == capacity) {
        capacity++;
    }
    if (index > used && capacity) {
        for(int i = used; i <= index; ++i ) {
            insert(0);
            if (i==index){
                array[i]=value;
            }
        }
        used = index+1;
        capacity = index+1;

    } else {
        for(int i = used; i > index ; --i) {
            array[i] = array[i-1];
        }
        array[index] = value;
        used++;
    }
}

void sequence::insert(int new_entry) {
    if (used == capacity) {
        capacity++;
    }
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

int sequence::size() {
    return used;
}

int sequence::size2() {
    return capacity;
}

sequence operator + (sequence array1, sequence array2) {
    sequence array3(array1.size() + array2.size());
    array3 += array1;
    array3 += array2;
    return array3;
}

void sequence::operator+=(sequence array1) {
    for(int i = 0; i < array1.capacity; i++) {
        array[capacity++] = array1.seqArr(i);
    }
}

sequence sequence::operator=(sequence array1) {
    if(this == &array1) {
        return * this;
    }
    delete [] array;
    array = new int[array1.capacity];
    for(int i = 0; i < array1.used; ++i) {
        array[i] = array1.array[i];
    }
    used = array1.used;
    capacity = array1.capacity;
}

bool sequence::operator == (sequence array1) {
    if(array1.capacity != this->capacity) {
        cout << "This array has different capacity" << endl;
        return false;
    }
    if(array1.used != this->used) {
        cout << "This array has different number of values" << endl;
        return false;
    }
    for(int i = 0; i < used; ++i) {
        if(array1.array[i] != this->array[i]) {
            cout << "First array has value of " << array1.array[i] << " at " << i << ". While second array has "
                    "a value of " << this->array[i] << "." << endl;
            return false;
        }
    }
    cout << "Both arrays are equal" << endl;
    return true;
}

ostream& operator << (ostream& output, sequence& array1) {
    for(int i = 0; i < array1.size(); i++) {
        output << array1.seqArr(i);
        if(i != array1.size()-1)
            output << ", ";
    }
    return output;
}

istream& operator >> (istream& input, sequence& array1) {
    cout << "Enter the size of the sequence" << endl;
    int capacity;
    input >> capacity;
    array1 = sequence(capacity);
    cout << "Enter " << capacity << " element(s) to fill up the sequence" << endl;
    for(int i = 0; i < capacity; i++) {
        int element;
        input >> element;
        array1.insert(element);
    }
    return input;
}