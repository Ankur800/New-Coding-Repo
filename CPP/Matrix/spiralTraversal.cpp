/*
	Print the spiral tranversal of a matrix.
	I/P:	1	2	3	4
			5	6	7	8
			9	10	11	12
			13	14	15	16
	O/P:	1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
#include<iostream>
#include<vector>
using namespace std;

void printSpiral(vector<vector<int>> &arr) {
	int top = 0;
	int left = 0;
	int right = arr[0].size() - 1;
	int bottom = arr.size() - 1;
	while(top <= bottom && left <= right) {
		// TOP ROW
		for(int j=left;j<=right;j++) {
			cout<<arr[top][j]<<" ";
		}
		top++;

		// RIGHT COLUMN
		for(int i=top;i<=bottom;i++) {
			cout<<arr[i][right]<<" ";
		}
		right--;

		// BOTTOM ROW (Reverse Order)
		if(top <= bottom) {
			for(int j=right;j>=left;j--) {
				cout<<arr[bottom][j]<<" ";
			}
			bottom--;
		}

		// LEFT COLUMN (Reverse Order)
		if(left <= right) {
			for(int i=bottom;i>=top;i--) {
				cout<<arr[i][left]<<" ";
			}
			left++;
		}
	}
}

int main() {
	vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	printSpiral(arr);

	return 0;
}