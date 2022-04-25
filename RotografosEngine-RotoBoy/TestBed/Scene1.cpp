#include "Scene1.h"
#include <iostream>
#include "App.h"
#include "InputManager.h"

Scene1::Scene1()
{
    juanpi = new GameObject("download.bmp");
    juanpi2 = new GameObject("locuras/frame_00_delay-0.07s.png"); 
    juanpi2->CreateSprite("locuras/frame_01_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_02_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_03_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_04_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_05_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_06_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_07_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_08_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_09_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_10_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_11_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_12_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_13_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_14_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_15_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_16_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_17_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_18_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_19_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_20_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_21_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_22_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_23_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_24_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_25_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_26_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_27_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_28_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_29_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_30_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_31_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_32_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_33_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_34_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_35_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_36_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_37_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_38_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_39_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_40_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_41_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_42_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_43_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_44_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_45_delay-0.07s.png");
    juanpi2->CreateSprite("locuras/frame_46_delay-0.07s.png");
    juanpi2->SetUpdateRate(3); 
    //screen dvd
 
    if (!rolon.openFromFile("rala.wav"))
        std::cout << "Madre santa, la rola ta fea" << std::endl; 
}

Scene1::~Scene1()
{

}

void Scene1::Start()
{
    Scene::Start(); 
    juanpi->CreateCollider(Square);
    juanpi2->CreateCollider(Circle);
    juanpi->SetPos(0, App::GetHeight() - 300);
    juanpi2->SetPos(App::GetWidth() - 300, App::GetHeight() - 300);
    speed = 5; 
    //speedY = 5; 
}

void Scene1::Update(float deltaTime)
{
    Scene::Update(deltaTime);
    
    //1era imagen
    if (InputManager::IsHolding(SDLK_d))
    {
        App::GetMainCamera()->MoveX(-1);
        //juanpi->MoveX(speed); 
    }
    if (InputManager::IsHolding(SDLK_a))
    {
        App::GetMainCamera()->MoveX(1);
        //juanpi->MoveX(-speed);
    }
    if (InputManager::IsHolding(SDLK_w))
    {
        App::GetMainCamera()->MoveY(-1);
        //juanpi->MoveY(-speed);
    }
    if (InputManager::IsHolding(SDLK_s)) 
    {
        App::GetMainCamera()->MoveY(1);
        //juanpi->MoveY(speed);
    }

    // que no se salga del limite 
    if (juanpi->GetPos()->x >= App::GetWidth() - juanpi->GetPos()->w)
        juanpi->SetX(App::GetWidth() - juanpi->GetPos()->w); 
    if (juanpi->GetPos()->y >= App::GetHeight() - juanpi->GetPos()->h)
        juanpi->SetY(App::GetHeight() - juanpi->GetPos()->h);
    if (juanpi->GetPos()->x <= 0)
        juanpi->SetX(0);
    if (juanpi->GetPos()->y <= 0)
        juanpi->SetY(0); 
   

    //2da imagen
    if (InputManager::IsHolding(SDLK_RIGHT))
    {
        juanpi2->MoveX(speed);
    }
    if (InputManager::IsHolding(SDLK_LEFT))
    {
        juanpi2->MoveX(-speed);
    }
    if (InputManager::IsHolding(SDLK_UP))
    {
        juanpi2->MoveY(-speed);
    }
    if (InputManager::IsHolding(SDLK_DOWN))
    {
        juanpi2->MoveY(speed);
    }
    if (juanpi2->GetPos()->x >= App::GetWidth() - juanpi2->GetPos()->w)
        juanpi2->SetX(App::GetWidth() - juanpi2->GetPos()->w);
    if (juanpi2->GetPos()->y >= App::GetHeight() - juanpi2->GetPos()->h)
        juanpi2->SetY(App::GetHeight() - juanpi2->GetPos()->h);
    if (juanpi2->GetPos()->x <= 0)
        juanpi2->SetX(0);
    if (juanpi2->GetPos()->y <= 0)
        juanpi2->SetY(0);


   // juanpi->MoveX(1);
   // juanpi2->MoveX(-1); 
    juanpi->Update();
    juanpi2->Update(); 

    std::cout << juanpi->GetCollider()->IsCollinding(juanpi2->GetCollider()) << std::endl; //esto se comenta para saber si jala el IsInside 
    if (juanpi->GetCollider()->IsCollinding(juanpi2->GetCollider()))
    {

    }

}

void Scene1::OnEnd()
{
    Scene::OnEnd();
    delete juanpi;
    delete juanpi2; 
}

