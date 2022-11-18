#include <iostream>
#include <sstream>
#include "DoubleVector.h"
#include "ObservationVector.h"

//
// Created by nimrod on 16-Nov-22.
//

void addNewObservation(int dim, int maxCount, ObservationVector &obs);

void printObservation(ObservationVector &obs);

void printExpectedValueVector(int dim, ObservationVector &obs);

void printCovarianceMatrix(int dim, ObservationVector &obs);

DoubleVector *getExpectedValueVector(int dim, ObservationVector &obs);

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
            default:
                break;
        }
        std::cin >> option;
    }

}

void addNewObservation(int dim, int maxCount, ObservationVector &obs) {
    std::cout << "Enter observation name:";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    int obIndex = -1;
    for (int i = 0; i < obs.getSize(); ++i) {
        if (obs.get(i).getName() == name) {
            //obs.remove(i);
            obIndex = i;
        }
    }

    if(obIndex == -1 && obs.getSize() == maxCount) {
        std::cout << "Max obs count reached!";
        return;
    }

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
    if (obIndex != -1) {
       obs.remove(obIndex);
    }
    obs.add(ob);
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

void printExpectedValueVector(int dim, ObservationVector &obs) {
    if (obs.getSize() == 0) {
        std::cout << "Empty calculator" << std::endl;
        return;
    }
    DoubleVector *doubleVector = getExpectedValueVector(dim, obs);
    std::cout << "mean == " << doubleVector->toString();
    delete doubleVector;
}

void printCovarianceMatrix(int dim, ObservationVector &obs) {
    if (obs.getSize() == 0) {
        std::cout << "Empty calculator" << std::endl;
        return;
    }
    double cob[dim][dim];
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cob[i][j] = 0;
        }
    }
    DoubleVector *expectedValueVector = getExpectedValueVector(dim, obs);
    double norm = obs.getSize() == 1 ? 1 : (1.0 / (obs.getSize() - 1));
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            for (int k = 0; k < obs.getSize(); ++k) {
                double v = norm * (obs.get(k).getDataAt(i) - expectedValueVector->get(i)) *
                           (obs.get(k).getDataAt(j) - expectedValueVector->get(j));

                cob[i][j] += v;
            }
        }
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            std::cout << cob[i][j] << " ";
        }
        std::cout << std::endl;
    }
    delete expectedValueVector;
}

DoubleVector *getExpectedValueVector(int dim, ObservationVector &obs) {
    DoubleVector *doubleVector = new DoubleVector(dim);
    for (int i = 0; i < dim; ++i) {
        double value = 0;
        for (int j = 0; j < obs.getSize(); ++j) {
            value += obs.get(j).getDataAt(i);
        }
        doubleVector->set(i, value / obs.getSize());
    }
    return doubleVector;
}

int main(int argc, char *argv[]) {
    start(argc, argv);
}


