#pragma once
#include "Node.h"

template <class T>
class LinkedList
{
public:
	LinkedList() {
		head = nullptr;
	}
	void AddElement(T value) {
		length++;
		if (head == nullptr) {
			head = new Node<T>(value);
		}
		else {
			Node<T>* ptr = head;
			while (ptr->GetNextNode() != nullptr) {
				ptr = ptr->GetNextNode();
			}
			ptr->AddNode(new Node<T>(value));
		}
	}

	void AddElement(int index, T value)
	{
		if (head == nullptr)
		{
			head = new Node<T>(value);
		}
		else
		{
			if (index == 0)
			{
				Node<T>* node = new Node<T>(value);
				node->AddNode(head);
				head = node;
			}
			else
			{
				Node <T>* ptr = head;
				for (int i = 0; i == index - 1; i++)
				{
					ptr = ptr->GetNextNode();
				}
				Node <T>* aux = ptr->GetNextNode();
				ptr->AddNode(new Node <T>(value));
				ptr->GetNextNode()->AddNode(aux);
			}
		}
		length++;
	}

	T GetElement(int index) {
		int i = 0;
		for(Node<T>* ptr = head; ptr != nullptr; ptr = ptr->GetNextNode())
		{
			if (i == index)
				return ptr->obj;
			++i;
		}
		return T();
	}

	void DeleteElement(T element) {
		Node<T>* aux = nullptr;
		for (Node<T>* ptr = head; ptr != nullptr; ptr = ptr->GetNextNode())
		{
			if (ptr->obj == element) {
				if (ptr == head) {
					head = ptr->GetNextNode();
					delete ptr;
					length--;
					return;
				}
				else {
					aux->AddNode(ptr->GetNextNode());
					delete ptr;
					length--;
					return;
				}
			}
			aux = ptr;
		}
	}

	void DeleteElements(T element) {
		Node<T>* aux = nullptr;
		for (Node<T>* ptr = head; ptr != nullptr;)
		{
			if (ptr->obj == element) {
				if (ptr == head) {
					head = ptr->GetNextNode();
					delete ptr;
					ptr = head;
					length--;
					continue;
				}
				else {
					aux->AddNode(ptr->GetNextNode());
					delete ptr;
					ptr = aux;
					length--;
				}
			}
			aux = ptr;
			ptr = ptr->GetNextNode();
		}
	}

	bool Exists(T searchElement) {
		for (Node<T>* ptr = head; ptr != nullptr; ptr = ptr->GetNextNode()) {
			if (ptr->obj == searchElement) {
				return true;
			}
		}
		return false;
	}

	void ReverseList() {
		Node<T>** auxArr = new Node<T>*[Count()];
		int i = 0;
		for (Node<T>* aux = head; aux != nullptr; aux = aux->GetNextNode()) {
			auxArr[i++] = aux;
		}
		for (i = Count()-1; i >= 0; --i) {
			if (i == 0) {
				auxArr[i]->AddNode(nullptr);
			} else {
				auxArr[i]->AddNode(auxArr[i - 1]);
			}
		}
		head = auxArr[Count() - 1];
	}

	void DeleteElement(size_t index) {
		if (index >= length)
			return;
		Node<T>* aux = nullptr;
		Node<T>* aux2 = nullptr;
		if (index == 0) {
			aux = head->GetNextNode();
			delete head;
			head = aux;
			length--;
			return;
		}
		else {
			aux = head;
			for (int i = 0; i <= index; ++i) {
				if (i + 1 == index) {
					aux2 = aux;
				}
				else if (i == index) {
					aux2->AddNode(aux->GetNextNode());
					delete aux;
					length--;
					return;
				}
				aux = aux->GetNextNode();
			}
		}
	}

	int Count() {
		return length;
	}

	Node<T>* GetHead() {
		return head;
	}

	Node<T>* head;
protected:
	int length = 0;
};

