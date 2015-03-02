#include <iostream>
#include "myStack.h"
#include <stack>
using namespace std;

int main() {

	myStack *a = new myStack(100);
	cout << "Stack should currently be empty." << endl;
	cout << a->is_empty() << endl;
	cout << a->peek_top() << endl;
	a->printSizeOfStack();
	cout << "Confirm." << endl;
	a->push(4);
	a->push(5);
	cout << "Stack should currently have 2 elements. 5 on top." << endl;
	cout << a->is_empty() << endl;
	cout << a->peek_top() << endl;
	a->printSizeOfStack();
	cout << "Confirm." << endl;
	a->pop();
	cout << "Stack should currently have 1 element. 4 on top." << endl;
	cout << a->is_empty() << endl;
	cout << a->peek_top() << endl;
	a->printSizeOfStack();
	cout << "Confirm." << endl;

	stack<int> realStack;
	realStack.push(10);
	realStack.push(20);
	cout << realStack.top() << endl;
	realStack.pop(); // Note, pop doesn't return any value!
	cout << realStack.top() << endl;
	cout << realStack.empty() << endl;

	return 0;
}