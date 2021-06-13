/*
	Find previous smaller element in the array.
	I/P:	6	2	5	4	1	5	6
	O/P:	-1	-1	2	2	-1	1	5
*/
#include<iostream>
#include<stack>
using namespace std;

void getPreviousSmaller(int arr[], int n) {
	stack<int> s;
	s.push(0);
	cout<<-1<<" ";
	for(int i=1;i<n;i++) {
		while(!s.empty() && arr[s.top()] > arr[i]) {
			s.pop();
		}
		int ans = (s.empty()) ? -1 : arr[s.top()];
		cout<<ans<<" ";
		s.push(i);
	}
	cout<<endl;
}

int main() {
	int arr[] = {6, 2, 5, 4, 1, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	getPreviousSmaller(arr, n);

	return 0;
}