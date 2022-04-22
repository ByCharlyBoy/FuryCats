#include "Collider.h"

Collider::Collider()
{
	position = new RotografosEngine::Vector<2>(std::vector<float>{0, 0});
}

Collider::~Collider()
{
}

bool Collider::IsCollinding(Collider* other)
{
	return false;
}

bool Collider::PointInside(int x, int y)
{
	return false;
}

void Collider::UpdatePosition(int x, int y)
{
	position->SetComponent(0, 0, x); 
	position->SetComponent(1, 0, y);
}

ColliderType Collider::Type()
{
	return _type;
}

// NO SE TOCA xD