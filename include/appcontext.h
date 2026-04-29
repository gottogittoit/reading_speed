#ifndef APP_CONTEXT_H
#define APP_CONTEXT_H

#include <SDL3_ttf\SDL_ttf.h>
#include <string>

struct AppContext {
	AppContext() {
		mRunning = true;
	}

	SDL_Event mEvent{};
	bool mRunning;

	TTF_Text* text = nullptr;
	std::string focusedWord{};
};

#endif