#include <iostream>
#include "DoubleVector.h"
#include "ObservationVector.h"

//
// Created by nimrod on 16-Nov-22.
//

void addNewObservation(int i, int i1);

void printObservation();

void printExpectedValueVector();

void printCovarianceMatrix();

void start(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Invalid arguments <int> <int>." << std::endl;
        return;
    }
    int dim = std::stoi(argv[1]);
    int maxCount = std::stoi(argv[1]);




    ObservationVector obs();


    std::cout << "[1] New observations" << std::endl;
    std::cout << "[2] Print observations" << std::endl;
    std::cout << "[3] Expected value vector" << std::endl;
    std::cout << "[4] Covariance matrix" << std::endl;
    std::cout << "[5] Exit" << std::endl;
    int option;
    std::cin >> option;
    while (true) {
        switch (option) {
            case 1:
                addNewObservation(dim, maxCount);
                break;
            case 2:
                printObservation();
                break;
            case 3:
                printExpectedValueVector();
                break;
            case 4:
                printCovarianceMatrix();
                break;
            case 5:
                //TODO: Free resources
                return;
        }
    }

}

void printCovarianceMatrix() {

}

void printExpectedValueVector() {

}

void printObservation() {

}

void addNewObservation(int i, int i1) {

}

int main(int argc, char *argv[]) {
    start(argc, argv);


}


