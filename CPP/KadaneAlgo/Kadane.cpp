#include<iostream>
#include<vector>
using namespace std;

int kadane(vector<int> arr) {
	int n = arr.size();
	int best_sum = 0;
	int current_sum = 0;
	for(int i=0;i<n;i++) {
		current_sum += arr[i];
		if(current_sum > best_sum) {
			best_sum = current_sum;
		}
		if(current_sum < 0) {
			current_sum = 0;
		}
	}
	return best_sum;
}

int main() {
	vector<int> arr{1, 2, -7, -9, 6, 7, -3, 9, 10, -20, -3};
	cout<<kadane(arr)<<endl;
	
	return 0;
}
