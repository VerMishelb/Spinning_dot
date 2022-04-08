#include "Circle.h"
#include <math.h>
extern struct App app;

void Circle_Init(Circle* c) {
	*c = (Circle){
		{app.w_width / 2, app.w_height / 2},
		10,
		-5,
		1.0
	};
}

void Circle_Update(float delta, Circle* circle) {
	if (INPUT_GET(app.input, Input_Left)) {
		circle->speed -= 0.1;
	}
	if (INPUT_GET(app.input, Input_Right)) {
		circle->speed += 0.1;
	}
}

void Circle_Render(Circle* c) {
	SDL_SetRenderDrawColor(app.renderer, 0xff, 0xff, 0xff, 0xff);
	for (int i = 0; i < 180; ++i) {
		double cosArg = i / 180. * PI;
		SDL_RenderDrawPointF(app.renderer, c->position.x + cos(cosArg) * c->size, c->position.y + sin(cosArg) * c->size);
		SDL_RenderDrawPointF(app.renderer, c->position.x + cos(cosArg) * c->size, c->position.y - sin(cosArg) * c->size);
	}
}