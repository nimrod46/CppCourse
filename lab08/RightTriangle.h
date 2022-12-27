//
// Created by nimrod on 27-Dec-22.
//

#ifndef CPPCOURSE_RIGHTTRIANGLE_H
#define CPPCOURSE_RIGHTTRIANGLE_H


#include "Triangle.h"

class RightTriangle : Triangle {
private:
public:
    RightTriangle(uint x, uint y, uint size, char border);
    void draw() override;

};


#endif //CPPCOURSE_RIGHTTRIANGLE_H
