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
	word_TTFText = TTF_CreateText(textEngine, Fonts::getFocusedWordFont(), "null", 0);
	WPM_TTFText = TTF_CreateText(textEngine, Fonts::getFocusedWordFont(), "0", 0);
}

SDL_Window* RenderContext::getWindow() {
	return window;
}

SDL_Renderer* RenderContext::getRenderer() {
	return renderer;
}

//	Renders each word of the text
void RenderContext::renderWord(AppContext& context) {
	//	TODO: Should throw an exception if either the text string is not set or the word is not rendered
	if (TTF_SetTextString(word_TTFText, context.focusedWord.c_str(), 0)) {
		TTF_DrawRendererText(word_TTFText, 100.0f, 100.0f);
	}
	else {
		SDL_Log("Error: renderWord() failed!");
	}
}

void RenderContext::initializeWindow(AppContext& context) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (!SDL_RenderRects(renderer, context.gui.wdgtArray, context.gui.numWdgts)) {
		SDL_Log("Error: GUI rectangles not rendered!");
	}

	if (!SDL_RenderTexture(renderer, context.textureBag.upArrow.getTexture(), nullptr, &context.gui.upArrow.rect)) {
		SDL_Log("Error: Up Arrow texture not rendered!");
	}
	if (!SDL_RenderTexture(renderer, context.textureBag.downArrow.getTexture(), nullptr, &context.gui.downArrow.rect)) {
		SDL_Log("Error: Down Arrow texture not rendered!");
	}

	//	TODO: Render pause, play, rewind, and ffw textures
	if (!SDL_RenderTexture(renderer, context.textureBag.pause.getTexture(), nullptr, &context.gui.pause.rect)) {
		SDL_Log("Error: Pause texture not rendered!");
	}

	SDL_RenderPresent(renderer);
}

//	Renders the words per minute
void RenderContext::renderWPM(AppContext& context) {
	if (TTF_SetTextString(WPM_TTFText, (std::to_string(context.WPM)).c_str(), 0)) {
		TTF_DrawRendererText(WPM_TTFText, 115.0f, 40.0f);
	}
	else {
		SDL_Log("Error: renderWPM() failed!");
	}
}

void RenderContext::renderFrame(AppContext& context) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderClear(renderer);

	//	Render the GUI rectangles and the arrows
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (!SDL_RenderRects(renderer, context.gui.wdgtArray, context.gui.numWdgts)) {
		SDL_Log("Error: GUI rectangles not rendered!");
	}
	//	TODO: Consider generalizing this for loop
	for (auto& button : context.gui.buttonArray) {
		if (button.increaseSpeed) {
			if (button.hovered) {
				SDL_RenderTexture(renderer, context.textureBag.upArrowHovered.getTexture(), nullptr, &context.gui.upArrow.rect);
			}
			else{
				SDL_RenderTexture(renderer, context.textureBag.upArrow.getTexture(), nullptr, &context.gui.upArrow.rect);
			}
		}
		else {
			if (button.hovered) {
				SDL_RenderTexture(renderer, context.textureBag.downArrowHovered.getTexture(), nullptr, &context.gui.downArrow.rect);
			}
			else {
				SDL_RenderTexture(renderer, context.textureBag.downArrow.getTexture(), nullptr, &context.gui.downArrow.rect);
			}
		}
	}
	//	TODO:	Render hovered/not hovered textures for pause, play, rewind, and ffw
	SDL_RenderTexture(renderer, context.textureBag.pause.getTexture(), nullptr, &context.gui.pause.rect);

	renderWPM(context);
	renderWord(context);

	SDL_RenderPresent(renderer);
}