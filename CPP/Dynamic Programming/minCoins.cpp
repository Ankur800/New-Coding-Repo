/*
	Given a value and set of coins. Suppose supply of each coin is infinite.
	Find the minimum number of coins which sum up the given value.
	I/P:	coins[] = { 25, 10, 5 } 	val = 30
	O/P:	2 	(25, 5)

	I/P:	coins[] = { 9, 6, 5, 1 } 	val = 11
	O/P: 	2 	(5, 6)
*/
#include<bits/stdc++.h>
using namespace std;

// Top-Down
int findMinCoins(int value, vector<int> &coins, vector<int> &dp) {
	if(value == 0) return 0;
	if(dp[value] != INT_MAX) return dp[value];

	int ans = INT_MAX;
	for(int i=0;i<coins.size();i++) {
		if(coins[i] <= value) {
			ans = min(ans, findMinCoins(value-coins[i], coins, dp));
		}
	}

	dp[value] = (ans == INT_MAX ? ans : 1 + ans);
	return dp[value];
}

// Bottom-Up
int findMinCoinsEff(int value, vector<int> &coins) {
	vector<int> dp(value+1, INT_MAX);
	dp[0] = 0;
	for(int i=0;i<=value;i++) {
		for(int j=0;j<coins.size();j++) {
			if(i >= coins[j]) {
				dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
			}
		}
	}

	return dp[value];
}

int main() {
	vector<int> coins = { 9, 6, 5, 1 };
	int value = 11;

	vector<int> dp(value+1, INT_MAX);
	cout<<findMinCoins(value, coins, dp)<<endl;
	cout<<findMinCoinsEff(value, coins)<<endl;

	return 0;
}