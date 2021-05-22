/*
	An interesting array problem to find the length of the longest subarray that has 
	alternating even odd elements.
	I/P:	{5, 10, 20, 6, 3, 8}
	O/P:	3


	EXTENSION OF KADANE'S ALGO
*/
#include<iostream>
using namespace std;

int getLength(int *arr, int n) {
	int maxLength = 0;
	int tempLength = 1;
	bool isLastEven = (arr[0] % 2 == 0) ? true : false;

	for(int i=1;i<n;i++) {
		if(isLastEven) {
			if(arr[i] % 2 != 0) {
				tempLength++;
				isLastEven = false;
			} else {
				tempLength = 1;
			}
		} else {
			if(arr[i] % 2 == 0) {
				tempLength++;
				isLastEven = true;
			} else {
				tempLength = 1;
			}
		}
		maxLength = max(maxLength, tempLength);
	}

	return maxLength;
}

int main() {
	int arr[] = {5, 10, 20, 6, 3, 8};
	int n = 6;

	cout<<getLength(arr, n)<<endl;

	return 0;
}