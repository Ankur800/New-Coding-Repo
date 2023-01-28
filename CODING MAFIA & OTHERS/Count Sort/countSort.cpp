#include<iostream>
using namespace std;

void countSort(int* arr, int n) {
	static int c[10];
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		c[x]++;
	}
	int x = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < c[i]; j++) {
			arr[x] = i;
			x++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = { 4,4,3,0,1,2,2,3 };
	countSort(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}