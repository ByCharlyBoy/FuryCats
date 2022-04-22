#pragma once
#include "DLinkedList.h"
template <class T>
class Queue :
    public DLinkedList<T>
{
public:
    void Push(T data) {
        DLinkedList<T>::AddElement(0, data);
    }

    T Pop() {
        T retVal = DLinkedList<T>::tail->obj;
        DLinkedList<T>::DeleteElement(DLinkedList<T>::Count() - 1);
        return retVal;
    }

    T Peek() {
        return DLinkedList<T>::tail->obj;
    }
};

