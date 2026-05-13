#ifndef GUI_WIDGETS_H
#define GUI_WIDGETS_H

#include <SDL3\SDL.h>

struct Button {
	SDL_FRect rect;
	bool hovered;
	bool increaseSpeed;
};

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


	Button upArrow = {
		.rect = {
		.x = 245,
		.y = 95,
		.w = 32,
		.h = 16},
		.hovered = false,
		.increaseSpeed = true
	};

	Button downArrow = {
		.rect = {
		.x = 245,
		.y = 116,
		.w = 32,
		.h = 16},
		.hovered = false,
		.increaseSpeed = false
	};

	SDL_FRect contentSettings = {
		.x = 60,
		.y = 160,
		.w = 75,
		.h = 50
	};

	SDL_FRect guiSettings = {
		.x = 150,
		.y = 160,
		.w = 75,
		.h = 50
	};

	static const int numWdgts = 5;
	SDL_FRect wdgtArray[numWdgts] = { textInfo, readingInfo, textContent, contentSettings, guiSettings };

	static const int numButtons = 2;
	Button buttonArray[numButtons] = { upArrow, downArrow };

};

#endif