/*
	Given a 2-d matrix. Print the matrix in Snake Pattern.
	I/P:		1 	2 	3 	4
				5 	6 	7 	8
				9	10 	11 	12
				13	14	15	16

	O/P:		1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13
*/
#include<iostream>
using namespace std;

void printSnakePattern(int arr[4][4]) {
	int m = 4, n = 4;
	for(int i=0;i<m;i++) {
		if(i % 2 == 0) {
			for(int j=0;j<n;j++) {
				cout<<arr[i][j]<<" ";
			}
		} else {
			for(int j=n-1;j>=0;j--) {
				cout<<arr[i][j]<<" ";
			}
		}
	}
}

int main() {
	int arr[4][4] = {{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}};

	printSnakePattern(arr);

	return 0;
}