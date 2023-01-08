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
    queue->add(&i);
    int d = 2;
    queue->add(&d);
    int e = 3;
    queue->add(&e);

    std::cout << *queue->getFirst();
    return 0;
}