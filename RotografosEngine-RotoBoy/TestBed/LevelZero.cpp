#include "LevelZero.h"
#include <iostream>
#include "App.h"
#include "InputManager.h"


LevelZero::LevelZero() 
{
	jardin = new GameObject("FuryCats/Escena2.png"); 
	cat = new GameObject("FuryCats/Cat2.png");

	for (int i = 0; i < NUM_RATS_X; i++){
		ratX[i] = new GameObject("FuryCats/Rat2.png"); //instacia la rat 
		rataliveX[i] = true; 
		ratmovementX[i] = ratspeedx; 
		
	}
	for (int i = 0; i < NUM_RATS_Y; i++) {
		ratY[i] = new GameObject("FuryCats/Rat2.png");
		rataliveY[i] = true;
		ratmovementY[i] = ratspeedy;

	}
	for (int i = 0; i < NUM_PODS; i++)
	{
		podadora[i] = new GameObject("FuryCats/Podadora2.png");
		podmovementX[i] = podspeedx; 
	}
	for (int i = 0; i < NUM_ARRAS; i++)
	{
		arrastahojas[i] = new GameObject("FuryCats/Arras.png"); 
		arrasalive[i] = true;
		//arrastramovY[i] = arrastraspeedy; 
	}
	prequelScene = new GameObject("FuryCats/HD_FuryCats_CoverPurple.png"); 

}

LevelZero::~LevelZero() 
{

}

void LevelZero::setPosrat(GameObject* rat, int rat_type, int minPosX, int minPosY, int maxPosX, int maxPosY)
{
	int randNum, randNum2; 	
	randNum = rand() % (maxPosX - 0 + 1) + minPosX;
	randNum2 = rand() % (maxPosY - 0 + 1) + minPosY;
	rat->SetPos(randNum, randNum2);
	
}

void LevelZero::Start() 
{
	Scene::Start(); 
	cat->CreateCollider(Square); 
	cat->SetPos(0, App::GetHeight() - 100);
	//--------------------------------------
	for (int i = 0; i < NUM_RATS_X; i++) {
		ratX[i]->CreateCollider(Square); 
		setPosrat(ratX[i], 0, 1, 1, 1280, 720);
	}
	//----------------------------------------
	for (int i = 0; i < NUM_RATS_Y; i++) {
		
		ratY[i]->CreateCollider(Square);
		setPosrat(ratY[i], 0, 1, 1, 1280, 720);
	}
	//---------------------------------------
	for (int i = 0; i < NUM_PODS; i++) {
		podadora[i]->CreateCollider(Square);
		switch (i) {
		case 0:
			//podadora en la parte de arriba
			setPosrat(podadora[i], 2, 1, 1, 1280, App::GetHeight()/2 - 87);
			break;
		case 1:
			//podadora en la parte de abajo
			setPosrat(podadora[i], 2, 1, App::GetHeight() / 2, 1280, App::GetHeight() - 200);
			break;
		}
		//podadora[i]->SetPos(650, App::GetHeight() - 600);
	}
	//------------------------------------------
	for (int i = 0; i < NUM_ARRAS; i++) //****
	{
		arrastahojas[i]->CreateCollider(Square); 
		//SetPos(0, App::GetHeight() - 100);
		setPosrat(arrastahojas[i], 0, 0, 0, App::GetWidth() - 100, App::GetHeight() - 50);
	
	}
	

	inGame = true; 
	score = 0; 
}

void LevelZero::Update(float deltaTime) //set pos //moviemnto del personaje desde el update
{
	Scene::Update(deltaTime); 
	
	timer += deltaTime; 
	//std::cout << timer <<std::endl; 

	jardin->Update(); 

	for (int i = 0; i < NUM_RATS_X; i++) {
		//rata en X y parte de su collision
		if (rataliveX[i])
		{	
			ratX[i]->Update();
		}
		else 
		{
			setPosrat(ratX[i], 0, 1, 1, 1280, 720);
			rataliveX[i] = true; 
			i = i - 1; 
		}
	}

	//rata en Y y parte de su collision
	for (int i = 0; i < NUM_RATS_Y; i++) {
		if (rataliveY[i])
		{
			ratY[i]->Update();
		}
		else
		{
			setPosrat(ratY[i], 0, 1, 1, 1280, 720);
			rataliveY[i] = true; 
			i = i - 1; 
		}
	}
	//-------------------------------------------
	for (int i = 0; i < NUM_PODS; i++) {
		
		if (podadora[i] != nullptr)
			podadora[i]->Update();
	}
	
	for (int i = 0; i < NUM_ARRAS; i++) {
		if (arrastahojas[i] != nullptr)
			arrastahojas[i]->Update(); 
			 
	}

	//podadora en X y parte de su collision
	if (catalive)
	{
		move_Player(); 
		cat->Update(); 
	}

	if (InputManager::IsPressed(SDLK_SPACE))
	{
		if (prequeleScene == false)
		{
			prequeleScene = true; 
			std::cout << "New Scene"; 
		}
	}

	if (prequeleScene == false)
		prequelScene->Update(); 

	//-------------------------------------
	/*if (catalive = false || life = 0 )
	{
		
	}*/
	if (InputManager::IsReleased(SDLK_g) && !sceneStarting) {
		App::ChangeScene(new LevelZero());
		InputManager::ResetStorage();
		std::cout << "jala" << std::endl; 
	}

	move_RatX();
	move_RatY();
	move_ObstacleX();
	Player_Collide();
	sceneStarting = false;

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
	for (int i = 0; i < NUM_RATS_X; i++)
	{
		if (rataliveX[i] && cat->GetCollider()->IsCollinding(ratX[i]->GetCollider()))
		{
			//std::cout << "Comidita" << std::endl;
			rataliveX[i] = false;
			score += 10;
			std::cout << "Se sumaron 10 puntos";
			std::cout << score << std::endl;
		}
		
		/*if (cat->GetCollider() && podadora[i]->GetCollider()->IsCollinding(cat->GetCollider()))
		{
			std::cout << "Se muere" << std::endl;
			catalive = false;

		}*/
	}
	for (int i = 0; i < NUM_RATS_Y; i++)
	{
		if (rataliveY[i] && cat->GetCollider()->IsCollinding(ratY[i]->GetCollider()))
		{
			rataliveY[i] = false;
			score += 10;
			std::cout << "Se sumaron 10 puntos" << std::endl;
			std::cout << score << std::endl;
		}

		
	}
	for (int i = 0; i < NUM_PODS; i++)
	{
		if (catalive && podadora[i]->GetCollider()->IsCollinding(cat->GetCollider()))
		{
			catalive = false;
			score -= 5;
			std::cout << "Se restaron 5 puntos" << std::endl;
			std::cout << score << std::endl;

			life -= 1;
			std::cout << "Se muere" << std::endl;
			if (catalive == false && life >= 0)
			{
				 
				cat->SetPos(0, App::GetHeight() - 100);
				catalive = true;
				std::cout << "Revivido" << std::endl;

			}

		}
	}
	for (int i = 0; i < NUM_ARRAS; i++)
	{
		if (catalive && arrastahojas[i]->GetCollider()->IsCollinding(cat->GetCollider()))
		{
			score -= 5;
			std::cout << "Se restaron 3 puntos" << std::endl;
			std::cout << score << std::endl;
			catalive = false;
			life--;
			if (catalive == false && life >= 1)
			{
				cat->SetPos(0, App::GetHeight() - 100);
				catalive = true;
			}
		}


	}

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
		if (cat->GetPos()->x <= 0) {
			cat->SetX(5);
			touchingmX = true;
		}
		else if (cat->GetPos()->x >= App::GetWidth() - cat->GetPos()->w) {
			cat->SetX(App::GetWidth() - cat->GetPos()->w - 5);
			touchingX = true;
		}

		if (cat->GetPos()->y <= 0) {
			cat->SetY(5);
			touchingmY = true;
		}
		else if (cat->GetPos()->y >= App::GetHeight() - cat->GetPos()->h) {
			cat->SetY(App::GetHeight() - cat->GetPos()->h - 5);
			touchingY = true;
		}

		catmovementX = 0;
		catmovementY = 0;
	}

	if (catmovementX == 0 && catmovementY == 0)
	{

		if (InputManager::IsReleased(SDLK_q) && !touchingmX && !touchingmY)
		{
			catmovementX = -catspeedx; 
			catmovementY = -catspeedy; 
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_w) && !touchingmY)
		{
			catmovementY = -catspeedy;
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_e) && !touchingX && !touchingmY)
		{
			catmovementX = catspeedx;
			catmovementY = -catspeedy;
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_a) && !touchingmX)
		{
			catmovementX = -catspeedx;	
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_d) && !touchingX)
		{
			catmovementX = catspeedx;
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_z) && !touchingmX && !touchingY)
		{
			catmovementX = -catspeedx;
			catmovementY = catspeedy;
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_x) && !touchingY)
		{
			catmovementY = catspeedy;
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
		if (InputManager::IsReleased(SDLK_c) && !touchingX && !touchingY)
		{
			catmovementX = catspeedx;
			catmovementY = catspeedy;
			touchingX = false;
			touchingmX = false;
			touchingY = false;
			touchingmY = false;
		}
	}
	cat->Move(catmovementX, catmovementY);

}

void LevelZero::move_ObstacleX() //mov del obstaculo
{
	for (int i = 0; i < NUM_PODS; i++) {
		if (podadora[i] == nullptr)
			continue; 
		if (podadora[i]->GetPos()->x + podadora[i]->GetPos()->w >= App::GetWidth())
		{
			podmovementX[i] = -podspeedx; //limite derecha

		}
		else if (podadora[i]->GetPos()->x <= 0)
		{
			podmovementX[i] = podspeedx; //limite izquierda
		}

		if (podadora[i]->GetPos()->x + podadora[i]->GetPos()->w >= App::GetWidth())
			podadora[i]->SetX(App::GetWidth() - podadora[i]->GetPos()->w - 10);
		if (podadora[i]->GetPos()->y + podadora[i]->GetPos()->h >= App::GetHeight())
			podadora[i]->SetY(App::GetHeight() - podadora[i]->GetPos()->h);
		if (podadora[i]->GetPos()->x <= 0)
			podadora[i]->SetX(0);
		if (podadora[i]->GetPos()->y <= 0)
			podadora[i]->SetY(0);
		podadora[i]->MoveX(podmovementX[i]);
	}
	
}

void LevelZero::move_Arras() 
{
	/*for (int i = 0; i < NUM_ARRAS; i++)
	{
		if (arrastahojas[i]->GetPos()->y + arrastahojas[i]->GetPos()->h >= App::GetHeight())
			arrastahojas[i]->SetY(App::GetHeight() - arrastahojas[i]->GetPos()->h - 10);
		if (arrastahojas[i]->GetPos()->y + arrastahojas[i]->GetPos()->w >= App::GetWidth())
			arrastahojas[i]->SetX(App::GetWidth() - arrastahojas[i]->GetPos()->w);
		if (arrastahojas[i]->GetPos()->y <= 0)
			arrastahojas[i]->SetY(0);
	}*/
}


void LevelZero::move_RatX()
{
	for (int i = 0; i < NUM_RATS_X; i++) 
	{
		if (ratX[i]->GetPos()->x + ratX[i]->GetPos()->w >= App::GetWidth())
		{
			ratmovementX[i] = -ratspeedx; //limite derecha 
		}
		else if (ratX[i]->GetPos()->x <= 0)
		{
			ratmovementX[i] = ratspeedx; //limite izquierda
		}

		if (ratX[i]->GetPos()->x + ratX[i]->GetPos()->w >= App::GetWidth())
			ratX[i]->SetX(App::GetWidth() - ratX[i]->GetPos()->w - 10);
		if (ratX[i]->GetPos()->y + ratX[i]->GetPos()->h >= App::GetHeight())
			ratX[i]->SetY(App::GetHeight() - ratX[i]->GetPos()->h);
		if (ratX[i]->GetPos()->x <= 0)
			ratX[i]->SetX(0);
		if (ratX[i]->GetPos()->y <= 0)
			ratX[i]->SetY(0);
		ratX[i]->MoveX(ratmovementX[i]);
	}
	
}

void LevelZero::move_RatY()
{
	for (int i = 0; i < NUM_RATS_Y; i++)
	{
		if (ratY[i]->GetPos()->y + ratY[i]->GetPos()->h >= App::GetHeight())
		{
			ratmovementY[i] = -ratspeedy;
		}
		else if (ratY[i]->GetPos()->y <= 0)
		{
			ratmovementY[i] = ratspeedy;
		}

		if (ratY[i]->GetPos()->y + ratY[i]->GetPos()->h >= App::GetHeight())
			ratY[i]->SetY(App::GetHeight() - ratY[i]->GetPos()->h - 10);
		if (ratY[i]->GetPos()->y + ratY[i]->GetPos()->w >= App::GetWidth())
			ratY[i]->SetX(App::GetWidth() - ratY[i]->GetPos()->w);
		if (ratY[i]->GetPos()->y <= 0)
			ratY[i]->SetY(0);
		/*if (ratY[i]->GetPos()->y <= 0)
			ratY[i]->SetX(0);*/
			


		ratY[i]->MoveY(ratmovementY[i]);
	}
}
	

int LevelZero::AddPoints(int player_points, int ia_points)
{
	return player_points + ia_points; 

}

void LevelZero::OnEnd()
{
	Scene::OnEnd();
	delete jardin; 
	for(int i = 0; i < NUM_RATS_X; ++i)
		delete ratX[i];
	for(int i = 0; i < NUM_RATS_Y; ++i)
		delete ratY[i]; 
	delete cat;
	for (int i = 0; i < NUM_PODS; ++i)
		delete podadora[i]; 
	for (int i = 0; i < NUM_ARRAS; ++i)
		delete arrastahojas[i]; 
	delete prequelScene;
}





//diseno del nivel, donde vamos a poner cada cosa



