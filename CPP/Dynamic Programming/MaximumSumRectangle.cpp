/*
 * Given a 2D array, find the maximum sum rectangle in it. 
 * In other words find maximum sum over all rectangles in the matrix.
	4 5
	1 2 -1 -4 -20
	-8 -3 4 2 1
	3 8 10 1 3
	-4 -1 1 7 -6
*/

#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

// O(n^4 approach) 
int maximum_sum_rectangle(vector<vector<int>> arr) {
	int m = arr.size();
	int n = arr[0].size();
	vector<vector<int>> sum(m, vector<int>(n, 0));
	int maxSum = INT_MIN;
	// Storing sum from each (i, j) to (m-1, n-1)
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			for(int k = i;k<m;k++) {
				for(int l=j;l<n;l++) {
					sum[i][j] += arr[k][l];
				}
			}
		}
	}
	// Finding Sum of each possible rectangle to choose max one
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			for(int k = i;k<m;k++) {
				for(int l=j;l<n;l++) {
					int tempSum = sum[i][j];
					if(k < m-1) {
						tempSum -= sum[k+1][j];
					}
					if(l < n-1) {
						tempSum -= sum[i][l+1];
					}
					if(k < m-1 && l < n-1) {
						tempSum += sum[k+1][l+1];
					}
					if(tempSum > maxSum) {
						maxSum = tempSum;
					}
				}
			}
		}
	}
	
	return maxSum;
}

int kadaneArraySum(int* arr, int n) {
	int maxSum = INT_MIN;
	int currSum = 0;
	for(int i=0;i<n;i++) {
		currSum += arr[i];
		if(currSum > maxSum) {
			maxSum = currSum;
		}
		if(currSum < 0) {
			currSum = 0;
		}
	}
	//cout<<"MaxSum "<<maxSum<<endl;
	return maxSum;
}

int max_sum_kadane_and_dp(vector<vector<int>> arr) {
	int m = arr.size();
	int n = arr[0].size();
	int maxSum = INT_MIN;
	
	int sumArray[m];
	
	for(int left=0;left<m;left++) {
		memset(sumArray, 0, sizeof(sumArray));
		for(int right=left;right<n;right++) {
			// Updating Sum
			for(int i=0;i<m;i++) {
				sumArray[i] += arr[i][right];
			}
				
			// Applying Kadane's Algo
			int tempSum = kadaneArraySum(sumArray, m);
			
			if(tempSum > maxSum) {
				maxSum = tempSum;
			}
		}
	}
	return maxSum;
}

int main() {
	int n, m;
	cin>>m>>n;
	vector<vector<int>> arr(m, vector<int>(n));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
		}
	}
	//O(n^4 approach)
	cout<<maximum_sum_rectangle(arr)<<endl;
	
	//O(n^3 approach)
	cout<<max_sum_kadane_and_dp(arr)<<endl;

	return 0;
}
