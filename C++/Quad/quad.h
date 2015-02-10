#include <math.h>

class Quad {
	private: 
		int height;
		int width;

	public:
		int initialize(int h, int w) {
			height = h;
			width = w;
		}
		
		int area() {
			return height*width;
		}

		float diagonal() {
			return sqrt(height*height + width*width);
		}
};