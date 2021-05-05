#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

//O(2^n)
int lcs(char* s1, char* s2) {
	if(s1[0] == '\0' || s2[0] == '\0') {
		return 0;
	}
	if(s1[0] == s2[0]) {
		return 1 + lcs(s1+1, s2+1);
	} else {
		return max(lcs(s1+1, s2), lcs(s1, s2+1));
	}
}

//DP	O(mn)
int lcs2Helper(char* s1, char*s2, int m, int n, int** dp) {
	if(m == 0 || n == 0) {
		return 0;
	}
	if(dp[m][n] > -1) {
		return dp[m][n];
	}
	int ans;
	if(s1[0] == s2[0]) {
		ans = 1 + lcs2Helper(s1+1, s2+1, m-1, n-1, dp);
	} else {
		int option1 = lcs2Helper(s1+1, s2, m-1, n, dp);
		int option2 = lcs2Helper(s1, s2+1, m, n-1, dp);
		ans = max(option1, option2);
	}
	dp[m][n] = ans;
	return ans;
}

string lcs3Helper(char* s1, char*s2, int m, int n, string** dp) {
	if(m == 0 || n == 0) {
		return "";
	}
	if(dp[m][n] != "\0") {
		return dp[m][n];
	}
	string ans;
	if(s1[0] == s2[0]) {
		//ans = 1 + lcs2Helper(s1+1, s2+1, m-1, n-1, dp);
		ans = s1[0] + lcs3Helper(s1+1, s2+1, m-1, n-1, dp);
	} else {
		string option1 = lcs3Helper(s1+1, s2, m-1, n, dp);
		string option2 = lcs3Helper(s1, s2+1, m, n-1, dp);
		if(option1.size() > option2.size()) {
			ans = option1;
		} else {
			ans = option2;
		}
	}
	dp[m][n] = ans;
	return ans;
}

string lcs3(char* s1, char* s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	string** dp = new string*[m+1];
	for(int i=0;i<=m;i++) {
		dp[i] = new string[n+1];
		for(int j=0;j<=n;j++) {
			dp[i][j] = "\0";
		}
	}
	string ans = lcs3Helper(s1, s2, m, n, dp);
	for(int i=0;i<=m;i++) {
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}


int lcs2(char* s1, char* s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int*[m+1];
	for(int i=0;i<=m;i++) {
		dp[i] = new int[n+1];
		for(int j=0;j<=n;j++) {
			dp[i][j] = -1;
		}
	}
	int ans = lcs2Helper(s1, s2, m, n, dp);
	for(int i=0;i<=m;i++) {
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int lcsIterative(char* s1, char* s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	vector<vector<int>>dp(m+1, vector<int>(n+1));
	for(int i=0;i<=m;i++) {
		dp[i][0] = 0;
	}
	for(int i=0;i<=n;i++) {
		dp[0][i] = 0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(s1[m-i] == s2[n-j]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main() {
	//char s1[] = "abcdef";
	//char s2[] = "a1b2d3e4f5g6h6";
	char s1[] = "whgtdwhgtdg";
	char s2[] = "aswcfg";
	cout<<lcs(s1, s2)<<endl;			//O(2^n)	Recursive
	cout<<lcs2(s1, s2)<<endl;			//O(mn)  	DP-Recursive
	cout<<lcsIterative(s1, s2)<<endl;	//O(mn)		DP-Iterative
	cout<<lcs3(s1, s2)<<endl;
	
	return 0;
}
