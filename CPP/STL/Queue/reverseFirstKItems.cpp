#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstKItems(queue<int> &q, int k) {
	if(q.empty() || k <= 0 || k > q.size()) {
		return;
	}

	stack<int> st;
	for(int i=0;i<k;i++) {
		st.push(q.front());
		q.pop();
	}

	while(!st.empty()) {
		q.push(st.top());
		st.pop();
	}

	for(int i=0;i<q.size()-k;i++) {
		q.push(q.front());
		q.pop();
	}
}

void printQueue(queue<int> q) {
	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
}

int main() {
	queue<int> q({10, 20, 30, 40, 50});
	int k = 3;

	printQueue(q);
	cout<<endl;

	reverseFirstKItems(q, k);

	printQueue(q);

	return 0;
}