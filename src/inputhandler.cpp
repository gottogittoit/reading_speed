#include <chrono>
#include <iostream>
#include "inputhandler.h"
#include "constants.h"

InputHandler::InputHandler() {}

void InputHandler::pollEvents(AppContext& context) {
	while (SDL_PollEvent(&context.mEvent)) {
		switch (context.mEvent.type) {
		case SDL_EVENT_QUIT:
			context.mRunning = false;
			SDL_Log("App quit!");
			break;
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			for (auto& button : context.wdgts.buttonArray) {
				if (button.hovered) {
					modifyWordTimer(context, button.increaseSpeed);
					std::cout << "Word timer modified: " << button.increaseSpeed;
				}
			}
			break;
		}
	}
}

void InputHandler::wordTimer(AppContext& context) {
	using namespace std::literals;
	using Clock = std::chrono::steady_clock;

	static auto lastWordTime = Clock::now();
	auto currentTime = Clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWordTime) >= context.mutableSpeed) {
		lastWordTime = currentTime;
		context.displayNewWord = true;
	}
}

void InputHandler::modifyWordTimer(AppContext& context, bool increase) {
	if (increase && context.WPM < context.maxWPM) {
		context.WPM += 10.0;
		std::chrono::duration<double> d = std::chrono::duration<double>{ 60.0 / (context.WPM) };
		context.mutableSpeed = std::chrono::duration_cast<std::chrono::milliseconds>(d);
	}
	else if (!increase && context.WPM > context.minWPM){
		context.WPM -= 10.0;
		std::chrono::duration<double> d = std::chrono::duration<double>{ 60.0 / (context.WPM) };
		context.mutableSpeed = std::chrono::duration_cast<std::chrono::milliseconds>(d);
	}
}

void transformMouseInput(AppContext& context, SDL_Renderer* renderer, SDL_FPoint& point) {
    SDL_FRect renderRect;
    SDL_GetRenderLogicalPresentationRect(renderer, &renderRect);

    float x, y;
    SDL_GetMouseState(&x, &y);

    float tx, ty;
    tx = (x / renderRect.w) * Constants::renderLogicalW;
    ty = (y / renderRect.h) * Constants::renderLogicalH;

    point.x = tx;
    point.y = ty;
}

void InputHandler::handleMouseInput(AppContext& context, SDL_Renderer* renderer) {
    SDL_FPoint transformed;
    transformMouseInput(context, renderer, transformed);

    for (auto& button : context.wdgts.buttonArray) {
        if (SDL_PointInRectFloat(&transformed, &button.rect)) {
            button.hovered = true;
        }
		else {
			button.hovered = false;
		}
    }
}