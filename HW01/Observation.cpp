//


#include "Observation.h"
#include <cstring>

Observation::Observation() {

}

Observation::Observation(Observation *observation) {
    this->name = observation->name;
    this->data = observation->data;
}

Observation::Observation(std::string &name, DoubleVector &data) {
    this->name = name;
    this->data = &data;
}

Observation::Observation(std::string &name, int dataSize) {
    this->name = name;
    this->data = new DoubleVector(dataSize);
}

std::string Observation::getName() {
    return name;
}

double Observation::getDataAt(int index) {
    return data->get(index);
}

void Observation::setDataAt(int index, double value) {
    data->set(index, value);
}

