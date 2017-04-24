//
// Created by Chris on 12/23/2016
//

#ifndef ASSIGNMENT_6_HASHTABLE_H
#define ASSIGNMENT_6_HASHTABLE_H

#include "Nodes.h"

class HashTable {
public:
   // Hashtable initial constructor
    HashTable(int n) {
        table = vector<Nodes*>(n);
        size = n;
        valueCount = 0;
    }
    int getSize() { return size; }
    void insert(int data);  //function used for inserting items into the table
    void search(int data);  //function used for seach for a value in the table
    void printTable();      //prints the hashtable

private:
    vector<Nodes*> table;
    int size;
    int valueCount;   //keeps count of number of values
    int HashKey(int data) {   //Calculates the index of the item using, data % size
        return data % size;
    }
    void checkForResize();    //Checks if table needs resizing
    void traverseTree(TreeNode* node, vector<Nodes*>& newTable); //Traverses through tree in order to remap
    void traverseList(LinkNode* node, vector<Nodes*>& newTable); //Traverses through linkedlist in order to remap
    void printTree(TreeNode* node);
    void printList(LinkNode* node);
    int searchT(TreeNode* node, int data, int index);  //Searches inside tree
    int searchL(LinkNode* node, int data, int index);  //Searches inside list
};


#endif //ASSIGNMENT_6_HASHTABLE_H
