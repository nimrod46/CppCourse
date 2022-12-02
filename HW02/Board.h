//
// Created by nimrod on 02/12/2022.
//

#ifndef CPPCOURSE_BOARD_H
#define CPPCOURSE_BOARD_H


#include "Cell.h"

class Board {
private:
    Cell ***cells;
    int size{};
    int emptyCellsCount{};
    void DestroyCells();

public:

    explicit Board(int size);

    Board(Board const &board);

    Board &operator=(Board const &rhs);

    ~Board();

    friend std::ostream &operator<<(std::ostream &stream, Board &board);

    bool placePotionAt(int x, int y, char potionSymbol, int *playerScoreToAdd, int *opponentScoreToRemove);

    void checkNeighborsCells(int x, int y, char i, int *playerScoreToAdd, int *opponentScoreToRemove);

    Cell* getNeighborsCellsSpecialSymbol(int x, int y, char potionSymbol, char currentCellSymbol);

    bool isGameOver() const;

};

#endif //CPPCOURSE_BOARD_H
