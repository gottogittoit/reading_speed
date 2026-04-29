#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3\SDL.h>
#include "guiwidgets.h"
#include "appcontext.h"

class RenderContext {
public:
	RenderContext();
	RenderContext(int width, int height, int renderW, int renderH);
	~RenderContext();

	void initializeTTFText();

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();

	void renderWord(AppContext& appContext);
	void renderFrame(AppContext& appContext);
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	TTF_TextEngine* textEngine = nullptr;
	TTF_Text* text = nullptr;

	GUIWidgets wdgts;

};

#endif