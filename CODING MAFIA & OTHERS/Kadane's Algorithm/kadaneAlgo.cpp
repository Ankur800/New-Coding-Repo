#include<iostream>
using namespace std;

void kadaneAlgo(int* arr, int n) {
	int maxSum = arr[0];
	int currentSum = arr[0];
	for (int i = 1; i < n; i++) {
		if (currentSum + arr[i] < 0)
			currentSum = 0;
		else {
			currentSum = currentSum + arr[i];
			if (currentSum > maxSum)
				maxSum = currentSum;
		}
	}
	cout << "The maximum sum by the array is " << maxSum << endl;
}

int main() {
	int arr[] = { 4,5,-5,3,9,-2,-9 };
	kadaneAlgo(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}