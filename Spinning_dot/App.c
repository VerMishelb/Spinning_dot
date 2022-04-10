#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "App.h"
#include "Input.h"
#include "Circle.h"
//#include <SDL_ttf.h>

extern struct App app = { WINDOW_W, WINDOW_H, 0, 0, 0, 0 };
Circle* circle = 0;
//TTF_Font* font = 0;
//SDL_Color Color_Text = { 0xa0, 0xa0, 0xa0, 0xff };


int App_Init(void) {
	if (SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) {
		printf("Could not initialise SDL: %s", SDL_GetError());
		return -1;
	}
	app.window = SDL_CreateWindow("Spinning dot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app.w_width, app.w_height, SDL_WINDOW_SHOWN);
	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC);
	//font = TTF_OpenFont("SourceCodePro-Regular.ttf", 14);
	//if (!font) {
	//	printf("Error: %s", TTF_GetError());
	//	exit(-1);
	//}
	circle = malloc(sizeof(*circle));
	Circle_Init(circle);
	return 0;
}

void App_Update(float delta) {
	while (SDL_PollEvent(&app.event_)) {
		Input_Update(&app);
	}
	
	if (app.input.Escape) { App_Destroy(); }

	Circle_Update(delta, circle);
}

void App_Render(void) {
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0xff);
	SDL_RenderClear(app.renderer);

	Circle_Render(circle);


	//char str[600] = {0};
	//sprintf_s(str, 600, "← → — изменение скорости вращения.\n"
	//	"↑ ↓ — изменение радиуса траектории.\n"
	//	"+ - — изменение размера точки.\n"
	//	"Esc — выйти.\n"
	//	"Радиус точки:       %d\n"
	//	"Радиус траектории:  %d\n"
	//	"Скорость  вращения: %.1f",
	//	circle->size, (int)circle->rotationRadius, circle->speed
	//);

	//if (TTF_WasInit()) {
	//	SDL_Surface* textSurface = TTF_RenderUTF8_Solid_Wrapped(font, str, Color_Text, 0);
	//	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(app.renderer, textSurface);
	//	SDL_Rect textRect = { 10, 10, 0, 0 };
	//	textRect.w = textSurface->w;
	//	textRect.h = textSurface->h;
	//	SDL_FreeSurface(textSurface);
	//	SDL_RenderCopy(app.renderer, textTexture, 0, &textRect);
	//}

	SDL_RenderPresent(app.renderer);
}

void App_Destroy(void) {
	//TTF_Quit();
	free(circle);
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}
