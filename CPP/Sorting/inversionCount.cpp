/*
	Count the inversions in array.
	There are two conditions for the  elements to be inverse:
	1.	arr[i] > arr[j]
	2.	i < j

	I/P:	{2, 4, 1, 3, 5}
	O/P:	3
*/
#include<iostream>
using namespace std;

int merge(int arr[], int l, int mid, int r) {
	int n1 = mid-l+1, n2 = r-mid;
	int left[n1], right[n2];
	for(int i=0;i<n1;i++) {
		left[i] = arr[l+i];
	}
	for(int i=0;i<n2;i++) {
		right[i] = arr[mid+1+i];
	}
	int res = 0, i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {
		if(left[i] <= right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
			res += (n1 - i);
		}
	}
	while(i < n1) {
		arr[k++] = left[i++];
	}
	while(j < n2) {
		arr[k++] = right[j++];
	}

	return res;
}

int getInversions(int arr[], int l, int r) {
	int res = 0;
	if(l < r) {
		int mid = (l + r) / 2;
		res += getInversions(arr, l, mid);
		res += getInversions(arr, mid + 1, r);
		res += merge(arr, l, mid, r);
	}

	return res;
}

int main() {
	int arr[] = {2, 4, 1, 3, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<getInversions(arr, 0, n-1)<<endl;

	return 0;
}