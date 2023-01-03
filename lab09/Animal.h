//
// Created by nimrod on 03-Jan-23.
//

#ifndef CPPCOURSE_ANIMAL_H
#define CPPCOURSE_ANIMAL_H

#include <string>

enum Gender {
    Male,
    Female
};

class Animal {
private:
    std::string name;
    Gender gender;


public:
    Animal(Gender &gender, std::string &name);

    const std::string &getName() const;

    Gender getGender() const;

    virtual void speak() = 0;

    virtual Animal *reproduce1(Animal &other);

    virtual Animal *reproduce2(Animal &other);
};

#endif //CPPCOURSE_ANIMAL_H
