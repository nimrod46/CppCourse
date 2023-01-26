#include "DirectedGraph.h"

//
// Created by nimrod on 26/01/2023.
//
int main(int argc, char* argv[]) {
    std::vector<std::string> filesNames;
    std::string outputFileName = "output.dat";
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if(arg == "-o") {
            outputFileName = argv[i + 1];
            i++;
            continue;
        }
        filesNames.emplace_back(arg);
    }

    

    DirectedGraph<std::string> dg;


    return 0;
}