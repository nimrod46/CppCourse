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

Board::Board(Board const &rhs) {
    cells = nullptr;
    *this = rhs;
}

Board &Board::operator=(const Board &rhs) {
    if (this == &rhs) {
        return *this;
    }
    DestroyCells();
    this->size = rhs.size;
    this->emptyCellsCount = rhs.emptyCellsCount;
    this->cells = new Cell **[size];

    for (int i = 0; i < size; ++i) {
        cells[i] = new Cell *[size];
        for (int j = 0; j < size; ++j) {
            cells[i][j] = new Cell(*rhs.cells[i][j]);
        }
    }
}

Board::~Board() {
    DestroyCells();
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

            if (cells[i][j]->isCollapsed() || cells[i][j]->isPotion()) {
                continue;
            }
            Cell* originalCell = cells[i][j];
            Cell* newCell = getNeighborsCellsSpecialSymbol(i, j, potionSymbol, cells[i][j]->getSymbol());
            if (newCell->isCollapsed()) {
                (*playerScoreToAdd) -= originalCell->isPlayerGem(potionSymbol);
                (*opponentScoreToRemove) -= originalCell->isOpponentGem(potionSymbol);
            }

            emptyCellsCount -= originalCell->isEmpty() && !newCell->isEmpty();

            *cells[i][j] = *newCell;
            *playerScoreToAdd += newCell->isPlayerGem(potionSymbol);
            delete newCell;
        }
    }
}

Cell* Board::getNeighborsCellsSpecialSymbol(int x, int y, char potionSymbol, char currentCellSymbol) {
    bool foundOpponentPotion = false;
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }
            foundOpponentPotion = foundOpponentPotion || cells[i][j]->hasOpponentPotion(potionSymbol);
            if (cells[i][j]->getSymbol() == potionSymbol) {
                return new Cell('X');
            }
        }
    }
    return foundOpponentPotion ? new Cell(Cell::getGemByPotion(potionSymbol)) : new Cell(currentCellSymbol);
}

bool Board::isGameOver() const {
    return emptyCellsCount == 0;
}

void Board::DestroyCells() {
    if (cells == nullptr) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            delete cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
}
