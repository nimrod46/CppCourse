//
// Created by nimrod on 10-Jan-23.
//

#ifndef CPPCOURSE_PAPILLOMA_H
#define CPPCOURSE_PAPILLOMA_H


#include "Virus.h"

class Papilloma : public Virus {

public:
    Virus *getNextGenVirus() override {
        Papilloma *virus = new Papilloma(name, *valuesVector, targetVector, lastGenVirusIndex);
        virus->pogressGen(*this);
        return virus;
    }

    Papilloma(std::string &name, Vector<int> &valuesVector, Vector<int> *targetVector, int *lastGenVirusIndex)
            : Virus("P", name, valuesVector, targetVector, lastGenVirusIndex, 1) {}

    Papilloma(Virus &virus) : Virus(virus) {}
};


#endif //CPPCOURSE_PAPILLOMA_H
