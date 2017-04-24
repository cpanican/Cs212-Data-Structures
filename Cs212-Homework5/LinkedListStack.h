//
// Created by Chris on 12/4/2016.
//

#ifndef ASSIGNMENT5_LINKEDLISTSTACK_H
#define ASSIGNMENT5_LINKEDLISTSTACK_H

#include <stack>
using namespace std;

template <class T>
class LinkedListStack {

private:
    stack<T> list;
    unsigned long size = list.size();

    // similar function from LinkedListNode.h. This recursive fuction is used in insert_at
    void insert(int stackTrack, int index, stack<T>& newStack, T nData) {
        if(stackTrack == index) {
            list.push(nData);
            unsigned long tempSize = newStack.size();
            for(int i = 0; i < tempSize; i++) {
                list.push(newStack.top());
                newStack.pop();
            }
            return;
        }
        else {
            newStack.push(list.top());
            list.pop();
            insert(stackTrack+1, index, newStack, nData);
        }
    }

    // similar function from LinkedListNode.h. This recursive fuction is used in remove_from
    void remove(int stackTrack, int index, stack<T>& newStack) {
        if(stackTrack == index) {
            list.pop();
            unsigned long tempSize = newStack.size();
            for(int i = 0; i < tempSize; i++) {
                list.push(newStack.top());
                newStack.pop();
            }
        }
        else {
            newStack.push(list.top());
            list.pop();
            remove(stackTrack+1, index, newStack);
        }
    }

public:
    // default constructor
    LinkedListStack() {
        list = stack<T>();
        size = 0;
    }

    // copy constructor
    LinkedListStack(const LinkedListStack& newList) {
        list = newList.list;
        size = newList.size;
    }

    // calls a recursive function from private: index. Elements are inserted in a temp stack, then when index is
    // reached, the values from temp stack goes to the main stack.
    void insert_at(int index, T element) {
        stack<T> temp;
        insert(0, index, temp, element);
        size = list.size();
    }

    // calls at recursive function in private: remove. Removes element in stack until index is reached.
    void remove_from(int index) {
        stack<T> temp;
        remove(0, index, temp);
        size = list.size();
    }

    // overload = operator
    LinkedListStack&operator=(LinkedListStack& list) {
        return *this;
    }

    int getSize() {
        return size;
    }

    // gets data from the head
    T getHead() {
        return list.top();
    }

    // prints the stack
    void printStack(int n, LinkedListStack<int> list) {
        for(int i = 0; i < n; i++) {
            cout << list.getHead();
            if(i != n-1)
                cout << " ";
            list.remove_from(0);
        }
    }

};


#endif //ASSIGNMENT5_LINKEDLISTSTACK_H
