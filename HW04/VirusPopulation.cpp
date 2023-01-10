//
// Created by nimrod on 20/12/2022.
//

#include <iostream>
#include <climits>
#include "VirusPopulation.h"


VirusPopulation::VirusPopulation(int pm, int dim, Vector<int> *targetVector) {
    this->pM = pm;
    this->dim = dim;
    this->targetVector = new Vector<int>(*targetVector);
    Virus defMin = Virus(INT_MIN);
    Virus defMax = Virus(INT_MAX);
    this->viruses = new Queue<Virus>(defMin, defMax);
    this->bestVirus = nullptr;
    this->lastGensIndexes = new int *[dim];
    for (int i = 0; i < dim; ++i) {
        lastGensIndexes[i] = new int(0);
    }
}

VirusPopulation::VirusPopulation(VirusPopulation &rhs) {
    this->viruses = nullptr;
    this->bestVirus = nullptr;
    this->lastGensIndexes = nullptr;
    this->targetVector = nullptr;
    pM = 0;
    dim = 0;
    *this = rhs;
}

VirusPopulation &VirusPopulation::operator=(const VirusPopulation &rhs) {
    if (this == &rhs) {
        return (*this);
    }

    delete viruses;
    delete bestVirus;
    delete lastGensIndexes;
    delete targetVector;

    this->viruses = new Queue<Virus>(*rhs.viruses);
    this->targetVector = new Vector<int>(*rhs.targetVector);
    this->lastGensIndexes = new int *[rhs.dim];
    for (int i = 0; i < rhs.dim; ++i) {
        lastGensIndexes[i] = new int(*rhs.lastGensIndexes[i]);
    }
    this->bestVirus = new Virus(*rhs.bestVirus);
    this->pM = rhs.pM;
    this->dim = rhs.dim;
    return *this;
}

VirusPopulation::~VirusPopulation() {
    Virus *v = viruses->getFirst();
    while (viruses->getNext(&v)) {
        delete v;
    }
    delete viruses;
    delete targetVector;
    for (int i = 0; i < dim; ++i) {
        delete lastGensIndexes[i];
    }
    delete lastGensIndexes;
    delete bestVirus;
}

void VirusPopulation::addVirus(std::string &name, Vector<int> &values, int index) {
    auto *virus = new Virus(name, values, targetVector, lastGensIndexes[index], pM);
    viruses->add(virus);

    bestVirus = bestVirus == nullptr ? new Virus(*virus) : bestVirus;
}

void VirusPopulation::operator++(int) {
    Virus *virusToRemove = viruses->getlast();
    viruses->remove(virusToRemove);

    Virus *virus = new Virus(*viruses->getFirst());
    viruses->add(virus);
}

std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation) {
    Virus *virus;
    stream << *virusPopulation.viruses->getFirst();
    while (virusPopulation.viruses->getNext(&virus)) {
        stream << *virus;
    }
    stream << std::endl;
    stream << *virusPopulation.bestVirus;
    return stream;
}

void VirusPopulation::operator*() {
    Queue<Virus> linkedList(*viruses);
    Virus *virus = linkedList.getFirst();
    **virus;
    viruses->remove(virus);
    viruses->add(virus);
    while (linkedList.getNext(&virus)) {
        **virus;
        viruses->remove(virus);
        viruses->add(virus);
    }

    if ((*viruses->getFirst()) < *bestVirus) {
        *bestVirus = *viruses->getFirst();
    }
}

bool VirusPopulation::foundMatch() {
    return viruses->getFirst()->getErrorFromTarget() == 0;
}

