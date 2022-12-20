//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_VIRUSPOPULATION_H
#define CPPCOURSE_VIRUSPOPULATION_H


#include "SortedVirusLinkedList.h"

class VirusPopulation {
private:
    SortedVirusLinkedList sortedLinkedList;
    DoubleVector *targetVector;
    int dim;
    int pM;

public:
    VirusPopulation(int dim, int pm, DoubleVector *targetVector);

    void addVirus(std::string &name, DoubleVector &values);

    VirusPopulation &operator++(int);

    void operator*();

    friend std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation);

    bool foundMatch();
};


#endif //CPPCOURSE_VIRUSPOPULATION_H