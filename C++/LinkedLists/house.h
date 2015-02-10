#ifndef house_h
#define house_h

#include <string>

struct house {
	std::string name; // Which animal is here?
	house *next; // What is the address of the next animal?
};

#endif