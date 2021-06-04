/*
	Given an array, we need to find the length of longest subsequence that has consecutive elements.
	These consecutive elements may appear in any order in the subsequence.
	I/P:	{1, 3, 9, 2, 8, 2}
	I/P:	3
*/
#include<iostream>
#include<unordered_set>
using namespace std;

int findLength(int arr[], int n) {
	unordered_set<int> s(arr, arr+n);

	int res = 1;
	for(auto it : s) {
		if(s.find(it-1) == s.end())	{	// It can be starting element of the subsequence
			int curr = 1;
			while(s.find(it+curr) != s.end()) {
				curr++;
			}

			res = max(curr, res);
		}
	}

	return res;
}

int main() {
	int arr[] = {1, 3, 9, 2, 8, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<findLength(arr, n)<<endl;

	return 0;
}