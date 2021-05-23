/*
	Given an array of unsorted integers. Find peak(any one if there are many) element in the array.
	I/P:	{10, 20, 15, 5, 23, 90, 67}
	O/P:	20 OR 90

	Naive Approach: O(N)
	Efficient Approach: using binary search O(logN)
*/
#include<iostream>
using namespace std;

int findPeak(int arr[], int n) {
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = low + (high - low)/2;
		// Check whether mid is a peak, if so, return it.
		if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])) {
			return arr[mid];
		}
		// If left of mid is greater, atleast one peak will exist in left
		if(mid > 0 && arr[mid] < arr[mid-1]) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	return -1;
}

int main() {
	int arr[] = {10, 20, 15, 5, 23, 90, 67};
	int n = 7;
	cout<<findPeak(arr, n)<<endl;

	return 0;
}