//
// Created by nimrod on 27-Dec-22.
//

#ifndef CPPCOURSE_RECTANGLE_H
#define CPPCOURSE_RECTANGLE_H


#include "Shape.h"

class Rectangle : Shape {
private:
public:
    Rectangle(uint x, uint y, uint width, uint height, char border);
    void draw() override;
};


#endif //CPPCOURSE_RECTANGLE_H
