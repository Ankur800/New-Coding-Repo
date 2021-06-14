/*
	We are given an array and a number k, we need to find maximums of all subarrays of size k.
	I/P:	10	8	5	12	15	7	6
	O/P:	10	12	15	15 15
*/
#include<iostream>
#include<deque>
using namespace std;

void printMax(int arr[], int n, int k) {
	deque<int> dq;

	for(int i=0;i<k;i++) {
		while(!dq.empty() && arr[i] >= arr[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(int i=k;i<n;i++) {
		cout<<arr[dq.front()]<<" ";

		while(!dq.empty() && dq.front() <= i - k) {
			dq.pop_front();
		}

		while(!dq.empty() && arr[i] >= arr[dq.back()]) {
			dq.pop_back();
		}

		dq.push_back(i);
	}

	cout<<arr[dq.front()]<<endl;
}

int main() {
	int arr[] = {10, 8, 5, 12, 15, 7, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	printMax(arr, n, k);

	return 0;
}