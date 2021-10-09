#include "Node.h"

#ifndef TASK3_EDGE_H
#define TASK3_EDGE_H

template<typename T>
class Edge {
private:
    Node<T> *departure;
    Node<T> *destination;

public:

    Edge(Node<T> *begin, Node<T> *end);

    Node<T> *getBegin();

    void setBegin(Node<T> *from);

    Node<T> *getEnd();

    void setEnd(Node<T> *to);
};

template<typename T>
Edge<T>::Edge(Node<T> *begin, Node<T> *end)
        :departure(begin), destination(end) {}

template<typename T>
Node<T> *Edge<T>::getBegin() {
    return departure;
}

template<typename T>
void Edge<T>::setBegin(Node<T> *from) {
    Edge::departure = from;
}

template<typename T>
Node<T> *Edge<T>::getEnd() {
    return destination;
}

template<typename T>
void Edge<T>::setEnd(Node<T> *to) {
    Edge::destination = to;
}

#endif