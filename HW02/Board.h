//
// Created by nimrod on 02/12/2022.
//

#ifndef CPPCOURSE_BOARD_H
#define CPPCOURSE_BOARD_H


#include "Cell.h"

class Board {
private:
    Cell ***cells;
    int size;
    int emptyCellsCount;

public:

    explicit Board(int size);

    friend std::ostream &operator<<(std::ostream &stream, Board &board);

    bool placePotionAt(int x, int y, char potionSymbol, int *playerScoreToAdd, int *opponentScoreToRemove);

    void checkNeighborsCells(int x, int y, char i, int *playerScoreToAdd, int *opponentScoreToRemove);

    char getNeighborsCellsSpecialSymbol(int i, int j, char potionSymbol);

    bool isGameOver();
};

#endif //CPPCOURSE_BOARD_H
