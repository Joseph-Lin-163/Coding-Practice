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

	queue<int> realQueue;
	realQueue.push(10);
	realQueue.push(20);
	cout << "Real Queue's front is: " << realQueue.front() << endl;
	realQueue.pop();
	cout << "Real Queue's front is: " << realQueue.front() << endl;
	realQueue.pop();
	if (realQueue.empty() == true)
		cout << "Real Queue is empty." << endl;
	else
		cout << "Real Queue isn't empty." << endl;

	return 0;
}