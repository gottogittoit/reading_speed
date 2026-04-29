#include <SDL3\SDL.h>
#include <iostream>
#include <string>
#include "parser.h"

Parser::Parser() {}

void Parser::readFile(const char* filename, std::string& output) {
	iStream.open(filename, std::ios::in);
	if (iStream.is_open()) {
		//	Ignores BOM characters if present
		if (iStream.peek() == 0xEF) {
			iStream.ignore(3);
		}
		//	The default-constructed streambuf_iterator is known as the end-of-stream iterator; this line
		//	reads the entire file at once
		std::string txt((std::istreambuf_iterator<char>(iStream)), std::istreambuf_iterator<char>());
		/*for (int i = 0; i < 100; i++) {
			std::cout << txt[i];
		}*/
		output = std::move(txt);
		iStream.close();
	}
	else {
		SDL_Log("Error: file failed to open!");
		output = "";
	}
}

void Parser::extractWords(std::string& output, int numWords) {
	for (int i = 0; i < numWords; i++) {
		
	}
}