//
// Created by nimrod on 29-Nov-22.
//

#include "Stack.h"

Stack::Stack() {
    list = new List();
}

Stack::Stack(const Stack &stack) {
    list = nullptr;
    (*this) = stack;
}

Stack &Stack::operator=(const Stack &rhs) {
    if (this == &rhs) {
        return (*this);
    }
    delete list;

    list = new List();

    for (int i = 0; i <= list->size(); i++) {
        list->operator[](i) = rhs.list->operator[](i);
    }
    return *this;
}

Stack::Stack(Stack &&rhs) : list(rhs.list) {
    rhs.list = nullptr;
}

Stack &Stack::operator=(Stack &&rhs) {
    list = rhs.list;
    rhs.list = nullptr;
    return *this;
}

Stack::~Stack() {
    delete list;
}

void Stack::push(int num) {
    list->insert(num);
}

int Stack::pop() {
    int n = (*list)[0];
    list->remove(n);
    return n;
}

int Stack::top() const {
    return (*list)[0];
}

bool Stack::empty() const {
    return list->size() == 0;
}

void Stack::transfer(Stack &stack) const {
    for (int i = 0; i <= list->size(); ++i) {
        stack.push(list->operator[](i));
    }
}

int Stack::operator*() const {
    return top();
}

void Stack::operator~() {
    list->clear();
}

bool Stack::operator!() const {
    return empty();
}

void Stack::operator<<(int num) {
    push(num);
}

void Stack::operator>>(int &num) {
    num = pop();
}

void Stack::operator<<(Stack &stack) {
    for (int i = 0; i <= stack.list->size(); ++i) {
        push(stack.list->operator[](i));
    }
}

void Stack::operator>>(Stack &stack) {
    for (int i = 0; i < stack.list->size(); ++i) {
        stack.push(list->operator[](i));
    }
}

std::ostream &operator<<(std::ostream &stream, Stack &stack) {
    for (int i = 0; i < stack.list->size(); ++i) {
        stream << stack.list->operator[](i) << " ";
    }
    return stream;
}






