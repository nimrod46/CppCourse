//
// Created by nimrod on 02/12/2022.
//

#include <iostream>
#include <sstream>
#include "Alchemize.h"
#include "Player.h"

Alchemize::Alchemize(int size) : board(new Board(size)) {

}

void Alchemize::start() {
    Player *red = new Player('R', 'r');
    Player *player = red;
    Player *blue = new Player('B', 'b');
    Player *opponent = blue;
    printBoard(*red, *blue);
    while (true) {
        if (!inputFromClient(*player, *opponent)) {
            std::cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;
        }
        std::swap(player, opponent);
        printBoard(*red, *blue);

        if (board->isGameOver()) {
            break;
        }
    }

    if (red->getScore() == blue->getScore()) {
        std::cout << "The game ended with a tie" << std::endl;
        return;
    }
    if (red->getScore() > blue->getScore()) {
        std::cout << "Red won" << std::endl;
        return;
    }
    std::cout << "Blue won" << std::endl;
}

bool Alchemize::inputFromClient(Player &player, Player &opponent) const {
    std::cout << player.getPotionSymbol() << ":" << std::endl;
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
    if (!board->placePlayerAt(x - 1, y - 1, player, opponent)) {
        return false;
    }
    return true;
}

void Alchemize::printBoard(Player &redPlayer, Player &bluePlayer) {
    std::cout << "Red count: " << redPlayer.getScore() << "\tBlue count: " << bluePlayer.getScore() << std::endl;
    std::cout << *board;
}
