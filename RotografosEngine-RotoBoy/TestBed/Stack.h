#pragma once
#include "LinkedList.h"

template <class T>
class Stack :
    public LinkedList<T>
{
public:
    void Push(T data) {
        Node<T>* node = new Node<T>(data);
        node->AddNode(LinkedList<T>::head);
        LinkedList<T>::head = node;
        LinkedList<T>::length++;
    }

    T Pop() {
        T retVal = LinkedList<T>::head->obj;
        Node<T>* temp = LinkedList<T>::head;
        LinkedList<T>::head = LinkedList<T>::head->GetNextNode();
        delete temp;
        LinkedList<T>::length--;
        return retVal;
    }

    T Peek() {
        return LinkedList<T>::head->obj;
    }
};

