//
// Created by nimrod on 20/12/2022.
//

#include <iostream>
#include <climits>
#include "VirusPopulation.h"
#include "Papilloma.h"
#include "Lentivirus.h"
#include "Mimivirus.h"


VirusPopulation::VirusPopulation(int dim, Vector<int> *targetVector) {
    this->dim = dim;
    this->targetVector = new Vector<int>(*targetVector);
    Virus defMin(INT_MIN);
    Virus defMax(INT_MAX);
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
    this->dim = rhs.dim;
    return *this;
}

VirusPopulation::~VirusPopulation() {
    Virus *v = viruses->getlast();
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

void VirusPopulation::addVirus(std::string &type, std::string &name, Vector<int> &values, int index) {

    Virus *virus;
    if (type == "P") {
        virus = new Papilloma(name, values, targetVector, lastGensIndexes[index]);
    } else if (type == "L") {
        virus = new Lentivirus(name, values, targetVector, lastGensIndexes[index]);
    } else if (type == "M") {
        virus = new Mimivirus(name, values, targetVector, lastGensIndexes[index]);
    } else {
        std::cerr << "Error: invalid virus type" << std::endl;
        exit(-1);
    }

    viruses->addByPriority(virus);
    bestVirus = bestVirus == nullptr ? new Virus(*virus) : bestVirus;
}

void VirusPopulation::operator++(int) {
    Virus *virusToRemove = viruses->getFirst();
    while (dynamic_cast<Papilloma *>(virusToRemove) != nullptr) {
        if (!viruses->getPrevious(&virusToRemove)) {
            return;
        }
    }
    viruses->remove(virusToRemove);


    Virus *virus = viruses->getlast()->getNextGenVirus();
    viruses->addByPriority(virus);
}

std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation) {
//    Virus *virus;
//    stream << *virusPopulation.viruses->getFirst();
//    while (virusPopulation.viruses->getNext(&virus)) {
//        stream << *virus;
//    }
    stream << *virusPopulation.viruses;
    stream << std::endl;
    stream << *virusPopulation.bestVirus;
    return stream;
}

void VirusPopulation::operator*() {
    Queue<Virus> linkedList(*viruses);
    Virus *virus = linkedList.getlast();
    **virus;
    viruses->remove(virus);
    viruses->addByPriority(virus);
    while (linkedList.getNext(&virus)) {
        **virus;
        viruses->remove(virus);
        viruses->addByPriority(virus);
    }

    if ((*viruses->getlast()) < *bestVirus) {
        *bestVirus = *viruses->getlast();
    }
}

bool VirusPopulation::foundMatch() {
    return viruses->getlast()->getErrorFromTarget() == 0;
}

