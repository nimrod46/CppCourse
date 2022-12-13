//
// Created by nimrod on 13-Dec-22.
//

#include "Transformer.h"

Transformer::Transformer(int speed) : Robot(speed, 0.25){
    isGroundMode = true;
}

void Transformer::move(std::string track) {

    if(drawChance()) {
        isGroundMode = !isGroundMode;
    }

    if (getTrackChar(track) == '_') {
        moveForward();
        return;
    }

    if(!isGroundMode) {
        moveForward();
    }
}
