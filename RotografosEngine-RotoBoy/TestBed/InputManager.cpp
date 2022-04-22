#include "InputManager.h"

uint64_t InputManager::keyboardStorage[6]; 

bool InputManager::IsPressed(SDL_Keycode key)
{
    int k = FindKey(key);
    int store = k / 64;
	return keyboardStorage[store] & static_cast<unsigned long long> (1) << k % 64;
}

bool InputManager::IsReleased(SDL_Keycode key)
{
    int k = FindKey(key);
    int store = k / 64;
    return keyboardStorage[store + 4] & static_cast<unsigned long long> (1) << k % 64;
}

bool InputManager::IsHolding(SDL_Keycode key)
{
    int k = FindKey(key);
    int store = k / 64;
    return keyboardStorage[store + 2] & static_cast<unsigned long long> (1) << k % 64;
}

void InputManager::ChangeState(SDL_Keysym key, InputState state)
{
    int k = FindKey(key.sym);
    int store = k / 64; 
	switch (state)
	{
	case pressed:
        keyboardStorage[store] |= static_cast<unsigned long long> (1) << k % 64; 
        keyboardStorage[store + 2] |= static_cast<unsigned long long> (1) << k % 64;
		break;
	case released:
        keyboardStorage[store + 4] |= static_cast<unsigned long long> (1) << k % 64;
        keyboardStorage[store + 2] ^= static_cast<unsigned long long> (1) << k % 64;
        keyboardStorage[store] ^= static_cast<unsigned long long> (1) << k % 64;
       
		break;
	default:

		break;
	}
}

void InputManager::UpdateStates()
{
    keyboardStorage[0] = 0; 
    keyboardStorage[1] = 0; 
    keyboardStorage[4] = 0;
    keyboardStorage[5] = 0; 
}

void InputManager::ResetStorage()
{
    for (int i = 0; i < 6; ++i)
        keyboardStorage[1] = 0; 
}

int InputManager::FindKey(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_RETURN:
        return 0;
    case SDLK_ESCAPE:
        return 1; 
    case SDLK_BACKSPACE:
        return 2; 
    case SDLK_TAB:
        return 3; 
    case SDLK_SPACE:
        return 4; 
    case SDLK_EXCLAIM:
        return 5; 
    case SDLK_QUOTEDBL:
        return 6; 
    case SDLK_HASH:
        return 7; 
    case SDLK_PERCENT:
        return 8; 
    case SDLK_DOLLAR:
        return 9; 
    case SDLK_AMPERSAND:
        return 10; 
    case SDLK_QUOTE:
        return 11; 
    case SDLK_LEFTPAREN:
        return 12; 
    case SDLK_RIGHTPAREN:
        return 13; 
    case SDLK_ASTERISK:
        return  14; 
    case SDLK_PLUS:
        return 15; 
    case SDLK_COMMA:
        return 16; 
    case SDLK_MINUS:
        return 17; 
    case SDLK_PERIOD:
        return 18; 
    case SDLK_SLASH:
        return 19; 
    case SDLK_0:
        return 20; 
    case SDLK_1:
        return 21;
    case SDLK_2:
        return 22;
    case SDLK_3:
        return 23;
    case SDLK_4:
        return 24;
    case SDLK_5:
        return 25;
    case SDLK_6:
        return 26;
    case SDLK_7:
        return 27;
    case SDLK_8:
        return 28;
    case SDLK_9:
        return 29;
    case SDLK_COLON:
        return 30;
    case SDLK_SEMICOLON:
        return 31;
    case SDLK_LESS:
        return 32;
    case SDLK_EQUALS:
        return 33;
    case SDLK_GREATER:
        return 34;
    case SDLK_QUESTION:
        return 35;
    case SDLK_AT: 
        return 36;
    case SDLK_LEFTBRACKET:
        return 37;
    case SDLK_BACKSLASH:
        return 38;
    case SDLK_RIGHTBRACKET:
        return 39;
    case SDLK_CARET: 
        return 40;
    case SDLK_UNDERSCORE:
        return 41;
    case SDLK_BACKQUOTE:
        return 42;
    case SDLK_a:
        return 43;
    case SDLK_b:
        return 44;
    case SDLK_c:
        return 45;
    case SDLK_d:
        return 46;
    case SDLK_e:
        return 47;
    case SDLK_f:
        return 48;
    case SDLK_g:
        return 49;
    case SDLK_h:
        return 50;
    case SDLK_i:
        return 51;
    case SDLK_j:
        return 52;
    case SDLK_k: 
        return 53;
    case SDLK_l:
        return 54;
    case SDLK_m:
        return 55;
    case SDLK_n:
        return 56;
    case SDLK_o:
        return 57;
    case SDLK_p:
        return 58;
    case SDLK_q:
        return 59;
    case SDLK_r:
        return 60;
    case SDLK_s:
        return 61;
    case SDLK_t:
        return 62;
    case SDLK_u:
        return 63;
    case SDLK_v:
        return 64;
    case SDLK_w: 
        return 65;
    case SDLK_x:
        return 66;
    case SDLK_y: 
        return 67;
    case SDLK_z:
        return 68;
    case SDLK_CAPSLOCK:
        return 69;
    case SDLK_F1:
        return 70;
    case SDLK_F2:
        return 71;
    case SDLK_F3:
        return 72;
    case SDLK_F4:
        return 73;
    case SDLK_F5:
        return 74;
    case SDLK_F6:
        return 75;
    case SDLK_F7:
        return 76;
    case SDLK_F8:
        return 77;
    case SDLK_F9:
        return 78;
    case SDLK_F10:
        return 79;
    case SDLK_F11:
        return 80;
    case SDLK_F12:
        return 81;
    case SDLK_PRINTSCREEN:
        return 82;
    case SDLK_SCROLLLOCK:
        return 83;
    case SDLK_PAUSE:
        return 84;
    case SDLK_INSERT:
        return 85;
    case SDLK_HOME:
        return 86;
    case SDLK_PAGEUP:
        return 87;
    case SDLK_DELETE:
        return 88;
    case SDLK_END:
        return 89;
    case SDLK_PAGEDOWN:
        return 90;
    case SDLK_RIGHT:
        return 91;
    case SDLK_LEFT:
        return 92;
    case SDLK_DOWN:
        return 93;
    case SDLK_UP:
        return 94;
    case SDLK_NUMLOCKCLEAR:
        return 95;
    case SDLK_KP_DIVIDE:
        return 96;
    case SDLK_KP_MULTIPLY:
        return 97;
    case SDLK_KP_MINUS:
        return 98;
    case SDLK_KP_PLUS:
        return 99;
    case SDLK_KP_ENTER:
        return 100;
    case SDLK_KP_1:
        return 101;
    case SDLK_KP_2:
        return 102;
    case SDLK_KP_3:
        return 103;
    case SDLK_KP_4:
        return 104;
    case SDLK_KP_5:
        return 105;
    case SDLK_KP_6:
        return 106;
    case SDLK_KP_7:
        return 107;
    case SDLK_KP_8:
        return 108;
    case SDLK_KP_9:
        return 109;
    case SDLK_KP_0:
        return 110;
    case SDLK_KP_PERIOD:
        return 111;
    case SDLK_LCTRL:
        return 112;
    case SDLK_LSHIFT:
        return 113;
    case SDLK_LALT:
        return 114;
    case SDLK_LGUI:
        return 115;
    case SDLK_RCTRL:
        return 116;
    case SDLK_RSHIFT:
        return 117;
    case SDLK_RALT:
        return 118;
    case SDLK_RGUI:
        return 119;

    default:
        return -1; 
        break;
    }
    return 0;
}
