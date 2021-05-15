/*
	Given an array of inetegers. All numbers are appearing even number of times except two numbers.
	Find the numbers.
	I/P:	{3, 4, 3, 4, 5, 4, 4, 6, 7, 7}
	O/P:	5, 6

	Idea:	Find xor of all numbers.
			We'll have xor of two odd occuring numbers.
			Let's say we have 5 ^ 6 at last, i.e. 3 => 0011
			Now, we'll find last set bit, because set bit means one number is having 1 and other is having 0 at that bit.
			Using this concept we will divide our array into two parts.
			Each part will be conatining one odd occurring number.
			Again apply xor operations on individual arrays.
			We'll get the result.
*/
#include<iostream>
using namespace std;

void findOddAppearingNumbers(int arr[], int n) {
	int XOR = 0, res1 = 0, res2 = 0;
	for(int i=0;i<n;i++) {
		XOR = (XOR ^ arr[i]);
	}
	int rightMostSetBit = XOR & ~(XOR - 1);
	for(int i=0;i<n;i++) {
		if((arr[i] & rightMostSetBit) != 0) {
			res1 = res1 ^ arr[i];
		} else {
			res2 = res2 ^ arr[i];
		}
	}

	cout<<res1<<" "<<res2<<endl;
}

int main() {
	int arr[] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
	int n = 10;
	findOddAppearingNumbers(arr, n);

	return 0;
}