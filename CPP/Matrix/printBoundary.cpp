/*
	Given a matrix. Print its boundary elements. 
	(first row left to right, last column top to bottom, last row right to left and first column bottom to top)
	I/P:	1	2	3	4
			5	6	7	8
			9	10	11	12
			13	14	15	16

	O/P:	1 2 3 4 8 12 16 15 14 13 9 5
*/
#include<iostream>
#include<vector>
using namespace std;

void printBoundary(vector<vector<int>> &arr) {
	int m=arr.size();
	int n=arr[0].size();
	// corner cases
	if(m == 1) {
		for(int j=0;j<n;j++) {
			cout<<arr[0][j]<<" ";
		}
	} else if(n == 1) {
		for(int i=0;i<m;i++) {
			cout<<arr[i][0]<<" ";
		}
	} else {
		int i=0, j=0;

		for(;j<n;j++) {
			cout<<arr[i][j]<<" ";
		}
		i++;
		j--;
		for(;i<m;i++) {
			cout<<arr[i][j]<<" ";
		}
		i--;
		j--;
		for(j;j>=0;j--) {
			cout<<arr[i][j]<<" ";
		}
		i--;
		j++;
		for(;i>=1;i--) {
			cout<<arr[i][j]<<" ";
		}
	}
}

int main() {
	vector<vector<int>> arr = {{1, 2, 3, 4},
								{5, 6, 7, 8},
								{9, 10, 11, 12},
								{13, 14, 15, 16}};
	printBoundary(arr);

	return 0;
}