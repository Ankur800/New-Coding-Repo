/*
	Given an array of interval representing start time and end time. Merge the overlapping intervals.
	I/P:	{{7, 9}, {6, 10}, {4, 5}, {1, 3}, {2, 4}}
	O/P:	{{1, 5}, {6, 10}}
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct Interval {
	int start, end;
};

bool myComp(Interval &a, Interval &b) {
	if(a.start == b.start) {
		return a.end <= b.end;
	}
	return a.start <= b.start;
}

void mergeOverlappingIntervals(Interval arr[], int n) {
	sort(arr, arr+n, myComp);
	int res = 0;
	for(int i=1;i<n;i++) {
		if(arr[res].end >= arr[i].start) {
			arr[res].end = max(arr[res].end, arr[i].end);
		} else {
			res++;
			arr[res] = arr[i];
		}
	}

	for(int i=0;i<=res;i++) {
		cout<<"("<<arr[i].start<<", "<<arr[i].end<<")"<<endl;
	}

}

int main() {
	Interval arr[] = {{7, 9}, {6, 10}, {4, 5}, {1, 3}, {2, 4}};
	int n = sizeof(arr) / sizeof(arr[0]);

	mergeOverlappingIntervals(arr, n);

	return 0;
}