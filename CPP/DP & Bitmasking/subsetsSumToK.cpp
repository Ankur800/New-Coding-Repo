#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void findSubsets(int* arr, int n, int &k) {
	// Take masks of 0 to (2^n - 1)
	int p = pow(2, n) - 1;
	for(int mask=0;mask<p;mask++) {
		int sum = 0;
		vector<int> temp;
		for(int j=0;j<n;j++) {
			if((mask & (1<<j)) != 0) {
				sum += arr[j];
				temp.push_back(arr[j]);
			}
		}
		if(sum == k) {
			for(int i=0;i<temp.size();i++) {
				cout<<temp[i]<<" ";
			}
			cout<<endl;
		}
	}
}

int main() {
	int arr[] = {2, 5, 4, 3, 1};
	int k = 7;
	int n = 5;
	findSubsets(arr, n, k);

	return 0;
}