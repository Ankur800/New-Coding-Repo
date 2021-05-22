/*
	Majority element is an element that appears more than n/2 times in an array of size n.
	Return the index(any index) of the element which is in majority.
	I/P:	{8, 8, 6, 6, 6, 4, 6}
	O/P:	2 or 3 or 4 or 6
*/
#include<iostream>
using namespace std;

int getMajorityElementIndex(int arr[], int n) {
	int res = 0, count = 1;
	// Step 1 Getting majority element
	for(int i=1;i<n;i++) {
		if(arr[res] == arr[i]) {
			count++;
		} else {
			count--;
		}

		if(count == 0) {
			res = i;
			count = 1;
		}
	}

	// Step 2 verification
	count = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] == arr[res]) {
			count++;
		}
	}
	if(count <= n/2) {
		return -1;
	}

	return res;
}

int main() {
	int arr[] = {8, 8, 6, 6, 6, 4, 6};
	int n = 7;
	cout<<getMajorityElementIndex(arr, n)<<endl;

	return 0;
}