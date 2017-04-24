/*
 * Chris Panican
 * CSC 212 Homework 4
 * dequeue.h - this file contains the implementations of a double-ended queue.
 */

#ifndef HOMEWORK4_DEQUEUE_H
#define HOMEWORK4_DEQUEUE_H

#include "node.h"
template <class Y>
class dequeue {
public:
    // Constructor of an empty queue with NULL head and tail pointers.
    dequeue() {
        head_ptr = NULL;
        tail_ptr = NULL;
        size = 0;
    }

    // Destructor of a queue
    ~dequeue() {
        node<Y>* cursor = head_ptr;
        while(cursor != NULL) {
            node<Y>* nextNode = cursor->get_nextLink();
            delete cursor;
            cursor = nextNode;
        }
        delete cursor;
    }

    // Check if head_ptr is null/empty. If head_ptr is null, return true.
    bool checkEmpty() {
        if (head_ptr == NULL && tail_ptr == NULL) {
            return 1;
        } else return 0;
    }

    // Returns the size of queue by accessing int size.
    int getSize() {
        return size;
    }

    // Prints the whole queue. Starts at head and ends when cursor sees a NULL on next link.
    void printList() {
        if(checkEmpty()) {
            cout << "List is empty" << endl;
        } else {
            cout << "List: ";
            node<Y>* cursor;
            for(cursor = head_ptr; cursor != NULL; cursor = cursor->get_nextLink()) {
                cout << cursor->getData() << " ";
            }
            cout << endl;
        }
    }

    // Pre-condition: Data type must be valid.
    // Post-condition: A new value is inserted at the head of the queue.
    void insertFirst(Y newData) {
        size++;
        if(checkEmpty()) {
            node<Y>* point = new node<Y>(newData);
            head_ptr = point;
            tail_ptr = point;
        } else {
            node<Y>* point = new node<Y>(newData,head_ptr);
            head_ptr->set_prevLink(point); // head_ptr -> head = point;
            head_ptr = point; // Re-point head_ptr to new node
        }
    }

    // Pre-condition: There should be a value inside the queue.
    // Post-condition: The value at head is removed. Following node is new head (if node exists).
    void removeFirst() {
        if(checkEmpty()) {
            cout << "List is empty" << endl;
            return;
        } else {
            head_ptr = head_ptr->get_nextLink();
            head_ptr->set_prevLink(NULL);
        }
        size--;
    }

    // Pre-condition: Data type must be valid.
    // Post-condition: A new value is inserted at the tail of the queue.
    void insertLast(Y newData) {
        size++;
        if(checkEmpty()) {
            node<Y>* point = new node<Y>(newData);
            head_ptr = point;
            tail_ptr = point;
        } else {
            node<Y>* point = new node<Y>(newData, NULL, tail_ptr);
            tail_ptr->set_nextLink(point); // head_ptr -> next = point;
            tail_ptr = point; // Re-point tail_ptr to new node
        }
    }

    // Pre-condition: There should be a value inside the queue.
    // Post-condition: The value at tail is removed. Previous node is new tail (if node exists).
    void removeLast() {
        if(checkEmpty()) {
            cout << "List is empty" << endl;
        } else {
            tail_ptr = tail_ptr->get_prevLink();
            tail_ptr->set_nextLink(NULL);
            size--;
        }
    }

private:
    node<Y> * head_ptr;
    node<Y> * tail_ptr;
    int size;
};

#endif //HOMEWORK4_DEQUEUE_H
