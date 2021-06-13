/*
	How many elements(in left) are just greater than or equal to the current. Only neighbour elements.
	I/P:	15	13	12	14	16	8	6 	4 	10	30
	O/P:	1 	1 	1 	3 	5 	1 	1 	1 	4 	10
*/
#include<iostream>
#include<stack>
using namespace std;

int* getStockSpan(int arr[], int n) {
	stack<int> s;
	int *res = new int[n];
	for(int i=0;i<n;i++) {
		while(!s.empty() && arr[i] >= arr[s.top()]) {
			s.pop();
		}
		int span = (s.empty()) ? (i+1) : (i - s.top());
		res[i] = span;
		s.push(i);
	}

	return res;
}

int main(){
	int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
	int n = sizeof(arr) / sizeof(arr[0]);

	int *res = getStockSpan(arr, n);

	for(int i=0;i<n;i++) {
		cout<<res[i]<<" ";
	}

	delete(res);

	return 0;
}