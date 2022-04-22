#pragma once

template <class T>
class Node
{
public:
	Node(T object) {
		obj = object;
	}
	void AddNode(Node<T>* nextNode) {
		_nextNode = nextNode;
	}
	void DeleteReferenceToNode() {
		_nextNode = nullptr;
	}
	Node<T>* GetNextNode() {
		return _nextNode;
	}

	T obj;
private:
	Node<T>* _nextNode = nullptr;
};

