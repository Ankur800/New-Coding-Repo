/*
	Write a bool function which tells that a given number is Palindrom Number or not.
	I/P: 	n = 78987				I/P:	8668
	O/P: 	Yes						O/P:	Yes
*/

#include<iostream>
using namespace std;

bool isPalindrom(int n) {
	int reverseNumber = 0;
	int num = n;
	while(n) {
		int lastDigit = n%10;
		reverseNumber = reverseNumber * 10 + lastDigit;
		n = n/10;
	}

	if(reverseNumber == num) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int n;
	cin>>n;
	if(isPalindrom(n)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}