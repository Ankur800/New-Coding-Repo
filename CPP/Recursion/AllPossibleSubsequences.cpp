#include<iostream>
#include<vector>
using namespace std;

void allPossibleSubsequences(string s, vector<string> &res) {
	if(s == "") {
		res.push_back("");
		return;
	}
	string smallString = s.substr(1);
	allPossibleSubsequences(smallString, res);
	string first = "";
	first += s[0];
	int n = res.size();
	for(int i=0;i<n;i++) {
		string temp = res[i];
		res.push_back(first + temp);
	}
}
int main() {
	string s = "abcd";
	vector<string> res;
	allPossibleSubsequences(s, res);
	for(int i=0;i<res.size();i++) {
		cout<<res[i]<<endl;
	}
	
	return 0;
}
