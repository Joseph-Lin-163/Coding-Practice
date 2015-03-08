#ifndef corgi_h
#define corgi_h

#include "animal.h"
#include "dog.h"
#include <string>

class corgi : public dog {
public:
	corgi(int weight) : dog(weight, "corgi") {

	}
	~corgi() {
		std::cout << "Corgi destructor called." << std::endl;
	}

	void breed() {
		std::cout << "I am a corgi!" << std::endl;
	}

	void makeNoise() {
		std::cout << "Bark! Bark! I'm a corgi!" << std::endl;
	}
private:

};


#endif