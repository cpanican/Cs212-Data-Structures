/*
 * Implement a double-ended list (deque pronounced deck) data structure using the linked list data structure.  You may insert at or remove the head or tail of the list.
 * Create a template file for that.
 * Find a strategy to speed up delete and insert (Think about vector).
 *
 * Chris Panican
 * CSC 212 Homework 4
 * main.cpp - contains test files
 */

#include <iostream>
#include "dequeue.h"
int main() {
    dequeue<int> list = dequeue<int>();

    cout << "Insert integer values 1, 2, and 3 in the front of the queue." << endl;
    list.insertFirst(1);
    list.insertFirst(2);
    list.insertFirst(3);
    list.printList();
    cout << "Size: " << list.getSize() << endl << endl;

    cout << "Insert integer values 4, 5, and 6 in the tail of the queue." << endl;
    list.insertLast(4);
    list.insertLast(5);
    list.insertLast(6);
    list.printList();
    cout << "Size: " << list.getSize() << endl << endl;

    cout << "Remove first and last values from the queue" << endl;
    list.removeFirst();
    list.removeLast();
    list.printList();
    cout << "Size: " << list.getSize() << endl << endl;

    list.~dequeue();
}