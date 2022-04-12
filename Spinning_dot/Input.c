#include "Input.h"

void Input_Update(struct App* app) {
	if (app->event_.type == SDL_QUIT) {
		app->stop = 1;
	}
	if (app->event_.type == SDL_KEYDOWN || app->event_.type == SDL_KEYUP) {
		char ispressed = (app->event_.type == SDL_KEYDOWN) ? 1 : 0;//bool might return true not only for 1
		switch (app->event_.key.keysym.sym) {
		case SDLK_LEFT:
		case SDLK_a:
			app->input.Left = ispressed;
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			app->input.Right = ispressed;
			break;
		case SDLK_UP:
		case SDLK_w:
			app->input.Up = ispressed;
			break;
		case SDLK_DOWN:
		case SDLK_s:
			app->input.Down = ispressed;
			break;
		case SDLK_MINUS:
		case SDLK_KP_MINUS:
			app->input.Minus = ispressed;
			break;
		case SDLK_EQUALS:
		case SDLK_KP_PLUS:
			app->input.Plus = ispressed;
			break;
		case SDLK_ESCAPE:
			app->input.Escape = ispressed;
			break;
		case SDLK_LSHIFT:
		case SDLK_RSHIFT:
			app->input.Shift = ispressed;
			break;
		case SDLK_r:
			app->input.Reset = ispressed;
			break;
		default:
			break;
		}
	}
}