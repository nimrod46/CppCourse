#include <iostream>
#include "Queue.h"

//
// Created by nimrod on 08-Jan-23.
//
int main() {
    int i = -1;
    int m = 110000;
    Queue<int> *queue = new Queue<int>(i, m);

    i = 1;
    queue->addByPriority(&i);
    int d = 2;
    queue->addByPriority(&d);
    int e = 3;
    queue->addByPriority(&e);

    std::cout << *queue->getFirst();
    return 0;
}