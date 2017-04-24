/*
 * A. Make the insert_at and remove_from functions of the linked list to work recursively. (4 pts)
 * B. Design a linked list data structure using node as the internal structure. You are encapsulating the data structure and the user no longer have access to the node datatype. (3 pts)
 * C. Design a linked list data structure using only the stack data structure as the internal data structure (You do not allowed to use array, node or any other object data types). (6 pts)
 * Make the value semantics correct.
 * D. Make the value semantic of your both data structures safe and write the destructor for them. (6 pts)
 * E. Make destructor of B to work recursively. (4 pts)
 */

#include <iostream>
#include "LinkedListNode.h"
#include "LinkedListStack.h"

using namespace std;

int main() {

    // LinkedList with node Test
    LinkedListNode<int> list1 = LinkedListNode<int>();

    cout << "*** Linked list node test ***" << endl;
    cout << "Original list:" << endl;
    list1.insertFirst(1);
    list1.insertFirst(2);
    list1.insertFirst(3);
    list1.insertFirst(4);
    list1.insertFirst(5);
    list1.printList();
    cout << endl;

    cout << "Insert 2 at index 3:" << endl;
    list1.insert_at(3,2);
    list1.printList();
    cout << endl;

    cout << "Insert 1 at index 1:" << endl;
    list1.insert_at(1,1);
    list1.printList();
    cout << endl;

    cout << "Remove 1st index:" << endl;
    list1.remove_from(1);
    list1.printList();
    cout << endl;

    cout << "Remove 3rd index:" << endl;
    list1.remove_from(3);
    list1.printList();
    cout << endl << endl;

    // LinkedList with stack Test
    LinkedListStack<int> list2 = LinkedListStack<int>();
    cout << "*** Linked List Stack test ***" << endl;

    list2.insert_at(0,5);
    list2.insert_at(0,4);
    list2.insert_at(0,3);
    list2.insert_at(0,2);
    list2.insert_at(0,1);
    cout << "Original list:" << endl;
    cout << "List: ";
    int n = list2.getSize();
    list2.printStack(n,list2);
    cout << endl << endl;

    cout << "Remove 2nd index" << endl;
    list2.remove_from(2);
    cout << "List: ";
    n = list2.getSize();
    list2.printStack(n,list2);
    cout << endl;

    cout << "Insert 2 at 2nd index" << endl;
    list2.insert_at(2,3);
    cout << "List: ";
    n = list2.getSize();
    list2.printStack(n,list2);
    cout << endl;

    return 0;
}
