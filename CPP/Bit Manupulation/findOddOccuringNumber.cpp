/*
	Given an array of inetegers. All numbers are appearing even number of times except one number.
	Find that number.
	I/P:	{4, 3, 4, 4, 4, 5, 5}
	O/P:	3
*/
#include<iostream>
using namespace std;

int oddOccurringEle(int arr[], int n) {
	int res = 0;
	for(int i=0;i<n;i++) {
		res = (res ^ arr[i]);
	}

	return res;
}

int main() {
	int arr[] = {4, 3, 3, 5, 4, 5, 5};
	int n = 7;
	cout<<oddOccurringEle(arr, n)<<endl;

	return 0;
}