#include <iostream>
#include <string>
#include <quad.h>
using namespace std;

int main() {
	Quad q1;
	q1.initialize(3,4);

	cout << "q1's area is " << q1.area() << endl;
	cout << "The length of the q1's diagonal is " << q1.diagonal() << endl;

	return 0;
}