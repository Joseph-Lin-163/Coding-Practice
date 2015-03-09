#ifndef animal_h
#define animal_h

class animal {
public:
	animal(int weight) {
		m_weight = weight;
	}

	virtual ~animal() {	
		std::cout << "Animal destructor called." << std::endl;
	}

	virtual void makeNoise() = 0;
	// pure virtual function, I don't have to give an implementation
	// here, but inheriting classes need to implement
private:
	int m_weight;

};

#endif