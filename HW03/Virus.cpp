//
// Created by nimrod on 20/12/2022.
//

#include "Virus.h"
#include "DoubleVector.h"
#include <iostream>

Virus::Virus(std::string &name, DoubleVector &valuesVector, DoubleVector *targetVector, int pM) : name(name) {
    this->valuesVector = new DoubleVector(valuesVector);
    this->targetVector = targetVector;
    this->pM = pM;
    this->defaultScore = -1;
    genIndex = 0;
    lastGenVirusIndex = new int(0);
}


Virus::Virus(int defaultScore) {
    name = "";
    this->valuesVector = nullptr;
    this->targetVector = nullptr;
    this->pM = 0;
    this->defaultScore = defaultScore;
    genIndex = 0;
    lastGenVirusIndex = new int(0);
}

Virus::Virus(Virus &virus) : name(virus.name) {
    this->name = virus.name;
    this->valuesVector = new DoubleVector(*virus.valuesVector);
    this->targetVector = virus.targetVector;
    this->defaultScore = -1;
    this->pM = virus.pM;
    genIndex = ++(*virus.lastGenVirusIndex);
    lastGenVirusIndex = virus.lastGenVirusIndex;
}

Virus &Virus::operator=(const Virus &virus) {
    if (this == &virus) {
        return (*this);
    }

    this->name = virus.name;
    this->valuesVector = new DoubleVector(*virus.valuesVector);
    this->targetVector = virus.targetVector;
    this->defaultScore = -1;
    this->pM = virus.pM;
    genIndex = virus.genIndex;
    lastGenVirusIndex = virus.lastGenVirusIndex;
    return *this;
}

double Virus::getErrorFromTarget() const {
    if (defaultScore != -1) {
        return defaultScore;
    }
    double score = 0;
    for (int i = 0; i < valuesVector->getSize(); ++i) {
        score += valuesVector->get(i) == targetVector->get(i);
    }
    return 1 - score / valuesVector->getSize();
}

bool Virus::operator==(const Virus &virus) const {
    return this->name == virus.name && genIndex == virus.genIndex;
}


std::ostream &operator<<(std::ostream &stream, Virus &virus) {
    stream << virus.name;
    if (virus.genIndex != 0) {
        stream << "_" << virus.genIndex;
    }
    stream << "\t";

    for (int i = 0; i < virus.valuesVector->getSize(); ++i) {
        stream << virus.valuesVector->get(i) << " ";
    }
    stream << std::endl;
    return stream;
}

void Virus::operator*() const {
    for (int k = 0; k < pM; ++k) {
        int i = ((double) rand() * (valuesVector->getSize())) / RAND_MAX;
        int j = ((double) rand() * (valuesVector->getSize())) / RAND_MAX;
        int tmp = valuesVector->get(i);
        valuesVector->set(i, valuesVector->get(j));
        valuesVector->set(j, tmp);
    }
}

bool Virus::operator<(const Virus &virus) const {
    if (getErrorFromTarget() == virus.getErrorFromTarget()) {
        return genIndex < virus.genIndex;
    }

    return getErrorFromTarget() < virus.getErrorFromTarget();
}
