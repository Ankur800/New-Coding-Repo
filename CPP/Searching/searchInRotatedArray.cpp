/*
	Search an element in a sorted and rotated array.
	I/P:	{100, 200, 300, 400, 20, 30, 40}	x = 20
	O/P:	True

	Naive approach- Linear Search O(n)
	Binary Search - O(logN)

	Key concept- In any sorted and rotated array, atleast one half is always sorted.
*/
#include<iostream>
using namespace std;

int isElementExist(int arr[], int n, int x) {
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		// Check which part is sorted
		if(arr[mid] == x) {
			return mid;
		}
		if(arr[low] <= arr[mid]) {
			// Left part is sorted
			// If left part contains the element
			if(arr[low] <= x && arr[mid] > x) {		// Yes
				high = mid - 1;
			} else {								// No
				low = mid + 1;
			}
		} else {
			// Right part is sorted
			// If right part contains the element
			if(arr[mid] < x && arr[high] >= x) { 	// Yes
				low = mid + 1;
			} else {								// No
				high = mid - 1;
			}
		}
	}

	return -1;
}

int main() {
	int arr[] = {100, 200, 300, 400, 20, 30, 40};
	int n = 7;
	int x = 20;
	cout<<isElementExist(arr, n, x)<<endl;

	return 0;
}