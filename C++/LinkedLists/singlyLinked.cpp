#include <iostream>
#include <string>
#include "singlyLinked.h"

using namespace std;

int main() {
	singlyLinked *someList = new singlyLinked();
	// cat -> dog -> rat -> bird -> moose
	someList->addItem("moose");
	someList->addItem("bird");
	someList->addItem("rat");
	someList->addItem("dog");
	someList->addItem("cat");
	someList->printSize();
	someList->printItems();
	someList->deleteItem(0);
	someList->printSize();
	someList->printItems();
	cout << "Dog is at position: " << someList->findItem("dog") << endl;
	someList->findItem("cat");
	cout << "Moose is at position: " << someList->findItem("moose") << endl;
	someList->deleteItem(5);
	someList->addItem("cat", 5);
	someList->addItem("pony", -1);
	someList->deleteItem("pony");
	someList->printSize();
	someList->printItems();
	delete someList;
	return 0;
}