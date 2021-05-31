/*
	Given a matrix, find its transpose matrix.
	I/P:	1	2	3	4
			5	6	7	8
			9	10	11	12
			13	14	15	16

	O/P:	1 	5 	9 	13
			2 	6 	10 	14
			3 	7 	11 	15
			4 	8 	12 	16
*/
#include<iostream>
#include<vector>
using namespace std;

void getTranspose(vector<vector<int>> &arr) {
	int m=arr.size();
	int n=arr[0].size();
	for(int i=0;i<m;i++) {
		for(int j=i+1;j<n;j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
}

int main() {
	vector<vector<int>> arr = {{1, 2, 3, 4},
								{5, 6, 7, 8},
								{9, 10, 11, 12},
								{13, 14, 15, 16}};

	getTranspose(arr);

	for(int i=0;i<arr.size();i++) {
		for(int j=0;j<arr[i].size();j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}