//
// Created by nimrod on 22-Nov-22.
//

#include <cstdlib>
#include <iostream>
#include "SquareMat.h"

SquareMat::SquareMat(int dim) {
    ndim = dim;
    data = new int *[dim];
    for (int i = 0; i < dim; ++i) {
        data[i] = new int[dim];
        for (int j = 0; j < dim; ++j) {
            data[i][j] = rand() % 900 + 100;
        }
    }
    std::cout << "C'tor" << std::endl;
}

SquareMat::SquareMat(const SquareMat &other) {
    ndim = other.ndim;
    data = new int *[ndim];
    for (int i = 0; i < ndim; ++i) {
        data[i] = new int[ndim];
        for (int j = 0; j < ndim; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    std::cout << "Copy C'tor" << std::endl;
}

SquareMat &SquareMat::operator=(const SquareMat &other) {
    for (int i = 0; i < ndim; ++i) {
        delete[]data[i];

    }
    delete[] data;

    ndim = other.ndim;
    data = new int *[ndim];
    for (int i = 0; i < ndim; ++i) {
        data[i] = new int[ndim];
        for (int j = 0; j < ndim; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

SquareMat::~SquareMat() {
    for (int i = 0; i < ndim; ++i) {
        delete[]data[i];
    }
    delete[] data;
}

int SquareMat::at(int i, int j) const {
    return data[i][j];
}

void SquareMat::print() const {
    for (int i = 0; i < ndim; ++i) {
        for (int j = 0; j < ndim; ++j) {
            std::cout << data[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

double getSum(const SquareMat &mat) {
    double sum = 0;
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat.size(); ++j) {
            sum += mat.at(i, j);
        }
    }
    return sum;
}

bool SquareMat::compare(SquareMat &other) {
    return getSum(*this) < getSum(other);
}
