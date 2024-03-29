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
	void move_Arras(); 
	void move_RatX();
	void move_RatY(); 
	int AddPoints(int player_points, int ia_points); 
	void OnEnd(); 

	//constantes
	enum cons
	{
		NUM_RATS_X = 6,
		NUM_RATS_Y = 4,
		NUM_PODS = 2,
		NUM_ARRAS = 2
	}; 
	

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
	GameObject* jardin; 
	GameObject* ratX[NUM_RATS_X]; //cantidad de ratas[3]
	GameObject* ratY[NUM_RATS_Y]; 
	GameObject* cat; 
	GameObject* podadora[NUM_PODS];
	GameObject* podadoraY;
	GameObject* arrastahojas[NUM_ARRAS]; 
	GameObject* prequelScene; 
	bool prequeleScene = false; 
	bool sceneStarting = true;


	//speed movimento teclas
	int catspeedx = 5; 
	int catspeedy = 5; 

	int catmovementX = 0;
	int catmovementY = 0; 

	bool touchingX = false;
	bool touchingmX = false;
	bool touchingY = false;
	bool touchingmY = false;

	int ratspeedx = 8; 
	int ratspeedy = 8;

	int ratmovementX[NUM_RATS_X]; 
	int ratmovementY[NUM_RATS_Y]; 

	int podspeedx = 5; 
	int podmovementX[NUM_PODS];

	/*int arrastraspeedy = 5; 
	int arrastramovY[NUM_ARRAS]; */

	bool rataliveX[NUM_RATS_X];  
	bool rataliveY[NUM_RATS_Y]; 

	bool arrasalive[NUM_ARRAS]; 

	bool catalive = true; 
	
	void setPosrat(GameObject* rat, int rat_type, int minPosX, int minPosY, int maxPosX, int maxPosY);

};

