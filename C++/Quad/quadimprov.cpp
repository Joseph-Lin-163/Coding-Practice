#include <iostream>
#include <string>
#include <quadimprov.h>
#include <quadimprov2.h>
using namespace std;

int main() {
	Quad q1(3);
	Quad q2[3];
	cout << "q1's area is " << q1.area() << endl;
	cout << "The length of the q1's diagonal is " << q1.diagonal() << endl;

	Quad *q3;
	q3 = new Quad[5];
	delete [] q3;

	Quad2 q4;

	return 0;
}