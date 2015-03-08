#include <iostream>
#include "animal.h"
#include "dog.h"
#include "corgi.h"
using namespace std;

int main() {
	
	dog *a = new dog(20,"golden retriever");
	dog *b = new corgi(10);
	a->makeNoise();
	a->breed();
	b->makeNoise();
	b->breed();
	delete a;
	delete b;
	cout << "Notice how the type dog doesn't call corgi's destructor." << endl;
	corgi *c = new corgi(10);
	cout << "First use corgi's makeNoise and breed" << endl;
	c->makeNoise();
	c->breed();
	cout << "Now use parent class dog's makeNoise and breed" << endl;
	c->dog::makeNoise();
	c->dog::breed();
	delete c;

	return 0;
}