/*
	Given a string. Find the LPS(Longest Proper Prefix Suffix) Array.
	I/P:	str: bbaacbbbaab
	O/P:	lps: 0 1 0 0 0 1 2 2 3 4 1
*/
#include<iostream>
using namespace std;

void findLPS(string str, int lps[]) {
	int n = str.length();
	int len = 0;			// For storing lps values
	lps[0] = 0;		// 0 for single element
	int i = 1;
	while(i < n) {
		if(str[i] == str[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if(len == 0) {
				lps[i] = 0;
				i++;
			} else {
				len = lps[len-1];
			}
		}
	}
}

int main() {
	string s = "bbaacbbbaab";
	int lps[s.length()];
	findLPS(s, lps);

	for(int i=0;i<s.length();i++) {
		cout<<lps[i]<<" ";
	}
	cout<<endl;

	return 0;
}