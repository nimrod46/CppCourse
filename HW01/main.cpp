#include <iostream>
#include <sstream>
#include "DoubleVector.h"
#include "ObservationVector.h"

//
// Created by nimrod on 16-Nov-22.
//

void addNewObservation(int i, int i1, ObservationVector &obs);

void printObservation(ObservationVector &obs);

void printExpectedValueVector(int dim, ObservationVector &obs);

void printCovarianceMatrix(int dim, ObservationVector &obs);

void start(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Invalid arguments <int> <int>." << std::endl;
        return;
    }
    int dim;
    dim = std::stoi(argv[1]);
    int maxCount;
    maxCount = std::stoi(argv[2]);


    ObservationVector obs(0);

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
                addNewObservation(dim, maxCount, obs);
                break;
            case 2:
                printObservation(obs);
                break;
            case 3:
                printExpectedValueVector(dim, obs);
                break;
            case 4:
                printCovarianceMatrix(dim, obs);
                break;
            case 5:
                //TODO: Free resources
                return;
        }
        std::cin >> option;
    }

}

void printExpectedValueVector(int dim, ObservationVector &obs) {

}

void printCovarianceMatrix(int dim, ObservationVector &obs) {
    DoubleVector doubleVector(dim);
    for (int i = 0; i < obs.getSize(); ++i) {
        for (int j = 0; j < dim; ++i) {

        }
    }

}

void printObservation(ObservationVector &obs) {
    std::cout << "Enter observation name:";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    for (int i = 0; i < obs.getSize(); ++i) {
        if (obs.get(i).getName() == name) {
            std::cout << name << " == " << obs.get(i).toString();
            return;
        }
    }
    std::cout << "Empty calculator" << std::endl;
}

void addNewObservation(int dim, int maxCount, ObservationVector &obs) {
    std::cout << "Enter observation name:";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter observation values:";
    std::string values;
    // std::cin.ignore();
    std::getline(std::cin, values);

    std::stringstream ss(values);
    std::string value;
    int count = 0;
    DoubleVector doubleVector(0);
    while (ss >> value) {
        count++;
        doubleVector.add(std::stod(value));
    }
    if (count != dim) {
        std::cout << "Invalid observation." << std::endl;
        return;
    }
    Observation ob(name, doubleVector);
    for (int i = 0; i < obs.getSize(); ++i) {
        if (obs.get(i).getName() == name) {
            obs.remove(i);
        }
    }
    obs.add(ob);
}

int main(int argc, char *argv[]) {
    start(argc, argv);


}


