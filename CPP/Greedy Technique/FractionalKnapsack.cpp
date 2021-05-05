#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
	int weight, value;
};

bool myComp(Item &a, Item &b) {
	double value1 = ((double)a.value)/a.weight;
	double value2 = ((double)b.value)/b.weight;
	return value1 > value2;
}

int main() {
	int W, n;
	cin>>n>>W;
	Item arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i].weight>>arr[i].value;
	}
	sort(arr, arr+n, myComp);
	double profit = 0;
	
	for(int i=0;i<n;i++) {
		if(arr[i].weight <= W) {
			profit += arr[i].value;
			W -= arr[i].weight;
		} else {
			profit += W * ((double)arr[i].value/arr[i].weight);
			break;
		}
	}
	cout<<profit;
	
	return 0;
}
