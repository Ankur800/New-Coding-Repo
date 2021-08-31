/*
	Given length of a pipe n, and three lengths a, b and c. 
	Find the maximum number of pieces which can be obtained by cutting the rod.
	Each piece's length must be same as either a, or b, or c.
	I/P:	n = 25, a = 13, b = 11, c = 12
	O/P:	2  	(11, 12)

	I/P:	n = 5, a = 1, b = 2, c = 3
	O/P:	5 	(1, 1, 1, 1, 1)
*/
#include<bits/stdc++.h>
using namespace std;

// Top-Down
int getMaxCuts(int n, int a, int b, int c, vector<int> &dp) {
	if(n == 0) return 0;
	if(n < 0) return -1;
	if(dp[n] != -1) return dp[n];
	int ans = max(getMaxCuts(n-a, a, b, c, dp), max(getMaxCuts(n-b, a, b, c, dp), getMaxCuts(n-c, a, b, c, dp)));
	if(ans == -1) {
		dp[n] = ans;
	} else {
		dp[n] = 1 + ans;
	}

	return dp[n];
}

// Bottom-Up
int getMaxCutsEff(int n, int a, int b, int c) {
	vector<int> dp(n+1, -1);
	dp[0] = 0;
	for(int i=1;i<=n;i++) {
		if(i-a >= 0) {
			dp[i] = 1 + dp[i-a];
		}
		if(i-b >= 0) {
			dp[i] = max(dp[i], 1 + dp[i-b]);
		}
		if(i-c >= 0) {
			dp[i] = max(dp[i], 1 + dp[i-c]);
		}
	}

	return dp[n];
}

int main() {
	int n = 5;
	int a = 1, b = 2, c = 3;
	vector<int> dp(n+1, -1);
	cout<<getMaxCuts(n, a, b, c, dp)<<endl;
	cout<<getMaxCutsEff(n, a, b, c)<<endl;

	return 0;
}