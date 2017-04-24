//
// Created by Chris on 12/17/2016.
//

/*  Design a heap data structure and call it priority queue.
 *  Create a class, call it process. Each process has a priority and processing time that will be initialized using the constructor.
 *  Inside your queue, you can store multiple processes, however the process with the highest priority comes out first. When a process is removed from the queue, the priority of the other processes will increase by the processing time of the removed process.
 *  You should be able to add a new process to the queue. Remove the highest priority process from a queue and get the number of processes in the queue.
 *  Optional: Implement a function that receives a process as argument and the priority change (increase or decrease) of that process and change the priority of that process. What would be the running time of this function.
 */

#ifndef ASSIGNMENT7_PRIORITY_QUEUE_H
#define ASSIGNMENT7_PRIORITY_QUEUE_H

#include <iostream>
using namespace std;

const int MAX=100;

class data
{
    int val,p;  /* val stores the value and p stores the respective priority*/
}d[MAX];

int heapsize=0,length=0;
data temp;

int parent(int i) {
    return (i/2);
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return (2*i+1);
}

void minheapify(data a[],int i)  /* min heapify(min value at first) using the key of the data */
{
    int l=left(i);
    int smallest;
    int r=right(i);
    if (l<=heapsize && a[l].p<a[i].p)
        smallest=l;
    else smallest=i;
    if (r<=heapsize && a[r].p<a[smallest].p)
        smallest=r;
    if (!(smallest==i))
    {
        temp=a[i];
        a[i]=a[smallest];
        a[smallest]=temp;
        minheapify(a,smallest);
    }
}

int heap_min(data a[]) {
    return a[1].p;
}

void buildminheap(data a[],int length) {
    heapsize=length;
    for(int l=(length/2);l>1;l--)
        minheapify(a,l);
}

void heapincp(data a[],int i,int ps) {
    if (ps>a[i].p)
        cout<<"ERROR";
    a[i].p=ps;
    while((i>1) && (a[parent(i)].p>a[i].p))
    {
        temp=a[i];
        a[i]=a[parent(i)];
        a[parent(i)]=temp;
        i=parent(i);
    }
}



int heap_extract_min(data a[]) {
    if (heapsize<1)
        cout<<"ERROR UNDERFLOW";
    int minimum = a[1].val;
    a[1]= a[heapsize];
    heapsize--;
    minheapify(a,1);
    return minimum;
}

void min_heap_insert(data a[],int p)
{
    heapsize+=1;
    a[heapsize].p = 100000000;
    heapincp(a,heapsize,p);
}


#endif //ASSIGNMENT7_PRIORITY_QUEUE_H