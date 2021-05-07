/*
	Buy maximum items with given money
*/
#include<iostream>
#include<queue>
using namespace std;

int buyMaximumItems(int *arr, int n, int money) {
	int count = 0;
	priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);
	while(!pq.empty() && money >= pq.top()) {
		money -= pq.top();
		count++;
		pq.pop();
	}

	return count;
}

int main() {
	int arr[] = {1, 12, 5, 111, 200};
	int n = 5;
	int money = 10;
	cout<<buyMaximumItems(arr, n, money);

	return 0;
}