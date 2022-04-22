#include "SpritePool.h"
#include <SDL_image.h>

SpritePool* SpritePool::_instance; 

SpritePool::~SpritePool()
{
	for (auto it = _spriteDictionary.begin(); it != _spriteDictionary.end(); ++it) //for con iteradores de c++
	{
		SDL_FreeSurface((*it).second); 
	}
}

SpritePool *const SpritePool::GetInstance()
{
	return _instance == nullptr ? _instance  //Sistema en el cual solo existe una instancia, 
		= new SpritePool() : _instance; //solo existira 1 vez y tendra memoria cuando llamemos al GetInstance
}

void SpritePool::DeleteSpritePool()
{

	if (_instance)
		delete _instance; 
}

SDL_Surface* SpritePool::GetSprite(std::string spriteName)
{
	if (_spriteDictionary.find(spriteName) == _spriteDictionary.end())
		return nullptr; 
	return _spriteDictionary[spriteName]; //va a regresar al sdl_surface con el sprite name
}

void SpritePool::LoadSprite(std::string spriteName, std::string fileName)
{
	if (_spriteDictionary.find(spriteName) == _spriteDictionary.end())
	      _spriteDictionary.emplace(spriteName, IMG_Load(fileName.c_str())); 
} 

SpritePool::SpritePool()
{

}


////ttps://github.com/tanmayvijay/Ping-Pong-on-CPP/blob/master/main.cpp
