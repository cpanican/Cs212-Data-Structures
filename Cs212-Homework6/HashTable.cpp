//
// Created by Chris on 12/23/2016
//

#include "HashTable.h"

// Calculate the index of data
void HashTable::insert(int data) {
    if(table.at(HashKey(data)) == NULL)
        table.at(HashKey(data)) = new Nodes(data);
    else
        table.at(HashKey(data))->insert(data);
    valueCount++;
    checkForResize();  //checks if the table needs resizing after the insert
}

// Show the index of an inputed data
void HashTable::search(int data) {
    int index = HashKey(data);
    cout << data << " is at index " << index << " in HashTable";
    if(table.at(index)->size > 10)
        cout << ", inside a BST at node index " << searchT(table.at(index)->root, data, 0);
    else
        cout << ", inside a LinkedList at node index " << searchL(table.at(index)->head, data, 0);
}

//if value count is greater than or equal to n*log(n) then table size is doubled
void HashTable::checkForResize() {
    if(valueCount >= size*log2(size)) {
        int oldSize = size;
        size = size*2;
        vector<Nodes*> newTable(size);
        for(int i = 0; i < oldSize; i++) {
            if(table.at(i) == NULL)
                continue;
            else if(table.at(i)->getSize() > 10)
                traverseTree(table.at(i)->root, newTable);
            else {
                traverseList(table.at(i)->head, newTable);
            }
        }
        table = newTable;
    }
}

// Traverse the tree 
void HashTable::traverseTree(TreeNode* node, vector<Nodes*> &newTable) {
    if(node != NULL) {
        if (newTable.at(HashKey(node->data)) == NULL)
            newTable.at(HashKey(node->data)) = new Nodes(node->data);
        else
            newTable.at(HashKey(node->data))->insert(node->data);
        traverseTree(node->left, newTable);
        traverseTree(node->right, newTable);
    }
}

// Traverse the list
void HashTable::traverseList(LinkNode* node, vector<Nodes*> &newTable) {
    for(LinkNode* i = node; i != NULL; i = i->next) {
        if (newTable.at(HashKey(i->data)) == 0)
            newTable.at(HashKey(i->data)) = new Nodes(i->data);
        else
            newTable.at(HashKey(i->data))->insert(i->data);
    }
}

// Print the table
void HashTable::printTable() {
    for(int i = 0; i < size; i++) {
        cout << i << ": ";
        if(table.at(i) == NULL) {
            cout << "\n";
            continue;
        }
        else if(table.at(i)->getSize() > 10) {
            printTree(table.at(i)->root);
            cout << " (In-ordered Binary Search Tree)";
        }
        else {
            printList(table.at(i)->head);
            cout << " (LinkedList)";
        }
        cout << "\n";
    }
}

// Print the tree
void HashTable::printTree(TreeNode* node) {
    if(node != NULL) {
        cout << node->data << "->";
        printTree(node->left);
        printTree(node->right);
    }
}

// Print the list
void HashTable::printList(LinkNode* node) {
    for(LinkNode* i = node; i != NULL; i = i->next)
        cout << i->data << "->";
}

int HashTable::searchT(TreeNode* node, int data, int index) {
    // Base Cases: root is null or key is present at root
    if (node == NULL || node->data == data)
        return index;

    // Key is greater than root's key
    if (node->data < data)
        return searchT(node->right, data, 2*index+2);

    // Key is smaller than root's key
    return searchT(node->left, data, 2*index+1);
}

int HashTable::searchL(LinkNode* node, int data, int index) {
    if(node == NULL || node->data == data)
        return index;
    return searchL(node->next, data, index+1);
}