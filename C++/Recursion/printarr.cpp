#include <iostream>

using namespace std;

void printForward(int a [], int position, int size) {
	cout << a[position] << endl;
	if (position == size - 1)
		return;
	printForward(a, position+1, size);
}

void printBackward(int a [], int position, int size) {
	if (position == size)
		return;
	printBackward(a, position+1, size);
	cout << a[position] << endl;
}

int main() {

	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	printForward(a,0,10);
	printBackward(a,0,10);

	return 0;
}