#include <iostream>
#include "myQueue.h"
#include <queue>
using namespace std;

int main() {

	myQueue *a = new myQueue(100);
	cout << "Queue should be empty right now." << endl;
	a->front();
	if (a->is_empty() == true)
		cout << "Queue is empty." << endl;
	else
		cout << "Queue is not empty." << endl;
	cout << a->sizeOfQueue() << endl;
	a->push(3);
	a->push(4);
	cout << "Queue should have two elements. Front should be 3." << endl;
	cout << a->front() << endl;
	if (a->is_empty() == true)
		cout << "Queue is empty." << endl;
	else
		cout << "Queue is not empty." << endl;
	cout << a->sizeOfQueue() << endl;
	a->pop();
	cout << "Queue should have 1 element. Front should be 4." << endl;
	cout << a->front() << endl;
	if (a->is_empty() == true)
		cout << "Queue is empty." << endl;
	else
		cout << "Queue is not empty." << endl;
	cout << a->sizeOfQueue() << endl;

	return 0;
}