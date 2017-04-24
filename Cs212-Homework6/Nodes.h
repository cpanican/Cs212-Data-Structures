//
// Created by Chris on 12/23/2016
//

#ifndef ASSIGNMENT_6_NODES_H
#define ASSIGNMENT_6_NODES_H

#include <list>
#include <cstddef>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* Implementation of node class for Linked List */
class LinkNode {
public:
    int data;
    LinkNode* next;
    LinkNode* prev;

    //constructor. data value, pointer for next node, pointer for previous node
    LinkNode(const int& tempData = NULL, LinkNode* tempNlink = NULL, LinkNode* tempPlink = NULL) {
        data = tempData;
        next = tempNlink;
        prev = tempPlink;
    }
};

/* Implementation of node class for Trees*/
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    //constructor. data value, pointer for left node, pointer for right node
    TreeNode(const int& tempData = NULL, TreeNode* tempLlink = NULL, TreeNode* tempRlink = NULL) {
        data = tempData;
        left = tempLlink;
        right = tempRlink;
    }
};

class Nodes {
friend class HashTable;
public:
    TreeNode* root;
    //First element inserted as linkedlist
    Nodes(int firstData) {
        head = new LinkNode(firstData);
        size++;
    }
    void insert(int data);  //inserts element inside either list or tree
    void checkToConvert();  //checks if list should be converted to tree
    int getSize() { return size; }

private:
    int size = 0;
    LinkNode* head;

    void sortList();        //sorts the list to easily convert into BST
    int countNodesInList();
    TreeNode* listToBST();
    TreeNode* listToBSTrec(int n);  //recursion function that converts list to BST
    TreeNode* insertTree(TreeNode* node, int key);

};


#endif //ASSIGNMENT_6_NODES_H
