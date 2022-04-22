#pragma once

template <class T>
class DNode
{
public:
	DNode(T object) {
		obj = object;
	}
	void SetNextNode(DNode<T>* nextNode) {
		_nextNode = nextNode;
	}
	void SetLastNode(DNode<T>* lastNode) {
		_lastNode = lastNode;
	}
	void DeleteReferenceToNextNode() {
		_nextNode = nullptr;
	}
	void DeleteReferenceToLastNode() {
		_lastNode = nullptr;
	}
	DNode<T>* GetNextNode() {
		return _nextNode;
	}
	DNode<T>* GetLastNode() {
		return _lastNode;
	}
	T obj;
private:
	DNode<T>* _nextNode = nullptr;
	DNode<T>* _lastNode = nullptr;
};

