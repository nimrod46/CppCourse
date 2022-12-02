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

    Cell(char symbol);

    char getSymbol() const;

    bool canPutPotion() const;

    void setSymbol(char symbol);

    bool hasOpponentPotion(char symbol) const;

    static char getOpponentSymbol(char playerSymbol);

    static char getGemByPotion(char playerSymbol);

    static char getOpponentGemByPotion(char playerSymbol);

    bool isPotion() const;

    bool isCollapsed() const;

    bool isPlayerGem(char playerSymbol) const;

    bool isEmpty() const;

    bool isOpponentGem(char playerSymbol) const;

    bool isPlayer(char playerSymbol) const;
};


#endif //CPPCOURSE_CELL_H
