//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_VIRUSPOPULATIONOLD_H
#define CPPCOURSE_VIRUSPOPULATIONOLD_H


#include "SortedVirusLinkedList.h"

class VirusPopulationOLD {
private:
    SortedVirusLinkedList* sortedLinkedList;
    DoubleVector *targetVector;
    int ** lastGensIndexes;
    VirusOLD* bestVirus;
    int pM;
    int dim;

public: //There is no need for move ctor and oper as there is no logic in moving a VirusPopulationOLD in my code
    VirusPopulationOLD(int pm, int dim, DoubleVector *targetVector);

    void addVirus(std::string &name, DoubleVector &values, int index);

    VirusPopulationOLD(VirusPopulationOLD &rhs);

    VirusPopulationOLD &operator=(const VirusPopulationOLD &rhs);

    ~VirusPopulationOLD();

    void operator++(int);

    void operator*();

    friend std::ostream &operator<<(std::ostream &stream, VirusPopulationOLD &virusPopulation);

    bool foundMatch();
};


#endif //CPPCOURSE_VIRUSPOPULATIONOLD_H
