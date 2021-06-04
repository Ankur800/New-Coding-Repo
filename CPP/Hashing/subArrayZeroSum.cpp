/*
	Given an array. Find if there exists a subarray with zero sum or not.
	I/P:	{-3, 4, -3, -1, 1}
	O/P:	Yes
*/
#include<iostream>
#include<unordered_set>
using namespace std;

bool isZeroSumExists(int arr[], int n) {
	unordered_set<int> s;
	int sum = 0;
	s.insert(0);
	for(int i=0;i<n;i++) {
		sum += arr[i];
		if(s.find(sum) != s.end()) {
			return true;
		} else {
			s.insert(sum);
		}
	}

	return false;
}

int main() {
	int arr[] = {3, 4, -3, -1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	if(isZeroSumExists(arr, n)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}