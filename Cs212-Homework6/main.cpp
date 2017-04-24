//Ishan Soni

#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    //Creates a HashTable of initial size 5
    HashTable table(5);
    table.insert(1);
    table.insert(2);
    table.insert(3);
    table.insert(4);
    table.insert(5);
    table.insert(6);
    table.insert(7);
    //Prints the table after insertion of items
    table.printTable();

    //Searches for a value and prints its location
    cout << "\n";
    table.search(2);
    cout << "\n";
    cout << "\n";

    //HashTable size is increased because the number of values exceeded n*log(n) amount
    table.insert(12);
    table.insert(15);
    table.insert(11);
    table.insert(21);
    table.insert(31);
    table.insert(41);
    table.insert(51);
    table.insert(61);
    table.insert(71);
    table.insert(81);
    table.insert(91);
    table.insert(101);
    table.insert(111);
    table.insert(5);
    table.insert(8);
    table.printTable();

    cout << "\n";
    table.search(61);
    cout << "\n";

    return 0;
}