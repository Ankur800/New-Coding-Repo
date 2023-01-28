#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool subset_sum(vector<int> arr, int sum, int n) {
	vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {
			if (i == 0)
				t[i][j] = false;
			if (j == 0)
				t[i][j] = true;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			if (arr[i - 1] <= j) {
				t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][sum];
}

bool equal_sum_partition(vector<int> arr, int n) {
	int sum = 0;
	for (int x : arr) {
		sum += x;
	}
	if (sum % 2 != 0) {
		return false;
	}
	else {
		return subset_sum(arr, sum / 2, n);
	}
}
	

int main() {
	vector<int> arr = { 1,5,11,5 };
	int n = arr.size();
	cout << equal_sum_partition(arr, n) << endl;

	return 0;
}