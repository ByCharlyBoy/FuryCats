#include "World.h"
#include <iostream>
#include "GameObject.h"
#include "Vector.h"

float World::Gravity = 9.8f; 
std::vector<GameObject*> World::registeredObject;

void World::Update(float deltaTime)
{
	for (auto i = registeredObject.begin();
		i != registeredObject.end(); ++i)
	{
		(*i)->GetRigidbody()->Update(deltaTime);
		for (auto j = registeredObject.begin(); j != registeredObject.end(); ++j)
		{
			if (i == j)
			    continue; 
			if ((*i)->GetCollider()->IsCollinding((*j)->GetCollider()))
			{
				if ((*i)->GetCollider()->IsCollinding((*j)->GetCollider()))
				{
					RotografosEngine::Vector<2> displacement({ (float)(*j)->GetPos()->x - (*i)->GetPos()->x,
						(float)(*j)->GetPos()->y - (*i)->GetPos()->y });

					if (!(*i)->GetRigidbody()->IsKinematic() && !(*j)->GetRigidbody()->IsKinematic())
					{
						displacement.Mult(.5f); 
						(*j)->Move(displacement.GetComponent(0, 0), displacement.GetComponent(1, 0));
						displacement.Mult(-1); 
						(*i)->Move(displacement.GetComponent(0, 0), displacement.GetComponent(1, 0));

						RotografosEngine::Vector<2> forcel({ 
							(*i)->GetRigidbody()->GetVelocity().GetComponent(0,0) * (*i)->GetRigidbody()->GetWeight(),
							(*i)->GetRigidbody()->GetVelocity().GetComponent(1,0) * (*i)->GetRigidbody()->GetWeight()});

						RotografosEngine::Vector<2> force2({
							(*i)->GetRigidbody()->GetVelocity().GetComponent(0,0) * (*i)->GetRigidbody()->GetWeight(),
							(*i)->GetRigidbody()->GetVelocity().GetComponent(1,0) * (*i)->GetRigidbody()->GetWeight() });

						RotografosEngine::Vector<2> forceRes({
							forcel.GetComponent(0,0) + force2.GetComponent(0,0),
							forcel.GetComponent(1,0) + force2.GetComponent(1,0)
						});

						RotografosEngine::Vector<2> forceRes2({
							forcel.GetComponent(0,0) - force2.GetComponent(0,0),
							forcel.GetComponent(1,0) - force2.GetComponent(1,0)
						});

						(*i)->GetRigidbody()->AddForce(forceRes2); 
						(*i)->GetRigidbody()->AddForce(forceRes);
					}

					else if (!(*i)->GetRigidbody()->IsKinematic() && (*j)->GetRigidbody()->IsKinematic())
					{
						displacement.Mult(-1);
						(*i)->Move(displacement.GetComponent(0, 0), displacement.GetComponent(1, 0));
						auto vel = (*i)->GetRigidbody()->GetVelocity(); 
						vel.Mult(-1 * ((*i)->GetRigidbody()->GetBounce())); 
						(*i)->GetRigidbody()->SetVelocity(vel); 
					}

					else 
					{
						displacement.Mult(.5f);
						(*j)->Move(displacement.GetComponent(0, 0), displacement.GetComponent(1, 0));
						displacement.Mult(-1);
						(*i)->Move(displacement.GetComponent(0, 0), displacement.GetComponent(1, 0));
					}
				}
			}
		
		}
	}
}

void World::RegisterObject(GameObject* obj)
{
	registeredObject.push_back(obj);
}

void World::UnregisterObject(GameObject* obj)
{
	auto res = std::find(registeredObject.begin(),
		registeredObject.end(), obj);
	if (res != registeredObject.end())
		registeredObject.erase(res); 
}
