//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_VIRUS_H
#define CPPCOURSE_VIRUS_H


#include <string>
#include "DoubleVector.h"

class Virus {

private:
    std::string name;
    DoubleVector *valuesVector;
    DoubleVector *targetVector;
    int genIndex;
    int pM;
    int defaultScore;
    int *lastGenVirusIndex;

public:
    Virus(std::string &name, DoubleVector &valuesVector, DoubleVector *targetVector, int pM);

    explicit Virus(int defaultScore);

    Virus(Virus &virus);

    Virus &operator=(const Virus &virus);

    Virus(Virus &&virus) noexcept;

    Virus & operator=(Virus &&virus) noexcept;

    double getErrorFromTarget() const;

    bool operator==(const Virus &virus) const;

    bool operator<(const Virus &virus) const;

    void operator*() const;

    friend std::ostream &operator<<(std::ostream &stream, Virus &virus);
};


#endif //CPPCOURSE_VIRUS_H
