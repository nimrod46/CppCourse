#include <iostream>
#include "SquareMat.h"


//
// Created by nimrod on 22-Nov-22.
//
int main() {
    SquareMat mats[] = {SquareMat(5), SquareMat(8), SquareMat(4), SquareMat(10), SquareMat(9)};
    SquareMat* minMat = &mats[0];
    for (auto & mat : mats) {
        std::cout << mat.size() << std::endl;
        if (mat.compare(*minMat)) {
            minMat = &mat;
        }
    }
    minMat->print();

    SquareMat mat1(mats[0]);
    mat1 = *minMat;
    mat1.print();
}
