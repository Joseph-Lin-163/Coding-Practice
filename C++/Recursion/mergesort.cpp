#include <iostream>

using namespace std;

void merge(int arr [], int low, int mid, int high) {
	int *converge = new int[high - low + 1];
	int lowIndex = low;
	int highIndex = mid + 1;

	int index = 0;
	while (lowIndex <= mid && highIndex <= high) {
		if (arr[lowIndex] <= arr[highIndex]) {
			converge[index] = arr[lowIndex];
			lowIndex++;
		}
		else {
			converge[index] = arr[highIndex];
			highIndex++;
		}
		index++;
	}

	if (lowIndex <= mid) {
		for ( ; index < high - low + 1 ; index++) {
			converge[index] = arr[lowIndex];
			lowIndex++;
		}
	}
	else { 
		for ( ; index < high - low + 1; index++ ) {
			converge[index] = arr[highIndex];
			highIndex++;
		}
	}

	for (int i = 0; i < high - low + 1; i++) {
		arr[i+low] = converge[i];
	}

	delete [] converge;
}

void mergeSort(int arr [], int low, int high) {
	if (low < high) {
		int mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1,high);
		merge(arr, low, mid, high);
	}
}

int main() {

	int a[10] = {4,5,7,8,9,10,3,2,1,6};
	mergeSort(a,0,9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << endl;
	}

	return 0;
}