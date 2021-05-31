/*
	Given a row-wise and column-wise sorted matrix.
	For a given element x, find its position if it exists.
	I/P:	10	20	30	40
			15	25	35	45
			27	29	37	48		x = 29
			32	33	39	50

	O/P:	Found at (2, 1)
*/
#include<iostream>
#include<vector>
using namespace std;

void searchElement(vector<vector<int>> &arr, int x) {		// O(row + col)
	int n = arr.size();
	int m = arr[0].size();
	int i=0, j=m-1;
	while(i < n && j >= 0) {
		if(arr[i][j] == x) {
			cout<<"Found at (" + to_string(i) + ", " + to_string(j) + ")"<<endl;
			return;
		} else if(x < arr[i][j]) {
			j--;
		} else {
			i++;
		}
	}

	cout<<"Element is not found!"<<endl;
}

int main() {
	vector<vector<int>> arr = {{10, 20, 30, 40},
								{15, 25, 35, 45},
								{27, 29, 37, 48},
								{32, 33, 39, 50}};

	int x = 29;

	searchElement(arr, x);

	return 0;
}