//
// Created by nimrod on 02/12/2022.
//

#ifndef CPPCOURSE_CELL_H
#define CPPCOURSE_CELL_H


#include "Player.h"

class Cell {
private:
    char symbol;
public:
    Cell();

    explicit Cell(char symbol);

    char getSymbol() const;

    bool canPutPotion() const;

    void setSymbol(char symbol);

    bool isPotion() const;

    bool isCollapsed() const;

    bool isPlayerGem(Player &player) const;

    bool isEmpty() const;

    bool isPlayerPotion(Player &player) const;
};


#endif //CPPCOURSE_CELL_H
