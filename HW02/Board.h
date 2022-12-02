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
    void DestroyCells();

public:

    explicit Board(int size);

    Board(Board const &board);

    Board &operator=(Board const &rhs);

    ~Board();

    friend std::ostream &operator<<(std::ostream &stream, Board &board);

    bool placePlayerAt(int x, int y, char playerSymbol, int *playerScoreToAdd, int *opponentScoreToRemove);

    void updateNeighboringCellsByPlayerMove(int x, int y, char playerSymbol, int *playerScoreToAdd, int *opponentScoreToRemove);

    Cell* getCellByNeighbors(int x, int y, char playerSymbol, char currentCellSymbol);

    bool isGameOver() const;

};

#endif //CPPCOURSE_BOARD_H
