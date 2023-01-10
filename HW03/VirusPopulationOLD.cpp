//
// Created by nimrod on 20/12/2022.
//

#include <iostream>
#include "VirusPopulationOLD.h"


VirusPopulationOLD::VirusPopulationOLD(int pm, int dim, DoubleVector *targetVector) {
    this->pM = pm;
    this->dim = dim;
    this->targetVector = new DoubleVector(*targetVector);
    this->sortedLinkedList = new SortedVirusLinkedList();
    this->bestVirus = nullptr;
    this->lastGensIndexes = new int *[dim];
    for (int i = 0; i < dim; ++i) {
        lastGensIndexes[i] = new int(0);
    }
}

VirusPopulationOLD::VirusPopulationOLD(VirusPopulationOLD &rhs) {
    this->sortedLinkedList = nullptr;
    this->bestVirus = nullptr;
    this->lastGensIndexes = nullptr;
    this->targetVector = nullptr;
    pM = 0;
    dim = 0;
    *this = rhs;
}

VirusPopulationOLD &VirusPopulationOLD::operator=(const VirusPopulationOLD &rhs) {
    if (this == &rhs) {
        return (*this);
    }

    delete sortedLinkedList;
    delete bestVirus;
    delete lastGensIndexes;
    delete targetVector;

    this->sortedLinkedList = new SortedVirusLinkedList(*rhs.sortedLinkedList);
    this->targetVector = new DoubleVector(*rhs.targetVector);
    this->lastGensIndexes = new int*[rhs.dim];
    for (int i = 0; i < rhs.dim; ++i) {
        lastGensIndexes[i] = new int(*rhs.lastGensIndexes[i]);
    }
    this->bestVirus = new VirusOLD(*rhs.bestVirus);
    this->pM = rhs.pM;
    this->dim = rhs.dim;
    return *this;
}

VirusPopulationOLD::~VirusPopulationOLD() {
    VirusOLD* v = sortedLinkedList->getFirst();
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

void VirusPopulationOLD::addVirus(std::string &name, DoubleVector &values, int index) {
    auto *virus = new VirusOLD(name, values, targetVector, lastGensIndexes[index], pM);
    sortedLinkedList->add(virus);

    bestVirus = bestVirus == nullptr ? new VirusOLD(*virus) : bestVirus;
}

void VirusPopulationOLD::operator++(int) {
    VirusOLD *virusToRemove = sortedLinkedList->getlast();
    sortedLinkedList->remove(virusToRemove);

    auto *virus = new VirusOLD(*sortedLinkedList->getFirst());
    sortedLinkedList->add(virus);
}

std::ostream &operator<<(std::ostream &stream, VirusPopulationOLD &virusPopulation) {
    VirusOLD *virus;
    stream << *virusPopulation.sortedLinkedList->getFirst();
    while (virusPopulation.sortedLinkedList->getNext(&virus)) {
        stream << *virus;
    }
    stream << std::endl;
    stream << *virusPopulation.bestVirus;
    return stream;
}

void VirusPopulationOLD::operator*() {
    SortedVirusLinkedList linkedList(*sortedLinkedList);
    VirusOLD *virus = linkedList.getFirst();
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

bool VirusPopulationOLD::foundMatch() {
    return sortedLinkedList->getFirst()->getErrorFromTarget() == 0;
}

