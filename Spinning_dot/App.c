#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "App.h"
#include "Input.h"
#include "Circle.h"
#include "Debug.h"
#include <SDL_ttf.h>

struct App app = { WINDOW_W, WINDOW_H, 0, 0, 0, 0 };
Circle* circle = 0;
TTF_Font* font = 0;
SDL_Color Color_Text = { 0xa0, 0xa0, 0xa0, 0xff };


int App_Init(void) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		DBG_MSG("Could not initialise SDL: %s", SDL_GetError());
		return -1;
	}
	if (TTF_Init()) {
		DBG_MSG("Could not initialise SDL_ttf: %s", TTF_GetError());
		return -1;
	}

	app.window = SDL_CreateWindow("Spinning dot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app.w_width, app.w_height, SDL_WINDOW_SHOWN);
	if (!app.window) { DBG_MSG("Could not create window: %s", SDL_GetError()); return -1; }

	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (!app.renderer) { DBG_MSG("Could not create renderer: %s", SDL_GetError()); return -1; }

	font = TTF_OpenFont("SourceCodePro-Regular.ttf", 14);
	if (!font) { DBG_MSG("TTF_OpenFont error: %s", TTF_GetError()); return -1; }

	circle = malloc(sizeof(*circle));
	if (!circle) { DBG_MSG("Could not allocate memory"); return -1; }

	Circle_Init(circle);
	DBG_MSG("Success");
	return 0;
}

void App_Update(float delta) {
	while (SDL_PollEvent(&app.event_)) {
		Input_Update(&app);
	}

	if (app.input.Escape) { app.stop = 1; }

	Circle_Update(delta, circle);
}

void App_Render(void) {
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(app.renderer);

	Circle_Render(circle);

	//Текст
	char str[512] = { 0 };
	sprintf_s(str, 600, "← → — изменение скорости вращения.\n"
		"↑ ↓ — изменение радиуса траектории.\n"
		"+ - — изменение размера точки.\n"
		"Esc — выйти.\n"
		"Shift — больший шаг изменения значений\n"
		"R — сбросить параметры\n"
		"Радиус точки:       %d\n"
		"Радиус траектории:  %d\n"
		"Скорость  вращения: %.1f",
		circle->size, (int)circle->rotationRadius, circle->speed
	);
	SDL_Surface* textSurface = TTF_RenderUTF8_Solid_Wrapped(font, str, Color_Text, 0);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(app.renderer, textSurface);
	SDL_Rect textRect = { 10, 10, 0, 0 };
	textRect.w = textSurface->w;
	textRect.h = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_RenderCopy(app.renderer, textTexture, 0, &textRect);

	SDL_RenderPresent(app.renderer);
}

void App_Destroy(void) {
	DBG_MSG("Shutting down...");
	free(circle);

	TTF_Quit();
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}
