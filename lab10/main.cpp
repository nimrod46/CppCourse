#include <iostream>
#include "LinkedList.h"

//
// Created by nimrod on 10-Jan-23.
//
int main() {
    LinkedList<int> *linkedList = new LinkedList<int>();
    int i = 5;
    linkedList->insert(&i);
    int i1 = 10;
    linkedList->insert(&i1);

    std::cout << *linkedList;

    int i2 = 11;
    *(*linkedList)[1] = i2;
    std::cout << *linkedList;
}