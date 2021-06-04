/*
	Find longest subarray with given sum.
	I/P:	{8, 3, 1, 5, -6, 6, 2, 2} 		sum = 4
	O/P:	4		Index(4, 7)
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubArray(int arr[], int n, int sum) {
	unordered_map<int, int> m;		// We will store prefix_sum and index
	int prefix_sum = 0;
	int res = 0;	// length of subarray
	for(int i=0;i<n;i++) {
		prefix_sum += arr[i];
		if(prefix_sum == sum) {
			res = i+1;
		}
		if(m.find(prefix_sum) == m.end()) {
			m.insert({prefix_sum, i});
		}
		if(m.find(prefix_sum - sum) != m.end()) {
			res = max(res, i - m[prefix_sum - sum]);
		}
	}

	return res;
}

int main() {
	int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 4;

	cout<<longestSubArray(arr, n, sum)<<endl;

	return 0;
}