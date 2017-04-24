/*  Design a heap data structure and call it priority queue.
 *  Create a class, call it process. Each process has a priority and processing time that will be initialized using the constructor.
 *  Inside your queue, you can store multiple processes, however the process with the highest priority comes out first. When a process is removed from the queue, the priority of the other processes will increase by the processing time of the removed process.
 *  You should be able to add a new process to the queue. Remove the highest priority process from a queue and get the number of processes in the queue.
 *  Optional: Implement a function that receives a process as argument and the priority change (increase or decrease) of that process and change the priority of that process. What would be the running time of this function.
 */

#include "priority_queue.h"

int main() {
    char op;
    do
    {
        int ch;

        cout<<"----------Menu-------------\n\n";
        cout<<"\t1.Insertion\n\t2.Extract";
        cout<<"\n\n\tEnter your Choice<1,2> ?";
        cin>>ch;
        switch(ch)
        {
            case 1 :  length++;
                cout<<"Enter Value ?";
                cin>>d[length].val;
                cout<<"Enter Priority (KEY) ?";
                cin>>d[length].p;

                min_heap_insert(d,d[length].p);
                break;

            case 2 :  cout<<"\nPRIORITY QUEUE\n";
                cout<< heap_extract_min(d)<<"\t";
                length--;
                break;
        }
        cout<<"\n\nDo You Want to Continue <Y/N> ?";
        cin>>op;
    } while(op=='Y' || op=='y');

    return 0;
}
