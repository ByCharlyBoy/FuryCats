#pragma once
#include <map> //Diccionario 
#include <string>
#include <SDL.h>

class SpritePool
{
public:
	static SpritePool *const GetInstance(); //No se mueve, ni se borra
	static void DeleteSpritePool(); 
	SDL_Surface* GetSprite(std::string spriteName);
	void LoadSprite(std::string spriteName, std::string fileName); 

private:
	SpritePool(); 
	~SpritePool(); //destructor
	static SpritePool* _instance;  
	std::map<std::string, SDL_Surface*> _spriteDictionary; ///Crea un diccionario (guardara sprite)

};

