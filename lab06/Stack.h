//
// Created by nimrod on 29-Nov-22.
//

#ifndef CPPCOURSE_STACK_H
#define CPPCOURSE_STACK_H

#include <iostream>
#include "List.h"

class Stack {
private:
    List* list;

public:


    Stack();

    Stack(Stack const &rhs);

    Stack &operator=(const Stack &rhs);

    Stack(Stack &&dim) noexcept ;

    Stack &operator=(Stack &&rhs);

    ~Stack();

    void push(int num);

    int pop();

    int top() const;

    bool empty() const;

    void transfer(Stack &stack) const;

    int operator*() const;

    void operator~();

    bool operator!() const;

    void operator<<(int num);

    void operator>>(int &num);

    void operator<<(Stack &stack);

    void operator>>(Stack &stack);

    friend std::ostream &operator<<(std::ostream &stream, Stack &stack);

};

void reverse(Stack & stack);


#endif //CPPCOURSE_STACK_H
