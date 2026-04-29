#ifndef PARSER_H
#define PARSER_H

#include <fstream>

class Parser {
public:
	Parser();
	
	void readFile(const char* filename, std::string& output);
	void extractWords(std::string& output, int numWords);
private:
	std::ifstream iStream;
};

#endif