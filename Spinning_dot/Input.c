#include "Input.h"

void Input_Update(struct App* app) {
	if (app->event_.type == SDL_KEYDOWN) {
		switch (app->event_.key.keysym.sym) {
		case SDLK_LEFT:
		case SDLK_a:
			INPUT_SET(app->input, Input_Left);
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			INPUT_SET(app->input, Input_Right);
			break;
		case SDLK_ESCAPE:
			INPUT_SET(app->input, Input_Quit);
		}
	}
	if (app->event_.type == SDL_KEYUP) {
		switch (app->event_.key.keysym.sym) {
		case SDLK_LEFT:
		case SDLK_a:
			INPUT_UNSET(app->input, Input_Left);
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			INPUT_UNSET(app->input, Input_Right);
			break;
		case SDLK_ESCAPE:
			INPUT_UNSET(app->input, Input_Quit);
		}
	}
}