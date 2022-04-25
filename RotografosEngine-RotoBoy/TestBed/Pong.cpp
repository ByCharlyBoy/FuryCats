#include "Pong.h"
#include <iostream>
#include "App.h"
#include "InputManager.h"

Pong::Pong() // inicializa la pocision de la bola
{
    this->center_x = x;
    this->center_y = y;
    this->x = x;
    this->y = y;
    this->direction = MOVING;
    
    ball = new GameObject("fancy-ball.png");
    racket1 = new GameObject("fancy-paddle-green.png");
    racket2 = new GameObject("fancy-paddle-blue.png");
}

Pong::~Pong()
{

}

void Pong::Start()
{
    Scene::Start();
    ball->CreateCollider(Square);
    racket1->CreateCollider(Square);
    racket2->CreateCollider(Square);
    ball->SetPos(100, 100);
    racket1->SetPos(10, 10);
    racket2->SetPos(550, 100);
    speedx = 5;
    speedy = 5;
}

void Pong::Update(float deltaTime)
{
    Scene::Update(deltaTime);
    move_ball(); 
    
    if (ball->GetPos()->x >= App::GetWidth() - ball->GetPos()->w || 
        ball->GetPos()->y >= App::GetHeight() - ball->GetPos()->h ||
        ball->GetPos()->x <= 0 || ball->GetPos()->y <= 0)
    {
        ball_collide(); 
    }
    ball->Update();

    racket1->Update(); //Movimiento Barra1 izquierda
    if (InputManager::IsHolding(SDLK_w))
    {
        racket1->MoveY(-5);
    }
    if (InputManager::IsHolding(SDLK_s))
    {
        racket1->MoveY(5);
    }
    if (racket1->GetPos()->x >= App::GetWidth() - racket1->GetPos()->w) //Que no se pase del limite
        racket1->SetX(App::GetWidth() - racket1->GetPos()->w);
    if (racket1->GetPos()->y >= App::GetHeight() - racket1->GetPos()->h)
        racket1->SetY(App::GetHeight() - racket1->GetPos()->h);
    if (racket1->GetPos()->x <= 0)
        racket1->SetX(0);
    if (racket1->GetPos()->y <= 0)
        racket1->SetY(0);

    racket2->Update(); //Movimiento barra2 Derecha
    if (InputManager::IsHolding(SDLK_a))
    {
        racket2->MoveY(-5);
    }
    if (InputManager::IsHolding(SDLK_d))
    {
        racket2->MoveY(5);
    }
    if (racket2->GetPos()->x >= App::GetWidth() - racket2->GetPos()->w) //Que no se pase del limite
        racket2->SetX(App::GetWidth() - racket2->GetPos()->w);
    if (racket2->GetPos()->y >= App::GetHeight() - racket2->GetPos()->h)
        racket2->SetY(App::GetHeight() - racket2->GetPos()->h);
    if (racket2->GetPos()->x <= 0)
        racket2->SetX(0);
    if (racket2->GetPos()->y <= 0)
        racket2->SetY(0);

}

void Pong::reset_ball() //Función para devolver la pelota a su posición inicial (centro)
{
    x = center_x;
    y = center_y;
    direction = STOP;
}

void Pong::change_ball_direction(Ball_Direction d)
{
    direction = d;  //función para cambiar la dirección de la pelota cuando golpea una pared
}

void Pong::randomized_ball_direction()
{
    direction = (Ball_Direction)((rand() % 6) + 1); //inicializa la direccion del balon random 
}

void Pong::ball_collide()
{
    speedx *= -1;
    speedy *= -1;
}

void Pong::move_ball()
{
    switch (direction)
    {
    case STOP:
        break;
    case MOVING:
        ball->Move(speedx, speedy);
        break;
    default:
        break;
    }
}





