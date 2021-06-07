/*
	Reverse the words in a string.
	I/P:	Welcome to India
	O/P:	India to Welcome

	Step1: 	Reverse the individual words.		emocleW ot aidnI
	Step2:	Reverse the whole string.			India to Welcome
*/
#include<iostream>
using namespace std;

void _reverse(string &s, int start, int end) {
	while(start < end) {
		swap(s[start++], s[end--]);
	}
}

string reversedSentence(string s) {
	int start = 0;
	for(int end = 0;end < s.length();end++) {
		if(s[end] == ' ') {
			_reverse(s, start, end - 1);
			start = end + 1;
		}
	}
	_reverse(s, start, s.length() - 1);
	_reverse(s, 0, s.length() - 1);

	return s;
}

int main() {
	string s = "Welcome to India";

	cout<<reversedSentence(s)<<endl;

	return 0;
}