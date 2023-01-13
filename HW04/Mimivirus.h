//
// Created by nimrod on 10-Jan-23.
//

#ifndef CPPCOURSE_MIMIVIRUS_H
#define CPPCOURSE_MIMIVIRUS_H


#include "Virus.h"

class Mimivirus : public Virus {

public:
    Mimivirus(std::string &name, Vector<int> &valuesVector, Vector<int> *targetVector, int *lastGenVirusIndex)
            : Virus("M", name, valuesVector, targetVector, lastGenVirusIndex, 4) {}

    Virus *getNextGenVirus() override {
        Mimivirus *virus = new Mimivirus(name, *valuesVector, targetVector, lastGenVirusIndex);
        virus->pogressGen(*this);
        return virus;
    }
};


#endif //CPPCOURSE_MIMIVIRUS_H
