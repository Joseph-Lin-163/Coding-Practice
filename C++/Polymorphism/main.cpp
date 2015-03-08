#include <iostream>
#include <string>
#include "shape.h"
#include "circle.h"
#include "square.h"
using namespace std;

void printPrice(shape &s) {
	cout << "$";
	cout << 2*s.getArea(); 
}

void printPrice1(shape *s) {
	cout << "$";
	cout << 2*s->getArea(); 
}

int main() {

	// Non pointer version
	square s(3,4);
	circle c(5);
	cout << "Welcome to the window buying store, you've decided to purchase a square and circle window."
	<< " The area of the square is " << s.getArea() << " m^2 and the area of the circle is " << c.getArea()
	<< " m^2. You will need to pay $2/m^2." << endl;
	cout << "The square window cost comes out to ";
	printPrice(s); 
	cout << " and the circle window cost comes out to ";
	printPrice(c);
	cout << "." << endl;
	
	// Pointer version
	// square *s1 = new square(3,4);
	// circle *c1 = new circle(5);
	// cout << "Welcome to the window buying store, you've decided to purchase a square and circle window."
	// << " The area of the square is " << s1->getArea() << " m^2 and the area of the circle is " << c1->getArea()
	// << " m^2. You will need to pay $2/m^2." << endl;
	// cout << "The square window cost comes out to ";
	// printPrice1(s1); 
	// cout << " and the circle window cost comes out to ";
	// printPrice1(c1);
	// cout << "." << endl;
	// delete s1;
	// delete c1;	


	return 0;
}