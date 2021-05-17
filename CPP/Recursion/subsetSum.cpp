/*
	Given an array of integers and sum. Count number of subsets whose sum is equal to the given sum.
	I/P:	{10, 5, 2, 3, 6}	sum = 8
	O/P:	2
*/
#include<iostream>
using namespace std;

int countSubsets(int *arr, int n, int sum, int output) {
	if(output == sum) {
		return 1;
	}
	if(output > sum || n < 0) {
		return 0;
	}
	return countSubsets(arr, n-1, sum, output) + countSubsets(arr, n-1, sum, output+arr[n-1]);
}

int main() {
	int arr[] = {10, 5, 2, 3, 6};
	int sum = 8;
	int n = 5;
	int output = 0;
	cout<<countSubsets(arr, n, sum, output)<<endl;

	return 0;
}