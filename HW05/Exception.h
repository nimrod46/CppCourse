//
// Created by nimrod on 26/01/2023.
//

#ifndef CPPCOURSE_EXCEPTION_H
#define CPPCOURSE_EXCEPTION_H


#include <string>
#include <iostream>
#include <utility>

class Exception {
private:
    std::string errMessage;
public:
    explicit Exception(std::string msg) : errMessage(std::move(msg)) {};

    void print() { std::cerr << errMessage << std::endl; };
};


#endif //CPPCOURSE_EXCEPTION_H
