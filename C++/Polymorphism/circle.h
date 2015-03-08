#ifndef circle_h
#define circle_h
#include "shape.h"

class circle : public shape {
public:
	circle(int rad) {
		m_rad = rad;
	}
	~circle() {
		std::cout << "Deleting circle!" << std::endl;
	}
	virtual double getArea() {
		return m_rad*m_rad*3.14;
	}
private:	
	int m_rad;
};

#endif