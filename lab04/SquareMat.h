//
// Created by nimrod on 22-Nov-22.
//

#ifndef CPPCOURSE_SQUAREMAT_H
#define CPPCOURSE_SQUAREMAT_H


class SquareMat {

private:
    int **data;
    int ndim;
public:
    SquareMat(int dim);

    SquareMat(SquareMat const &dim);

    SquareMat &operator=(SquareMat const &rhs);

    ~SquareMat();

    int size() const { return ndim; }

    int at(int i, int j) const;

    void print() const;

    bool compare(SquareMat &other);
};


#endif //CPPCOURSE_SQUAREMAT_H
