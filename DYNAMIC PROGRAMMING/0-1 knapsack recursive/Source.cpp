#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapSack(vector<int> weight, vector<int> value, int W, int n) {
	if (n == 0 || W == 0) {
		return 0;
	}
	if (weight[n-1] <= W) {
		return max(value[n - 1] + knapSack(weight, value, W - weight[n - 1], n - 1), knapSack(weight, value, W, n - 1));
	}
	else if (weight[n - 1] > W) {
		return knapSack(weight, value, W, n - 1);
	}
}

int main() {
	vector<int> weight = { 10, 20, 30 };
	vector<int> value = { 60, 100, 120 };
	int W = 50;
	int n = weight.size();
	cout << knapSack(weight, value, W, n) << endl;

	return 0;
}