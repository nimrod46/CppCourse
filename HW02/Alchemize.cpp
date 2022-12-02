//
// Created by nimrod on 02/12/2022.
//

#include <iostream>
#include <sstream>
#include "Alchemize.h"

Alchemize::Alchemize(int size) : board(new Board(size)), redScore(0), blueScore(0) {

}

void Alchemize::start() {
    printBoard();
    char playerSymbol = 'R';
    int *playerScore = &redScore;
    int *opponentScore = &blueScore;
    while (true) {
        if (!inputFromClient(playerSymbol, playerScore, opponentScore)) {
            std::cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;
        }
        int *tmp = playerScore;
        playerScore = opponentScore;
        opponentScore = tmp;

        playerSymbol = Cell::getOpponentSymbol(playerSymbol);
        printBoard();

        if (board->isGameOver()) {
            break;
        }
    }

    if (redScore == blueScore) {
        std::cout << "The game ended with a tie" << std::endl;
        return;
    }
    if (redScore > blueScore) {
        std::cout << "Red won" << std::endl;
        return;
    }
    std::cout << "Blue won" << std::endl;
}

bool Alchemize::inputFromClient(char playerSymbol, int *playerScore, int *opponentScore) const {
    std::cout << playerSymbol << ":" << std::endl;
    std::string input;

    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string n;
    int x, y;
    if (!(ss >> n)) {
        return false;
    }
    x = std::stoi(n);
    if (!(ss >> n)) {
        return false;
    }
    y = std::stoi(n);
    if (!board->placePlayerAt(x - 1, y - 1, playerSymbol, playerScore, opponentScore)) {
        return false;
    }
    return true;
}

void Alchemize::printBoard() {
    std::cout << "Red count: " << redScore << "\tBlue count: " << blueScore << std::endl;
    std::cout << *board;

}
