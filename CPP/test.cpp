#include<iostream>
#include<string>
using namespace std;

void findOccurance(string str, string s) {
	int i = 0;
	
	while(true) {
		str = str.substr(i);
		int idx = str.find(s);
		if(idx == string::npos) {
			break;
		} else {
			cout<<idx<<" ";
			i = idx+1;
		}
	}
}

int main() {
	string str = "geeks for geeks";
	string s = "geeks";
	findOccurance(str, s);

	return 0;
}