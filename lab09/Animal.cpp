//
// Created by nimrod on 03-Jan-23.
//

#include "Animal.h"
#include "Mule.h"
#include "Donkey.h"
#include "Horse.h"

Animal::Animal(Gender &gender, std::string &name) : gender(gender), name(name) {

}

Animal *Animal::reproduce1(Animal &other) {
    if (getGender() == other.getGender()) {
        return nullptr;
    }

    if (typeid(*this) == typeid(Mule) || typeid(other) == typeid(Mule)) {
        return nullptr;
    }

    if (typeid(*this) == typeid(Horse) && typeid(other) == typeid(Horse)) {
        Gender gender1 = rand() % 2 == 0 ? Male : Female;
        std::string newName = this->getName() + other.getName();
        return new Horse(gender1, newName);
    }

    if (typeid(*this) == typeid(Donkey) && typeid(other) == typeid(Donkey)) {
        Gender gender1 = rand() % 2 == 0 ? Male : Female;
        std::string newName = this->getName() + other.getName();
        return new Donkey(gender1, newName);
    }
    Gender gender1 = rand() % 2 == 0 ? Male : Female;
    std::string newName = this->getName() + other.getName();
    return new Mule(gender1, newName);
}

Animal *Animal::reproduce2(Animal &other) {
    if (getGender() == other.getGender()) {
        return nullptr;
    }

    Mule* thisIsMule = dynamic_cast<Mule *>(this);
    Mule* otherIsMule = dynamic_cast<Mule *>(&other);

    if (thisIsMule || otherIsMule) {
        return nullptr;
    }

    Horse* thisIsHorse = dynamic_cast<Horse *>(this);
    Horse* otherIsHorse = dynamic_cast<Horse *>(&other);

    if (thisIsHorse && otherIsHorse) {
        Gender gender1 = rand() % 2 == 0 ? Male : Female;
        std::string newName = this->getName() + other.getName();
        return new Horse(gender1, newName);
    }

    Donkey* thisIsDonkey = dynamic_cast<Donkey *>(this);
    Donkey* otherIsDonkey = dynamic_cast<Donkey *>(&other);

    if (thisIsDonkey && otherIsDonkey) {
        Gender gender1 = rand() % 2 == 0 ? Male : Female;
        std::string newName = this->getName() + other.getName();
        return new Donkey(gender1, newName);
    }
    Gender gender1 = rand() % 2 == 0 ? Male : Female;
    std::string newName = this->getName() + other.getName();
    return new Mule(gender1, newName);
}

const std::string &Animal::getName() const {
    return name;
}

Gender Animal::getGender() const {
    return gender;
}
