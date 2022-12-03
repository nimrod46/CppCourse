//
// Created by nimrod on 03/12/2022.
//

#include "Player.h"

Player::Player(char potionSymbol, char gemSymbol) : score(0), potionSymbol(potionSymbol), gemSymbol(gemSymbol) {
}

int Player::getScore() const {
    return score;
}

char Player::getPotionSymbol() const {
    return potionSymbol;
}

char Player::getGemSymbol() const {
    return gemSymbol;
}

Player &Player::operator-=(const int &i) {
    score -= i;
    return *this;
}

Player &Player::operator+=(const int &i) {
    score += i;
    return *this;
}
