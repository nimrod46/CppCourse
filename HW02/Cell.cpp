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

bool Cell::canPutPotion() {
    return symbol == 'O';
}

void Cell::setSymbol(char potion_symbol) {
    symbol = potion_symbol;
}

bool Cell::hasOpponentPotion(char potion_symbol) const {
    return getOpponentSymbol(potion_symbol) == symbol;
}

bool Cell::isPotion() {
    return symbol == 'R' || symbol == 'B';
}

bool Cell::isCollapsed() {
    return symbol == 'X';
}

bool Cell::isEmpty() {
    return symbol == 'O';
}

char Cell::getOpponentSymbol(char potion_symbol) {
    return potion_symbol == 'R' ? 'B' : 'R';
}

char Cell::getGemByPotion(char potionSymbol) {
    return potionSymbol == 'R' ? 'r' : 'b';
}

char Cell::getOpponentGemByPotion(char potionSymbol) {
    return getGemByPotion(getOpponentSymbol(potionSymbol));
}

bool Cell::isPlayerGem(char potionSymbol) const {
    return getGemByPotion(potionSymbol) == symbol;
}

bool Cell::isOpponentGem(char potionSymbol) const {
    return getOpponentGemByPotion(potionSymbol) == symbol;
}
