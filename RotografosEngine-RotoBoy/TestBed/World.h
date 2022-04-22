#pragma once
#include <SDL.h>
#include <vector>

class GameObject;

class World
{
public:
	static float Gravity; 
	static void Update(float deltaTime); 
	static void RegisterObject(GameObject* obj);
	static void UnregisterObject(GameObject* obj); 

private: 
	static std::vector<GameObject*> registeredObject; 
};

