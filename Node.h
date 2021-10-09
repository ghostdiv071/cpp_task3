#include <vector>

#ifndef TASK3_NODE_H
#define TASK3_NODE_H

template<typename T>
class Node {
private:
    int identifier;
    T value;
    std::vector<Node *> neighbors;

public:
    Node(int identifier, T value);

    int getId();

    void setId(int id);

    T getValue();

    void setValue(T val);

    std::vector<Node *> getNeighbors();

    void addNeighbor(Node *neighbor);

    void removeNeighbor(int id);
};

template<typename T>
Node<T>::Node(int identifier, T value):identifier(identifier), value(value) {}

template<typename T>
int Node<T>::getId() {
    return identifier;
}

template<typename T>
void Node<T>::setId(int id) {
    identifier = id;
}

template<typename T>
T Node<T>::getValue() {
    return value;
}

template<typename T>
void Node<T>::setValue(T val) {
    value = val;
}

template<typename T>
std::vector<Node<T> *> Node<T>::getNeighbors() {
    return neighbors;
}

template<typename T>
void Node<T>::removeNeighbor(int id) {
    int ptr = 0;
    for (Node<T> *neighbor : neighbors) {
        if (neighbor->getId() == id) {
            neighbors.erase(neighbors.begin() + ptr);
        }
        ptr++;
    }
}

template<typename T>
void Node<T>::addNeighbor(Node *neighbor) {
    neighbors.push_back(neighbor);
}

#endif