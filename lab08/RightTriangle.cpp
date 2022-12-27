//
// Created by nimrod on 27-Dec-22.
//

#include <string>
#include <sstream>
#include <iostream>
#include "RightTriangle.h"
#include "Shape.h"

RightTriangle::RightTriangle(uint x, uint y, uint size, char border) : Triangle(x, y, size, border) {

}

void RightTriangle::draw() {
    std::ostringstream os;
    os << std::string(getY(), '\n');

    os << std::string(getX(), ' ');
    os << getBorder();
    os << '\n';

    for (int i = 1; i < getHeight() - 1; ++i) {
        os << std::string(getX(), ' ');
        os << getBorder() << std::string(i - 1, ' ') << getBorder() << std::endl;
    }

    os << std::string(getX(), ' ');
    os << std::string(getWidth(), getBorder()) << std::endl;
    std::cout << os.str();
}