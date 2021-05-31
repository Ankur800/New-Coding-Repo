/*
	Given a row-wise sorted matrix. Find the median.
	You may suppose, the number of elements is odd and all elements are distinct.
	I/P:	5	10	20	30	40
			1 	2 	3 	4 	6
			11	13	15	17	19

	O/P:	11

	Assumptions:
		R*C is odd.
		All elements are distinct.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMedian(vector<vector<int>> &arr) {
	int n = arr.size();
	int m = arr[0].size();
	int min = arr[0][0], max = arr[0][m-1];
	for(int i=0;i<n;i++) {
		if(arr[i][0] < min) {	// Find min element
			min = arr[i][0];
		}
		if(arr[i][m-1] > max) {	// Find max element
			max = arr[i][m-1];
		}
	}

	int medPos = (m * n + 1) / 2;	// Find the position of median element in the sorted array

	while(min < max) {
		int mid = (min + max) / 2;
		int midPos = 0;		// We need to find the position of mid element in sorted array
		for(int i=0;i<n;i++) {
			midPos += (upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin());
		}
		if(midPos < medPos) {
			min = mid + 1;
		} else {
			max = mid;
		}
	}

	return min;
}

int main() {
	vector<vector<int>> arr = {{5, 10, 20, 30, 40},
								{1, 2, 3, 4, 6},
								{11, 13, 15, 17, 19}};

	cout<<findMedian(arr)<<endl;

	return 0;
}