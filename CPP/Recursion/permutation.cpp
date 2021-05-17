/*
	Print all permutations of a given string
*/
#include<iostream>
using namespace std;

void printPermutation(string s, int i) {
	if(i == s.length()) {
		cout<<s<<endl;
		return;
	}
	for(int j=i;j<s.length();j++) {
		swap(s[i], s[j]);
		printPermutation(s, i+1);
		swap(s[i], s[j]);
	}
}

int main() {
	string s = "abc";
	printPermutation(s, 0);

	return 0;
}