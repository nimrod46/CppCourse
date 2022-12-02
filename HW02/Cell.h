//
// Created by nimrod on 02/12/2022.
//

#ifndef CPPCOURSE_CELL_H
#define CPPCOURSE_CELL_H


class Cell {
private:
//    const static char symbols[6]; //= {'O'};
//    int symbol_index;
    char symbol;
public:
    Cell();

    char getSymbol() const;

    bool canPutPotion();

    void setSymbol(char symbol);

    bool hasOpponentPotion(char symbol) const;

    static char getOpponentSymbol(char symbol);

    static char getGemByPotion(char potionSymbol);

    static char getOpponentGemByPotion(char potionSymbol);
};


#endif //CPPCOURSE_CELL_H
