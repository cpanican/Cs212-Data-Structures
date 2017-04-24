//
// Created by Chris on 12/4/2016.
//

#ifndef ASSIGNMENT5_LINKEDLISTNODE_H
#define ASSIGNMENT5_LINKEDLISTNODE_H

#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
class LinkedListNode {

private:
    // node class
    template <class S>
    class node {
    public:
        S data;
        node* nextLink;
        node* prevLink;

        node(const S& nData = NULL, node* nLink = NULL, node* pLink = NULL) {
            data = nData;
            nextLink = nLink;
            prevLink = pLink;
        }

        T getData() {
            return data;
        }
    };

    node<T>* head_ptr;
    node<T>* tail_ptr;
    int size;


public:
    // Default constructor for node linked list.
    LinkedListNode() {
        head_ptr = NULL;
        tail_ptr = NULL;
        size = 0;
    }

    // Constructor for node linked list
    LinkedListNode(const LinkedListNode& newList) {
        head_ptr = newList.head_ptr;
        tail_ptr = newList.head_ptr;
        size = newList.size;
    }

    // insert_at function for hw 5. This function accepts an index and a data. There is a recursive function inside called insert.
    void insert_at(int index, T newData) {
        insert(0, index, head_ptr, newData);
        size++;
    }

    // remove_from function for hw 5. This function accepts an index. There is a recursive function inside called remove.
    void remove_from(int index) {
        remove(0, index, head_ptr);
        size--;
    }

    // Destructor for node linked list.
    ~LinkedListNode() {
        if (head_ptr != NULL)
            rec_destructor(head_ptr);
    }

private:
    // This is a recursive function for iterating, and inserting a data in correct index. Used from insert_at function.
    void insert(int nodeTrack, int index, node<T>* thisNode, T nData) {
        if(nodeTrack == index) {
            node<T>* temp = new node<T>(nData, thisNode, thisNode->prevLink);
            thisNode->prevLink->nextLink = temp;
            thisNode->prevLink = temp;
            return;
        }
        else {
            insert(nodeTrack+1, index, thisNode->nextLink, nData);
        }
    }

    // this is a recursive function used on remove_from function.
    void remove(int nodeTrack, int index, node<T>* thisNode) {
        if(nodeTrack == index) {
            thisNode->prevLink->nextLink = thisNode->nextLink;
            thisNode->nextLink->prevLink = thisNode->prevLink;
            return;
        }
        else {
            remove(nodeTrack+1, index, thisNode->nextLink);
        }
    }

    LinkedListNode&operator=(LinkedListNode& list) {
        return *this;
    }

    // Recursive destructor, used in ~LinkedListNode
    // E. Make destructor of B to work recursively. (4 pts)
    void rec_destructor(node<T>* node) {
        if(node == NULL)
            return;
        rec_destructor(node->nextLink);
        delete node;
    }






    /*****************************************
     *                                       *
     *   Code below came from Assignment 4   *
     *                                       *
     *****************************************/
public:
    // Check if head_ptr is null/empty. If head_ptr is null, return true.
    bool checkEmpty() {
        if (head_ptr == NULL && tail_ptr == NULL) {
            return 1;
        } else return 0;
    }

    // Pre-condition: Data type must be valid.
    // Post-condition: A new value is inserted at the head of the queue.
    void insertFirst(T newData) {
        size++;
        if(checkEmpty()) {
            node<T>* point = new node<T>(newData);
            head_ptr = point;
            tail_ptr = point;
        } else {
            node<T>* point = new node<T>(newData,head_ptr);
            head_ptr->prevLink = point; // head_ptr -> head = point;
            head_ptr = point; // Re-point head_ptr to new node
        }
    }

    // Pre-condition: Data type must be valid.
    // Post-condition: A new value is inserted at the tail of the queue.
    void insertLast(T newData) {
        size++;
        if(checkEmpty()) {
            node<T>* point = new node<T>(newData);
            head_ptr = point;
            tail_ptr = point;
        } else {
            node<T>* point = new node<T>(newData, NULL, tail_ptr);
            tail_ptr->nextLink = point; // head_ptr -> next = point;
            tail_ptr = point; // Re-point tail_ptr to new node
        }
    }

    // Pre-condition: There should be a value inside the queue.
    // Post-condition: The value at head is removed. Following node is new head (if node exists).
    void removeFirst() {
        if(checkEmpty()) {
            cout << "List is empty" << endl;
            return;
        } else {
            head_ptr = head_ptr->nextLink;
            head_ptr->prevLink = NULL;
        }
        size--;
    }

    // Pre-condition: There should be a value inside the queue.
    // Post-condition: The value at tail is removed. Previous node is new tail (if node exists).
    void removeLast() {
        if(checkEmpty()) {
            cout << "List is empty" << endl;
        } else {
            tail_ptr = tail_ptr->prevLink;
            tail_ptr->nextLink = NULL;
            size--;
        }
    }

    // Prints the whole queue. Starts at head and ends when cursor sees a NULL on next link.
    void printList() {
        if(checkEmpty()) {
            cout << "List is empty" << endl;
        } else {
            cout << "List: ";
            node<T>* cursor;
            for(cursor = head_ptr; cursor != NULL; cursor = cursor->nextLink) {
                cout << cursor->getData() << " ";
            }
            cout << endl;
        }
    }
};

#endif //ASSIGNMENT5_LINKEDLISTNODE_H
