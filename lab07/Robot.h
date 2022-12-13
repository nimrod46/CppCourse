//
// Created by nimrod on 13-Dec-22.
//

#ifndef CPPCOURSE_ROBOT_H
#define CPPCOURSE_ROBOT_H

#include <string>

class Robot {
private:
    int speed;
    double chance;
    int position;
protected:
    void moveForward();
    bool drawChance();
    char getTrackChar(std::string track) const;
public:
    explicit Robot(int speed = 1, double chance = 0.3);

    virtual void move(std::string track);
};

#endif //CPPCOURSE_ROBOT_H
