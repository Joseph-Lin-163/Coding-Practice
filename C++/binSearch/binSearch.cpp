// Given a list of ordered elements, can you figure out which
// element the user chooses? (Element will be hard coded)

#include <iostream>
#include <string>
using namespace std;

void findNum(int someNum, int givenArr[], int size) {
	int lowerlimit = 0;
	int tempSize = size/2;
	bool foundNum = false;
	int lastTriedNum = -1;
	int count = 0;

	while (!foundNum) {
		count++;
		if (lastTriedNum != givenArr[tempSize]) {
			lastTriedNum = givenArr[tempSize];
		}
		else
			break;
		cout << "Trying position " << tempSize << "\n";
		if (someNum == givenArr[tempSize]) {
			cout << "Random number is " << tempSize << endl;
			cout << "It took us " << count << " tries to find the number." << endl;
			foundNum = true;
			return;
		}
		else {
			cout << "Wrong position\n";
			if (someNum < givenArr[tempSize]) {
				size = tempSize;
				tempSize = size/2;
			}
			else {
				lowerlimit = tempSize;
				tempSize = (lowerlimit + size)/2;
			}
		}
	}

	cout << "Error: Number not in list of ordered elements" << endl;
}

int main() {
	int chooseMe = 0;
	int arr[10000];
	for (int i = 0; i < 10000; i++) {
		arr[i] = i;
	}

	findNum(chooseMe,arr,10000);

	return 0;
}