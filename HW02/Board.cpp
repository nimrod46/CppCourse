//
// Created by nimrod on 02/12/2022.
//

#include <ostream>
#include "Board.h"

Board::Board(int size) : cells(new Cell **[size]), size(size), emptyCellsCount(size * size) {
    for (int i = 0; i < size; ++i) {
        cells[i] = new Cell *[size];
        for (int j = 0; j < size; ++j) {
            cells[i][j] = new Cell();
        }
    }
}

std::ostream &operator<<(std::ostream &stream, Board &board) {
    for (int i = 0; i < board.size; ++i) {
        for (int j = 0; j < board.size; ++j) {
            stream << board.cells[i][j]->getSymbol() << '\t';
        }
        stream << std::endl;
    }
}

bool Board::placePotionAt(int x, int y, char potionSymbol, int *playerScoreToAdd, int *opponentScoreToRemove) {
    if (x >= size || x < 0 || y < 0 || y >= size) {
        return false;
    }

    if (!cells[x][y]->canPutPotion()) {
        return false;
    }

    checkNeighborsCells(x, y, potionSymbol, playerScoreToAdd, opponentScoreToRemove);
    cells[x][y]->setSymbol(potionSymbol);
    emptyCellsCount--;

    return true;
}

void Board::checkNeighborsCells(int x, int y, char potionSymbol, int *playerScoreToAdd, int *opponentScoreToRemove) {
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }
            if (cells[i][j]->getSymbol() == 'X' || cells[i][j]->getSymbol() == 'B' || cells[i][j]->getSymbol() == 'R') {
                continue;
            }
            char symbol = getNeighborsCellsSpecialSymbol(i, j, potionSymbol);
            if (symbol == 'X') {
                (*playerScoreToAdd) -= Cell::getGemByPotion(potionSymbol) == cells[i][j]->getSymbol();
                (*opponentScoreToRemove) -= Cell::getGemByPotion(Cell::getOpponentSymbol(potionSymbol)) == cells[i][j]->getSymbol();
            }
            if (cells[i][j]->getSymbol() == 'O' && symbol != 'O') {
                emptyCellsCount--;
            }
            cells[i][j]->setSymbol(symbol == 'O' ? cells[i][j]->getSymbol() : symbol);
            *playerScoreToAdd += symbol == Cell::getGemByPotion(potionSymbol);

        }
    }
}

char Board::getNeighborsCellsSpecialSymbol(int x, int y, char potionSymbol) {
    bool found_opponent_potion = false;
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }
            found_opponent_potion = found_opponent_potion || cells[i][j]->hasOpponentPotion(potionSymbol);
            if (cells[i][j]->getSymbol() == potionSymbol) {
                return 'X';
            }
        }
    }
    return found_opponent_potion ? Cell::getGemByPotion(potionSymbol) : 'O';
}

bool Board::isGameOver() {
    return emptyCellsCount == 0;
}
