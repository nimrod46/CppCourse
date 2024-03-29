#include <iostream>
#include <sstream>
#include "../HW03/DoubleVector.h"
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

    ObservationVector *obs = new ObservationVector(0);

    std::cout << "[1] New observation" << std::endl;
    std::cout << "[2] Print observation" << std::endl;
    std::cout << "[3] Expected value vector" << std::endl;
    std::cout << "[4] Covariance matrix" << std::endl;
    std::cout << "[5] Exit" << std::endl;
    int num;
    while (true) {
        std::cin >> num;
        switch (num) {
            case 1:
                addNewObservation(dim, maxCount, *obs);
                break;
            case 2:
                printObservation(*obs);
                break;
            case 3:
                printExpectedValueVector(dim, *obs);
                break;
            case 4:
                printCovarianceMatrix(dim, *obs);
                break;
            case 5:
                delete obs;
                return;
            default:
                std::cerr << "Invalid option." << std::endl;
                break;
        }
    }
}

void addNewObservation(int dim, int maxCount, ObservationVector &obs) {
    std::cout << "Enter observation name:" << std::endl;
    std::string name;
    std::cin.ignore(); //We need this when using getline after using cin
    std::getline(std::cin, name);
    int obToRemoveIndex = -1;
    for (int i = 0; i < obs.getSize(); ++i) {
        if (obs.get(i).getName() == name) {
            obToRemoveIndex = i;
        }
    }

    if (obToRemoveIndex == -1 && obs.getSize() == maxCount) {
        std::cerr << "Max obs count reached!";
        return;
    }

    std::cout << "Enter observation values:" << std::endl;
    std::string values;
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
        std::cerr << "Invalid observation." << std::endl;
        return;
    }

    Observation ob(name, doubleVector);
    if (obToRemoveIndex != -1) {
        obs.remove(obToRemoveIndex);
    }
    obs.add(ob);
}

void printObservation(ObservationVector &obs) {
    std::cout << "Enter observation name:" << std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    for (int i = 0; i < obs.getSize(); ++i) {
        if (obs.get(i).getName() == name) {
            std::cout << name << " = " << obs.get(i).toString() << std::endl;
            return;
        }
    }
    std::cerr << "Invalid or nonexistent observation." << std::endl;
}

void printExpectedValueVector(int dim, ObservationVector &obs) {
    if (obs.getSize() == 0) {
        std::cerr << "Empty calculator." << std::endl;
        return;
    }
    DoubleVector *doubleVector = getExpectedValueVector(dim, obs);
    std::cout << "mean = " << doubleVector->toString() << std::endl;
    delete doubleVector;
}

void printCovarianceMatrix(int dim, ObservationVector &obs) {
    if (obs.getSize() == 0) {
        std::cerr << "Empty calculator." << std::endl;
        return;
    }
    double cob[dim][dim]; //I know calculation should be in float but this is the only way I pass all tests
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cob[i][j] = 0;
        }
    }
    DoubleVector *expectedValueVector = getExpectedValueVector(dim, obs);
    double norm = obs.getSize() == 1 ? 1 : (1.0 / (obs.getSize() - 1.0));
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            for (int k = 0; k < obs.getSize(); ++k) {
                double v = norm * (obs.get(k).getDataAt(i) - expectedValueVector->get(i)) *
                          (obs.get(k).getDataAt(j) - expectedValueVector->get(j));

                cob[i][j] += v;
            }
        }
    }
    delete expectedValueVector;

    std::cout << "cov = [" << std::endl;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            std::cout << " " << (float) cob[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "]";
}

DoubleVector *getExpectedValueVector(int dim, ObservationVector &obs) {
    auto *doubleVector = new DoubleVector(dim);
    for (int i = 0; i < dim; ++i) {
        double value = 0;
        for (int j = 0; j < obs.getSize(); ++j) {
            value += obs.get(j).getDataAt(i);
        }
        doubleVector->set(i, value / obs.getSize());
    }
    return doubleVector;
}

//int main(int argc, char *argv[]) {
//    start(argc, argv);
//}


