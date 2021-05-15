/*
	Given non-negative n, find number of set bits in n.
*/
#include<iostream>
using namespace std;

int countSetBits(int n) {		// O(number of bits)
	int count = 0;
	for(int i=0;i<=31;i++) {
		if((n & (1 << i)) != 0) {
			count++;
		}
	}

	return count;
}

int countSetBits2(int n) {		// O(number of set bits)
	int count = 0;
	while(n) {
		n = (n & (n-1));
		count++;
	}

	return count;
}

int main() {
	int n;
	cin>>n;
	cout<<countSetBits(n)<<endl;
	cout<<countSetBits(n)<<endl;

	return 0;
}