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
#include "texturemanager.h"
#include "texturebag.h"

struct SDL_Application {
	AppContext appContext;
	RenderContext rContext;
	InputHandler inputHandler;
	Parser parser;
	FocusedText ft;
	TextureManager textureManager;

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
		parser.readFile("assets/text-files/moby-dick.txt", mobyStr);
		mobySS = std::stringstream(mobyStr);

		std::string aliceStr;
		parser.readFile("assets/text-files/alice's-adventures-in-wonderland.txt", aliceStr);
		aliceSS = std::stringstream(aliceStr);

		std::cout << "moby-dick length: " << mobyStr.length() << " alice length: " << aliceStr.length();

		ft = FocusedText(&mobySS);
		ft.checkPtr();
		//	Pseudocode
		//	while (advanceText)
		//			word = getWordFromString(string)	->stringstream will return a word until it is empty, and then returns a literal
		//			printWordToWindow(word)		->this function will control the speed at which the words get printed

		loadTextures();
		rContext.initializeTTFText();
		rContext.initializeWindow(appContext);
	}

	~SDL_Application() {
		SDL_Quit();
	}

	void loadTextures() {
		appContext.textureBag.upArrow.loadTexture(rContext.getRenderer(), "assets/arrow1.bmp");
		appContext.textureBag.upArrowHovered.loadTexture(rContext.getRenderer(), "assets/arrow2.bmp");
		appContext.textureBag.downArrow.loadTextureRotated(rContext.getRenderer(), "assets/arrow1.bmp", 180.0f);
		appContext.textureBag.downArrowHovered.loadTextureRotated(rContext.getRenderer(), "assets/arrow2.bmp", 180.0f);

		appContext.textureBag.pause.loadTexture(rContext.getRenderer(), "assets/pause1.bmp");
		appContext.textureBag.pauseHovered.loadTexture(rContext.getRenderer(), "assets/pause2.bmp");
		appContext.textureBag.play.loadTexture(rContext.getRenderer(), "assets/play1.bmp");
		appContext.textureBag.playHovered.loadTexture(rContext.getRenderer(), "assets/play2.bmp");


		//	TODO
		/*appContext.textureBag.play.loadTexture(rContext.getRenderer(), "assets/play.bmp");
		appContext.textureBag.rewind.loadTexture(rContext.getRenderer(), "assets/rewind.bmp");
		appContext.textureBag.ffw.loadTexture(rContext.getRenderer(), "assets/ffw.bmp");*/

	}

	void Input() {
		inputHandler.pollEvents(appContext);
		inputHandler.wordTimer(appContext);
		inputHandler.handleMouseInput(appContext, rContext.getRenderer());
	}

	void Update() {
		if (appContext.displayNewWord) {
			appContext.focusedWord = ft.returnWord();
			appContext.displayNewWord = false;
		}
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