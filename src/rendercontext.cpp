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

void RenderContext::renderWord(AppContext& appContext) {
	if (TTF_SetTextString(appContext.text, appContext.focusedWord.c_str(), 0)) {
		SDL_Log("Text string set!\n");
		if (TTF_DrawRendererText(appContext.text, 100.0f, 100.0f)) {
			SDL_Log("Word rendered!\n");
		}
	}
	else {
		SDL_Log("Error: renderWord() failed!");
	}
}

void RenderContext::renderFrame(AppContext& appContext) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderRects(renderer, wdgts.wdgtArray, wdgts.numWdgts);

	renderWord(appContext);

	SDL_RenderPresent(renderer);
}