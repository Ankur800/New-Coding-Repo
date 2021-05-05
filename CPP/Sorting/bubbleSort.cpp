#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
	for(int i=0;i<n-1;i++) {
		bool isSorted = true;
		for(int j=0;j<n-i-1;j++) {
			if(arr[j] > arr[j+1]) {
				isSorted = false;
				swap(arr[j], arr[j+1]);
			}
		}
		if(isSorted) {
			break;
		}
	}
}

int main() {
	int arr[] = {2, 10, 8, 7};
	bubbleSort(arr, 4);
	for(int i=0;i<4;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}