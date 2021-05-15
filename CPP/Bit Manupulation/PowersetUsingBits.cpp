/*
	Given a string. Generate all power sets using bit wise operators.
*/
#include<iostream>
#include<cmath>
using namespace std;

void generatePowerSet(string s) {
	int n = s.length();
	int k = pow(2, n) - 1;
	for(int i=0;i<=k;i++) {
		string temp = "";
		for(int j=0;j<=n;j++) {				// number of bits according to string size=> abc: 111 max
			if((i & (1 << j)) != 0) {
				temp += s[j];
			}
		}

		cout<<temp<<" ";
	}
}

int main() {
	string s = "abc";
	generatePowerSet(s);

	return 0;
}