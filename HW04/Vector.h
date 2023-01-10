//
// Created by nimrod on 08-Jan-23.
//

#ifndef CPPCOURSE_VECTOR_H
#define CPPCOURSE_VECTOR_H


#include <string>
#include <iostream>

template<typename T>
class Vector {
private:
    int size;
    int capacity;
    T *values;
public: //There is no need for move ctor and oper as there is no logic in moving a vector in my code
    explicit Vector(int size);

    Vector &operator=(const Vector &rhs);

    Vector(Vector& vector);

    ~Vector();

    Vector& add(double value);

    Vector& set(int index, T& value);

    T& get(int index) const;

    T& remove(int index);

    int getSize() const;

    void print();

    std::string toString();
};

template<typename T>
Vector<T>::Vector(int size) : size(0) {
    capacity = size;
    values = new T[size];
    for (int i = 0; i < size; ++i) {
        values[i] = 0;
    }
}

template<typename T>
Vector<T>::Vector(Vector<T>& vector) : size(vector.size){
    capacity = vector.size;
    values = new T[size];
    for (int i = 0; i < size; ++i) {
        values[i] = vector.get(i);
    }
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs) {
    if (this == &rhs) {
        return (*this);
    }

    delete values;

    this->size = rhs.size;
    capacity = rhs.capacity;
    values = new double[capacity];
    for (int i = 0; i < size; ++i) {
        values[i] = rhs.get(i);
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    delete values;
}

template<typename T>
Vector<T> &Vector<T>::add(double value) {
    if (size == capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        double *new_values = new double[capacity];
        for (int i = 0; i < size; ++i) {
            new_values[i] = values[i];
        }
        for (int i = size; i < capacity; ++i) {
            new_values[i] = 0;
        }
        values = new_values;
    }
    values[size++] = value;
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::set(int index, T& value) {
    values[index] = value;
    return *this;
}

template<typename T>
T& Vector<T>::get(int index) const {
    return values[index];
}

template<typename T>
T& Vector<T>::remove(int index) {
    for (int i = index; i < size - 1; ++i) {
        values[i] = values[i + 1];
    }
    size--;
    return 0;
}

template<typename T>
int Vector<T>::getSize() const {
    return size;
}

template<typename T>
void Vector<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, Vector<T> &vector) {
    stream << "[";
    for (int i = 0; i < vector.getSize(); ++i) {
        stream << " " << vector.get(i);
    }
    stream << "]";
    return stream;
}

#endif //CPPCOURSE_VECTOR_H
