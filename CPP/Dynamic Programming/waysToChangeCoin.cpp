/*
	Given a coin array, which consists of coins available with infinite supplies and a sum is given.
	Find the number of ways in which the sum can be achieved.
	I/P:		coins[] = { 2, 5, 3, 6 }
				sum = 10
	O/P:		5
						Explanation
						2 2 2 2 2
						2 3 5
						5 5
						2 2 6
						2 2 3 3
*/

#include<bits/stdc++.h>
using namespace std;

int getCountRec(int coins[], int n, int sum) {
	if(sum == 0) return 1;
	if(n == 0) return 0;

	int res = getCountRec(coins, n-1, sum);		// Ignoring current coin
	if(sum >= coins[n-1]) {
		res += getCountRec(coins, n, sum - coins[n-1]);		// Considering
	}

	return res;
}

int getCount(int coins[], int n, int sum) {
	vector<vector<int>> dp(sum+1, vector<int>(n+1));
	for(int i=0;i<=n;i++) {
		dp[0][i] = 1;
	}
	for(int i=1;i<=sum;i++) {
		dp[i][0] = 0;
	}

	for(int i=1;i<=sum;i++) {
		for(int j=1;j<=n;j++) {
			dp[i][j] = dp[i][j-1];	// Ignoring particular coin
			if(coins[j-1] <= i) {	// Considering
				dp[i][j] += dp[i-coins[j-1]][j];
			}
		}
	}

	return dp[sum][n];
}

int main() {
	int coins[] = { 2, 5, 3, 6 };
	int sum = 10;
	int n = sizeof(coins)/sizeof(coins[0]);

	int ans = getCount(coins, n, sum);

	cout<<ans<<endl;

	return 0;
}