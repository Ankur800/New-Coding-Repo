/*
	Given a string and a pattern, find the occurances of pattern in given string.
	I/P:	s 		= abdabcbabc
			pattern = abc
	O/P:	3, 7
*/
#include<iostream>
using namespace std;

#define q 137;		// Some big prime number for modulo operations to avoid overflow

void findOccurances(string text, string pat) {
	int n = text.length();
	int m = pat.length();			// We are taking q just to avoid overflow

	int d = 5;		// Let's take an arbitary d

	// Compute (d^(m-1)) % q
	int h = 1;
	for(int i=1;i<=m-1;i++) {
		h = (h * d) % q;
	}

	// Compute p and t0
	int p=0, t=0;
	for(int i=0;i<m;i++) {
		p = (p*d + pat[i]) % q;
		t = (t*d + text[i]) % q;
	}

	// Check for Spurious hits
	for(int i=0;i<=n-m;i++) {
		if(p == t) {
			bool flag = true;
			for(int j=0;j<m;j++) {
				if(text[i+j] != pat[j]) {
					flag = false;
					break;
				}
			}
			if(flag == true) {
				cout<<i<<" ";
			}
		}
		if(i < n-m) {
			t = (d * (t - text[i] * h) + text[i + m]) % q;
			if(t < 0) {		// In case of negative modulo
				t = t + q;
			}
		}
	}
}

int main() {
	string s = "abdabcbabc";
	string pattern = "abc";
	findOccurances(s, pattern);

	return 0;
}