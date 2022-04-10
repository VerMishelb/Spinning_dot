#ifndef DEFINES_H
#define DEFINES_H

#include <SDL.h>

#define WINDOW_W 800
#define WINDOW_H 600
#define PI 3.141592653589793

typedef struct Input {
	char 
		Left,
		Right,
		Up,
		Down,
		Plus,
		Minus,
		Escape,
		Shift,
		Reset;
} Input;

struct App {
	int w_width;
	int w_height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event_;
	char stop;
	Input input;
};

#endif