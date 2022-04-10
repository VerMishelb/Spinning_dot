#include "Circle.h"
#include <math.h>
extern struct App app;

void Circle_Init(Circle* c) {
	*c = (Circle){
		{app.w_width / 2, app.w_height / 2},
		2,
		1.f,
		50.f,
		0.f
	};
}

void Circle_Update(float delta, Circle* circle) {
	if (app.input.Left) {
		circle->speed -= 0.1f + (0.5f * app.input.Shift);
	}
	if (app.input.Right) {
		circle->speed += 0.1f + (0.5f * app.input.Shift);
	}
	if (app.input.Up) {
		circle->rotationRadius += 1.f + (3.f * app.input.Shift);
	}
	if (app.input.Down) {
		circle->rotationRadius -= 1.f + (3.f * app.input.Shift);
	}
	if (app.input.Plus) {
		circle->size += 1 + (3 * app.input.Shift);
	}
	if (app.input.Minus) {
		circle->size -= 1 + (3 * app.input.Shift);
	}
	if (app.input.Reset) {
		Circle_Init(circle);
	}

	circle->timePassed += delta * circle->speed;
}

void Circle_Render(Circle* c) {
	//Точка-центр вращения
	SDL_SetRenderDrawColor(app.renderer, 0x00, 0xff, 0x00, 0xff);
	SDL_RenderDrawPoint(app.renderer, c->position.x, c->position.y);

	SDL_SetRenderDrawColor(app.renderer, 0xff, 0xff, 0xff, 0xff);
	raster_circle(app.renderer,
		c->position.x + c->rotationRadius * cos(c->timePassed),
		c->position.y + c->rotationRadius * sin(c->timePassed),
		c->size);
}

//"Midpoint circle algorithm" для отрисовки кругов
//https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
void raster_circle(SDL_Renderer* renderer, int x0, int y0, int radius) {
	int err = 1 - radius;
	int dx = 0;
	int dy = -2 * radius;
	int x = 0;//смещение от центра
	int y = radius;

	//Пропадающие точки
	SDL_RenderDrawPoint(renderer, x0, y0 + radius);
	SDL_RenderDrawPoint(renderer, x0, y0 - radius);
	SDL_RenderDrawPoint(renderer, x0 + radius, y0);
	SDL_RenderDrawPoint(renderer, x0 - radius, y0);

	while (x < y) {
		if (err >= 0) {
			y--;
			dy += 2;
			err += dy;
		}
		x++;
		dx += 2;
		err += dx + 1;
		SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
	}
}