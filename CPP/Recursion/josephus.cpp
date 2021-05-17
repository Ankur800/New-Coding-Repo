/*
	N people standing in a circle. The people with gun kills kth person. Gun went to next person.
	Tell who will survive?
	I/P:	n = 7, k = 3
	O/P:	3
*/
#include<iostream>
using namespace std;

int josephus(int n, int k) {
	if(n == 1) {
		return 0;
	}

	return (josephus(n-1, k) + k) % n;
}

int main() {
	int n, k;
	cin>>n>>k;
	cout<<josephus(n, k)<<endl;

	return 0;
}