/*
	Given an array of integers. Find median of elements on every point.
	I/P:		arr[] = { 25, 	7, 		10, 	15, 	20 }
	O/P:				{ 25, 	16, 	10, 	12.5, 	15  }

						Sequence				Sort 					Median
						25						25						25
						25, 7					7, 25					16		(7+25)/2
						25, 7, 10				7, 10, 25				10
						25, 7, 10, 15			7, 10, 15, 25			12.5 	(10+15)
						25, 7, 10, 15, 20		7, 10, 15, 20, 25		15
*/
#include<iostream>
#include<queue>
using namespace std;

void printMedianOfStream(int arr[], int n) {
	priority_queue<int> s;
	priority_queue<int, vector<int>, greater<int>> g;
	s.push(arr[0]);
	cout<<arr[0]<<" ";
	for(int i=1;i<n;i++) {
		int x = arr[i];
		if(s.size() > g.size()) {
			if(x < s.top()) {
				g.push(s.top());
				s.pop();
				s.push(x);
			} else {
				g.push(x);
			}
			cout<<(s.top() + g.top())/2.0<<" ";
		} else {
			if(x <= s.top()) {
				s.push(x);
			} else {
				g.push(x);
				s.push(g.top());
				g.pop();				
			}
			cout<<s.top()<<" ";
		}
	}
}

int main() {
	int arr[] = { 25, 7, 10, 15, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printMedianOfStream(arr, n);

	return 0;
}