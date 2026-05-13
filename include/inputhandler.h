#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL3\SDL.h>
#include "appcontext.h"

class InputHandler {
public:
	InputHandler();
	void pollEvents(AppContext& context);

	//	Signals when a word should be displayed
	void wordTimer(AppContext& context);
	void modifyWordTimer(AppContext& context, bool increase);
	void handleMouseInput(AppContext& context, SDL_Renderer* renderer);
};

#endif