//
// Created by nimrod on 16-Nov-22.
//

#ifndef CPPCOURSE_OBSERVATION_H
#define CPPCOURSE_OBSERVATION_H


#include <string>
#include "DoubleVector.h"

class Observation {

private:
    std::string name;
    DoubleVector* data;
public:
    Observation();
    Observation(std::string& name, DoubleVector& data);
    Observation(std::string& name, int dataSize);
    std::string getName();
    double getDataAt(int index);
    void setDataAt(int index, double value);

    Observation(Observation *pObservation);
};


#endif //CPPCOURSE_OBSERVATION_H
