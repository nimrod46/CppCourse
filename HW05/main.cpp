#include <fstream>
#include <sstream>
#include "DirectedGraph.h"

void handleUserInput(DirectedGraph<std::string> &graph);

void handleFilesInput(std::vector<std::string> &filesNames, const std::string &outputFileName);

//
// Created by nimrod on 26/01/2023.
//
int main(int argc, char *argv[]) {
    std::vector<std::string> filesNames;
    std::string outputFileName = "output.dat";
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o") {
            outputFileName = argv[i + 1];
            i++;
            continue;
        }
        filesNames.emplace_back(arg);
    }
    DirectedGraph<std::string> dg;

    handleFilesInput(filesNames, outputFileName);

    handleUserInput(dg);

    return 0;
}

void handleFilesInput(std::vector<std::string> &filesNames, const std::string &outputFileName,
                      DirectedGraph<std::string> &dg) {

    std::ifstream infile;
    for (const std::string &fileName: filesNames) {
        infile.open(fileName);
        std::string data;
        while (std::getline(infile, data)) {

            std::stringstream line(data);
            std::string from;
            line >> from;

            std::string to;
            line >> to;

            int weight;
            line >> weight;

            dg.addVertex(from);
            dg.addVertex(to);
            dg.addEdge(from, to, weight);
        }
        infile.close();
    }


    std::ofstream file;
    file.open(outputFileName);
    file << dg;
}

void handleUserInput(DirectedGraph<std::string> &graph) {

    while (true) {
        std::string sourceNode;
        std::cin >> sourceNode;
        if (sourceNode == "exit") {
            return;
        }

        if (!graph.containsVertex(sourceNode)) {

            std::cout << sourceNode << " does not exist in the current network" << std::endl;
            std::cout << "USAGE: <node> or ‘exit’ to terminate" << std::endl;
            continue;
        }

        std::vector<std::string> connectedNodes = graph.getNeighbourVertices(sourceNode);
        if (connectedNodes.empty()) {
            std::cout << sourceNode << " : " << "no outbound travel" << std::endl;
            continue;
        }
        std::cout << sourceNode;
        for (const std::string &node: connectedNodes) {
            std::cout << '\t' << node;
        }
        std::cout << std::endl;
    }
}
