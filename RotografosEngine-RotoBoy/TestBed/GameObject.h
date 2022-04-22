#pragma once
#include <string>
#include <SDL.h>
#include <vector>
#include "Collider.h"
#include "Rigidbody.h"

class GameObject
{
public:
	GameObject();
	GameObject(std::string imgName);
	void CreateSprite(std::string imgName);
	void DeleteSprite(int spriteIndex);
	void CreateRigidbody(); 
	Rigidbody* GetRigidbody();
	virtual void Start();
	virtual void Update();
	void SetX(int x);
	void SetY(int y);
	void SetUpdateRate(int rate); 
	void SetPos(int x, int y);
	SDL_Rect* GetPos();
	void MoveX(int x);
	void MoveY(int y);
	void Move(int x, int y);
	bool CreateCollider(ColliderType type); 
	Collider* GetCollider(); 
	~GameObject();
private:
	std::vector<SDL_Surface*> sprite; //Es un arreglo de sprites
	SDL_Rect* spritePosition;
	Collider *collider; 
	Rigidbody* rigidbody; 
	int spriteIndex = 0; 
	int updateRate = 1; 
	int updateCount = 0; 

};