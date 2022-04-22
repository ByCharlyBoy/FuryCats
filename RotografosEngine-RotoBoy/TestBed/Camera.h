#pragma once
#include "Vector.h"
class Camera
{
public:
	Camera();
	~Camera();
	void SetPos(int x, int y);
	void MoveX(int x);
	void MoveY(int y);
	void ResetPosX();
	RotografosEngine::Vector<2> GetPos();

private:
	RotografosEngine::Vector<2> *position; 

};

