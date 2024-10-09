#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int arr[5][5];
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			cin >> arr[row][col];
		}
	}
	int i, j;
	cin >> i >> j;
	cout << "Before:\n";
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			cout << arr[row][col]<<" ";
		}
		cout << '\n';
	}
	
	for (int row = 0; row < 5; row++) {
		swap(&arr[row][i-1], &arr[row][j-1]);
	}
	
	cout << "\nAfter:\n";
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			cout << arr[row][col]<<" ";
		}
		cout << "\n";
	}
	return 0;
}
/*
Test Example:

Input:
11 12 13 14 15
21 22 23 24 25
31 32 33 34 35
41 42 43 44 45
51 52 53 54 55
2 3

Output:
11 13 12 14 15
21 23 22 24 25
31 33 32 34 35
41 43 42 44 45
51 53 52 54 55
*/