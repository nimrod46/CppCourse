//
// Created by nimrod on 13-Dec-22.
//

#include "Robot.h"

Robot::Robot(int speed, double chance) {
    this->speed = speed;
    this->chance = chance;
    position = 0;
}

void Robot::move(std::string track) {
    if (track[position] == '_') {
        moveForward();
        return;
    }

    if(drawChance()) {
        moveForward();
    }
}

void Robot::moveForward() {
    position += speed;
}

bool Robot::drawChance() {
    return ((std::rand() % 10 + 1.0) / 10) > chance;
}

char Robot::getTrackChar(std::string track) const {
    return track[position];
}

