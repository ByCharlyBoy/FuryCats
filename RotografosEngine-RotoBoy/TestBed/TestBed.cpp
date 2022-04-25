// TestBed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(2:4235)
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL_main.h>
#include <string>
#include "Stack.h"
#include "App.h"
#include "Node.h"
#include "DLinkedList.h"
#include "GraphNode.h"
#include "Scene1.h"
#include "CircleCollider.h"
#include "RectangleCollider.h"
#include "Pong.h"
#include "LevelZero.h"


using namespace std;

template <class T>
void ReverseList2(LinkedList<T>* ll) {
    Stack<Node<T>*> stack;
    for (Node<T>* aux = ll->head; aux != nullptr; aux = aux->GetNextNode()) {
        stack.Push(aux);
    }
    ll->head = stack.Pop();
    Node<T>* aux = ll->head;
    while (stack.Count() > 0) {
        aux->AddNode(stack.Pop());
        aux = aux->GetNextNode();
    }
    aux->AddNode(nullptr);
}

struct Calle {
    int longitud;
    string nombre;
};

std::string FindPath(GraphNode<Calle>* start, GraphNode<Calle>* end) {
    Stack<GraphNode<Calle>*> calles_recorridas;
    LinkedList<GraphNode<Calle>*> calles_que_no_sirven;
    std::string endPath = "";
    calles_recorridas.Push(end);
    while (calles_recorridas.Peek() != start) {
        GraphNode<Calle>* helper = nullptr;
        for (int i = 0; i < calles_recorridas.Peek()->linkedNodes.Count(); ++i) {
            //linkedNodes[i]
            if (calles_recorridas.Exists(calles_recorridas.Peek()->linkedNodes.GetElement(i)) ||
                calles_que_no_sirven.Exists(calles_recorridas.Peek()->linkedNodes.GetElement(i))) {
                continue;
            }
            helper = calles_recorridas.Peek()->linkedNodes.GetElement(i);
            break;
        }
        if (helper == nullptr && calles_recorridas.Count() <= 1) { //No podemos llegar al destino
            endPath = "Destino no encontrado";
            return endPath;
        }
        if (helper == nullptr && calles_recorridas.Count() > 1) { //La calle no nos sirve
            calles_que_no_sirven.AddElement(calles_recorridas.Pop());
            continue;
        }
        calles_recorridas.Push(helper);
    }
    while (calles_recorridas.Count() > 0) {
        GraphNode<Calle>* helper = calles_recorridas.Pop();
        endPath += helper->obj.nombre + (calles_recorridas.Count() > 0 ? "<-" : "");
    }
    return endPath;
}

int main(int argc, char** argv)
{
    //GraphNode<Calle>* calle1 = new GraphNode<Calle>({ 200, "la chingada" });
    //GraphNode<Calle>* calle2 = new GraphNode<Calle>({ 500, "zapata" });
    //GraphNode<Calle>* calle3 = new GraphNode<Calle>({ 1000, "gurigus" });
    //GraphNode<Calle>* calle4 = new GraphNode<Calle>({ 700, "viejo" });
    //GraphNode<Calle>* calle5 = new GraphNode<Calle>({ 1800, "zapato" });
    //calle1->LinkNode(calle3);
    //calle1->LinkNode(calle4);
    //calle2->LinkNode(calle1);
    //calle3->LinkNode(calle5);
    //calle4->LinkNode(calle5);
    //calle4->LinkNode(calle3);
    //calle5->LinkNode(calle2);

    //std::cout << FindPath(calle1, calle1);
    CircleCollider circle(320, 330, 10);
    std::cout << circle.PointInside(320, 330);

    App::StartApp(1280, 720, new LevelZero());

     

    return 0; 
}
