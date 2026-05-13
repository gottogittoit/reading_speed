#ifndef FONTS_H
#define FONTS_H

#include <SDL3_ttf\SDL_ttf.h>
#include <iostream>
#include <filesystem>

namespace Fonts {
	inline TTF_Font* getFocusedWordFont() {
		static TTF_Font* focusedWordFont = [] {
			TTF_Font* tempFont;
			try {
				tempFont = TTF_OpenFont("assets/Roboto-VariableFont_wdth,wght.ttf", 20.0f);
				if (!tempFont) {
					throw "Couldn't open focusedWordFont\n";
				}
			}
			catch (const char* exception) {
				std::cout << "Exception: " << exception;
			}
			return tempFont;
			}();
		return focusedWordFont;
	}
}

#endif