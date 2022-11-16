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
public:
    explicit DoubleVector(int capacity);

    void destroy();

    DoubleVector& add(double value);

    DoubleVector& set(int index, double value);

    double get(int index) const;

    double remove(int index);

    int getSize() const;

    void print();

    std::string toString();
};

#endif //CPPCOURSE_DOUBLEVECTOR_H
