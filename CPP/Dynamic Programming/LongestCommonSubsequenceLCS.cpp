/*
	Find the Longest common subsequence
	I/P:
					s1 = abcdgh
					s2 = aedfhr
	O/P:			3    (adh)
*/
#include<bits/stdc++.h>
using namespace std;

// Normal Recursion
// O(2^mn)
int lcsRecursive(string s1, string s2, int n, int m) {
	if(n < 0 || m < 0) return 0;

	if(s1[n] == s2[m]) {
		return 1 + lcsRecursive(s1, s2, n-1, m-1);
	} else {
		return max(lcsRecursive(s1, s2, n-1, m), lcsRecursive(s1, s2, n, m-1));
	}
}

// Memoization / Top-Down	O(mn)
int lcsMemoization(string s1, string s2, int n, int m, vector<vector<int>> &arr) {
	if(n < 0 || m < 0) return 0;

	if(arr[n][m] != -1) {
		return arr[n][m];
	}

	int ans = 0;
	if(s1[n] == s2[m]) {
		ans = 1 + lcsMemoization(s1, s2, n-1, m-1, arr);
	} else {
		ans = max(lcsMemoization(s1, s2, n-1, m, arr), lcsMemoization(s1, s2, n, m-1, arr));
	}

	arr[n][m] = ans;
	return ans;
}

// Tabulation / Bottom-Up	O(mn)
int lcsTabulation(string s1, string s2, int n, int m) {
	vector<vector<int>> arr(n+1, vector<int>(m+1));

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s1[i-1] == s2[j-1]) {
				arr[i][j] = 1 + arr[i-1][j-1];
			} else {
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}

	return arr[m][n];
}

int main() {
	string s1 = "abcdgh";
	string s2 = "aedfhr";

	// Recursive
	cout<<"Recursive -> "<<lcsRecursive(s1, s2, s1.length()-1, s2.length()-1)<<endl;

	// Memoization
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> arr(n+1, vector<int>(m+1, -1));
	cout<<"Memoization ->"<<lcsMemoization(s1, s2, n-1, m-1, arr)<<endl;

	// Tabulation
	cout<<"Tabulation -> "<<lcsTabulation(s1, s2, n, m)<<endl;

	return 0;
}