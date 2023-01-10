//
// Created by nimrod on 20/12/2022.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "Vector.h"
#include "VirusPopulation.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: run the program with <init file name> <location file name>" << std::endl;
        exit(-1);
    }
    std::string configFileName = argv[1];
    std::string firstGenerationFileName = argv[2];


    std::ifstream file;
    file.open(configFileName);

    if (file.fail()) {
        std::cerr << "Invalid input." << std::endl;
        exit(-1);
    }

    std::stringstream ss;
    ss << file.rdbuf();

    file.close();

    int dim;
    ss >> dim;

    Vector<int> *targetVector = new Vector<int>(0);
    for (int i = 0; i < dim; ++i) {
        int n;
        ss >> n;
        targetVector->add(n);
    }

    file.open(firstGenerationFileName);

    if (file.fail()) {
        std::cerr << "Invalid input." << std::endl;
        exit(-1);
    }

    ss << file.rdbuf();
    file.close();

    int vectorsCount;
    ss >> vectorsCount;
    VirusPopulation *virusPopulation = new VirusPopulation(dim, targetVector);
    for (int i = 0; i < vectorsCount; ++i) {
        std::string type;
        ss >> type;
        std::string name;
        ss >> name;
        Vector<int> values(0);
        for (int j = 0; j < dim; ++j) {
            int n;
            ss >> n;
            values.add(n);
        }
        if (ss.fail()) {
            std::cerr << "Invalid input." << std::endl;
            exit(-1);
        }
        virusPopulation->addVirus(type, name, values, i);
    }

    int rotation;
    std::cin >> rotation;
    for (int i = 0; i < rotation; ++i) {

        (*virusPopulation)++;
        **virusPopulation;
        if (virusPopulation->foundMatch()) {
            break;
        }
    }
    std::cout << *virusPopulation;

    delete virusPopulation;
    delete targetVector;
}