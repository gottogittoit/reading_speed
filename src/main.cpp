#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <sstream>
#include "fonts.h"
#include "guiwidgets.h"
#include "rendercontext.h"
#include "appcontext.h"
#include "inputhandler.h"
#include "parser.h"
#include "focusedText.h"

struct SDL_Application {
	AppContext appContext;
	RenderContext rContext;
	InputHandler inputHandler;
	Parser parser;
	FocusedText ft;

	std::stringstream mobySS;
	std::stringstream aliceSS;

	bool mRunning = true;

	SDL_Application() {
		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("SDL initialization failed!");
		}
		if (!TTF_Init()) {
			SDL_Log("SDL-TTF initialization failed!");
		}

		std::string mobyStr;
		parser.readFile("../../text-files/moby-dick.txt", mobyStr);	// (loads file based on working directory)
		mobySS = std::stringstream(mobyStr);

		std::string aliceStr;
		parser.readFile("../../text-files/alice's-adventures-in-wonderland.txt", aliceStr);
		aliceSS = std::stringstream(aliceStr);

		std::cout << "moby-dick length: " << mobyStr.length() << " alice length: " << aliceStr.length();

		ft = FocusedText(&mobySS);
		ft.checkPtr();
		//	Pseudocode
		//	while (advanceText)
		//			word = getWordFromString(string)	->stringstream will return a word until it is empty, and then returns a literal
		//			printWordToWindow(word)		->this function will control the speed at which the words get printed

		rContext.initializeTTFText();
	}

	~SDL_Application() {
		SDL_Quit();
	}

	void Input() {
		inputHandler.pollEvents(appContext);
	}

	void Update() {
		appContext.focusedWord = ft.returnWord();
	}

	void Render() {
		rContext.renderFrame(appContext);
	}

	void Tick() {
		Input();
		Update();
		Render();
	}

	void MainLoop() {
		while (appContext.mRunning) {
			Tick();
		}
	}

};

int main() {
	SDL_Application app;
	app.MainLoop();
	return 0;
}