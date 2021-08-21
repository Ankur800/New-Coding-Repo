/*
	Given k sorted arrays. Merge them into one sorted array.
	I/P:	arr[][] = {{5, 10}, {4, 9}, {6}};
	O/P:	4, 5, 6, 9, 10
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Triplet {
	int val, pos, index;
	Triplet(int x, int y, int z) {
		val = x;
		pos = y;
		index = z;
	}
};

struct myComp {
	bool operator()(Triplet &t1, Triplet &t2) {
		return t1.val > t2.val;
	}
};

vector<int> mergeArrays(vector<vector<int>> &arr) {
	vector<int> res;
	priority_queue<Triplet, vector<Triplet>, myComp> pq;
	for(int i=0;i<arr.size();i++) {
		Triplet t(arr[i][0], i, 0);
		pq.push(t);
	}

	while(!pq.empty()) {
		Triplet curr = pq.top();
		pq.pop();
		res.push_back(curr.val);
		int pos = curr.pos;
		int index = curr.index;
		if(index+1 < arr[pos].size()) {
			Triplet t(arr[pos][index+1], pos, index+1);
			pq.push(t);
		}
	}

	return res;
}

int main() {
	vector<vector<int>> arr = {{5, 10}, {4, 9}, {6}};
	vector<int> res = mergeArrays(arr);
	for(auto num : res) {
		cout<<num<<" ";
	}

	return 0;
}