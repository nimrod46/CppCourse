//
// Created by nimrod on 27-Dec-22.
//

#ifndef CPPCOURSE_SHAPE_H
#define CPPCOURSE_SHAPE_H

typedef unsigned int uint;

class Shape {
private:
    uint x;
    uint y;
    uint height;
    uint width;
    char border;
public:
    Shape(uint x, uint y, uint width, uint height, char border);

    virtual void draw() = 0;
    virtual ~Shape() = default;

    uint getX() const;

    void setX(uint x);

    uint getY() const;

    void setY(uint y);

    uint getHeight() const;

    void setHeight(uint height);

    uint getWidth() const;

    void setWidth(uint width);

    char getBorder() const;

    void setBorder(char border);

};

#endif //CPPCOURSE_SHAPE_H
