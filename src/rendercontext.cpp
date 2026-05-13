#include "rendercontext.h"
#include "fonts.h"
#include <iostream>

RenderContext::RenderContext() {
	if (!SDL_CreateWindowAndRenderer("Reading Speed App", 800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_Log("Window and renderer creation failed!");
	}
	SDL_SetRenderLogicalPresentation(renderer, 320, 240, SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

RenderContext::RenderContext(int width, int height, int renderW, int renderH) {
	if (!SDL_CreateWindowAndRenderer("Reading Speed App", width, height, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_Log("Window and renderer creation failed!");
	}
	SDL_SetRenderLogicalPresentation(renderer, renderW, renderH, SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

RenderContext::~RenderContext() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderContext::initializeTTFText() {
	textEngine = TTF_CreateRendererTextEngine(renderer);
	text = TTF_CreateText(textEngine, Fonts::getFocusedWordFont(), "null", 0);
}

SDL_Window* RenderContext::getWindow() {
	return window;
}

SDL_Renderer* RenderContext::getRenderer() {
	return renderer;
}

void RenderContext::renderWord(AppContext& context) {
	//	TO-DO: Should throw an exception if either the text string is not set or the word is not rendered
	if (TTF_SetTextString(text, context.focusedWord.c_str(), 0)) {
		TTF_DrawRendererText(text, 100.0f, 100.0f);
	}
	else {
		SDL_Log("Error: renderWord() failed!");
	}
}

void RenderContext::initializeWindow(AppContext& context) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (!SDL_RenderRects(renderer, context.wdgts.wdgtArray, context.wdgts.numWdgts)) {
		SDL_Log("Error: GUI rectangles not rendered!");
	}

	if (!SDL_RenderTexture(renderer, context.textureBag.upArrow.getTexture(), nullptr, &context.wdgts.upArrow.rect)) {
		SDL_Log("Error: Up Arrow texture not rendered!");
	}
	if (!SDL_RenderTexture(renderer, context.textureBag.downArrow.getTexture(), nullptr, &context.wdgts.downArrow.rect)) {
		SDL_Log("Error: Down Arrow texture not rendered!");
	}

	SDL_RenderPresent(renderer);
}

void RenderContext::renderFrame(AppContext& context) {
	//SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	//SDL_RenderClear(renderer);

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderRects(renderer, context.wdgts.wdgtArray, context.wdgts.numWdgts);
	// 
	//	Clear the area where text is drawn
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderClear(renderer);

	//	Render the GUI rectangles and the arrows
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (!SDL_RenderRects(renderer, context.wdgts.wdgtArray, context.wdgts.numWdgts)) {
		SDL_Log("Error: GUI rectangles not rendered!");
	}
	for (auto& button : context.wdgts.buttonArray) {
		if (button.increaseSpeed) {
			if (button.hovered) {
				SDL_RenderTexture(renderer, context.textureBag.upArrowHovered.getTexture(), nullptr, &context.wdgts.upArrow.rect);
			}
			else{
				SDL_RenderTexture(renderer, context.textureBag.upArrow.getTexture(), nullptr, &context.wdgts.upArrow.rect);
			}
		}
		else {
			if (button.hovered) {
				SDL_RenderTexture(renderer, context.textureBag.downArrowHovered.getTexture(), nullptr, &context.wdgts.downArrow.rect);
			}
			else {
				SDL_RenderTexture(renderer, context.textureBag.downArrow.getTexture(), nullptr, &context.wdgts.downArrow.rect);
			}
		}
	}

	renderWord(context);
	/*if (context.displayWord) {
		renderWord(context);
		context.displayWord = false;
	}*/

	SDL_RenderPresent(renderer);
}