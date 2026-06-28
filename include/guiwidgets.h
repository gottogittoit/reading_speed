#ifndef GUI_WIDGETS_H
#define GUI_WIDGETS_H

#include <SDL3\SDL.h>
#include <vector>

//	It is a general name in case I add more buttons, but for now only corresponds to the increase and decrease speed arrows
enum ButtonID {
	ARROW,
	PAUSE,
	PLAY,
	REWIND,
	FFW
};

struct Button {
	SDL_FRect rect;
	bool hovered;
	bool increaseSpeed;
	ButtonID id;
};

//	Each GUI element should be a block! For future features
struct GUIBlock {
	SDL_FRect box;
};

struct GUI {
	GUI() {}

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

	/*SDL_FRect contentSettings = {
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
	};*/

	Button upArrow = {
		.rect = {
		.x = 245,
		.y = 95,
		.w = 24,
		.h = 12},
		.hovered = false,
		.increaseSpeed = true,
		.id = ARROW
	};

	Button downArrow = {
		.rect = {
		.x = 245,
		.y = 116,
		.w = 24,
		.h = 12},
		.hovered = false,
		.increaseSpeed = false,
		.id = ARROW
	};

	Button pause = {
		.rect = {
			.x = 145,
			.y = 145,
			.w = 24,
			.h = 24},
			.hovered = false,
			.increaseSpeed = false,
			.id = PAUSE
	};

	Button play = {
		.rect = {
			.x = 145,
			.y = 145,
			.w = 24,
			.h = 24},
			.hovered = false,
			.increaseSpeed = false,
			.id = PLAY
	};


	static const int numWdgts = 2;
	SDL_FRect wdgtArray[numWdgts] = { textInfo, readingInfo };

	//	TODO: Decide if buttonArray should be arrowArray
	static const int numButtons = 2;
	Button buttonArray[numButtons] = { upArrow, downArrow };

};

#endif