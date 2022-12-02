//
// Created by nimrod on 02/12/2022.
//


#include <string>
#include <iostream>
#include "Alchemize.h"

void startGame(int argc, char *argv[]) {
    if(argc != 2) {
        std::cerr << "Invalid run arguments; run the game with board size." << std::endl;
        return;
    }
    int size = std::stoi(argv[1]);
    Alchemize alchemize(size);
    alchemize.start();
}








int main(int argc, char *argv[]) {
    startGame(argc, argv);
    return 0;
}