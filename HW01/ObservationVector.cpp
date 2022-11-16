//
// Created by nimrod on 16-Nov-22.
//


#include <iostream>
#include <sstream>
#include "ObservationVector.h"

ObservationVector::ObservationVector(int size) {
    this->size = size;
    capacity = size;
    observations = new Observation[size];
//    for (int i = 0; i < size; ++i) {
//        observations[i] = 0;
//    }
}

void ObservationVector::destroy() {
    delete observations;
}

ObservationVector &ObservationVector::add(Observation& value) {
    if (size == capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        Observation *new_values = new Observation[capacity];
        for (int i = 0; i < size; ++i) {
            new_values[i] = observations[i];
        }
//        for (int i = size; i < capacity; ++i) {
//            new_values[i] = 0;
//        }
        delete[] observations;
        observations = new_values;
    }
    observations[size++] = &value;
    return *this;
}

ObservationVector &ObservationVector::set(int index, Observation &observation) {
    observations[index] = &observation;
    return *this;
}

Observation ObservationVector::get(int index) const {
    return observations[index];
}

Observation ObservationVector::remove(int index) {
    for (int i = index; i < size - 1; ++i) {
        observations[i] = &observations[i + 1];
    }
    size--;
    return 0;
}

int ObservationVector::getSize() const {
    return size;
}

void ObservationVector::print() {
//    for (int i = 0; i < size; ++i) {
//        std::cout << get(i) << " ";
//    }
//    std::cout << std::endl;
}

std::string ObservationVector::toString() {
    std::stringstream ss;
//    ss << "[";
//    for (int i = 0; i < size; ++i) {
//        ss << " " << get(i);
//    }
//    ss << "]";
    return ss.str();
}
