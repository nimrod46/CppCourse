//

#include "Shape.h"

//
// Created by nimrod on 27-Dec-22.
Shape::Shape(uint x, uint y, uint width, uint height, char border) : x(x), y(y), width(width), height(height), border(border) {

}

uint Shape::getX() const {
    return x;
}

void Shape::setX(uint x) {
    Shape::x = x;
}

uint Shape::getY() const {
    return y;
}

void Shape::setY(uint y) {
    Shape::y = y;
}

uint Shape::getHeight() const {
    return height;
}

void Shape::setHeight(uint height) {
    Shape::height = height;
}

uint Shape::getWidth() const {
    return width;
}

void Shape::setWidth(uint width) {
    Shape::width = width;
}

char Shape::getBorder() const {
    return border;
}

void Shape::setBorder(char border) {
    Shape::border = border;
}
