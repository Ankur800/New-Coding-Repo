/*
	Given an array of elements, find the length of longest increasing subsequence.
	I/P:	arr[] = { 8, 100, 150, 10, 12, 14, 110 }
	O/P:	5 		(8, 10, 12, 14, 110)
*/
#include<bits/stdc++.h>
using namespace std;

int ceilIdx(int tail[], int l, int r, int x) {
	while(l < r) {
		int mid = (l+r)/2;
		if(tail[mid] >= x) {
			r = mid;
		} else {
			l = mid+1;
		}
	}

	return r;
}

int LIS(int arr[], int n) {
	int tail[n], len = 1;
	tail[0] = arr[0];
	for(int i=1;i<n;i++) {
		if(arr[i] > tail[len-1]) {
			tail[len] = arr[i];
			len++;
		} else {
			int c = ceilIdx(tail, 0, len-1, arr[i]);
			tail[c] = arr[i];
		}
	}

	return len;
}

int main() {
	int arr[] = { 8, 100, 150, 10, 12, 14, 110 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<LIS(arr, n)<<endl;

	return 0;
}