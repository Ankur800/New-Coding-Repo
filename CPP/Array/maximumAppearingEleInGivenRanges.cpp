/*
	Given n ranges, find the maximum appearing element in these ranges.
	L[]:	{1, 2, 5, 15}
	R[]:	{5, 8, 7, 18}
	O/P:	5
*/
#include<iostream>
#include<vector>
using namespace std;

int getMaxAppearing(int L[], int R[], int n) {
	vector<int> arr(1000);		// Let's suppose the max value in R is 1000
	for(int i=0;i<n;i++) {
		arr[L[i]]++;
		arr[R[i] + 1]--;
	}
	int maxEle = arr[0], res = 0;
	for(int i=1;i<1000;i++) {
		arr[i] += arr[i-1];
		if(arr[i] > maxEle) {
			maxEle = arr[i];
			res = i;
		}
	}

	return res;
}

int main() {
	int L[] = {1, 4, 3, 1};
	int R[] = {15, 8, 5, 4};
	int n = 4;
	cout<<getMaxAppearing(L, R, n)<<endl;

	return 0;
}