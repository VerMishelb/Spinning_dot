#ifndef DEFINES_H
#define DEFINES_H

#define WINDOW_W 800
#define WINDOW_H 600

struct App {
	int w_width;
	int w_height;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event_;
	char stop;
};

#endif