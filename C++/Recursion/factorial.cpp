#include <iostream>

using namespace std;

int computeFactorial(int n) {
	if (n == 0)
		return 1;

	return n*computeFactorial(n-1);

}

int main() {

	int a = computeFactorial(5);
	cout << a << endl;

	return 0;
}