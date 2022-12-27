//
// Created by nimrod on 16-Nov-22.
//

#include <iostream>
#include <sstream>
#include "DoubleVector.h"

DoubleVector::DoubleVector(int size) {
    this->size = size;
    capacity = size;
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = 0;
    }
}

DoubleVector::DoubleVector(DoubleVector& doubleVector) {
    this->size = doubleVector.size;
    capacity = doubleVector.size;
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = doubleVector.get(i);
    }
}

DoubleVector &DoubleVector::operator=(const DoubleVector &rhs) {
    if (this == &rhs) {
        return (*this);
    }

    delete values;

    this->size = rhs.size;
    capacity = rhs.capacity;
    values = new double[capacity];
    for (int i = 0; i < size; ++i) {
        values[i] = rhs.get(i);
    }
    return *this;
}

DoubleVector::~DoubleVector() {
    delete values;
}

DoubleVector &DoubleVector::add(double value) {
    if (size == capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        double *new_values = new double[capacity];
        for (int i = 0; i < size; ++i) {
            new_values[i] = values[i];
        }
        for (int i = size; i < capacity; ++i) {
            new_values[i] = 0;
        }
        values = new_values;
    }
    values[size++] = value;
    return *this;
}

DoubleVector &DoubleVector::set(int index, double value) {
    values[index] = value;
    return *this;
}

double DoubleVector::get(int index) const {
    return values[index];
}

double DoubleVector::remove(int index) {
    for (int i = index; i < size - 1; ++i) {
        values[i] = values[i + 1];
    }
    size--;
    return 0;
}

int DoubleVector::getSize() const {
    return size;
}

void DoubleVector::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}

std::string DoubleVector::toString() {
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < size; ++i) {
        ss << " " << get(i);
    }
    ss << "]";
    return ss.str();
}

