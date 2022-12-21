//
// Created by nimrod on 20/12/2022.
//

#include <iostream>
#include "VirusPopulation.h"


VirusPopulation::VirusPopulation(int pm, DoubleVector *targetVector) {
    this->pM = pm;
    this->targetVector = new DoubleVector(*targetVector);
    this->bestVirus = nullptr;
}

void VirusPopulation::addVirus(std::string &name, DoubleVector &values) {
    auto *virus = new Virus(name, values, targetVector, pM);
    sortedLinkedList.add(virus);

    bestVirus = bestVirus == nullptr ? new Virus(*virus) : bestVirus;
}

void VirusPopulation::operator++(int) {
    Virus *virusToRemove = sortedLinkedList.getlast();
    sortedLinkedList.remove(virusToRemove);

    auto *virus = new Virus(*sortedLinkedList.getFirst());
    sortedLinkedList.add(virus);
}

std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation) {
    Virus *virus;
    stream << *virusPopulation.sortedLinkedList.getFirst();
    while (virusPopulation.sortedLinkedList.getNext(&virus)) {
        stream << *virus;
    }
    stream << std::endl;
    stream << *virusPopulation.bestVirus;
    return stream;
}

void VirusPopulation::operator*() {
    SortedVirusLinkedList linkedList(sortedLinkedList);
    Virus *virus = linkedList.getFirst();
    **virus;
    sortedLinkedList.remove(virus);
    sortedLinkedList.add(virus);
    while (linkedList.getNext(&virus)) {
        **virus;
        sortedLinkedList.remove(virus);
        sortedLinkedList.add(virus);
    }

    if((*sortedLinkedList.getFirst()) < *bestVirus) {
        *bestVirus = *sortedLinkedList.getFirst();
    }
}

bool VirusPopulation::foundMatch() {
    return sortedLinkedList.getFirst()->getErrorFromTarget() == 0;
}

