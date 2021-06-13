/*
	Given a matrix with all 0s and 1s. Find the maximum rectangle with all 1s.
	I/P:	0 	1 	1 	0
			1 	1 	1 	1
			1 	1 	1 	1
			1 	1 	0 	0

	O/P:	8
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestHistogram(vector<int> &arr) {
	int n = arr.size();
	stack<int> s;
	int res = 0;
	for(int i=0;i<n;i++) {
		while(!s.empty() && arr[s.top()] >= arr[i]) {
			int tp = s.top();
			s.pop();
			int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
			res = max(curr, res);
		}
		s.push(i);
	}

	while(!s.empty()) {
		int tp = s.top();
		s.pop();
		int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
		res = max(res, curr);
	}

	return res;
}

int getMaxRectWithAll1s(vector<vector<int>> &arr) {
	int res = largestHistogram(arr[0]);
	for(int i=1;i<arr.size();i++) {
		for(int j=0;j<arr[0].size();j++) {
			if(arr[i][j] == 1) {
				arr[i][j] += arr[i-1][j];
			}
		}
		res = max(res, largestHistogram(arr[i]));
	}

	return res;
}

int main() {
	vector<vector<int>> arr = {
								{0, 1, 1, 0},
								{1, 1, 1, 1},
								{1, 1, 1, 1},
								{1, 1, 0, 0}};

	cout<<getMaxRectWithAll1s(arr)<<endl;

	return 0;
}