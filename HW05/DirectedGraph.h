//
// Created by nimrod on 26/01/2023.
//

#ifndef CPPCOURSE_DIRECTEDGRAPH_H
#define CPPCOURSE_DIRECTEDGRAPH_H

#include <vector>
#include <ostream>
#include <iostream>

template<typename V>
class DirectedGraph {

private:

    std::vector<std::vector<int>> matrix;
    std::vector<V> vertices;
    /**
     * Helper method, see @getAllConnectedVertices
     * @param v
     * @param connectedVertices
     */
    void getAllConnectedVerticesHelper(V v, std::vector<V> connectedVertices);

    /**
     * Return index of Vertex in a given iterator bounds
     * @param v Vertex to search
     * @param begin iterator begin
     * @param end iterator end
     * @return
     */
    int getItemIndex(V v, typename std::vector<V>::iterator begin, typename std::vector<V>::iterator end);

    /**
     * Return vertex index in matrix
     * @param v Vrtex
     * @return
     */
    int getVertexIndex(V v);

public:
    DirectedGraph();

    /**
     * Add vertex v to the graph
     * @param v Vertex to add
     */
    void addVertex(V v);

    /**
     * Remove vertex v from the graph
     * @param v Vertex to remove
     * @return True if the vertex was present in the graph, otherwise false
     */
    bool removeVertex(V v);

    /**
     * Add edge between source vertex 'from' to destination vertex 'to' with value of 'weight'
     * @param from Source vertex
     * @param to Destination vertex
     * @param weight edge weight
     * @return True if the edge was added successfully, otherwise false
     */
    bool addEdge(V from, V to, int weight);

    /**
     * Remove edge by source vertex and destination vertex
     * @param from Source vertex
     * @param to Destination vertex
     * @return True if the edge was removed successfully, otherwise false
     */
    bool removeEdge(V from, V to);

    /**
     * Set edge value to 'weight' between source vertex 'from' to destination vertex 'to'
     * @param from
     * @param to
     * @param weight
     * @return True if the edge was set successfully, otherwise false
     */
    bool setEdge(V from, V to, int weight);

    /**
     * Return edge 'weight' between source vertex 'from' to destination vertex 'to'
     * @param from Source vertex
     * @param to Destination vertex
     * @return The edge 'weight', 0 if edge does not exist between vertices
     */
    int getEdge(V from, V to);

    /**
     * @param v Vertex v
     * @return All adjacent vertices from v
     */
    std::vector<V> getNeighbourVertices(V v);

    /**
     *
     * @param v Vertex v
     * @return All vertices reachable from v
     */
    std::vector<V> getAllConnectedVertices(V v);

    /**
     *
     * @param v Vertex v
     * @return True if the graph contains the vertex, otherwise false
     */
    bool containsVertex(V v);

    /**
     * Prints the graph to the standard output
     */
    void print();

    template<class U>
    friend std::ostream &operator<<(std::ostream &stream, DirectedGraph<U> &queue);
};

template<typename V>
DirectedGraph<V>::DirectedGraph(): matrix(), vertices() {

}

template<typename V>
void DirectedGraph<V>::addVertex(V v) {
    if (containsVertex(v)) {
        return;
    }
    vertices.push_back(v);
    std::vector<int> row(matrix.size(), 0);
    matrix.push_back(row);

    for (std::vector<int> &i: matrix) {
        i.push_back(0);
    }

}

template<typename V>
bool DirectedGraph<V>::removeVertex(V v) {
    int index = getVertexIndex(v);
    if (index == -1) {
        return false;
    }

    vertices.erase(vertices.begin() + index);
    matrix.erase(matrix.begin() + index);
    for (std::vector<int> i: matrix) {
        i.erase(i.begin() + index);
    }
}

template<typename V>
bool DirectedGraph<V>::addEdge(V from, V to, int weight) {
    return setEdge(from, to, weight);
}

template<typename V>
bool DirectedGraph<V>::removeEdge(V from, V to) {
    return setEdge(from, to, 0);
}

template<typename V>
bool DirectedGraph<V>::setEdge(V from, V to, int weight) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    if (fromIndex == -1 || toIndex == -1) {
        return false;
    }
    matrix[fromIndex][toIndex] = weight;
    return true;
}

template<typename V>
int DirectedGraph<V>::getEdge(V from, V to) {
    int fromIndex = getVertexIndex(from);
    int toIndex = getVertexIndex(to);
    return matrix[fromIndex][toIndex];
}

template<typename V>
std::vector<V> DirectedGraph<V>::getNeighbourVertices(V v) {
    std::vector<V> neighbourVertices;
    int index = getVertexIndex(v);

    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[index][i] != 0) {
            neighbourVertices.push_back(vertices[i]);
        }
    }

    return neighbourVertices;
}

template<typename V>
std::vector<V> DirectedGraph<V>::getAllConnectedVertices(V v) {
    std::vector<V> connectedVertices;
    connectedVertices->push_back(v);

    getAllConnectedVerticesHelper(v, connectedVertices);

    connectedVertices->erase(connectedVertices->begin());
    return connectedVertices;
}

template<typename V>
void DirectedGraph<V>::getAllConnectedVerticesHelper(V v, std::vector<V> connectedVertices) {
    if (getItemIndex(v, connectedVertices.begin(), connectedVertices.begin()) != -1) {
        return;
    }

    int index = getVertexIndex(v);
    std::vector<V> neighbourVertices = getNeighbourVertices(v);
    for (V u: neighbourVertices) {
        connectedVertices.push_back(u);
        getAllConnectedVerticesHelper(u, connectedVertices);
    }
}

template<typename V>
void DirectedGraph<V>::print() {
    std::cout << *this;
}

template<typename V>
bool DirectedGraph<V>::containsVertex(V v) {
    return getVertexIndex(v) != -1;
}

template<class U>
std::ostream &operator<<(std::ostream &stream, DirectedGraph<U> &directedGraph) {
    for (size_t i = 0; i < directedGraph.matrix.size(); ++i) {
        stream << directedGraph.vertices[i] << ": ";
        std::vector<U> neighbourVertices = directedGraph.getNeighbourVertices(directedGraph.vertices[i]);
        for (U u: neighbourVertices) {
            stream << u << " ";
        }
        stream << std::endl;
    }
    return stream;
}

template<typename V>
int DirectedGraph<V>::getVertexIndex(V v) {
    return getItemIndex(v, vertices.begin(), vertices.end());
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
