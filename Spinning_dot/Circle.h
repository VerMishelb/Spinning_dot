#ifndef CIRCLE_H
#define CIRCLE_H

#include "Input.h"

typedef struct Circle {
	SDL_Point position;
	int size;
	int offset;
	double speed;
} Circle;

void Circle_Init(Circle* c);
void Circle_Update(float delta, Circle* circle);
void Circle_Render(Circle* c);

#endif