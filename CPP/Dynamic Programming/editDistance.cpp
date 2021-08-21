/*
	Given two strings s1 and s2. Tell the minimum number of steps to convert s1 into s2.
	The valid operations are:	
		a. Delete a char
		b. Insert a char
		c. Replace a char
	I/P:		s1 = "CAT" 		s2 = "CUT"			O/P: 1 		(replace(A, U))
	I/P:		s1 = "SATURDAY" s2 = "SUNDAY"		O/P: 3		(del A del T replace(R, D))
*/
#include<bits/stdc++.h>
using namespace std;

// Top-Down
int getSteps(string s1, string s2, int m, int n, vector<vector<int>> &dp) {
	if(m == 0) return n;	// insert elements of n
	if(n == 0) return m;	// delete remaining elements

	if(dp[m][n] != -1) {
		return dp[m][n];
	}

	int ans;
	if(s1[m-1] == s2[n-1]) {
		ans = getSteps(s1, s2, m-1, n-1, dp);
	} else {
		// Delete
		int ans1 = getSteps(s1, s2, m-1, n, dp);
		// Insert
		int ans2 = getSteps(s1, s2, m, n-1, dp);
		// Replace
		int ans3 = getSteps(s1, s2, m-1, n-1, dp);

		ans = 1 + min(ans1, min(ans2, ans3));
	}

	dp[m][n] = ans;

	return ans;
}

int getSteps2(string s1, string s2, int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1));

	for(int i=0;i<m+1;i++) {
		dp[i][0] = i;
	}
	for(int j=0;j<n+1;j++) {
		dp[0][j] = j;
	}

	for(int i=1;i<m+1;i++) {
		for(int j=1;j<n+1;j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
			}
		}
	}

	return dp[m][n];
}

int main() {
	string s1 = "SATURDAY";
	string s2 = "SUNDAY";

	int m = s1.length(), n = s2.length();
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	//int ans = getSteps(s1, s2, m, n, dp);
	int ans = getSteps2(s1, s2, m, n);

	cout<<ans<<endl;

	return 0;
}