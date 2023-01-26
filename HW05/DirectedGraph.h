//
// Created by nimrod on 26/01/2023.
//

#ifndef CPPCOURSE_DIRECTEDGRAPH_H
#define CPPCOURSE_DIRECTEDGRAPH_H

#include <vector>
#include <ostream>

template<typename V>
class DirectedGraph {

private:

    std::vector<std::vector<int>> matrix;
    std::vector<V> vertices;


public:
    DirectedGraph();

    void addVertex(V v);

    void removeVertex(V v);

    void addEdge(V from, V to, double weight);

    void removeEdge(V from, V to);

    void setEdge(V from, V to, double weight);

    double getEdge(V from, V to, double weight);

    std::vector<V> getNeighbourVertices(V v);

    std::vector<V> getAllConnectedVertices(V v);

    void print();

    template<class U>
    friend std::ostream &operator<<(std::ostream &stream, DirectedGraph<U> &queue);

};

template<typename V>
DirectedGraph<V>::DirectedGraph(): matrix(), vertices() {

}

template<typename V>
void DirectedGraph<V>::addVertex(V v) {
    vertices.push_back(v);

}

template<typename V>
void DirectedGraph<V>::removeVertex(V v) {

}

template<typename V>
void DirectedGraph<V>::addEdge(V from, V to, double weight) {

}

template<typename V>
void DirectedGraph<V>::removeEdge(V from, V to) {

}

template<typename V>
void DirectedGraph<V>::setEdge(V from, V to, double weight) {

}

template<typename V>
double DirectedGraph<V>::getEdge(V from, V to, double weight) {
    return 0;
}

template<typename V>
std::vector<V> DirectedGraph<V>::getNeighbourVertices(V v) {
    return std::vector<V>();
}

template<typename V>
std::vector<V> DirectedGraph<V>::getAllConnectedVertices(V v) {
    return std::vector<V>();
}

template<typename V>
void DirectedGraph<V>::print() {

}

template<class U>
std::ostream &operator<<(std::ostream &stream, DirectedGraph<U> &queue) {
    return <#initializer#>;
}

#endif //CPPCOURSE_DIRECTEDGRAPH_H
