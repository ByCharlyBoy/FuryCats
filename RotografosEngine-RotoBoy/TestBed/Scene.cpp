#include "Scene.h"

Scene::Scene()
{
	hasStarted = false;
}

Scene::~Scene()
{
}

void Scene::Start()
{
	hasStarted = true;
}

void Scene::Update()
{
}

void Scene::OnEnd()
{
}
