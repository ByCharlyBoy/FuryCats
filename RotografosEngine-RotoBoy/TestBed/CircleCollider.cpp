#include "CircleCollider.h"
#include "RectangleCollider.h"

CircleCollider::CircleCollider(int x, int y, float radio)	//alcance del archivo
{
	//this->x = x; //circulo posicion central 
	//this->y = y;
	//this->radio = radio; // radio del circulo 

	_type = ColliderType::Circle;  
	radius = radio; 
	UpdatePosition(x, y); //lo estamos llamando del collider

}

CircleCollider::~CircleCollider()
{

}

bool CircleCollider::IsCollinding(Collider *other)
{
	CircleCollider* o = (CircleCollider*)other;
	float distanciaX = this->position->GetComponent(0, 0) - o->position->GetComponent(0, 0);
	float distanciaY = this->position->GetComponent(1, 0) - o->position->GetComponent(1, 0);
	float distance = sqrt((distanciaX * distanciaX) //funcion matematica para la raiz cuadrada
		+ (distanciaY * distanciaY));

	if (other->Type() == Circle)
	{

		if (distance <= radius + o-> radius)
		{
			return true; //dentro del circulo
		}
		return false; //fuera del circulo

	}
	else if (other->Type() == Circle)
	{
		RectangleCollider* o = (RectangleCollider*)other;
		if
			(position->GetComponent(0, 0) + o->topLimit[0] >= this->position->GetComponent(0, 0) - GetRadius() &&
				position->GetComponent(0, 0) <= o->position->GetComponent(0, 0) + - GetRadius() &&

				position->GetComponent(1, 0) + o->topLimit[1] >= this->position->GetComponent(1, 0) &&
				position->GetComponent(1, 0) <= this->position->GetComponent(1, 0) + - GetRadius())
		{
			return true;
		}
		return false;
	}

}

bool CircleCollider::PointInside(int x, int y) //Que es lo que hace? 
{

	float distanciaX = this->position->GetComponent(0, 0) - x;
	float distanciaY = this->position->GetComponent(1, 0) - y;
	float distance = sqrt((distanciaX * distanciaX) //funcion matematica para la raiz cuadrada
		+ (distanciaY * distanciaY));


	if (distance <= radius)
	{
		return true; //dentro del circulo
	}
	return false; //fuera del circulo

} // f(x) point inside 

float CircleCollider::GetRadius()
{
	return radius;
}
