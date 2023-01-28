#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void fixLastElement(stack<int>& s, int k) {
	if (s.size() == 0 || s.top() <= k) {
		s.push(k);
		return;
	}
	int lastElement = s.top();
	s.pop();
	fixLastElement(s, k);
	s.push(lastElement);
}

void sortStack(stack<int>& s) {
	if (s.size() == 1)
		return;
	int lastElement = s.top();
	s.pop();
	sortStack(s);
	fixLastElement(s, lastElement);
}

int main() {
	vector<int> arr = { 1,4,6,1,3,0,12,3,9,43,1,7,0 };
	stack<int> s;
	for (int x : arr) {
		s.push(x);
	}
	sortStack(s);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}