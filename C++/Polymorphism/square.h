#ifndef square_h
#define square_h
#include "shape.h"

class square : public shape {
public:
	square(int x, int y) {
		m_x = x;
		m_y = y;
	}
	virtual ~square() {
		std::cout << "Deleting square!" << std::endl;
	}
	virtual double getArea() {
		return m_x*m_y;
	}
private:
	int m_x, m_y;
};

#endif