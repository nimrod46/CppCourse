//

#include "Cell.h"
//const char Cell::symbols[6] = {'O', 'X', 'R', 'B', 'r', 'b'};

Cell::Cell() : symbol('O') {

}

Cell::Cell(char symbol) {
    this->symbol = symbol;
}

char Cell::getSymbol() const {
    return symbol;
}

bool Cell::canPutPotion() const {
    return symbol == 'O';
}

void Cell::setSymbol(char potion_symbol) {
    symbol = potion_symbol;
}

bool Cell::hasOpponentPotion(char potion_symbol) const {
    return getOpponentSymbol(potion_symbol) == symbol;
}

bool Cell::isPotion() const {
    return symbol == 'R' || symbol == 'B';
}

bool Cell::isCollapsed() const {
    return symbol == 'X';
}

bool Cell::isEmpty() const {
    return symbol == 'O';
}

char Cell::getOpponentSymbol(char playerSymbol) {
    return playerSymbol == 'R' ? 'B' : 'R';
}

char Cell::getGemByPotion(char playerSymbol) {
    return playerSymbol == 'R' ? 'r' : 'b';
}

char Cell::getOpponentGemByPotion(char playerSymbol) {
    return getGemByPotion(getOpponentSymbol(playerSymbol));
}

bool Cell::isPlayerGem(char playerSymbol) const {
    return getGemByPotion(playerSymbol) == symbol;
}

bool Cell::isOpponentGem(char playerSymbol) const {
    return getOpponentGemByPotion(playerSymbol) == symbol;
}

bool Cell::isPlayer(char playerSymbol) const {
    return symbol == playerSymbol;
}
