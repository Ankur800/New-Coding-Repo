#include<iostream>
#include<climits>
using namespace std;

void selectionSortRecursive(int * arr, int index, int n) {
	// find min
	if(index == n-1) {
		return;
	}
	int minIndex = index;
	for(int i=index + 1;i<n;i++) {
		if(arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}
	swap(arr[index], arr[minIndex]);
	selectionSortRecursive(arr, index+1, n);
}

void selectionSort(int *arr, int n) {
	for(int i=0;i<n;i++) {
		// find min
		int min = INT_MAX;
		int minIndex = -1;
		for(int j=i;j<n;j++) {
			if(arr[j] < min) {
				min = arr[j];
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

int main() {
	int arr[] = {10, 5, 8, 20, 2, 18};
	int n = 6;
	//selectionSort(arr, n);
	selectionSortRecursive(arr, 0, n);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}