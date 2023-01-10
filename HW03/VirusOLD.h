//
// Created by nimrod on 20/12/2022.
//

#ifndef CPPCOURSE_VIRUSOLD_H
#define CPPCOURSE_VIRUSOLD_H


#include <string>
#include "DoubleVector.h"

class VirusOLD {

private:
    std::string name;
    DoubleVector *valuesVector;
    DoubleVector *targetVector;
    int *lastGenVirusIndex;
    int genIndex;
    int pM;
    int defaultScore;

public:
    VirusOLD(std::string &name, DoubleVector &valuesVector, DoubleVector *targetVector, int *lastGenVirusIndex, int pM);

    explicit VirusOLD(int defaultScore);

    VirusOLD(VirusOLD &virus);

    VirusOLD &operator=(const VirusOLD &virus);

    ~VirusOLD();

    VirusOLD(VirusOLD &&virus) noexcept;

    VirusOLD &operator=(VirusOLD &&virus) noexcept;

    double getErrorFromTarget() const;

    bool operator==(const VirusOLD &virus) const;

    bool operator<(const VirusOLD &virus) const;

    void operator*() const;

    friend std::ostream &operator<<(std::ostream &stream, VirusOLD &virus);
};


#endif //CPPCOURSE_VIRUSOLD_H
