/*
	Rotate a matrix by 90 degree anti-clockwise.
	I/P:	1	2	3	4
			5	6	7	8
			9	10	11	12
			13	14	15	16

	O/P:	4 	8 	12 	16
			3 	7 	11 	15
			2 	6 	10 	14
			1 	5 	9 	13

	Solution- Transpose and then reverse the rows.
*/
#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int>> &arr) {
	int n = arr.size();
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
}

void rotateMatrix(vector<vector<int>> &arr) {
	int n = arr.size();
	// 1. Transpose
	transpose(arr);
	// 2. Reverse row-wise
	int l=0, h=n-1;
	while(l < h) {
		swap(arr[l++], arr[h--]);
	}
}

int main() {
	vector<vector<int>> arr = {{1, 2, 3, 4},
								{5, 6, 7, 8},
								{9, 10, 11, 12},
								{13, 14, 15, 16}};

	rotateMatrix(arr);

	int n = arr.size();

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}