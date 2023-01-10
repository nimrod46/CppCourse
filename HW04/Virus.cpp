//
// Created by nimrod on 20/12/2022.
//

#include "Virus.h"
#include "Vector.h"
#include <iostream>
#include <utility>

Virus::Virus(std::string type, std::string &name, Vector<int> &valuesVector, Vector<int> *targetVector,
             int *lastGenVirusIndex, int pM)
        : type(std::move(type)), name(name) {

    this->valuesVector = new Vector<int>(valuesVector);
    this->targetVector = targetVector;
    this->lastGenVirusIndex = lastGenVirusIndex;
    this->pM = pM;
    this->defaultScore = -1;
    genIndex = 0;
}


Virus::Virus(int defaultScore) {
    name = "";
    type = "";
    this->valuesVector = nullptr;
    this->targetVector = nullptr;
    lastGenVirusIndex = nullptr;
    this->pM = 0;
    this->defaultScore = defaultScore;
    genIndex = 0;
    lastGenVirusIndex = nullptr;
}

Virus::Virus(Virus &virus) : name(virus.name) {
    this->type = virus.type;
    this->name = virus.name;
    if (virus.valuesVector != nullptr) {
        this->valuesVector = new Vector<int>(*virus.valuesVector);
    } else {
        this->valuesVector = nullptr;
    }
    this->targetVector = virus.targetVector;
    this->defaultScore = virus.defaultScore;
    this->pM = virus.pM;
    genIndex = virus.genIndex;
    lastGenVirusIndex = virus.lastGenVirusIndex;
}

Virus &Virus::operator=(const Virus &virus) {
    if (this == &virus) {
        return (*this);
    }

    delete valuesVector;

    this->type = virus.type;
    this->name = virus.name;
    this->valuesVector = new Vector<int>(*virus.valuesVector);
    this->targetVector = virus.targetVector;
    this->defaultScore = -1;
    this->pM = virus.pM;
    genIndex = virus.genIndex;
    lastGenVirusIndex = virus.lastGenVirusIndex;
    return *this;
}

Virus::Virus(Virus &&virus) noexcept {
    this->type = nullptr;
    this->name = nullptr;
    this->valuesVector = nullptr;
    this->targetVector = nullptr;
    this->lastGenVirusIndex = nullptr;
    this->defaultScore = -1;
    this->pM = 0;
    genIndex = 0;
    *this = std::move(virus);
}

Virus &Virus::operator=(Virus &&virus) noexcept {
    this->type = virus.type;
    this->name = virus.name;
    this->valuesVector = virus.valuesVector;
    this->targetVector = virus.targetVector;
    this->lastGenVirusIndex = virus.lastGenVirusIndex;
    this->genIndex = virus.genIndex;
    this->pM = virus.pM;
    this->defaultScore = virus.genIndex;

    virus.type = nullptr;
    virus.name = nullptr;
    virus.valuesVector = nullptr;
    virus.targetVector = nullptr;
    virus.lastGenVirusIndex = nullptr;
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
    stream << virus.type << " ";
    stream << virus.name;
    if (virus.genIndex != 0) {
        stream << "_" << virus.genIndex;
    }
    stream << " ";

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

Virus::~Virus() {
    delete valuesVector;
}

void Virus::pogressGen(Virus &virus) {
    genIndex = ++(*virus.lastGenVirusIndex);
    lastGenVirusIndex = virus.lastGenVirusIndex;
}
