/*
	Tell How many elements are smaller in left (include self)
	I/P- 	15	13	12	14	16	8	6	4	10	30
	O/P-	1	1	1 	3	5 	1 	1 	1 	4 	10
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpan(vector<int> &arr) {
	stack<int> st;
	cout<<1<<" ";
	st.push(0);
	for(int i=1;i<arr.size();i++) {
		while(!st.empty() && arr[i] >= arr[st.top()]) {
			st.pop();
		}
		int span = (st.empty()) ? (i+1) : (i - st.top());
		cout<<span<<" ";
		st.push(i);
	}
}

int main() {
	vector<int> arr = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
	stockSpan(arr);

	return 0;
}