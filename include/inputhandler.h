#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL3\SDL.h>
#include "appcontext.h"

class InputHandler {
public:
	InputHandler();
	void pollEvents(AppContext& context);
};

#endif