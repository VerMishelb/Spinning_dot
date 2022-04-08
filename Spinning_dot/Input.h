#ifndef BUTTONS_H
#define BUTTONS_H

#include "Defines.h"

#define INPUT_SET(i, k) i |= k
#define INPUT_UNSET(i, k) i &= ~k
#define INPUT_GET(i, k) ((i & k) ? 1 : 0)

enum Input {
	Input_Left = 1,
	Input_Right = 2,
	Input_Quit = 4
};

void Input_Update(struct App* app);

#endif // !BUTTONS_H
