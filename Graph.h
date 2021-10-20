#include <algorithm>
#include <iostream>
#include <sstream>
#include "Edge.h"
#include "Iterable.h"

using namespace std;

#ifndef TASK3_GRAPH_H
#define TASK3_GRAPH_H

template<typename T>
class Graph : public Iterable<T> {
private:
    vector<Node<T> *> nodes;
    vector<Edge<T> *> edges;
    vector<int> nodeIds;

    void dfs(int id, bool visited[]);

public:
    Graph() = default;

    ~Graph();

    vector<Node<T> *> &getNodes();

    vector<Edge<T> *> &getEdges();

    vector<int> &getNodeIds();

    void addNode(T value);

    void addEdge(int from, int to);

    Node<T> *getNodeById(int id);

    void removeNode(int id);

    void removeEdge(int from, int to);

    void depthSearch();

    void itrBypass();

    Iterator<T> *getIterator() override;

};

template<typename T>
Graph<T>::~Graph() {
    nodes.~vector<T>();
    edges.~vector<T>();
}

template<typename T>
vector<Node<T> *> &Graph<T>::getNodes() {
    return nodes;
}

template<typename T>
vector<Edge<T> *> &Graph<T>::getEdges() {
    return edges;
}

template<typename T>
vector<int> &Graph<T>::getNodeIds() {
    return nodeIds;
}

template<typename T>
void Graph<T>::addNode(T value) {
    nodeIds.push_back(nodeIds.size() + 1);
    nodes.push_back(new Node<T>(nodeIds.back(), value));
}

template<typename T>
void Graph<T>::addEdge(int from, int to) {
    Node<T> *begin = getNodeById(from);
    Node<T> *end = getNodeById(to);

    for (Edge<T> *edge: edges) {
        if ((edge->getBegin()->getId() == to && edge->getEnd()->getId() == from) ||
            (edge->getBegin()->getId() == from && edge->getEnd()->getId() == to))
            throw "There is already an edge between these nodes\n";
    }
    edges.push_back(new Edge<T>(begin, end));
    begin->addNeighbor(end);
    end->addNeighbor(begin);
}

template<typename T>
void Graph<T>::removeNode(int id) {
    Node<T> *node;
    try {
        node = getNodeById(id);
    } catch (std::out_of_range &e) {
        cout << e.what() << endl;
    }

    for (int i = id; i <= nodes.size(); i++) {
        getNodeById(i)->setId(getNodeById(i)->getId() - 1);
    }
    nodeIds.pop_back();
    nodes.erase(nodes.begin() + id - 1);
    for (Node<T> *neighbor: node->getNeighbors()) {
        removeEdge(node->getId(), neighbor->getId());
    }
    delete node;
}

template<typename T>
void Graph<T>::removeEdge(int from, int to) {
    int ptr = 0;
    for (Edge<T> *edge: edges) {
        if (edge->getBegin()->getId() == from && edge->getEnd()->getId() == to) {
            edge->getBegin()->removeNeighbor(edge->getEnd()->getId());
            edge->getEnd()->removeNeighbor(edge->getBegin()->getId());
            edges.erase(edges.begin() + ptr);
            delete edge;
        }
        ptr++;
    }
}

template<typename T>
void Graph<T>::depthSearch() {
    bool *visited = new bool[nodes.size()];
    dfs(1, visited);
}

template<typename T>
void Graph<T>::dfs(int id, bool visited[]) {
    visited[id] = true;
    Node<T> *node = getNodeById(id);
    cout << "Node id: " << node->getId() << ", node value: " << node->getValue() << "\n";
    for (Node<T> *v: node->getNeighbors()) {
        if (!visited[v->getId()]) {
            dfs(v->getId(), visited);
        }
    }
}

template<typename T>
Node<T> *Graph<T>::getNodeById(int id) {
    try {
        return nodes.at(id);
    } catch (std::out_of_range&) {
        cout << "No such node\n";
    }
}

template<typename T>
void Graph<T>::itrBypass() {
    stringstream stream;
    Iterator<T> *itr = getIterator();
    while (itr->hasNext()) {
        stream << "Node id: " << itr->current()->getId() << ", node value: " << itr->current()->getValue() << "\n";
        itr->next();
    }
    cout << stream.str();
}

template<typename T>
Iterator<T> *Graph<T>::getIterator() {
    return new Iterator<T>(nodes);
}

#endif
