#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void sendTopToButtom(stack<int> &s, int k) {
	if (s.size() == 0) {
		s.push(k);
		return;
	}
	int topElement = s.top();
	s.pop();
	sendTopToButtom(s, k);
	s.push(topElement);
}

void reverseStack(stack<int> &s) {
	if (s.size() == 1) {
		return;
	}
	int topElement = s.top();
	s.pop();
	reverseStack(s);
	sendTopToButtom(s, topElement);
}

int main() {
	vector<int> arr = { 1,2,3,4,5 };
	stack<int> s;
	for (int x : arr) {
		s.push(x);
	}
	reverseStack(s);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}