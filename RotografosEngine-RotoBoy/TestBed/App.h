#pragma once
#include <SDL.h>
#include <chrono>
#include "Camera.h"

class Scene;

class App
{
public:
	static void StartApp(int ScreenSizeX, int ScreenSizeY, Scene* startScene);
	static void KillProgram();
	static void ChangeScene(Scene* newScene);
	static SDL_Surface* GetScreenSurface();
	static int GetWidth(); 
	static int GetHeight(); 
	static Camera* const GetMainCamera();

private:
	App() = delete;
	~App() = delete;
	static void Init();
	static void EventPolling(SDL_Event* events);
	static void Update();
	static void Cleanup();
	static void DeleteScene(); 
	static bool _programIsExecuting;
	static bool _shouldDeleteScene; 
	static SDL_Window* _surfDisplay;
	static SDL_Surface* _drawSurface, *_clearSurface;
	static int _width, _height;
	static Scene* _currentScene, *_nextScene;
	static Camera* _mainCamera;
	static std::chrono::system_clock::time_point _lastTime; 
};

