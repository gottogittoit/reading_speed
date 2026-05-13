#ifndef APP_CONTEXT_H
#define APP_CONTEXT_H

#include <SDL3_ttf\SDL_ttf.h>
#include <string>
#include <chrono>
#include "guiwidgets.h"
#include "texturebag.h"

struct AppContext {
	AppContext() {
		mRunning = true;
	}

	SDL_Event mEvent{};
	bool mRunning;

	std::string focusedWord{};
	/*	TO-DO: Need a variable here to represent how long the app should wait
		before displaying another word which will be calculated by a function
		that runs whenever the word-speed changing buttons on the GUI are
		clicked (so an InputHandler function).*/
	std::chrono::milliseconds defaultSpeed{ 250 };
	std::chrono::milliseconds mutableSpeed = defaultSpeed;
	int WPM = 60 / (defaultSpeed.count()*0.001);
	int maxWPM = 1000;
	int minWPM = 10;
	bool displayNewWord = false;

	GUIWidgets wdgts;
	TextureBag textureBag;
};

#endif