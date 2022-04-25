#pragma once
class Scene
{
public:
	Scene();
	~Scene();
	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void OnEnd();
	bool hasStarted = false;
};

