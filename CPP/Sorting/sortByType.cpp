/*
	Given array with two types of numbers sort them by type.
	Suppose we have an array of elements of positive and negative type.
	We need to put negative elements first and then positive numbers. Order does't matter for a particular group.
	I/P:	{15, -3, -2, 18}
	O/P:	{-3, -2, 15, 18}

	We need to segregate an array of elements containing three types of elements.
		*	Sort an array of 0s, 1s, 2s.
		*	Three-way partitioning when multiple occurrences of a pivot may exist.
		*	Partitioning around a range.
*/
#include<iostream>
using namespace std;

void seperateElements(int arr[], int n) {
	int i=0, j=n-1;
	while(i < j) {
		if(arr[i] < 0 && arr[j] > 0) {
			i++;j--;
		} else if(arr[i] > 0 && arr[j] < 0) {
			swap(arr[i++], arr[j--]);
		} else if(arr[i] < 0) {
			i++;
		} else {
			j--;
		}
	}
}

int main() {
	int arr[] = {15, -3, -2, 18};
	int n = sizeof(arr)/sizeof(arr[0]);

	seperateElements(arr, n);

	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}