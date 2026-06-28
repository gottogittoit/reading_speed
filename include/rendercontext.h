#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3\SDL.h>
#include "guiwidgets.h"
#include "appcontext.h"
#include "texturebag.h"

class RenderContext {
public:
	RenderContext();
	RenderContext(int width, int height, int renderW, int renderH);
	~RenderContext();

	void initializeTTFText();

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();

	void renderWord(AppContext& context);
	void initializeWindow(AppContext& context);
	void renderWPM(AppContext& context);
	void renderFrame(AppContext& context);
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	TTF_TextEngine* textEngine = nullptr;
	TTF_Text* word_TTFText = nullptr;
	TTF_Text* WPM_TTFText = nullptr;
};

#endif