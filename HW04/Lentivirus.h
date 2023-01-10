//
// Created by nimrod on 10-Jan-23.
//

#ifndef CPPCOURSE_LENTIVIRUS_H
#define CPPCOURSE_LENTIVIRUS_H


#include "Virus.h"

class Lentivirus : Virus {
private:
    Lentivirus(std::string &name, Vector<int> &valuesVector, Vector<int> *targetVector, int *lastGenVirusIndex)
            : Virus(name, valuesVector, targetVector, lastGenVirusIndex, 2) {}

    Lentivirus(Virus &virus) : Virus(virus) {}

};


#endif //CPPCOURSE_LENTIVIRUS_H
