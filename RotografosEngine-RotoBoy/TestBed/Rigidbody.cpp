#include "Rigidbody.h"
#include "GameObject.h"

Rigidbody::Rigidbody(GameObject* parent)
{
	_velocity = new RotografosEngine::Vector<2>({ 0,0 });
	_acceleration = new RotografosEngine::Vector<2>({ 0,0 });
	parentGameObject = parent; 
}

Rigidbody::~Rigidbody()
{
	delete _velocity;
	delete _acceleration;
}

void Rigidbody::Update(float deltaTime)  //va a ser afectado por la gravedad, indica como se movera, a menos que le digamos que no
{
	parentGameObject->Move((int)round(_velocity->GetComponent(0, 0) * deltaTime), 
		(int)round(_velocity->GetComponent(1, 0) * deltaTime));
	_velocity->SetComponent(0, 0,
		_velocity->GetComponent(0, 0) * (_acceleration->GetComponent(0, 0) * deltaTime)); 
	_velocity->SetComponent(1, 0,
		_velocity->GetComponent(1, 0) * (_acceleration->GetComponent(1, 0) * deltaTime));

	if (!FloatIsNearValue (_velocity->GetComponent(0,0), 0, 0.3f))
		_acceleration->SetComponent(0, 0,
		_acceleration->GetComponent(0, 0) * (_drag * _weight * deltaTime));
	else
	{
		_velocity->SetComponent(0, 0, 0);
		_acceleration->SetComponent(0,0,0); 
	}

	_acceleration->SetComponent(1, 0,
		(_acceleration->GetComponent(1, 0) * (_drag* _weight * deltaTime)) +
		World::Gravity * _gravityInfluence * deltaTime);

	if (_velocity->GetComponent(1, 0) <= -42)
		_velocity->SetComponent(1, 0, -42);
	if (_acceleration->GetComponent(1, 0) <= World::Gravity)
		_acceleration->SetComponent(1, 0, World::Gravity); 
}


void Rigidbody::SetVelocity(RotografosEngine::Vector<2> velocity)
{
	_velocity->SetComponent(0, 0, velocity.GetComponent(0, 0)); 
	_velocity->SetComponent(1, 0, velocity.GetComponent(1, 0));
}

void Rigidbody::SetAcceleration(RotografosEngine::Vector<2> acceleration)
{
	_acceleration->SetComponent(0, 0, acceleration.GetComponent(0, 0));
	_acceleration->SetComponent(1, 0, acceleration.GetComponent(1, 0));
}

void Rigidbody::SetGravityInfluence(float influence)
{
	_gravityInfluence = influence;
}

void Rigidbody::SetDrag(float drag)
{
	_drag = drag;
}

void Rigidbody::SetWeight(float weight)
{
	_weight = weight;
}

void Rigidbody::SetKinematic(bool isKinematic)
{
	_isKinematic = isKinematic; 
}

void Rigidbody::SetBounce(float bounce)
{
	_bounce = bounce; 
}

RotografosEngine::Vector<2> Rigidbody::GetVelocity()
{
	return *_velocity;
}

RotografosEngine::Vector<2> Rigidbody::GetAcceleration()
{
	return *_acceleration;
}

float Rigidbody::GetGravityInfluence()
{
	return 0.0f;
}

float Rigidbody::GetDrag()
{
	return _drag;
}

float Rigidbody::GetWeight()
{
	return _weight;
}

float Rigidbody::GetBounce()
{
	return _bounce;
}

bool Rigidbody::IsKinematic()
{
	return _isKinematic;
}

void Rigidbody::AddForce(RotografosEngine::Vector<2> force)
{

	//a= f / m; 
	_acceleration->SetComponent(0,0, force.GetComponent(0,0) / _weight );
	_acceleration->SetComponent(1, 0, force.GetComponent(1, 0) / _weight);
}

bool Rigidbody::FloatIsNearValue(float val, float appVal, float diff)
{
	return (val <= appVal + diff && val >= appVal - diff);
}
