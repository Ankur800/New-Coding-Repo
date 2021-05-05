#include<iostream>
#include<string>
using namespace std;

void print_subsequences(string input, string output) {
	if(input.empty()) {
		cout<<output<<endl;
		return;
	}
	string smallString = input.substr(1);
	print_subsequences(smallString, output);
	output.push_back(input[0]);
	print_subsequences(smallString, output);
}

int main() {
	string s = "abc";
	print_subsequences(s, "");
	
	return 0;
}
