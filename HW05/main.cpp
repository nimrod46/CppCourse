#include <fstream>
#include <sstream>
#include <algorithm>
#include "DirectedGraph.h"
#include "Exception.h"

void handleUserInput(DirectedGraph<std::string> &graph);

void handleFilesInput(std::vector<std::string> &filesNames, const std::string &outputFileName,
                      DirectedGraph<std::string> &dg);

void
handleProgramArguments(int argc, char *const *argv, std::vector<std::string> &filesNames, std::string &outputFileName);

int main(int argc, char *argv[]) {
    try {
        std::vector<std::string> filesNames;
        std::string outputFileName;

        handleProgramArguments(argc, argv, filesNames, outputFileName);

        DirectedGraph<std::string> graph;

        handleFilesInput(filesNames, outputFileName, graph);

        handleUserInput(graph);
    } catch (Exception &e) {
        e.print();
    }

    return 0;
}

void
handleProgramArguments(int argc, char *const *argv, std::vector<std::string> &filesNames, std::string &outputFileName) {
    outputFileName = "output.dat";

    if (argc == 1) {
        std::string errMsg = "ERROR: make user to input at least one file";
        throw Exception(errMsg);
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o") {
            outputFileName = argv[i + 1];
            i++;
            continue;
        }
        filesNames.emplace_back(arg);
    }
}

void handleFilesInput(std::vector<std::string> &filesNames, const std::string &outputFileName,
                      DirectedGraph<std::string> &dg) {

    std::ifstream infile;
    for (const std::string &fileName: filesNames) {
        infile.open(fileName);

        if (infile.fail()) {
            throw Exception("ERROR: does not exist or cannot be opened");
        }

        std::string data;
        while (std::getline(infile, data)) {
            if(std::all_of(data.begin(),data.end(),isspace)) { //Avoid empty line
                continue;
            }
            std::stringstream line(data);
            std::string from;
            line >> from;

            if (line.fail()) {
                throw Exception("ERROR: node definition in " + fileName + " is invalid");
            }

            std::string to;
            line >> to;

            if (line.fail()) {
                throw Exception("ERROR: node definition in " + fileName + " is invalid");
            }

            int weight;
            line >> weight;

            if (line.fail() || weight <= 0) {
                throw Exception("ERROR: node definition in " + fileName + " is invalid");
            }

            line.get();
            line.get();
            if (!line.fail()) { //Too many argument in edge definition
                throw Exception("ERROR: node definition in " + fileName + " is invalid");
            }


            dg.addVertex(from);
            dg.addVertex(to);
            int lastEdgeValue = dg.getEdge(from, to);
            if(lastEdgeValue == 0 || weight < lastEdgeValue) {
                //Update edge only if it does not exist or if new value is less than the previous one
                dg.addEdge(from, to, weight);
            }
        }
        infile.close();
    }


    std::ofstream outFile;

    if (outFile.fail()) {
        throw Exception("ERROR: does not exist or cannot be opened");
    }

    outFile.open(outputFileName);
    outFile << dg;
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
