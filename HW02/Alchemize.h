//
// Created by nimrod on 02/12/2022.
//

#ifndef CPPCOURSE_ALCHEMIZE_H
#define CPPCOURSE_ALCHEMIZE_H


#include "Board.h"
#include "Player.h"

class Alchemize {
private:
    Board *board;

    bool inputFromClient(Player &player, Player &opponent) const;

    void printBoard(Player &redPlayer, Player &bluePlayer);

public:
    Alchemize(int size);

    void start();

};


#endif //CPPCOURSE_ALCHEMIZE_H
