#pragma once
#include "DNode.h"

template <class T>
class DLinkedList
{
public:
	DLinkedList() {
		head = nullptr;
	}
	void AddElement(T value) {
		length++;
		if (head == nullptr) {
			head = new DNode<T>(value);
		}
		else {
			DNode<T>* ptr = head;
			while (ptr->GetNextNode() != nullptr) {
				ptr = ptr->GetNextNode();
			}
			ptr->SetNextNode(new DNode<T>(value));
			ptr->GetNextNode()->SetLastNode(ptr);
			tail = ptr->GetNextNode();
		}
	}

	void AddElement(int index, T element) {
		if (head == nullptr)
		{
			head = new DNode<T>(element);
			tail = head;
		}
		else
		{
			if (index == 0)
			{
				DNode<T>* node = new DNode<T>(element);
				node->SetNextNode(head);
				head->SetLastNode(node);
				head = node;
			}
			else if (index == length - 1) {
				DNode<T>* node = new DNode<T>(element);
				node->SetLastNode(tail);
				tail->SetNextNode(node);
				tail = node;
			}
			else
			{
				DNode <T>* ptr = head;
				for (int i = 0; i == index; i++)
				{
					ptr = ptr->GetNextNode();
				}
				DNode<T>* node = new DNode<T>(element);
				ptr->GetLastNode()->SetNextNode(node);
				node->SetLastNode(ptr->GetLastNode());
				ptr->SetLastNode(node);
				node->SetNextNode(ptr);
			}
		}
		length++;
	}

	T GetElement(int index) {
		int i = 0;
		for (DNode<T>* ptr = head; ptr != nullptr; ptr = ptr->GetNextNode())
		{
			if (i == index)
				return ptr->obj;
			++i;
		}
		return T();
	}

	void ClearList() {
		while (head != nullptr) {
			DNode<T>* aux = head->GetNextNode();
			delete head;
			head = aux;
		}
		length = 0;
	}

	void ReverseList() {
		DNode<T>* auxHead = head;
		for (DNode<T>* iterator = tail; iterator->GetLastNode() != nullptr; iterator = iterator->GetNextNode()) {
			DNode<T>* aux = iterator->GetNextNode();
			iterator->SetNextNode(iterator->GetLastNode());
			iterator->SetLastNode(aux);
		}
		head = tail;
		tail = auxHead;
	}

	void DeleteElements(T element) {
		DNode<T>* aux = nullptr;
		for (DNode<T>* ptr = head; ptr != nullptr;)
		{
			if (ptr->obj == element) {
				if (ptr == head) {
					head = ptr->GetNextNode();
					head->SetLastNode(nullptr);
					delete ptr;
					ptr = head;
					length--;
					continue;
				}
				else if (ptr == tail) {
					tail = ptr->GetLastNode();
					tail->SetNextNode(nullptr);
					delete ptr;
					ptr = tail;
					length--;
					continue;
				}
				else {
					ptr->GetLastNode()->SetNextNode(ptr->GetNextNode());
					if (ptr->GetNextNode() != nullptr)
						ptr->GetNextNode()->SetLastNode(ptr->SetLastNode());
					delete ptr;
					length--;
				}
			}
			ptr = ptr->GetNextNode();
		}
	}
	
	void DeleteElement(T element) {
		for (DNode<T>* ptr = head; ptr != nullptr; ptr = ptr->GetNextNode())
		{
			if (ptr->obj == element) {
				if (ptr == head) {
					head = ptr->GetNextNode();
					head->SetLastNode(nullptr);
					delete ptr;
					length--;
					return;
				}
				else if (ptr == tail) {
					tail = tail->GetLastNode();
					tail->SetNextNode(nullptr);
					delete ptr;
					length--;
					return;
				}
				else {
					ptr->GetLastNode()->SetNextNode(ptr->GetNextNode());
					if(ptr->GetNextNode() != nullptr)
						ptr->GetNextNode()->SetLastNode(ptr->SetLastNode());
					delete ptr;
					length--;
					return;
				}
			}
		}
	}

	void DeleteElement(size_t index) {
		if (index >= length)
			return;
		DNode<T>* aux = nullptr;
		if (index == 0) {
			aux = head->GetNextNode();
			delete head;
			head = aux;
			head->SetLastNode(nullptr);
			length--;
			return;
		}
		else if (index == length - 1) {
			aux = tail->GetLastNode();
			delete tail;
			tail = aux;
			tail->SetNextNode(nullptr);
			length--;
			return;
		}
		else {
			aux = head;
			for (int i = 0; i <= index; ++i) {
				if (i == index) {
					aux->GetLastNode()->SetNextNode(aux->GetNextNode());
					if (aux->GetNextNode() != nullptr)
						aux->GetNextNode()->SetLastNode(aux->SetLastNode());
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

	DNode<T>* head;
	DNode<T>* tail;
protected:
	int length = 0;
};

