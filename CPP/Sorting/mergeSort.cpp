#include<iostream>
using namespace std;

void merge(int *arr, int l, int mid, int r) {
	int i = l, j = mid + 1;
	int size = r - l + 1;
	int temp[size];
	int k = 0;
	while(i <= mid && j <= r) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid) {
		temp[k++] = arr[i++];
	}
	while(j <= r) {
		temp[k++] = arr[j++];
	}
	k = l;
	for(int i=0;i<size;i++) {
		arr[k++] = temp[i];
	}
}

void mergeSort(int *arr, int l, int r) {
	if(l < r) {
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int main() {
	int arr[] = {10, 5, 30, 15, 7};
	int n = 5;
	mergeSort(arr, 0, n-1);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}