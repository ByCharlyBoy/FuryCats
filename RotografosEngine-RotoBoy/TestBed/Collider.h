#pragma once
#include "Vector.h"
enum ColliderType
{
	Square = 0,
	Circle
};

class Collider
{
public:
	Collider();
	~Collider();
	virtual bool IsCollinding(Collider* other);
	virtual bool PointInside(int x, int y);
	virtual void UpdatePosition(int x, int y);
	ColliderType Type();
	RotografosEngine::Vector<2> *position;

protected:
	ColliderType _type; 
	int posx, posy; 
};