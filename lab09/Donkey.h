//
// Created by nimrod on 03-Jan-23.
//

#ifndef CPPCOURSE_DONKEY_H
#define CPPCOURSE_DONKEY_H


#include <iostream>
#include "Animal.h"

class Donkey : virtual public Animal {
public:
    Donkey(Gender& gender, std::string& name) : Animal(gender, name) {}
    void speak() override { std::cout << "Donkey " << getName() << std::endl; }
};


#endif //CPPCOURSE_DONKEY_H
