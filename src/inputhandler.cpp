#include "inputhandler.h"

InputHandler::InputHandler() {}

void InputHandler::pollEvents(AppContext& context) {
	while (SDL_PollEvent(&context.mEvent)) {
		switch (context.mEvent.type) {
		case SDL_EVENT_QUIT:
			context.mRunning = false;
			SDL_Log("App quit!");
			break;
		}
	}
}