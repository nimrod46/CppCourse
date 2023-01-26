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

    std::vector<std::vector<int> *> *matrix;
    std::vector<V> *vertices;


public:
    DirectedGraph();

    void addVertex(V v);

    bool removeVertex(V v);

    void addEdge(V from, V to, int weight);

    void removeEdge(V from, V to);

    void setEdge(V from, V to, int weight);

    double getEdge(V from, V to);

    std::vector<V> *getNeighbourVertices(V v);

    std::vector<V> *getAllConnectedVertices(V v);

    void print();

    template<class U>
    friend std::ostream &operator<<(std::ostream &stream, DirectedGraph<U> &queue);

    int getVertexIndex(V v);

    void getAllConnectedVertices(V v, std::vector<V> *connectedVertices);

    int getItemIndex(V v, typename std::vector<V v>::iterator begin, typename std::vector<V>::iterator end);
};

template<typename V>
DirectedGraph<V>::DirectedGraph(): matrix(new std::vector<std::vector<int> *>()), vertices(new std::vector<V>()) {

}

template<typename V>
void DirectedGraph<V>::addVertex(V v) {
    vertices->push_back(v);
    matrix->push_back(new std::vector<int>());
    for (std::vector<int> *i: *matrix) {
        i->push_back(0);
    }

}

template<typename V>
bool DirectedGraph<V>::removeVertex(V v) {
    int index = getVertexIndex(v);
    if (index == -1) {
        return false;
    }

    vertices->erase(vertices->begin() + index);
    matrix->erase(matrix->begin() + index);
    for (std::vector<int> *i: *matrix) {
        i->erase(i->begin() + index);
    }
}

template<typename V>
void DirectedGraph<V>::addEdge(V from, V to, int weight) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    matrix->at(fromIndex)->at(toIndex) = weight;
}

template<typename V>
void DirectedGraph<V>::removeEdge(V from, V to) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    matrix->at(fromIndex)->at(toIndex) = 0;
}

template<typename V>
void DirectedGraph<V>::setEdge(V from, V to, int weight) {
    addEdge(from, to, weight);
}

template<typename V>
double DirectedGraph<V>::getEdge(V from, V to) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    return matrix->at(fromIndex)->at(toIndex);
}

template<typename V>
std::vector<V> *DirectedGraph<V>::getNeighbourVertices(V v) {
    std::vector<V> *neighbourVertices = new std::vector<V>();
    int index = getVertexIndex(v);

    for (int i = 0; i < matrix->size(); ++i) {
        if (matrix->at(index)->at(i) != 0) {
            neighbourVertices->push_back(vertices->at(i));
        }
    }

    return neighbourVertices;
}

template<typename V>
std::vector<V> *DirectedGraph<V>::getAllConnectedVertices(V v) {
    std::vector<V> *connectedVertices = new std::vector<V>();
    connectedVertices->push_back(v);
    int index = getVertexIndex(v);

    getAllConnectedVertices(v, connectedVertices);

    connectedVertices->erase(connectedVertices->begin());
    return connectedVertices;
}

template<typename V>
void DirectedGraph<V>::getAllConnectedVertices(V v, std::vector<V> *connectedVertices) {
    if (getItemIndex(v, connectedVertices->begin(), connectedVertices->begin()) != -1) {
        return;
    }

    int index = getVertexIndex(v);
    std::vector<V> *neighbourVertices = getNeighbourVertices(v);
    for (V u: *neighbourVertices) {
        connectedVertices->push_back(u);
        getAllConnectedVertices(u, connectedVertices);
    }
}

template<typename V>
void DirectedGraph<V>::print() {

}

template<class U>
std::ostream &operator<<(std::ostream &stream, DirectedGraph<U> &queue) {
    return 0;
}

template<typename V>
int DirectedGraph<V>::getVertexIndex(V v) {
    return getItemIndex(v, vertices->begin(), vertices->end());
}

template<typename V>
int
DirectedGraph<V>::getItemIndex(V v, typename std::vector<V>::iterator begin, typename std::vector<V>::iterator end) {
    for (typename std::vector<V>::iterator it = begin; it != end; ++it) {
        if (v == *it) {
            return it - begin;
        }
    }
    return -1;
}

#endif //CPPCOURSE_DIRECTEDGRAPH_H
