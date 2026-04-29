#ifndef GUI_WIDGETS_H
#define GUI_WIDGETS_H

#include <SDL3\SDL.h>

struct GUIWidgets {
	GUIWidgets() {}

	SDL_FRect textInfo = {
		.x = 60,
		.y = 25,
		.w = 100,
		.h = 50
	};

	SDL_FRect readingInfo = {
		.x = 200,
		.y = 25,
		.w = 75,
		.h = 50
	};

	SDL_FRect textContent = {
		.x = 90,
		.y = 90,
		.w = 150,
		.h = 60
	};

	SDL_FRect contentSettings = {
		.x = 60,
		.y = 160,
		.w = 75,
		.h = 50
	};

	SDL_FRect guiSettings = {
		.x = 60,
		.y = 160,
		.w = 75,
		.h = 50
	};

	static const int numWdgts = 5;
	SDL_FRect wdgtArray[numWdgts] = { textInfo, readingInfo, textContent, contentSettings, guiSettings };

};

#endif