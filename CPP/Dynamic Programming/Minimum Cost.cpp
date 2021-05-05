/* Find Minimum cost to reach starting point(0, 0) to end point(m-1, n-1) in a matrix
 * 4	3	2
 * 1	8	9
 * 1	1	8
 * The minimum cost will be 14 as :
 * (0, 0) -> (1, 0) -> (2, 0) -> (2, 1) -> (2, 2)
 * 	4	+		1	+	1		+	1	+	8 = 14
 */

#include<bits/stdc++.h>
using namespace std;

int min_cost(int** input, int si, int sj, int ei, int ej, int** arr) {
	if(si == ei && sj == ej) {
		return input[ei][ej];
	}
	if(si > ei || sj > ej) {
		return INT_MAX;
	}
	if(arr[si][sj] > -1) {
		return arr[si][sj];
	}
	int option1 = min_cost(input, si+1, sj, ei, ej, arr);
	int option2 = min_cost(input, si+1, sj+1, ei, ej, arr);
	int option3 = min_cost(input, si, sj+1, ei, ej, arr);
	arr[si][sj] = input[si][sj] + min(option1, min(option2, option3));
	return input[si][sj] + min(option1, min(option2, option3));
}

int min_cost_iterative(int** input, int m, int n) {
	int** arr = new int*[m];
	for(int i=0;i<m;i++) {
		arr[i] = new int[n];
	}
	arr[m-1][n-1] = input[m-1][n-1];
	for(int i=m-2;i>=0;i--) {
		arr[i][n-1] = input[i][n-1] + arr[i+1][n-1];
	}
	for(int j=n-2;j>=0;j--) {
		arr[m-1][j] = input[m-1][j] + arr[m-1][j+1];
	}
	for(int i=m-2;i>=0;i--) {
		for(int j=n-2;j>=0;j--) {
			arr[i][j] = input[i][j] + min(arr[i+1][j], min(arr[i+1][j+1], arr[i][j+1]));
		}
	}
	int ans = arr[0][0];
	for(int i=0;i<m;i++) {
		delete[] arr[i];
	}
	delete *arr;
	return ans;
}

int main() {
	int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;
	
	// creating 2d array for min_cost
	int m = 3;
	int n = 3;
	int** arr = new int*[m];
	for(int i=0;i<n;i++) {
		arr[i] = new int[n];
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			arr[i][j] = -1;
		}
	}

	cout << min_cost(input, 0,0,2,2, arr) << endl;
	// delete dynamic array
	for(int i=0;i<m;i++) {
		delete[] arr[i];
	}
	delete[] arr;
	
	cout << min_cost_iterative(input,3,3) << endl;
	delete [] input[0];
	delete [] input[1];
	delete [] input[2];
	delete [] input;
}
