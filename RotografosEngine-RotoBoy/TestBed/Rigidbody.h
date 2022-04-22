#pragma once
#include <SDL.h>
#include "Vector.h"
#include "World.h"

class GameObject;

class Rigidbody
{
public:
	Rigidbody(GameObject* parent);
	~Rigidbody();
	void Update(float deltaTime);
	void SetVelocity(RotografosEngine::Vector<2> _velocity);
	void SetAcceleration(RotografosEngine::Vector<2> _acceleration);
	void SetGravityInfluence(float influence);
	void SetDrag(float drag);
	void SetWeight(float weight);
	void SetKinematic(bool isKinematic);
	void SetBounce(float bounce);
	RotografosEngine::Vector<2> GetVelocity();
	RotografosEngine::Vector<2> GetAcceleration();
	float GetGravityInfluence();
	float GetDrag();
	float GetWeight();
	float GetBounce(); 
	bool IsKinematic();
	void AddForce(RotografosEngine::Vector<2> force); 
	

private:
	bool FloatIsNearValue(float val, float appVal, float diff);
	float _gravityInfluence = 1; //(0,1)
	float _drag = 0.5F; //friccion 
	float _weight = 1; //masa
	float _bounce; //va de (0, inf) 
	RotografosEngine::Vector<2>* _velocity; 
	RotografosEngine::Vector<2>* _acceleration;
	bool _isKinematic; 
	GameObject* parentGameObject; 



};

