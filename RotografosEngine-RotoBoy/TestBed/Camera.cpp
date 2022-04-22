#include "Camera.h"

Camera::Camera()
{
	position = new RotografosEngine::Vector<2>({ 0,0 });
}

Camera::~Camera()
{

}

void Camera::SetPos(int x, int y)
{
	position->SetComponent(0, 0, x);
	position->SetComponent(1, 0, y); 
}

void Camera::MoveX(int x)
{
	position->SetComponent(0, 0, position->GetComponent(0, 0) + x);
}

void Camera::MoveY(int y)
{
	position->SetComponent(1, 0, position->GetComponent(1, 0) + y);
}

void Camera::ResetPosX()
{
	position->SetComponent(0, 0, 0);
	position->SetComponent(1, 0, 0);
}

RotografosEngine::Vector<2> Camera::GetPos()
{
	return *position;
}
