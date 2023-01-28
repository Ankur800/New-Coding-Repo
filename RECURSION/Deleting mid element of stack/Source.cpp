#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void deleteMidElementFromStack(stack<int>& s, int midElementIndex) {
	if (s.size() == 0)
		return;
	if (midElementIndex == 1) {
		s.pop();
		return;
	}
	int temp = s.top();
	s.pop();
	deleteMidElementFromStack(s, midElementIndex-1);
	s.push(temp);
}

int main() {
	vector<int> arr = { 1,2,3,4,5 };
	stack<int>s;
	for (int x : arr) {
		s.push(x);
	}
	deleteMidElementFromStack(s, (s.size() / 2) + 1);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}