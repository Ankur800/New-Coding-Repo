/*
	Find x^n in logn time
*/

#include<iostream>
using namespace std;

int getPower(int x, int n) {
	if(n == 0) {
		return 1;
	}
	int res = 1;
	while(n) {
		if(n % 2 != 0) {
			res = res * x;
		}
		x = x * x;
		n = n/2;
	}

	return res;
}

int main() {
	int x = 3, n = 4;
	cout<<getPower(x, n)<<endl;

	return 0;
}