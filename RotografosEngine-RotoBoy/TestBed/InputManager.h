#pragma once
#include <SDL.h>

enum InputState
{
	pressed, 
	released
};


class InputManager
{
public:
	static bool IsPressed(SDL_Keycode key);
	static bool IsReleased(SDL_Keycode key);
	static bool IsHolding(SDL_Keycode key);
	static void ChangeState(SDL_Keysym,  InputState state);
	static void UpdateStates(); 
	static void ResetStorage();

private:
	/// <summary>
	/// Los primeros 2 slots son de key pressed  0 1
	/// los degundos 2 slots son de key held     2 3
	/// los terceros 2 slots son de key relesead 4 5
	/// </summary>
	static uint64_t keyboardStorage[6]; 
	static int FindKey(SDL_Keycode key); 



};

