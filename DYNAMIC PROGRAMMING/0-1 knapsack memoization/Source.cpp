#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static vector<vector<int>> t(100, vector<int>(100, -1));

int knap_sack(vector<int> weight, vector<int> value, int W, int n) {
	if (n == 0 || W == 0) {
		return 0;
	}

	if (t[n][W] != -1) {
		return t[n][W];
	}

	if (weight[n - 1] <= W) {
		return t[n][W] = max(value[n - 1] + knap_sack(weight, value, W - weight[n - 1], n - 1),
			knap_sack(weight, value, W, n - 1));
	}
	else if (weight[n-1] > W) {
		return t[n][W] = knap_sack(weight, value, W, n - 1);
	}
}

int main() {
	vector<int> weight = { 10, 20, 30 };
	vector<int> value = { 60, 100, 120 };
	int W = 50;
	int n = weight.size();
	cout << knap_sack(weight, value, W, n);

	return 0;
}