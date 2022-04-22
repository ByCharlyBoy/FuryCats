#include "RectangleCollider.h"
#include "CircleCollider.h"

RectangleCollider::RectangleCollider(int maxX, int maxY, int minX, int minY)
{
	
	_type = Square; 

	topLimit[0] = maxX; 
	topLimit[1] = maxY; 
	UpdatePosition(minX, minY); 

}

RectangleCollider::~RectangleCollider()
{
}

bool RectangleCollider::IsCollinding(Collider *other)
{
	if (other->Type() == Square)
	{
		RectangleCollider* o = (RectangleCollider*)other;
		if 
			(position->GetComponent(0, 0) + topLimit[0] >= o->position->GetComponent(0, 0) &&
			position->GetComponent(0, 0) <= o->position->GetComponent(0, 0) + o->topLimit[0] &&
			position->GetComponent(1, 0) + topLimit[1] >= o->position->GetComponent(1, 0) &&
			position->GetComponent(1, 0) <= o->position->GetComponent(1, 0) + o->topLimit[1])
		{
			return true;
		}
		return false;
	}

	else if (other->Type() == Circle)
	{
		CircleCollider* o = (CircleCollider*)other;
		if
			(position->GetComponent(0, 0) + topLimit[0] >= o->position->GetComponent(0, 0) - o->GetRadius() &&
			position->GetComponent(0, 0) <= o->position->GetComponent(0, 0) + o->GetRadius() &&

			position->GetComponent(1, 0) + topLimit[1] >= o->position->GetComponent(1, 0) &&
			position->GetComponent(1, 0) <= o->position->GetComponent(1, 0) + o->GetRadius())
		{
			return true;
		}
		return false;
	}
	
}

bool RectangleCollider::PointInside(int x, int y)
{
	if (IsInRange (x, position->GetComponent(0, 0), topLimit[0]) && IsInRange(y, position->GetComponent(1, 0), topLimit[1]))
	{
		return true; 
	}
	return false;
}

bool RectangleCollider::IsInRange(int value, int min, int max)
{
	if (value <= max && value >= min)
		return true; 

	return false;
}
