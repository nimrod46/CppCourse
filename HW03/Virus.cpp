//
// Created by nimrod on 20/12/2022.
//

#include "Virus.h"
#include "DoubleVector.h"
#include <iostream>
#include <string.h>

Virus::Virus(std::string &name, DoubleVector &valuesVector, DoubleVector *targetVector, int pM) : name(name) {
    this->valuesVector = new DoubleVector(valuesVector);
    this->targetVector = targetVector;
    this->pM = pM;
    this->defaultScore = -1;
    genIndex = 0;
    lastGenVirusIndex = new int(0);
}


Virus::Virus(int defaultScore){
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

int Virus::getScore() const {
    if(defaultScore != -1) {
        return defaultScore;
    }
    int score = 0;
    for (int i = 0; i < valuesVector->getSize(); ++i) {
        score += valuesVector->get(i) != targetVector->get(i);
    }
    return score;
}

bool Virus::operator==(const Virus &virus) const {
    return this->name == virus.name && genIndex == virus.genIndex;
}

std::string Virus::getName() {
    return name;
}

std::ostream &operator<<(std::ostream &stream, Virus &virus) {
    stream << virus.name;
    if(virus.genIndex != 0) {
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
        int i = rand() % valuesVector->getSize();
        int j = rand() % valuesVector->getSize();
        int tmp = valuesVector->get(i);
        valuesVector->set(i, valuesVector->get(j));
        valuesVector->set(j, tmp);
    }
}

bool Virus::operator<(const Virus &virus) const {
    if(getScore() == virus.getScore()) {
        return genIndex < virus.genIndex;
    }

    return getScore() < virus.getScore();
}
