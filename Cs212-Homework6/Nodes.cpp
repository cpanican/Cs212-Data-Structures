//
// Created by Chris on 12/23/2016
//

#include "Nodes.h"

// Insert tree if the list is above 10
void Nodes::insert(int data) {
    if(size > 10) {
        root = insertTree(root, data);
    } else {
        head->prev = new LinkNode(data, head);
        head = head->prev;
    }
    size++;
    if(size == 11) {
        checkToConvert();
    }
}

// Convert List to Tree
void Nodes::checkToConvert() {
    if(size > 10) {
        sortList();
        root = listToBST();
    }
}

// Sort the List
void Nodes::sortList() {
    vector<int> list;
    for(LinkNode* i = head; i != NULL; i = i->next)
        list.push_back(i->data);
    sort(list.begin(), list.end());

    head = new LinkNode(list.at(0));
    LinkNode* prev = head;
    for(int i = 1; i < list.size(); i++) {
        LinkNode* curr = new LinkNode(list.at(i), NULL, prev);
        prev->next = curr;
        prev = curr;
    }
}

// Counts the nodes in List
int Nodes::countNodesInList() {
    int count = 0;
    LinkNode* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Converts the list to Binary Search Tree
TreeNode* Nodes::listToBST() {
    /*Count the number of nodes in Linked List */
    int n = countNodesInList();

    /* Construct BST */
    return listToBSTrec(n);
}

/* The main function that constructs balanced BST and
   returns root of it.
   n is No. of nodes in the Doubly Linked List */
TreeNode* Nodes::listToBSTrec(int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;

    /* Recursively construct the left subtree */
    TreeNode* left = listToBSTrec(n / 2);

    /* head now refers to middle node,
       make middle node as root of BST*/
    TreeNode* root = new TreeNode(head->data);

    // Set pointer to left subtree
    root->left = left;

    /* Change head pointer of Linked List for parent
       recursive calls */
    head = head->next;

    /* Recursively construct the right subtree and link it
       with root. The number of nodes in right subtree  is
       total nodes - nodes in left subtree - 1 (for root) */
    root->right = listToBSTrec(n - n / 2 - 1);

    return root;
}

// Insert tree to node
TreeNode* Nodes::insertTree(TreeNode* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return new TreeNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insertTree(node->left, key);
    else if (key > node->data)
        node->right = insertTree(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}