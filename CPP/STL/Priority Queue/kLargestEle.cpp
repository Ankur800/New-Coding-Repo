#include<iostream>
#include<queue>
using namespace std;

void printkLargest(int *arr, int n, int k) {
	if(n == 0 || k > n) {
		return;
	}
	priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k);

	for(int i=k;i<n;i++) {
		if(arr[i] > pq.top()) {
			pq.pop();
			pq.push(arr[i]);
		}
	}

	for(int i=0;i<k;i++) {
		cout<<pq.top()<<" ";
		pq.pop();
	}
}

int main() {
	int arr[] = {5, 15, 10, 20, 8, 25, 18};
	int n = 7;
	int k = 3;
	printkLargest(arr, n, k);

	return 0;
}