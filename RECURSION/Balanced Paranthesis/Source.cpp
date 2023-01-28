#include<iostream>
#include<string>
using namespace std;

void solve(int open, int close, string output) {
	if (open == 0 && close == 0) {
		cout << output << endl;
		return;
	}
	if (open != 0) {
		string output1 = output;
		output1.push_back('(');
		solve(open - 1, close, output1);
	}
	if (close > open) {
		string output2 = output;
		output2.push_back(')');
		solve(open, close - 1, output2);
	}
}

int main() {
	int input = 3;
	string output = "";
	solve(input, input, output);

	return 0;
}