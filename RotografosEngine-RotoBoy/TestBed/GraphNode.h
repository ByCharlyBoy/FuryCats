#pragma once
#include "LinkedList.h"

template <class T>
class GraphNode
{
public:
	GraphNode(T object) {
		obj = object;
	}

	void LinkNode(GraphNode<T>* other) {
		linkedNodes.AddElement(other);
	}

	void DLinkNode(GraphNode<T>* other) {
		LinkNode(other);
		other->LinkNode(this);
	}

	void DelinkNode(GraphNode<T>* other) {
		linkedNodes.DeleteElement(other);
	}

	void DDelinkNode(GraphNode<T>* other) {
		DelinkNode(other);
		other->DelinkNode(this);
	}

	LinkedList<GraphNode<T>*> linkedNodes;
	T obj;
};

