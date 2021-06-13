/*
	Find the largest rectangular area in a Histogram.
	I/P:	6	2	5	4	1	5	6
	O/P:	10	
									 ___					 ___
									|	|	 ___		 ___|	|
									|	|	|	|___	|***|***|
									|	|	|	|	|	|***|***|	Area = 5 * 2 = 10
									|	|___|	|	|	|***|***|
									|	|	|	|	|___|***|***|
									|_6_|_2_|_5_|_4_|_1_|_5_|_6_|
*/
#include<iostream>
#include<stack>
using namespace std;

int getMaxRectAreaInHistogram(int arr[], int n) {
	stack<int> s;
	int res = 0;
	for(int i=0;i<n;i++) {
		while(!s.empty() && arr[s.top()] >= arr[i]) {
			int tp = s.top();
			s.pop();
			int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
			res = max(curr, res);
		}
		s.push(i);
	}
	// No next smaller element exists for these elements
	while(!s.empty()) {
		int tp = s.top();
		s.pop();
		int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
		res = max(curr, res);
	}

	return res;
}

int main() {
	int arr[] = {6, 2, 5, 4, 1, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<getMaxRectAreaInHistogram(arr, n)<<endl;

	return 0;
}