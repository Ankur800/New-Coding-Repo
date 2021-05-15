/*
	Given a number n. We need to find if kth bit is set or not?
	I/P: 	n=5, k=1
	O/P:	Yes
*/
#include<iostream>
using namespace std;

bool isSet(int n, int k) {
	if((n & (1 << (k-1))) != 0) {
		return true;
	}
	return false;
}

int main() {
	int n, k;
	cin>>n>>k;
	if(isSet(n, k)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}