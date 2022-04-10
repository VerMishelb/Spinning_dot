#include <stdlib.h>
#include "App.h"

extern struct App app;

int main(int argc, char* argv[]) {
	//atexit(App_Destroy);

	if (App_Init()) {
		app.stop = 1;
	}
	while (!app.stop) {
		App_Update(1/60.f);
		App_Render();
	}
	App_Destroy();
	return 0;
}