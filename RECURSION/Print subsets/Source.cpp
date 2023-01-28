#include<iostream>
#include<string>
using namespace std;

void allSubsets(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}
	string output1 = output;	//not in choice
	string output2 = output;
	output2.push_back(input[0]);	//yes is choice
	input.erase(input.begin() + 0);	//erasing the first because, the first char is in choice(may be yes or no)
	allSubsets(input, output1);
	allSubsets(input, output2);
}

int main() {
	string input = "abc";
	string output = "";
	allSubsets(input, output);

	return 0;
}