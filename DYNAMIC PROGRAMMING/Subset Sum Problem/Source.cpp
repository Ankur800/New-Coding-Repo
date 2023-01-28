#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool subset_sum_problem(vector<int> arr, int sum, int n) {
	vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {
			if (i == 0) {
				t[i][j] = false;
			}
			if (j == 0) {
				t[i][j] = true;
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			if (arr[i - 1] <= j) {
				t[i][j] = (t[i-1][j - arr[i - 1]]) || (t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][sum];
}

int main() {
	vector<int> arr = { 2,3,7,8,10 };
	int k = 11;
	int n = arr.size();
	cout << subset_sum_problem(arr, k, n) << endl;


	return 0;
}