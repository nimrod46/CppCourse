//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_VIRUSPOPULATION_H
#define CPPCOURSE_VIRUSPOPULATION_H


#include "Queue.h"
#include "Vector.h"
#include "Virus.h"

class VirusPopulation {
private:
    Queue<Virus> *viruses;
    Vector<int> *targetVector;
    int **lastGensIndexes;
    Virus *bestVirus;
    int dim;

public: //There is no need for move ctor and oper as there is no logic in moving a VirusPopulation in my code
    VirusPopulation(int dim, Vector<int> *targetVector);

    void addVirus(std::string &type, std::string &name, Vector<int> &values, int index);

    VirusPopulation(VirusPopulation &rhs);

    VirusPopulation &operator=(const VirusPopulation &rhs);

    ~VirusPopulation();

    void operator++(int);

    void operator*();

    friend std::ostream &operator<<(std::ostream &stream, VirusPopulation &virusPopulation);

    bool foundMatch();
};


#endif //CPPCOURSE_VIRUSPOPULATION_H
