#include<iostream>
using namespace std;

void solve(int n, int ones, int zeros, string output) {
	if (n == 0) {
		cout << output << endl;
		return;
	}
	string output1 = output;
	output1.push_back('1');
	solve(n - 1, ones + 1, zeros, output1);

	if (ones > zeros) {
		string output2 = output;
		output2.push_back('0');
		solve(n - 1, ones, zeros + 1, output2);
	}
}

int main() {
	int n = 4;
	string output = "";
	solve(n, 0, 0, output);

	return 0;
}