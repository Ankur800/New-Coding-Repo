/*
	Given two arrays X and Y of positive integers, find the number of pairs such that
	x^y > y^x (raised to power of) where x is an element from X and y is an element from Y.
	I/P:	M = 4, X[] = [2 3 4 5]
			N = 3, Y[] = [1 2 3]
	O/P:	5
*/
#include<iostream>
#include<algorithm>
using namespace std;

int count(int x, int arr[], int n, int NumOfY[]) {
	// For 0, no pair can satisfy the condition
	if(x == 0) {
		return 0;
	}
	// For 1, only 0s in Y can satisfy the condition
	if(x == 1) {
		return NumOfY[0];
	}

	int *idx = upper_bound(arr, arr+n, x);
	int ans += (arr+n) - idx;

	// If we are here, the surely x will be greater than 0 and 1, 
	// so it will be satisfying the condition with 0 and 1
	ans += NumOfY[0] + NumOfY[1];

	// If x is 2, upper bound consider 3 & 4. But (2, 3) and (2, 4) are not valid pairs, so removing them
	if(x == 2) {
		ans -= (NumOfY[3] + NumOfY[4]);
	}

	// If x is 3, upper bound will start from 4, but (3, 2) is a valid pair, so adding it
	if(x == 3) {
		ans += NumOfY[2];
	}

	return ans;
}

int countPairs(int X[], int Y[], int M, int N) {
	int NumOfY[5];
	for(int i=0;i<N;i++) {
		if(Y[i] < 5) {
			NumOfY[Y[i]]++;
		}
	}

	sort(Y, Y+N);

	int res = 0;
	for(int i=0;i<M;i++) {
		res += count(X[i], Y, N, NumOfY);
	}

	return res;
}

int main() {
	int X[] = {2, 3, 4, 5};
	int M = sizeof(X)/sizeof(X[0]);
	int Y[] = {1, 2, 3};
	int N = sizeof(Y)/sizeof(Y[0]);

	cout<<countPairs(X, Y, M, N)<<endl;

	return 0;
}