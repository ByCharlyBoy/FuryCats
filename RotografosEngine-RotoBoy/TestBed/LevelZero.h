#pragma once
#include "Scene.h" 
#include <SDL.h>
#include "GameObject.h"

class LevelZero :
	public Scene
{
public:
	LevelZero();
	~LevelZero();
	void Start();
	void Update(float deltaTime);
	void rat_Collide(); 
	void Obstacle_Collide();
	void Player_Collide(); 
	void Timer(); 
	void Score(); 
	void move_Player(); 
	void move_ObstacleX(); 
	void move_ObstacleY(); 
	void move_RatX();
	void move_RatY(); 
	int AddPoints(int player_points, int ia_points); 
	void OnEnd(); 


	

	//variables del mundo
	float timer = 0.0f; 
	bool inGame = false; 
	int score = 0; 
	//variables del jugador 
	int life = 3; 
	bool invencible = false; 
	int speed_cat = 8; 
	//variables del enemigo
	int rat_points = 5; 
	int podadora_points = -5; 
	int arrastradora_points = -3; 
	GameObject* ratX;
	GameObject* ratY; 
	GameObject* cat; 
	GameObject* podadora;
	GameObject* podadoraY;
	GameObject* arrastahojas; 


	//speed movimento teclas
	int catspeedx = 5; 
	int catspeedy = 5; 

	int catmovementX = 0;
	int catmovementY = 0; 

	int ratspeedx = 8; 
	int ratspeedy = 8;

	int ratmovementX = ratspeedx;
	int ratmovementY = ratspeedy;

	int podspeedx = 5; 
	int podmovementX = podspeedx;

	bool rataliveX = true; 
	bool rataliveY = true; 

	bool catalive = true; 
	
};

