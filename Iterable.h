#include "Iterator.h"

#ifndef TASK3_ITERABLE_H
#define TASK3_ITERABLE_H

template<typename T>
class Iterable {
    virtual Iterator<T>* getIterator() {throw "No implementation";};
};


#endif
