//
// Created by nimrod on 20/12/2022.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "DoubleVector.h"
#include "SortedVirusLinkedList.h"
#include "VirusPopulationOLD.h"

//int main(int argc, char *argv[]) {
//    if (argc != 3) {
//        std::cerr << "Usage: run the program with <init file name> <location file name>" << std::endl;
//        exit(-1);
//    }
//    std::string configFileName = argv[1];
//    std::string firstGenerationFileName = argv[2];
//
//
//    std::ifstream file;
//    file.open(configFileName);
//
//    if (file.fail()) {
//        std::cerr << "Invalid input." << std::endl;
//        exit(-1);
//    }
//
//    std::stringstream ss;
//    ss << file.rdbuf();
//
//    file.close();
//
//    int dim;
//    ss >> dim;
//    int m;
//    ss >> m;
//
//    auto *targetVector = new DoubleVector(0);
//    for (int i = 0; i < dim; ++i) {
//        int n;
//        ss >> n;
//        targetVector->add(n);
//    }
//
//    file.open(firstGenerationFileName);
//
//    if (file.fail()) {
//        std::cerr << "Invalid input." << std::endl;
//        exit(-1);
//    }
//
//    ss << file.rdbuf();
//    file.close();
//
//    int vectorsCount;
//    ss >> vectorsCount;
//    VirusPopulationOLD *virusPopulation = new VirusPopulationOLD(m, dim, targetVector);
//    for (int i = 0; i < vectorsCount; ++i) {
//        std::string name;
//        ss >> name;
//        DoubleVector values(0);
//        for (int j = 0; j < dim; ++j) {
//            int n;
//            ss >> n;
//            values.add(n);
//        }
//        if (ss.fail()) {
//            std::cerr << "Invalid input." << std::endl;
//            exit(-1);
//        }
//        virusPopulation->addVirus(name, values, i);
//    }
//
//    int rotation;
//    std::cin >> rotation;
//    for (int i = 0; i < rotation; ++i) {
//
//        (*virusPopulation)++;
//        **virusPopulation;
//        if (virusPopulation->foundMatch()) {
//            break;
//        }
//    }
//    std::cout << *virusPopulation;
//
//    delete virusPopulation;
//    delete targetVector;
//}