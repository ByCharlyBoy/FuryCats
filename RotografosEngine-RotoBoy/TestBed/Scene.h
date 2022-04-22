#pragma once
class Scene
{
public:
	Scene();
	~Scene();
	virtual void Start();
	virtual void Update();
	virtual void OnEnd();
	bool hasStarted = false;
};

