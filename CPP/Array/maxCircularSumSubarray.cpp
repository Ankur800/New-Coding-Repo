/*
	The task is to find maximum circular sum subarray of a given array. 
	I/P:	{3, -4, 5, 6, -8, 7}
	O/P:	17

	max_sum = max(max_linear_sum + max_circular_sum)
	max_circular_sum = totalSum - min_linear_sum
*/
#include<iostream>
using namespace std;

int kadane(int arr[], int n) {
	int maxSum = 0;
	int tempSum = 0;
	for(int i=0;i<n;i++) {
		tempSum += arr[i];
		if(tempSum < 0) {
			tempSum = 0;
		}
		maxSum = max(maxSum, tempSum);
	}
	return maxSum;
}

int main() {
	int arr[] = {3, -4, 5, 6, -8, 7};
	int n = 6;

	int maxLinearSum = kadane(arr, n);

	if(maxLinearSum < 0) {
		cout<<maxLinearSum<<endl;
		return 0;
	}

	// Now we need to find minimum sub-array sum
	int totalSum = 0;
	for(int i=0;i<n;i++) {
		totalSum += arr[i];
		arr[i] = -arr[i];
	}

	int minLinearSum = kadane(arr, n);

	int maxCircularSum = totalSum + minLinearSum;		// totalSum - (-minLinearSum)

	int maxSum = max(maxLinearSum, maxCircularSum);

	cout<<maxSum<<endl;

	return 0;
}