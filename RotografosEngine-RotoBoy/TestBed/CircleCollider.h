#pragma once
#include "Collider.h"
class CircleCollider :
    public Collider
{
public:

    float radius; 
    CircleCollider(int x, int y, float radio);
    ~CircleCollider();
    bool IsCollinding(Collider *other);
    bool PointInside(int x, int y);
    float GetRadius();
    ColliderType circleCollider;

    //int x = 0; // point position
    //int y = 0; 
    //float radio; 
    
};

