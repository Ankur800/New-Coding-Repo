/*
	Given a string, we need to find lexicographic rank of a string.
	I/P:	BAC
	O/P:	3
	I/P:	CBA
	O/P:	6
*/
#include<iostream>
using namespace std;

long long mul = 1;
long long preComputeFact(int n) {
	if(n <= 1) {
		return 1;
	}
	return n * preComputeFact(n-1);
}

int findLexRank(string str) {
	int res = 1;				// ans = smallerStrings + 1
	int n = str.length();
	//int mul = fact(n);		// precomputed

	int count[26] = {0};
	for(int i=0;i<n;i++) {		// Count of every char in string
		count[str[i] - 'A']++;
	}
	for(int i=1;i<26;i++) {		// Cummulative count i.e. how many chars are smaller than the current
		count[i] += count[i-1];
	}

	for(int i=0;i<n-1;i++) {
		mul = mul / (n-i);
		int idx = str[i] - 'A';			// Index of current char
		res = res + count[idx - 1] * mul;
		for(int j=idx;j<26;j++) {		// After idx, this char will not be available for the next one, so decreasing count
			count[j]--;
		}
	}

	return res;
}

int main() {
	string str = "STRING";

	mul = preComputeFact(str.length());	

	cout<<findLexRank(str)<<endl;

	return 0;
}