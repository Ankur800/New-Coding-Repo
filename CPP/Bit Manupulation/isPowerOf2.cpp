/*
	Given n, check whether it is power of 2 or not?
*/
#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
	if((n & (n-1)) == 0) {
		return true;
	} 
	return false;
}

int main() {
	int n;
	cin>>n;
	if(isPowerOfTwo(n)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}