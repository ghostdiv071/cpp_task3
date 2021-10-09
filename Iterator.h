#ifndef TASK3_ITERATOR_H
#define TASK3_ITERATOR_H

#include <vector>

template<typename T>
class Iterator {
private:
    std::vector<Node<T>*> data;
    int pointer;

public:
    explicit Iterator(std::vector<Node<T>*> data) : data(data) {
        pointer = 0;
    }

    virtual ~Iterator() = default;

    bool hasNext() {
        return (pointer + 1) <= data.size();
    }

    void next() {
        pointer++;
    }

    Node<T>* current() {
        return data.at(pointer);
    }

};


#endif
