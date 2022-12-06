//
// Created by nimrod on 02/12/2022.
//


#include <string>
#include <iostream>
#include <iostream>
#include <sstream>
#include "Player.h"
#include "Board.h"

void printBoard(Board &board, Player &redPlayer, Player &bluePlayer);

bool inputFromClient(Board &board, Player &player, Player &opponent);

void startGame(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid run arguments; run the game with board size." << std::endl;
        return;
    }
    int size = std::stoi(argv[1]);
    Board *board = new Board(size);
    Player *red = new Player('R', 'r');
    Player *player = red;
    Player *blue = new Player('B', 'b');
    Player *opponent = blue;

    printBoard(*board, *red, *blue);
    while (true) {
        if (!inputFromClient(*board, *player, *opponent)) {
            std::cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;
        }
        std::swap(player, opponent);

        printBoard(*board, *red, *blue);

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

bool inputFromClient(Board &board, Player &player, Player &opponent) {
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
    if (!board.placePlayerAt(x - 1, y - 1, player, opponent)) {
        return false;
    }
    return true;
}

void printBoard(Board &board, Player &redPlayer, Player &bluePlayer) {
    std::cout << "Red count: " << redPlayer.getScore() << "\tBlue count: " << bluePlayer.getScore() << std::endl;
    std::cout << board;
}


int main(int argc, char *argv[]) {
    startGame(argc, argv);
    return 0;
}