/*
	Implement KMP algorithm for pattern matching.
	I/P:	s 		= abdabcbabc
			pattern = abc
	O/P:	3, 7
*/
#include<iostream>
using namespace std;

void fillLPS(string str, int lps[]) {
	int n = str.length(), len = 0;
	lps[0] = 0;
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

void KMP(string str, string pat) {
	int n = str.length();
	int m = pat.length();
	int lps[m];				// LPS Array for pattern
	fillLPS(pat, lps);
	int i = 0, j = 0;
	while(i < n) {
		if(str[i] == pat[j]) {
			i++;
			j++;
		}
		if(j == m) {
			cout<<(i - j)<<" ";
			j = lps[j - 1];
		} else if(i < n && pat[j] != str[i]) {
			if(j == 0) {
				i++;
			} else {
				j = lps[j-1];
			}
		}
	}
}

int main() {
	string str = "abdabcbabc";
	string pat = "abc";

	KMP(str, pat);

	return 0;
}