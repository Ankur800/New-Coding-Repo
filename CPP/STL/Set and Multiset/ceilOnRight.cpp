/*
	Find ceil of every item on right
	I/P- 	10		100		200		30		120		120
	O/P-	30		120		-1		120		120		-1
*/
#include<iostream>
#include<set>
using namespace std;

int* findCeil(int *arr, int n) {
	set<int> s;
	int *res = new int[n];
	for(int i=n-1;i>=0;i--) {
		auto it = s.lower_bound(arr[i]);
		if(it == s.end()) {
			res[i] = -1;
		} else {
			res[i] = arr[i];
		}
		s.insert(arr[i]);
	}

	return res;
}

int main() {
	int arr[] = {10, 100, 200, 30, 120, 120};
	int n = 6;
	int *res = findCeil(arr, n);

	for(int i=0;i<n;i++) {
		cout<<res[i]<<" ";
	}

	delete[] res;

	return 0;
}