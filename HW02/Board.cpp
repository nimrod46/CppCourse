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

bool Board::placePlayerAt(int x, int y, Player &player, Player &opponent) {
    if (x >= size || x < 0 || y < 0 || y >= size) {
        return false;
    }

    if (!cells[x][y]->canPutPotion()) {
        return false;
    }

    updateNeighboringCellsByPlayerMove(x, y, player, opponent);
    cells[x][y]->setSymbol(player.getPotionSymbol());
    emptyCellsCount--;

    return true;
}

void Board::updateNeighboringCellsByPlayerMove(int x, int y, Player &player, Player &opponent) {
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }

            if (cells[i][j]->isCollapsed() || cells[i][j]->isPotion()) {
                continue;
            }

            Cell *originalCell = cells[i][j];
            Cell *newCell = getCellByNeighbors(i, j, player, opponent, *cells[i][j]);
            if (newCell->isCollapsed()) {
                player -= originalCell->isPlayerGem(player);
                opponent -= originalCell->isPlayerGem(opponent);
            }

            emptyCellsCount -= originalCell->isEmpty() && !newCell->isEmpty();

            player += newCell->isPlayerGem(player);

            *originalCell = *newCell;
            delete newCell;
        }
    }
}

Cell *Board::getCellByNeighbors(int x, int y, Player &player, Player &opponent, Cell &currentCell) {
    bool foundOpponentPotion = false;
    for (int i = std::max((x - 1), 0); i <= std::min((x + 1), size - 1); ++i) {
        for (int j = std::max((y - 1), 0); j <= std::min((y + 1), size - 1); ++j) {
            if (i == x && j == y) {
                continue;
            }

            if (cells[i][j]->isPlayerPotion(player)) {
                return new Cell('X');
            }

            foundOpponentPotion = foundOpponentPotion || cells[i][j]->isPlayerPotion(opponent);
        }
    }
    return foundOpponentPotion ? new Cell(player.getGemSymbol()) : new Cell(currentCell);
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
