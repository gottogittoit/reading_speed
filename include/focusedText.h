#ifndef FOCUSED_TEXT_H
#define FOCUSED_TEXT_H

#include <string>
#include <sstream>

class FocusedText {
public:
	FocusedText() {}
	FocusedText(std::stringstream* streamPtr);
	//FocusedText operator=(FocusedText ft);

	void checkPtr();

	std::string returnWord();
private:
	std::stringstream* mStreamPtr = nullptr;
	bool advanceText = false;		// toggled by play button
};

#endif