/*
 * Chris Panican
 * CSC 212 Homework 4
 * node.h - this file contains the implementations of a node with double sided links.
 */

#ifndef HOMEWORK4_NODE_H
#define HOMEWORK4_NODE_H

// NULL definition
#include <stddef.h>
#include <iostream>
using namespace std;

template <class T>
class node {
public:
    // Node constructor. Includes data of this node, and pointers to previous and following nodes.
    node(const T& newData = NULL, node* nextLink = NULL, node* prevLink = NULL) {
        data = newData;
        next = nextLink;
        prev = prevLink;
    }

    // Returns the data of current node.
    T getData() {
        return data;
    }

    // Points current node to next node.
    void set_nextLink(node * newLink) {
        next = newLink;
    }

    // Points current node to next node.
    void set_prevLink(node * newLink) {
        prev = newLink;
    }

    // Gets the pointer of next node to current node and returns it.
    node * get_nextLink() {
        return next;
    }

    // Gets the pointer of previous node to current node and returns it.
    node * get_prevLink() {
        return prev;
    }

private:
    T data;
    node* next;
    node* prev;
};

#endif //HOMEWORK4_NODE_H