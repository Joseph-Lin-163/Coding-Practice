#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* This simple program takes input as follows:
     Line 0: Some integer T which specifies total numbers in a list
     Line 1-T: integers for program to invert the bits on
     
     This program inverts bits of numbers (y)
    */
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
		unsigned x;
		cin >> x;
        cout << ~x << endl;
    }
    return 0;
}
