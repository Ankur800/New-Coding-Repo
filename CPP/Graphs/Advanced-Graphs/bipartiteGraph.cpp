#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>* edges = new vector<int>[n];
	int m;
	cin>>m;
	for(int i=0;i<m;i++) {
		int j, k;
		cin>>j>>k;
		edges[j].push_back(k);
		edges[k].push_back(j);
	}
	

	return 0;
}
