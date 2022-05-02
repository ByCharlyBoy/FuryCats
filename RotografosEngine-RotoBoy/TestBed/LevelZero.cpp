#include "LevelZero.h"
#include <iostream>
#include "App.h"
#include "InputManager.h"


LevelZero::LevelZero() 
{
	cat = new GameObject("FuryCats/Cat_rainbow.png");
	ratX = new GameObject("FuryCats/Rat.png"); 
	ratY = new GameObject("FuryCats/Rat.png"); 
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
	ratX->CreateCollider(Square); 
	ratX->SetPos(750, App::GetHeight() - 250); 
	//----------------------------------------
	ratY->CreateCollider(Square);
	ratY->SetPos(750, App::GetHeight() - 250);
	//---------------------------------------
	podadora->CreateCollider(Square); 
	podadora->SetPos(650, App::GetHeight() - 600); 

	inGame = true; 
	score = 0; 
}

void LevelZero::Update(float deltaTime) //set pos
{
	Scene::Update(deltaTime); 
	
	//moviemnto del personaje desde el update
	move_Player();
	cat->Update();


	timer += deltaTime; 
	//std::cout << timer <<std::endl; 

	//rata en X
	move_RatX();
	ratX->Update();

	//rata en Y
	move_RatY(); 
	ratY->Update(); 
	
	//podadora en X
	move_ObstacleX(); 
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

	if (catmovementX == 0 && catmovementY == 0)
	{

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
	cat->Move(catmovementX, catmovementY);

}

void LevelZero::move_ObstacleX() //mov del obstaculo
{
	std::cout << (podadora->GetPos()->x + podadora->GetPos()->w >= App::GetWidth()) << std::endl;
	if (podadora->GetPos()->x + podadora->GetPos()->w >= App::GetWidth())
	{
		podmovementX = -podspeedx; //limite derecha
		std::cout << " porfi jala" << std::endl;
	}
	else if (ratX->GetPos()->x <= 0)
	{
		podmovementX = podspeedx; //limite izquierda
	}

	if (podadora->GetPos()->x + podadora->GetPos()->w >= App::GetWidth())
		podadora->SetX(App::GetWidth() - podadora->GetPos()->w - 10);
	if (podadora->GetPos()->y + podadora->GetPos()->h >= App::GetHeight())
		podadora->SetY(App::GetHeight() - podadora->GetPos()->h);
	if (podadora->GetPos()->x <= 0)
		podadora->SetX(0);
	if (podadora->GetPos()->y <= 0)
		podadora->SetY(0);
	podadora->MoveX(podmovementX);
}

void LevelZero::move_ObstacleY() //en caso de necsitarlo (no lo creo)
{

}


void LevelZero::move_RatX()
{
	std::cout << (ratX->GetPos()->x + ratX->GetPos()->w >= App::GetWidth()) << std::endl;
	if (ratX->GetPos()->x + ratX->GetPos()->w >= App::GetWidth())
	{
		ratmovementX = -ratspeedx; //limite derecha
		std::cout << " porfi jala" << std::endl;
	}
	else if (ratX->GetPos()->x <= 0)
	{
		ratmovementX = ratspeedx; //limite izquierda
	}

	if (ratX->GetPos()->x + ratX->GetPos()->w >= App::GetWidth())
		ratX->SetX(App::GetWidth() - ratX->GetPos()->w - 10);
	if (ratX->GetPos()->y + ratX->GetPos()->h >= App::GetHeight())
		ratX->SetY(App::GetHeight() - ratX->GetPos()->h);
	if (ratX->GetPos()->x <= 0)
		ratX->SetX(0);
	if (ratX->GetPos()->y <= 0)
		ratX->SetY(0);
	ratX->MoveX(ratmovementX); 
	
}

void LevelZero::move_RatY()
{
	std::cout << (ratY->GetPos()->y + ratY->GetPos()->h >= App::GetHeight()) << std::endl;
	if (ratY->GetPos()->y + ratY->GetPos()->h >= App::GetHeight())
	{
		ratmovementY = -ratspeedy;  
	}
	else if (ratY->GetPos()->y <=0)
	{
		ratmovementY = ratspeedy; 
	}

	if (ratY->GetPos()->y + ratY->GetPos()->h >= App::GetHeight())
		ratY->SetY(App::GetHeight() - ratY->GetPos()->h - 10);
	if (ratY->GetPos()->y + ratY->GetPos()->w >= App::GetWidth())
		ratY->SetX(App::GetWidth() - ratY->GetPos()->w);
	if (ratY->GetPos()->y <= 0)
		ratY->SetY(0); 
	if (ratX->GetPos()->y <= 0)
		ratX->SetX(0);
	ratY->MoveY(ratmovementY); 	
}

int LevelZero::AddPoints(int player_points, int ia_points)
{
	return player_points + ia_points; 

}

void LevelZero::OnEnd()
{
	Scene::OnEnd(); 
	delete ratX; 
	delete ratY; 
	delete cat; 
	delete podadora; 
	delete arrastahojas; 
}



