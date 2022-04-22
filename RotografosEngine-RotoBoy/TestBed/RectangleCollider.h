#pragma once
#include "Collider.h"
class RectangleCollider :
    public Collider
{
public:

    RectangleCollider(int maxX, int maxY, int minX, int minY);
    ~RectangleCollider();
    bool IsCollinding(Collider *other);
    bool PointInside(int x, int y);
    int topLimit[2];
  
    
private:    
    bool IsInRange(int value, int min, int max); 

};

