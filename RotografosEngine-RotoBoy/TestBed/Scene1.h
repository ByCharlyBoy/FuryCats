#pragma once
#include "Scene.h"
#include <SDL.h>
#include "GameObject.h"
#include <SFML/Audio.hpp>

class Scene1 :
    public Scene
{
public:
    Scene1();
    ~Scene1();
    void Start();
    void Update(float deltaTime);
    void OnEnd();
    GameObject* juanpi;
    GameObject* juanpi2;
    GameObject* dvd; 
    int speed; 
    int speedY; 
    sf::Music rolon; //musica
};
