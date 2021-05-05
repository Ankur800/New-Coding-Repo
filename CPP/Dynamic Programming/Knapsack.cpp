/*
 * 	Test Case
4
1 2 4 5
5 4 8 6
5
 * 
 * Output -> 13
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int* weight, int* value, int n, int W, int** dp) {
	if(n == 0 || W == 0) {
		return 0;
	}
	if(dp[W][n] > -1) {
		return dp[W][n];
	}
	int option1 = 0, option2 = 0;
	if(weight[n-1] <= W) {
		option1 = value[n-1] + knapsack(weight, value, n-1, W - weight[n-1], dp);
	}
	option2 = knapsack(weight, value, n-1, W, dp);
	dp[W][n] = max(option1, option2);
	return dp[W][n];
}

int knapsack_iterative(int* weight, int* value, int n, int W) {
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	for(int j=0;j<=W;j++) {
		dp[0][j] = 0;
	}
	for(int i=1;i<=n;i++) {
		for(int w=1;w<=W;w++) {
			dp[i][w] = dp[i-1][w];
			if(weight[i-1] <= w) {
				dp[i][w] = max(dp[i][w], value[i-1] + dp[i-1][w - weight[i-1]]);
			}
		}
	}
	return dp[n][W];
}

int main() {
	int n;
	cin>>n;
	int weight[n];
	int value[n];
	int W;
	for(int i=0;i<n;i++) {
		cin>>weight[i];
	}
	for(int i=0;i<n;i++) {
		cin>>value[i];
	}
	cin>>W;
	int** dp = new int*[W+1];
	for(int i=0;i<=W;i++) {
		dp[i] = new int[n+1];
		for(int j=0;j<=n;j++) {
			dp[i][j] = -1;
		}
	}
	
	int ans = knapsack(weight, value, n, W, dp);
	cout<<ans<<endl;	//recursive
	cout<<knapsack_iterative(weight, value, n, W)<<endl;	//iterative
	
	for(int i=0;i<=W;i++) {
		delete[] dp[i];
	}
	delete[] dp;

	return 0;
}
