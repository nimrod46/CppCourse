#include <iostream>
#include "Queue.h"
#include "Vector.h"

//
// Created by nimrod on 08-Jan-23.
//
int main() {
    int i = -1;
    int m = 110000;
    Queue<int> *queue = new Queue<int>(i, m);
    int f = 0;
    queue->add(&f);

    int d = 2;
    queue->add(&d);
    i = 1;
    queue->add(&i);


    int e = 3;
    queue->add(&e);
    std::cout << *queue;

    queue->sort();

    std::cout << *queue;

    Vector<double>* vector = new Vector<double>(2);
    vector->add(1);
    vector->add(2);
    vector->add(14);
    vector->add(25);
    std::cout << *vector;
    return 0;
}