//
// Created by nimrod on 02/12/2022.
//

#ifndef CPPCOURSE_ALCHEMIZE_H
#define CPPCOURSE_ALCHEMIZE_H


#include "Board.h"

class Alchemize {
private:
    int redScore;
    int blueScore;
    Board *board;

    void printBoard();

    bool inputFromClient(char potionSymbol, int *playerScore, int *opponentScore) const;

public:
    Alchemize(int size);

    void start();

};


#endif //CPPCOURSE_ALCHEMIZE_H
