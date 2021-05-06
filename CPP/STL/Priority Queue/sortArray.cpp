#include<iostream>
#include<queue>
using namespace std;

void sort(int *arr, int n) {
	priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);	// MAX HEAP

	for(int i=0;i<n;i++) {
		arr[i] = pq.top();
		pq.pop();
	}
}

int main() {
	int arr[] = {3, 2, 2, 1};
	sort(arr, 4);

	for(int i=0;i<4;i++) {
		cout<<arr[i]<<" ";
	}
}