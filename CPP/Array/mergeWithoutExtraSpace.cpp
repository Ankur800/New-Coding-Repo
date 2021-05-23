/*
	Given two sorted arrays. Merge them with O(1) space or merge them without using extra space.
	I/P:	arr1[] = {10, 20, 30, 40, 50}	arr2[] = {5, 15, 25, 35, 45}
	O/P:	arr1[] = {5, 10, 15, 20, 25}	arr2[] = {30, 35, 40, 45, 50}
*/
#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n1, int n2) {
	int n = n1 + n2;
	int gap = (n + 1) / 2;
	while(gap > 0) {
		// For First Array
		int i;
		for(i=0;i+gap<n1;i++) {
			if(arr1[i] > arr1[i+gap]) {
				swap(arr1[i], arr1[i+gap]);
			}
		}

		// For Second Array
		for(;i<n1;i++) {
			if((i+gap-n1) < n2 ) {
				if(arr1[i] > arr2[i+gap-n1]) {
					swap(arr1[i], arr2[i+gap-n1]);
				}
			}
		}

		// For Third Array
		for(i=0;i+gap<n2;i++) {
			if(arr2[i] > arr2[i+gap]) {
				swap(arr2[i], arr2[i+gap]);
			}
		}

		if(gap == 1) {
			break;
		}
		gap = (gap + 1)/2;
	}
}

int main() {
	int arr1[] = {10, 20, 30, 40, 50};
	int n = 5;
	int arr2[] = {5, 15, 25, 35, 45};
	int m = 5;

	merge(arr1, arr2, n, m);

	for(int i=0;i<n;i++) {
		cout<<arr1[i]<<" ";
	}
	for(int i=0;i<m;i++) {
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	return 0;
}