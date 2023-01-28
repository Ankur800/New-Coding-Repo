#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knap_sack(vector<int> weight, vector<int> value, int W, int n) {
	vector<vector<int>> t(n+1, vector<int>(W+1));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < W + 1; j++) {
			if(i==0 || j==0){
				t[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			if (weight[i - 1] <= j) {
			t[i][j] = max(value[i - 1] + t[i - 1][j - weight[i - 1]], t[i - 1][j]);
			}
			else {
			t[i][j] = t[i - 1][j];
			}
		}
	}

	return t[n][W];
}

int main() {
	vector<int> weight = { 10,20,30 };
	vector<int> value = { 60,100,120 };
	static int W = 50;
	int n = weight.size();
	cout << knap_sack(weight, value, W, n) << endl;

	return 0;
}