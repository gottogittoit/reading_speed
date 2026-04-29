#include "focusedText.h"
#include <iostream>

FocusedText::FocusedText(std::stringstream* textStream) {
	if (textStream) {
		mStreamPtr = textStream;
	}
	else {
		std::cerr << "Error: text stream is nullptr\n";
	}
}

//FocusedText FocusedText::operator=(FocusedText ft) {
//	mStreamPtr = ft.mStreamPtr;
//	std::cout << "FocusedText copy assignment operator called!\n";
//	return *this;
//}

void FocusedText::checkPtr() {
	if (!mStreamPtr) {
		std::cerr << "stream pointer is null!";
	}
}

std::string FocusedText::returnWord() {
	std::string word;
	if (*mStreamPtr >> word) {
		return word;
	}
	return "EOF!";
}