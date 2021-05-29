/*
	We are given arrival and departure times of the guests, 
	we need to find the time to go to the pary so that you can meet maximum people.
	arr[] = {900, 940, 950, 1100, 1500, 1800}
	dep[] = {910, 1200, 1120, 1130, 1900, 2000}
	I/P:	3
*/
#include<iostream>
#include<algorithm>
using namespace std;

int getMaxMeeting(int arr[], int dep[], int n) {
	sort(arr, arr+n);
	sort(dep, dep+n);
	int i=0, j=0, res=0, curr=0;
	while(i < n && j < n) {
		if(arr[i] <= dep[j]) {
			curr++;
			i++;
		} else 	{
			curr--;
			j++;
		}
		res = max(res, curr);
	}

	return res;
}

int main() {
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<getMaxMeeting(arr, dep, n)<<endl;

	return 0;
}