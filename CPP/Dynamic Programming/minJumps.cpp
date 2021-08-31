/*
	Given an array which elements represents the maximum possible jump from that index.
	Find the minimum number of jumps to reach the end.
	I/P:	arr[] = { 3, 4, 2, 1, 2, 1 }
	O/P:	2 		(3 -> 4 -> 1)			3	4	2	1	2	1
											↓	↑↓	  			↑
											↓→→→↑↓→→→→→→→→→→→→→→↑
											  1			4
*/
#include<bits/stdc++.h>
using namespace std;

// Top-Down
int getMinSteps(vector<int> &arr, int n, vector<int> &dp) {
	if(n == 1) return 0;
	if(dp[n] != INT_MAX) return dp[n];

	int res = INT_MAX;
	for(int i=0;i<n-1;i++) {
		if((arr[i] + i) >= n-1) {
			int ans = getMinSteps(arr, i+1, dp);
			if(ans != INT_MAX) {
				res = min(res, 1 + ans);
			}
		}
	}

	dp[n] = res;
	return res;
}

// Bottom-Up
int getMinStepsEff(vector<int> &arr) {
	int n = arr.size();
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(arr[j] + j >= i) {
				if(dp[j] != INT_MAX) {
					dp[i] = min(dp[i], 1+dp[j]);
				}
			}
		}
	}

	return dp[n-1];
}

int main() {
	vector<int> arr = { 3, 4, 2, 1, 2, 1 };
	int n = arr.size();
	vector<int> dp(n+1, INT_MAX);
	cout<<getMinSteps(arr, n, dp)<<endl;
	cout<<getMinStepsEff(arr)<<endl;

	return 0;
}