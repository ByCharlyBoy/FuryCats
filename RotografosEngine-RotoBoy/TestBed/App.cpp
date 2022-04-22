#include "App.h"
#include "Scene.h"
#include <SDL_image.h>
#include <iostream>
#include "InputManager.h"
#include "World.h"


bool App::_programIsExecuting, App::_shouldDeleteScene;
SDL_Window* App::_surfDisplay = nullptr;
int App::_width;
int App::_height;
Scene* App::_currentScene, *App::_nextScene;
SDL_Surface* App::_drawSurface, *App::_clearSurface;
Camera* App::_mainCamera; 
std::chrono::system_clock::time_point App::_lastTime;

void App::StartApp(int ScreenSizeX, int ScreenSizeY, Scene* startScene)
{
	_width = ScreenSizeX;
	_height = ScreenSizeY;
	_currentScene = startScene;
	_nextScene = nullptr; 
	_mainCamera = new Camera(); 
	_lastTime = std::chrono::system_clock::now(); 
	Init();
	while (_programIsExecuting) {
		Update();
		DeleteScene(); 
	}
	Cleanup();
}

void App::KillProgram()
{
	_programIsExecuting = false;
}

void App::ChangeScene(Scene* newScene)
{
	_currentScene->OnEnd();
	_shouldDeleteScene = true; 
	if (newScene != nullptr)
	{
		_nextScene = newScene; 
	}
}


SDL_Surface* App::GetScreenSurface()
{
	return _drawSurface;
}

int App::GetWidth()
{
	return _width;
}

int App::GetHeight()
{
	return _height;
}

Camera* const App::GetMainCamera()
{
	return _mainCamera;
}

void App::Init()
{
	_programIsExecuting = true;
	_programIsExecuting = !SDL_Init(SDL_INIT_EVERYTHING);
	if (!_programIsExecuting)
		return;
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP; //
	int imginit = IMG_Init(flags);
	if ((imginit & flags) != flags)
		return; 
	_surfDisplay = SDL_CreateWindow("Juego mamalon", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
	if (_surfDisplay == nullptr) {
		_programIsExecuting = false;
		return;
	}
	_drawSurface = SDL_GetWindowSurface(_surfDisplay);
	_clearSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, _width, _height,
		32, 0,0, 0, 0);
	if (!_clearSurface) {
		std::cout << "ERROR" << SDL_GetError()
			<< std::endl;
	}
	SDL_FillRect(_clearSurface, NULL, 0xFFFF00FF);
	InputManager::ResetStorage(); 
}

void App::Update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) 
		EventPolling(&e);
	SDL_BlitSurface(_clearSurface, NULL, _drawSurface, NULL);
	if (_currentScene == nullptr)
		return;
	if (!_currentScene->hasStarted)
		_currentScene->Start();
	World::Update(std::chrono::duration_cast<std::chrono::seconds> (std::chrono::system_clock::now() - _lastTime).count()); 
	_currentScene->Update();
	SDL_UpdateWindowSurface(_surfDisplay);
	SDL_Delay(16);
	InputManager::UpdateStates(); 
	_lastTime = std::chrono::system_clock::now();
}

void App::Cleanup()
{
	SDL_DestroyWindow(_surfDisplay);
	SDL_Quit();
}

void App::DeleteScene()
{
	if (_shouldDeleteScene)
	{
		delete _currentScene; 
		_currentScene = _nextScene; 
		_nextScene = nullptr; 
	}
}

void App::EventPolling(SDL_Event* events)
{
	switch (events->type) 
	{
	case SDL_QUIT:
		_programIsExecuting = false;
		break;
	case SDL_KEYDOWN:
		InputManager::ChangeState(events->key.keysym, pressed); 
		break; 
	case SDL_KEYUP:
		InputManager::ChangeState(events->key.keysym, released);
		break; 

	}
}
