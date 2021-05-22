/*
	Find count of maximum consecutive 1s in a binary array. 
	I/P:	arr = {1, 0, 1, 1, 1, 1, 0, 1, 1};
	O/P:	4
*/
#include<iostream>
using namespace std;

int getSolution(int arr[], int n) {
	int max1s = 0;
	int tempMax = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] == 1) {
			tempMax++;
		} else {
			tempMax = 0;
		}
		max1s = max(tempMax, max1s);
	}

	return max1s;
}

int main() {
	int arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1};
	int n = 9;

	cout<<getSolution(arr, n)<<endl;

	return 0;
}