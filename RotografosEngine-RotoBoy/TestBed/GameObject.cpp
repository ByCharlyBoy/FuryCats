#include "GameObject.h"
#include <iostream>
#include <SDL_image.h>
#include "App.h"
#include "CircleCollider.h"
#include "RectangleCollider.h"
#include "SpritePool.h"
#include "World.h"

GameObject::GameObject()
{
	rigidbody = nullptr;
	collider = nullptr;
	spritePosition = new SDL_Rect();
	spritePosition->x = 0;
	spritePosition->y = 0;
}

GameObject::GameObject(std::string imgName)
{
	SpritePool::GetInstance()->LoadSprite(imgName, imgName);
	sprite.push_back(SpritePool::GetInstance()->GetSprite(imgName));	
	
	collider = nullptr; 
	rigidbody = nullptr; 

	if (sprite[0])
	{
		std::cout << "Unable to load image %s! SDL Error:\n" << SDL_GetError() << "download.bmp";
	}
	spritePosition = new SDL_Rect();
	spritePosition->x = 0;
	spritePosition->y = 0;
}

void GameObject::CreateSprite(std::string imgName)
{		
	SpritePool::GetInstance()->LoadSprite(imgName, imgName);
	sprite.push_back(SpritePool::GetInstance()->GetSprite(imgName));
	if (sprite[sprite.size()-1] == nullptr)
	{
		std::cout << "Unable to load image %s! SDL Error:\n" << SDL_GetError() << "download.bmp";
	}
	
}

void GameObject::DeleteSprite(int spriteI)
{
	if (spriteI < sprite.size())
	{
		sprite.erase(sprite.begin() + spriteI); 
	}
	spriteIndex = 0; 
}

void GameObject::CreateRigidbody()
{
	if (rigidbody)
		return;
	rigidbody = new Rigidbody(this);
}

Rigidbody* GameObject::GetRigidbody()
{
	return rigidbody;
}

void GameObject::Start()
{
}

void GameObject::Update()
{
	if (collider != nullptr)
	{
		collider->UpdatePosition(spritePosition->x, spritePosition->y); 
		if (collider->Type() == Square) 
		{
			((RectangleCollider*)collider)->topLimit[0] = spritePosition->w;
			((RectangleCollider*)collider)->topLimit[1] = spritePosition->h;
		}
	}
	if (sprite.size() != 0)
	{
		SDL_Rect f{ spritePosition->x -App::GetMainCamera()->GetPos().GetComponent(0,0),
			spritePosition->y - App::GetMainCamera()->GetPos().GetComponent(1,0), 0,0 };
		SDL_BlitSurface(sprite[spriteIndex], NULL, App::GetScreenSurface(), &f);
		updateCount++;
		updateCount %= updateRate; 
		if (!updateCount)
		{
			spriteIndex++; 
			spriteIndex %= sprite.size(); 
		}
		spritePosition->w = f.w;
		spritePosition->h = f.h;

	}
}

void GameObject::SetX(int x)
{
	spritePosition->x = x;
}

void GameObject::SetY(int y)
{
	spritePosition->y = y;
}

void GameObject::SetUpdateRate(int rate)
{
	updateRate = rate; 
}

void GameObject::SetPos(int x, int y)
{
	spritePosition->x = x;
	spritePosition->y = y;
}

SDL_Rect* GameObject::GetPos()
{
	return spritePosition;
}

void GameObject::MoveX(int x)
{
	spritePosition->x += x;
}

void GameObject::MoveY(int y)
{
	spritePosition->y += y;
}

void GameObject::Move(int x, int y)
{
	spritePosition->x += x;
	spritePosition->y += y;
}

bool GameObject::CreateCollider(ColliderType type)
{
	switch (type)
	{
	case Square:
		collider = new RectangleCollider(spritePosition->w, spritePosition->h , spritePosition->x, spritePosition->y);
			break;

	case Circle:
		collider = new CircleCollider(spritePosition->x, spritePosition->y, spritePosition->w /2);
			break;

	default:
		break;
	}
	return false;
}

Collider* GameObject::GetCollider()
{
	return collider;
}

GameObject::~GameObject()
{
	if (collider)
	{
		World::UnregisterObject(this); 
		delete collider;
	}
	 
	delete spritePosition;
	if (rigidbody)
	{
		World::UnregisterObject(this);
		delete rigidbody;
	}

}
		