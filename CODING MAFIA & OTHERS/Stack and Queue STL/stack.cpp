#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main() {
	vector<int>arr;
	arr = { 6,5,4,3,2,1 };

	queue<int>q;
	for (int i = 0; i < arr.size(); i++)
		q.push(arr[i]);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	

	cout << endl;

	stack<int>s;
	for (int i = 0; i < arr.size(); i++)
		s.push(arr[i]);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	
	return 0;
}