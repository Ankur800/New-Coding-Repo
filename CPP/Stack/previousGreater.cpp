/*
	Given an array of distinct integers, find closest(position-wise) greater on left of every element.
	If there is no greater element on left, then print -1.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void previousGreater(vector<int> &arr) {
	if(arr.size() == 0) {
		return;
	}
	stack<int> st;
	st.push(0);
	cout<<-1<<" ";
	for(int i=1;i<arr.size();i++) {
		while(!st.empty() && arr[i] > arr[st.top()]) {
			st.pop();
		}

		int ele = (st.empty()) ? -1 : arr[st.top()];
		cout<<ele<<" ";
		st.push(i);
	}
}

int main() {
	vector<int> arr = {15, 10, 18, 12, 4, 6, 2, 8};
	previousGreater(arr);

	return 0;
}