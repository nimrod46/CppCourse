//
// Created by nimrod on 20/12/2022.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "DoubleVector.h"
#include "SortedVirusLinkedList.h"
#include "VirusPopulation.h"

int main(int argc, char *argv[]) {

    std::string configFileName = argv[1];
    std::string firstGenerationFileName = argv[2];


    std::ifstream file;
    file.open(configFileName);
    std::stringstream ss;
    ss << file.rdbuf();

    file.close();

    int dim;
    ss >> dim;
    int m;
    ss >> m;

    DoubleVector *targetVector = new DoubleVector(0);
    for (int i = 0; i < dim; ++i) {
        int n;
        ss >> n;
        targetVector->add(n);
    }

    file.open(firstGenerationFileName);
    ss << file.rdbuf();
    file.close();

    int vectorsCount;
    ss >> vectorsCount;
    VirusPopulation virusPopulation(dim, m, targetVector);
    for (int i = 0; i < vectorsCount; ++i) {
        std::string name;
        ss >> name;
        DoubleVector values(0);
        for (int j = 0; j < dim; ++j) {
            int n;
            ss >> n;
            values.add(n);
        }
        virusPopulation.addVirus(name, values);
    }

    int rotation;
    std::cin >> rotation;
    for (int i = 0; i < rotation; ++i) {

        virusPopulation++;
        *virusPopulation;
        if(virusPopulation.foundMatch()) {
            break;
        }
    }
    std::cout << virusPopulation;

}