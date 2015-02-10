#ifndef quadimprov_h
#define quadimprov_h

#include <math.h>

class Quad {
	private: 
		int height;
		int width;

	public:
		/*Quad(int h, int w) {
			height = h;
			width = w;
		}*/
		
		Quad(int h, int w = 4) {
			height = h;
			width = w;
		}

		Quad() {
			height = 0;
			width = 0;
		}

		Quad(const Quad &src) {
			height = src.height;
			width = src.width;
		}

		~Quad() {
			std::cout << "Now I'm gone!" << std::endl;
		}

		int area() {
			return height*width;
		}

		float diagonal() {
			return sqrt(height*height + width*width);
		}
};

#endif