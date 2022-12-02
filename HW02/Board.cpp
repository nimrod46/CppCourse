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
    return *this;
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
    return stream;
}

bool Board::placePlayerAt(int x, int y, char playerSymbol, int *playerScoreToAdd, int *opponentScoreToRemove) {
    if (x >= size || x < 0 || y < 0 || y >= size) {
        return false;
    }

    if (!cells[x][y]->canPutPotion()) {
        return false;
    }

    checkNeighborsCells(x, y, playerSymbol, playerScoreToAdd, opponentScoreToRemove);
    cells[x][y]->setSymbol(playerSymbol);
    emptyCellsCount--;

    return true;
}

void Board::checkNeighborsCells(int x, int y, char playerSymbol, int *playerScoreToAdd, int *opponentScoreToRemove) {
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }

            if (cells[i][j]->isCollapsed() || cells[i][j]->isPotion()) {
                continue;
            }

            Cell *originalCell = cells[i][j];
            Cell *newCell = getCellByNeighbors(i, j, playerSymbol, cells[i][j]->getSymbol());
            if (newCell->isCollapsed()) {
                (*playerScoreToAdd) -= originalCell->isPlayerGem(playerSymbol);
                (*opponentScoreToRemove) -= originalCell->isOpponentGem(playerSymbol);
            }

            emptyCellsCount -= originalCell->isEmpty() && !newCell->isEmpty();

            *playerScoreToAdd += newCell->isPlayerGem(playerSymbol);

            *originalCell = *newCell;
            delete newCell;
        }
    }
}

Cell *Board::getCellByNeighbors(int x, int y, char playerSymbol, char currentCellSymbol) {
    bool foundOpponentPotion = false;
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }

            if (cells[i][j]->isPlayer(playerSymbol)) {
                return new Cell('X');
            }

            foundOpponentPotion = foundOpponentPotion || cells[i][j]->hasOpponentPotion(playerSymbol);
        }
    }
    return foundOpponentPotion ? new Cell(Cell::getGemByPotion(playerSymbol)) : new Cell(currentCellSymbol);
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
