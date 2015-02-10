// Given a list of 13 integers, can you figure out whether they are
// a Fibonacci sequence?

#include <iostream>
#include <string>
using namespace std;

bool isFib(int array[]) {
	for (int i = 0; i < 13; i++) {
		if (array[i] + array[i+1] != array[i+2])
			return false;
	}
	return true;
}

int main() {
	int arr[20] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377};
	if (isFib(arr))
		cout << "Success!\n";

	return 0;
}