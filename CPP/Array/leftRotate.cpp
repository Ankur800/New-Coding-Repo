/*
	Given an array of elements. Rotate the array to left by d space.
	I/P:	arr = {1, 2, 3, 4, 5}	d = 2
	O/P:	{3, 4, 5, 1, 2}
*/

// O(n) and O(1) space
#include<iostream>
using namespace std;

void reverse(int *arr, int l, int h) {
	while(l < h) {
		swap(arr[l], arr[h]);
		l++;
		h--;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int d = 2;
	int n = 5;

	reverse(arr, 0, d-1);
	reverse(arr, d, n-1);
	reverse(arr, 0, n-1);

	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}