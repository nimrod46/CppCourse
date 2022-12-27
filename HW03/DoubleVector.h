//
// Created by nimrod on 16-Nov-22.
//

#ifndef CPPCOURSE_DOUBLEVECTOR_H
#define CPPCOURSE_DOUBLEVECTOR_H

class DoubleVector {
private:
    int size;
    int capacity;
    double *values;
public: //There is no need for move ctor and oper as there is no logic in moving a vector in my code
    explicit DoubleVector(int size);

    DoubleVector &operator=(const DoubleVector &rhs);

    DoubleVector(DoubleVector& doubleVector);

    ~DoubleVector();

    DoubleVector& add(double value);

    DoubleVector& set(int index, double value);

    double get(int index) const;

    double remove(int index);

    int getSize() const;

    void print();

    std::string toString();
};

#endif //CPPCOURSE_DOUBLEVECTOR_H
