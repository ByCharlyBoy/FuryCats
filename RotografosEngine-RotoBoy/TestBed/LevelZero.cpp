#include "LevelZero.h"
#include <iostream>
#include "App.h"
#include "InputManager.h"


LevelZero::LevelZero()
{
	rat = new GameObject("download.bmp");
}

LevelZero::~LevelZero()
{

}

void LevelZero::Start()
{
	Scene::Start(); 
	rat->CreateCollider(Square); 
	rat->SetPos(0, App::GetHeight() - 300);
	speedx = 8; 
	speedy = 8; 
	inGame = true; 
	score = 0; 
}

void LevelZero::Update(float deltaTime) //set pos
{
	Scene::Update(deltaTime); 
	move_Rat(); 

	if (rat->GetPos()->x >= App::GetWidth() - rat->GetPos()->w)
		rat->SetX(App::GetWidth() - rat->GetPos()->w);
	if (rat->GetPos()->y >= App::GetHeight() - rat->GetPos()->h)
		rat->SetY(App::GetHeight() - rat->GetPos()->h);
	if (rat->GetPos()->x <= 0)
		rat->SetX(0);
	if (rat->GetPos()->y <= 0)
		rat->SetY(0);
	rat->Update();

	timer += deltaTime; 
	std::cout << timer <<std::endl; 
}


void LevelZero::rat_Collide()
{

}

void LevelZero::Obstacle_Collide()
{

}

void LevelZero::Player_Collide()
{

}

void LevelZero::Timer()
{

}

void LevelZero::Score()
{

}

void LevelZero::move_Player()
{

}

void LevelZero::move_Obstacle()
{

}

void LevelZero::move_Rat()
{
	if (InputManager::IsHolding(SDLK_RIGHT))
	{
		rat->MoveX(speedx);
	}
	if (InputManager::IsHolding(SDLK_LEFT))
	{
		rat->MoveX(-speedx);
	}
	if (InputManager::IsHolding(SDLK_UP))
	{
		rat->MoveY(-speedy);
	}
	if (InputManager::IsHolding(SDLK_DOWN))
	{
		rat->MoveY(speedy);
	}
}

int LevelZero::AddPoints(int player_points, int ia_points)
{
	return player_points + ia_points; 

}

void LevelZero::OnEnd()
{
	Scene::OnEnd(); 
	delete rat; 
	delete cat; 
	delete podadora; 
	delete arrastahojas; 
}



