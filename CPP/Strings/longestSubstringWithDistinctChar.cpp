/*
	Find length of longest substring with distinct characters.
	I/P:	abcadbd
	O/P:	4
*/
#include<iostream>
using namespace std;

int findSubstring(string str) {
	int n = str.length(), res = 0;
	int prev[26];
	fill(prev, prev+26, -1);
	int i = 0;				// Starting index of current window with distinct characters
	for(int j=0;j<n;j++) {
		i = max(i, prev[str[j] - 'a'] + 1);
		int maxEnd = j - i + 1;
		res = max(res, maxEnd);
		prev[str[j] - 'a'] = j;
	}

	return res;
}

int main() {
	string str = "abcadbd";

	cout<<findSubstring(str)<<endl;

	return 0;
}