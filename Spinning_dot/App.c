#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "App.h"
#include "Input.h"
#include "Circle.h"

extern struct App app = { WINDOW_W, WINDOW_H, 0, 0, 0, 0 };
Circle* circle = 0;

int App_Init(void) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Could not initialise SDL: %s", SDL_GetError());
		return -1;
	}
	app.window = SDL_CreateWindow("Spinning dot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app.w_width, app.w_height, SDL_WINDOW_SHOWN);
	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC);

	circle = malloc(sizeof(*circle));
	Circle_Init(circle);
	return 0;
}

void App_Update(float delta) {
	while (SDL_PollEvent(&app.event_)) {
		if (app.event_.type == SDL_QUIT) {
			app.stop = 1;
		}
		Input_Update(&app);
	}
	Circle_Update(delta, circle);
}

void App_Render(void) {
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(app.renderer);

	Circle_Render(circle);

	SDL_RenderPresent(app.renderer);
}

void App_Destroy(void) {
	free(circle);
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}
