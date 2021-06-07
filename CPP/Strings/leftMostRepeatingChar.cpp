/*
	Given a string, find the index of left most occuring character.
	I/P:	geeksforgeeks
	O/P:	0				(index of 'g')
	I/P:	abbcc
	O/P:	abbcc			(index of 'b')
*/
#include<iostream>
#include<vector>
using namespace std;

int findLeftMostIndex(string s) {
	vector<int> arr(26, 0);
	for(char ch : s) {
		arr[ch - 'a']++;
	}
	for(int i=0;i<s.length();i++) {
		if(arr[s[i] - 'a'] > 1) {
			return i;
		}
	}

	return -1;
}

int findLeftMostIndexEFFICIENT(string s) {
	bool visited[26];
	fill(visited, visited+26, false);
	int res = -1;
	for(int i=s.length()-1;i>=0;i--) {
		if(!visited[s[i] - 'a']) {
			visited[s[i] - 'a'] = true;
		} else {
			res = i;
		}
	}

	return res;
}

int main() {
	string s = "geeksforgeeks";
	cout<<findLeftMostIndexEFFICIENT(s)<<endl;

	return 0;
}