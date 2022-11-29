//
// Created by nimrod on 29-Nov-22.
//

#ifndef CPPCOURSE_STACK_H
#define CPPCOURSE_STACK_H

#include <iostream>

class Stack {
private:
    int *data;
    int index;

public:


    Stack(int size);

    Stack(Stack const &rhs);

    Stack &operator=(const Stack &rhs);

    Stack(Stack &&dim);

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

    friend std::ostream& operator<<(std::ostream& stream, Stack& stack);

};


#endif //CPPCOURSE_STACK_H
