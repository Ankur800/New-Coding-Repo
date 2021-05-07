/*
	Find K most frequent elements
*/
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct myComp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
	if(a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
}
};

void kMostFreqEle(int *arr, int n, int k) {		// in increasing order
	unordered_map<int, int> m;
	for(int i=0;i<n;i++) {
		m[arr[i]]++;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq(m.begin(), m.end());
	while(k--) {
		cout<<pq.top().first<<" ";		// O(klogn)
		pq.pop();
	}
	//sort(v.begin(), v.end(), myComp);

	// for(int i=0;i<k;i++) {		O(nlogn)
	// 	cout<<v[i].first<<" ";
	// }
}

void linearSol(int *arr, int n, int k) {	// order as in array
	unordered_map<int, int> m;
	for(int i=0;i<n;i++) {
		m[arr[i]]++;
	}
	vector<int> freq[n+1];		// max freq can be n, i.e. all elements are same

	for(int i=0;i<n;i++) {
		int f = m[arr[i]];
		if(f != -1) {
			freq[f].push_back(arr[i]);
			m[arr[i]] = -1;
		}
	}

	for(int i=n;i>=0;i--) {
		if(k == 0) {
			return;
		}
		if(freq[i] != 0) {
			cout<<freq[i]<<" ";
			k--;
		}
	}
}

int main() {
	int arr[] = {10, 20, 10, 30, 10, 20, 30};
	int n = 7;
	int k = 3;
	kMostFreqEle(arr, n, k);

	return 0;
}