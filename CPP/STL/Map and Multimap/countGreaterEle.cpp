/*
	Count the number of greater elements for each array items.
	I/P:	10		5		8		20		30		8
	O/P:	2		5		3		1		0		3
*/
#include<iostream>
#include<map>
using namespace std;

void countGreater(int *arr, int n) {
	map<int, int> m;
	for(int i=0;i<n;i++) {
		m[arr[i]]++;
	}

	int cum_freq = 0;
	for(auto it=m.rbegin();it!=m.rend();it++) {
		int freq = it->second;
		it->second = cum_freq;
		cum_freq += freq;
	}

	for(int i=0;i<n;i++) {
		cout<<m[arr[i]]<<" ";
	}
}

int main() {
	int arr[] = {10, 5, 8, 20, 30, 8};
	int n = 6;
	countGreater(arr, n);

	return 0;
}