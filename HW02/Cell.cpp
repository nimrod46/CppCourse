//
// Created by nimrod on 02/12/2022.
//

#include "Cell.h"
//const char Cell::symbols[6] = {'O', 'X', 'R', 'B', 'r', 'b'};

Cell::Cell() : symbol('O') {

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

char Cell::getOpponentSymbol(char potion_symbol) {
    return potion_symbol == 'R' ? 'B' : 'R';
}

char Cell::getGemByPotion(char potionSymbol) {
    return potionSymbol == 'R' ? 'r' : 'b';
}

char Cell::getOpponentGemByPotion(char potionSymbol) {
    return getGemByPotion(getOpponentSymbol(potionSymbol));
}
