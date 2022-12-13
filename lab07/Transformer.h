//
// Created by nimrod on 13-Dec-22.
//

#ifndef CPPCOURSE_TRANSFORMER_H
#define CPPCOURSE_TRANSFORMER_H


#include "Robot.h"

class Transformer : Robot {
private:
    bool isGroundMode;
public:
    explicit Transformer(int speed = 1);

private:
    void move(std::string track) override;

};


#endif //CPPCOURSE_TRANSFORMER_H
