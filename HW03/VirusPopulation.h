//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_VIRUSPOPULATION_H
#define CPPCOURSE_VIRUSPOPULATION_H


#include "SortedVirusLinkedList.h"

class VirusPopulation {
private:
    SortedVirusLinkedList* sortedLinkedList;
    DoubleVector *targetVector;
    int ** lastGensIndexes;
    Virus* bestVirus;
    int pM;
    int dim;

public:
    VirusPopulation(int pm, int dim, DoubleVector *targetVector);

    void addVirus(std::string &name, DoubleVector &values, int index);

    VirusPopulation(VirusPopulation &rhs);

    VirusPopulation &operator=(const VirusPopulation &rhs);

    ~VirusPopulation();

    void operator++(int);

    void operator*();

    friend std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation);

    bool foundMatch();
};


#endif //CPPCOURSE_VIRUSPOPULATION_H
