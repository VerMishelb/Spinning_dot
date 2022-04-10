#ifndef CIRCLE_H
#define CIRCLE_H

#include "Input.h"

typedef struct Circle {
	SDL_Point position;
	int size;
	float speed;
	float rotationRadius;
	float timePassed;
} Circle;

void Circle_Init(Circle* c);
void Circle_Update(float delta, Circle* circle);
void Circle_Render(Circle* c);
void raster_circle(SDL_Renderer* renderer, int x0, int y0, int radius);

#endif