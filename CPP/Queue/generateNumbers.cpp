/*
	Given a number n, print first n number(in increasing order)
	such that all these numbers have digits in set {5, 6}
	I/P:	6
	O/P:	5	6	55	56	65	66	555	556
*/
#include<iostream>
#include<queue>
using namespace std;

void generateNumbers(int n) {
	queue<string> q;
	q.push("5");
	q.push("6");

	for(int i=0;i<n;i++) {
		string temp = q.front();
		q.pop();

		cout<<temp<<" ";

		q.push(temp + "5");
		q.push(temp + "6");
	}

	cout<<endl;
}

int main() {
	int n = 10;
	generateNumbers(n);

	return 0;
}