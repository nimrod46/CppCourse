//
// Created by nimrod on 03-Jan-23.
//

#ifndef CPPCOURSE_MULE_H
#define CPPCOURSE_MULE_H


#include "Donkey.h"
#include "Horse.h"
#include "Animal.h"

class Mule : public Donkey, public Horse {
public:
    Mule(Gender &gender, std::string &name) : Animal(gender, name),
                                              Donkey(gender, name),
                                              Horse(gender, name) {}

    void speak() override { std::cout << "Mule " << getName(); }
};


#endif //CPPCOURSE_MULE_H
