/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1, 
	compute how much water it is able to trap after raining.
	I/P:	{5, 0, 6, 2, 3}
	O/P:	6
					
						|^|
					|^|W|*|
					|*|W|*|
					|*|W|*|W|^|			Total water trapped = 5 + 1 = 6
					|*|W|*|^|*|
					|*|W|*|*|*|
					 5 0 6 2 3
*/
#include<iostream>
using namespace std;

int getWater(int *arr, int n) {
	int amount = 0;
	int lMax[n], rMax[n];
	// Let's make left max wall height for each bar
	lMax[0] = arr[0];
	for(int i=1;i<n;i++) {
		lMax[i] = max(arr[i], lMax[i-1]);
	}
	// Let's make right max wall height for each bar
	rMax[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--) {
		rMax[i] = max(arr[i], rMax[i+1]);
	}

	// Now let's check with given left max wall and right max wall, how much water can be stored at ith wall
	for(int i=1;i<n-1;i++) {
		amount += min(lMax[i], rMax[i]) - arr[i];
	}

	return amount;
}

int main() {
	int arr[] = {5, 0, 6, 2, 3};
	int n = 5;
	cout<<getWater(arr, n)<<endl;

	return 0;
}