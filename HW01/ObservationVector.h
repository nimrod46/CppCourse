//
// Created by nimrod on 16-Nov-22.
//

#ifndef CPPCOURSE_OBSERVATIONVECTOR_H
#define CPPCOURSE_OBSERVATIONVECTOR_H

#include "Observation.h"

class ObservationVector {
private:
    int size;
    int capacity;
    Observation *observations;
public:
    explicit ObservationVector(int capacity);

    void destroy();

    ObservationVector &add(Observation &value);

    ObservationVector &set(int index, Observation &observation);

    Observation get(int index) const;

    Observation remove(int index);

    int getSize() const;

    void print();

    std::string toString();

};

#endif //CPPCOURSE_OBSERVATIONVECTOR_H
