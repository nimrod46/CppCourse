//
// Created by nimrod on 27-Dec-22.
//

#include <string>
#include <iostream>
#include <sstream>
#include "Rectangle.h"

Rectangle::Rectangle(uint x, uint y, uint width, uint height, char border) : Shape(x, y, width, height, border) {

}

void Rectangle::draw() {
    std::ostringstream os;
    os << std::string(getY(), '\n');

    os << std::string(getX(), ' ');
    os << std::string(getWidth(), getBorder());
    os << '\n';

    for (int i = 1; i < getHeight() - 1; ++i) {
        os << std::string(getX(), ' ');
        os << getBorder() << std::string(getWidth() - 2, ' ') << getBorder() << std::endl;
    }

    os << std::string(getX(), ' ');
    os << std::string(getWidth(), getBorder()) << std::endl;
    std::cout << os.str();
}
