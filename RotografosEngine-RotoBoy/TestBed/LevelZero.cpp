#include "LevelZero.h"
#include <iostream>
#include "App.h"
#include "InputManager.h"


LevelZero::LevelZero() 
{
	cat = new GameObject("FuryCats/Cat_rainbow.png");
	rat = new GameObject("FuryCats/Rat.png"); 
	podadora = new GameObject("FuryCats/Podadora.png"); 
}

LevelZero::~LevelZero() 
{

}

void LevelZero::Start() 
{
	Scene::Start(); 
	cat->CreateCollider(Square); 
	cat->SetPos(0, App::GetHeight() - 300);
	//--------------------------------------
	rat->CreateCollider(Square); 
	rat->SetPos(750, App::GetHeight() - 250); 
	//---------------------------------------
	podadora->CreateCollider(Square); 
	podadora->SetPos(650, App::GetHeight() - 600); 

	inGame = true; 
	score = 0; 
}

void LevelZero::Update(float deltaTime) //set pos
{
	Scene::Update(deltaTime); 


	if (cat->GetPos()->x >= App::GetWidth() - cat->GetPos()->w || 
		cat->GetPos()->y >= App::GetHeight() - cat->GetPos()->h ||
		cat->GetPos()->x <= 0 || 
		cat->GetPos()->y <= 0)
	{
		if (cat->GetPos()->x <= 0)
			cat->SetX(5);
		else if (cat->GetPos()->x >= App::GetWidth() - cat->GetPos()->w)
			cat->SetX(App::GetWidth() - cat->GetPos()->w - 5); 

		if (cat->GetPos()->y <= 0)
			cat->SetY(5);
		else if (cat->GetPos()->y >= App::GetHeight() - cat->GetPos()->h)
			cat->SetY(App::GetHeight() - cat->GetPos()->h - 5);

		catmovementX = 0; 
		catmovementY = 0; 
	}
	move_Player();
	cat->Move(catmovementX, catmovementY); 
	cat->Update();


	timer += deltaTime; 
	std::cout << timer <<std::endl; 

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

	move_Obstacle(); 
	if (podadora->GetPos()->x >= App::GetWidth() - podadora->GetPos()->w)
		podadora->SetX(App::GetWidth() - podadora->GetPos()->w);
	if (podadora->GetPos()->y >= App::GetHeight() - podadora->GetPos()->h)
		podadora->SetY(App::GetHeight() - podadora->GetPos()->h);
	if (podadora->GetPos()->x <= 0)
		podadora->SetX(0);
	if (podadora->GetPos()->y <= 0)
		podadora->SetY(0);
	podadora->Update();
}


void LevelZero::rat_Collide() //colison de la rata
{
	//la rata(enemigo) se esfuma cuando el gao la toca
}

void LevelZero::Obstacle_Collide() //collision del obstaculo
{

}

void LevelZero::Player_Collide() //collision del jugador
{

}

void LevelZero::Timer() //tiempo
{

}

void LevelZero::Score() //marcador
{

}

void LevelZero::move_Player() //mov del jugador
{
	//que sea 1 solo gato, que al presionnar las flechitas
	//presionas a la derecha y solo a la derecha, llegas a pared a la posicion que estbas
	//  
	//(la de la derecha) se mueva de manera lineal y tope con pared
	//en ese movimeinto, que choque con la rata y la elimine 
	//el mismo caso con el obsataculo, solo que ahi morira 

	if (catmovementX != 0 || catmovementY != 0)
	{
		return; 
	}

	if (InputManager::IsReleased(SDLK_q))
	{
		catmovementX = -catspeedx; 
		catmovementY = -catspeedy; 
	}
	if (InputManager::IsReleased(SDLK_w))
	{
		catmovementY = -catspeedy;
	}
	if (InputManager::IsReleased(SDLK_e))
	{
		catmovementX = catspeedx;
		catmovementY = -catspeedy;
	}
	if (InputManager::IsReleased(SDLK_a))
	{
		catmovementX = -catspeedx;	
	}
	if (InputManager::IsReleased(SDLK_d))
	{
		catmovementX = catspeedx;
	}
	if (InputManager::IsReleased(SDLK_z))
	{
		catmovementX = -catspeedx;
		catmovementY = catspeedy;
	}
	if (InputManager::IsReleased(SDLK_x))
	{
		catmovementY = catspeedy;
	}
	if (InputManager::IsReleased(SDLK_c))
	{
		catmovementX = catspeedx;
		catmovementY = -catspeedy;
	}
}

void LevelZero::move_Obstacle() //mov del obstaculo
{

}

void LevelZero::move_Rat()
{
	
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



