#ifndef dog_h
#define dog_h

#include "animal.h"
#include <string>

class dog : public animal {
public:
	dog(int weight, std::string breed) : animal(weight) {
		m_breed = breed;
	}

	virtual ~dog() {
		std::cout << "Dog destructor called." << std::endl;
	}

	virtual void makeNoise() {
		std::cout << "Bark! Bark! Bark!" << std::endl;
	}

	virtual void breed() {
		std::cout << "I am a " << m_breed << "!" << std::endl;
	}

private:
	std::string m_breed;
};
#endif