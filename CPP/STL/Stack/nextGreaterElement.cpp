/*
	Given an array of integers, find NEXT GREATER(position-wise closest and on right side) 
	for every array element;
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreater(vector<int> &arr) {
	if(arr.size() == 0) {
		return;
	}
	int n = arr.size();
	vector<int> res(n);
	stack<int> st;
	st.push(arr[n-1]);
	res[n-1] = -1;
	for(int i=n-2;i>=0;i--) {
		while(!st.empty() && arr[i] > st.top()) {
			st.pop();
		}
		res[i] = (st.empty()) ? -1 : st.top();
		st.push(arr[i]);
	}

	for(int i=0;i<n;i++) {
		cout<<res[i]<<" ";
	}
}

int main() {
	vector<int> arr = {5, 15, 10, 8, 6, 12, 9, 18};
	nextGreater(arr);

	return 0;
}