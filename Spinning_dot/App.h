#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <stdio.h>
#include "Defines.h"

int App_Init(void);
void App_Update(float delta);
void App_Render(void);
void App_Destroy(void);

#endif