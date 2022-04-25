#pragma once
#include "Scene.h" 
#include <SDL.h>
#include "GameObject.h"
#include<cstdlib> 
#include<ctime> 
#include<conio.h> 

enum Ball_Direction { STOP, MOVING};

class Pong :
    public Scene
{
public:
    Pong();
    ~Pong();
    void Start();
    void Update(float deltaTime);
    void reset_ball();
    void change_ball_direction(Ball_Direction d);
    void randomized_ball_direction();
    void move_ball();
    void ball_collide();


    int x, y, center_x, center_y; 
    Ball_Direction direction;
   
    int speedx = 5; 
    int speedy = 5;

    GameObject* ball;
    GameObject* racket1;
    GameObject* racket2;


};


