//
// Created by nimrod on 10-Jan-23.
//

#ifndef CPPCOURSE_LENTIVIRUS_H
#define CPPCOURSE_LENTIVIRUS_H


#include "Virus.h"

class Lentivirus : public Virus {
public:
    Lentivirus(std::string &name, Vector<int> &valuesVector, Vector<int> *targetVector, int *lastGenVirusIndex)
            : Virus("L", name, valuesVector, targetVector, lastGenVirusIndex, 2) {}

    Lentivirus(Virus &virus) : Virus(virus) {}

    Virus* getNextGenVirus() override {
        Lentivirus * virus = new Lentivirus(name, *valuesVector, targetVector, lastGenVirusIndex);
        virus->pogressGen(*this);
        return virus;
    }
};


#endif //CPPCOURSE_LENTIVIRUS_H
