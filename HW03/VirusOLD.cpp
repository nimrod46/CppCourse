//
// Created by nimrod on 20/12/2022.
//

#include "VirusOLD.h"
#include "DoubleVector.h"
#include <iostream>

VirusOLD::VirusOLD(std::string &name, DoubleVector &valuesVector, DoubleVector *targetVector, int *lastGenVirusIndex, int pM)
        : name(name) {
    this->valuesVector = new DoubleVector(valuesVector);
    this->targetVector = targetVector;
    this->lastGenVirusIndex = lastGenVirusIndex;
    this->pM = pM;
    this->defaultScore = -1;
    genIndex = 0;
}


VirusOLD::VirusOLD(int defaultScore) {
    name = "";
    this->valuesVector = nullptr;
    this->targetVector = nullptr;
    lastGenVirusIndex = nullptr;
    this->pM = 0;
    this->defaultScore = defaultScore;
    genIndex = 0;
    lastGenVirusIndex = nullptr;
}

VirusOLD::VirusOLD(VirusOLD &virus) : name(virus.name) {
    this->name = virus.name;
    this->valuesVector = new DoubleVector(*virus.valuesVector);
    this->targetVector = virus.targetVector;
    this->defaultScore = -1;
    this->pM = virus.pM;
    genIndex = ++(*virus.lastGenVirusIndex);
    lastGenVirusIndex = virus.lastGenVirusIndex;
}

VirusOLD &VirusOLD::operator=(const VirusOLD &virus) {
    if (this == &virus) {
        return (*this);
    }

    delete valuesVector;

    this->name = virus.name;
    this->valuesVector = new DoubleVector(*virus.valuesVector);
    this->targetVector = virus.targetVector;
    this->defaultScore = -1;
    this->pM = virus.pM;
    genIndex = virus.genIndex;
    lastGenVirusIndex = virus.lastGenVirusIndex;
    return *this;
}

VirusOLD::VirusOLD(VirusOLD &&virus) noexcept {
    this->name = nullptr;
    this->valuesVector = nullptr;
    this->targetVector = nullptr;
    this->lastGenVirusIndex = nullptr;
    this->defaultScore = -1;
    this->pM = 0;
    genIndex = 0;
    *this = std::move(virus);
}

VirusOLD &VirusOLD::operator=(VirusOLD &&virus) noexcept {
    this->name = virus.name;
    this->valuesVector = virus.valuesVector;
    this->targetVector = virus.targetVector;
    this->lastGenVirusIndex = virus.lastGenVirusIndex;
    this->genIndex = virus.genIndex;
    this->pM = virus.pM;
    this->defaultScore = virus.genIndex;

    virus.name = nullptr;
    virus.valuesVector = nullptr;
    virus.targetVector = nullptr;
    virus.lastGenVirusIndex = nullptr;
    return *this;
}

double VirusOLD::getErrorFromTarget() const {
    if (defaultScore != -1) {
        return defaultScore;
    }
    double score = 0;
    for (int i = 0; i < valuesVector->getSize(); ++i) {
        score += valuesVector->get(i) == targetVector->get(i);
    }
    return 1 - score / valuesVector->getSize();
}


bool VirusOLD::operator==(const VirusOLD &virus) const {
    return this->name == virus.name && genIndex == virus.genIndex;
}

std::ostream &operator<<(std::ostream &stream, VirusOLD &virus) {
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

void VirusOLD::operator*() const {
    for (int k = 0; k < pM; ++k) {
        int i = ((double) rand() * (valuesVector->getSize())) / RAND_MAX;
        int j = ((double) rand() * (valuesVector->getSize())) / RAND_MAX;
        int tmp = valuesVector->get(i);
        valuesVector->set(i, valuesVector->get(j));
        valuesVector->set(j, tmp);
    }
}

bool VirusOLD::operator<(const VirusOLD &virus) const {
    if (getErrorFromTarget() == virus.getErrorFromTarget()) {
        return genIndex < virus.genIndex;
    }

    return getErrorFromTarget() < virus.getErrorFromTarget();
}

VirusOLD::~VirusOLD() {
    delete valuesVector;
}
