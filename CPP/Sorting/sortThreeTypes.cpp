/*
	Given array with three types of numbers sort them by type.
	Suppose we have an array of elements containing 0, 1, 2.
	Group them by 0, 1, 2.
	I/P:	{0, 1, 2, 1, 1, 2}
	O/P:	{0, 1, 1, 1, 2, 2}
*/
#include<iostream>
using namespace std;

void sortByType(int arr[], int n) {
	int low = 0, high = n-1, mid = 0;
	while(mid <= high) {
		if(arr[mid] == 0) {
			swap(arr[mid], arr[low]);
			low++;mid++;
		} else if(arr[mid] == 1) {
			mid++;
		} else {
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}

int main() {
	int arr[] = {0, 1, 2, 1, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);

	sortByType(arr, n);

	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}