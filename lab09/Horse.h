//
// Created by nimrod on 03-Jan-23.
//

#ifndef CPPCOURSE_HORSE_H
#define CPPCOURSE_HORSE_H


#include <iostream>
#include "Animal.h"

class Horse : virtual public Animal {
public:
    Horse(Gender& gender, std::string& name) : Animal(gender, name) {}
    void speak() override { std::cout << "Horse " << getName() << std::endl; }
};


#endif //CPPCOURSE_HORSE_H
