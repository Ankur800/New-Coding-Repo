/*
	Given a binary array. Find the length of longest subarray with equal number of zeros and ones.
	I/P:	{1, 0, 1, 1, 1, 0, 0}
	O/P:	6
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int findLength(int arr[], int n) {
	unordered_map<int, int> m;		// We will store sum and index
	int sum = 0;
	int ans = 0;
	for(int i=0;i<n;i++) {
		sum += (arr[i] == 1) ? 1 : -1;
		if(sum == 0) {
			ans = i+1;
		}
		if(m.find(sum) == m.end()) {
			m.insert({sum, i});
		} else {
			ans = max(ans, i - m[sum]);
		}
	}

	return ans;
}

int main() {
	int arr[] = {1, 0, 1, 1, 1, 0, 0};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<findLength(arr, n)<<endl;

	return 0;
}