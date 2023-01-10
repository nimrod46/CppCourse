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
    this->sortedLinkedList = new Queue<Virus>(defMin, defMax);
    this->bestVirus = nullptr;
    this->lastGensIndexes = new int *[dim];
    for (int i = 0; i < dim; ++i) {
        lastGensIndexes[i] = new int(0);
    }
}

VirusPopulation::VirusPopulation(VirusPopulation &rhs) {
    this->sortedLinkedList = nullptr;
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

    delete sortedLinkedList;
    delete bestVirus;
    delete lastGensIndexes;
    delete targetVector;

    this->sortedLinkedList = new Queue<Virus>(*rhs.sortedLinkedList);
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
    Virus *v = sortedLinkedList->getFirst();
    while (sortedLinkedList->getNext(&v)) {
        delete v;
    }
    delete sortedLinkedList;
    delete targetVector;
    for (int i = 0; i < dim; ++i) {
        delete lastGensIndexes[i];
    }
    delete lastGensIndexes;
    delete bestVirus;
}

void VirusPopulation::addVirus(std::string &name, Vector<int> &values, int index) {
    auto *virus = new Virus(name, values, targetVector, lastGensIndexes[index], pM);
    sortedLinkedList->add(virus);

    bestVirus = bestVirus == nullptr ? new Virus(*virus) : bestVirus;
}

void VirusPopulation::operator++(int) {
    Virus *virusToRemove = sortedLinkedList->getlast();
    sortedLinkedList->remove(virusToRemove);

    auto *virus = new Virus(*sortedLinkedList->getFirst());
    sortedLinkedList->add(virus);
}

std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation) {
    Virus *virus;
    stream << *virusPopulation.sortedLinkedList->getFirst();
    while (virusPopulation.sortedLinkedList->getNext(&virus)) {
        stream << *virus;
    }
    stream << std::endl;
    stream << *virusPopulation.bestVirus;
    return stream;
}

void VirusPopulation::operator*() {
    Queue<Virus> linkedList(*sortedLinkedList);
    Virus *virus = linkedList.getFirst();
    **virus;
    sortedLinkedList->remove(virus);
    sortedLinkedList->add(virus);
    while (linkedList.getNext(&virus)) {
        **virus;
        sortedLinkedList->remove(virus);
        sortedLinkedList->add(virus);
    }

    if ((*sortedLinkedList->getFirst()) < *bestVirus) {
        *bestVirus = *sortedLinkedList->getFirst();
    }
}

bool VirusPopulation::foundMatch() {
    return sortedLinkedList->getFirst()->getErrorFromTarget() == 0;
}

