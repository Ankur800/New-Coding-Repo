/*
	Given an array of inetegers. Move all zeros at the end without affecting the sequence of non-zero elements.
	I/P:	{10, 8, 0, 0, 12, 0}
	O/P:	{10, 8, 12, 0, 0, 0}
*/
#include<iostream>
using namespace std;

void moveZerosToEnd(int *arr, int n) {
	int count = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] != 0) {
			swap(arr[i], arr[count]);
			count++;
		}
	}
}

int main() {
	int arr[] = {10, 8, 0, 0, 12, 0};
	int n = 6;

	moveZerosToEnd(arr, n);

	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}