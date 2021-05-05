#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
	if(start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateLazySegmentTree(int* tree, int* lazy, int start, int end, int treeNode, int left, int right, int value) {
	if(start > end) {
		return;
	}
	//First Check whether some update work has left in past
	if(lazy[treeNode] != 0) {
		tree[treeNode] += lazy[treeNode];
		if(start != end) {
			lazy[2*treeNode] += lazy[treeNode];
			lazy[2*treeNode+1] += lazy[treeNode];
		}
		lazy[treeNode] = 0;
	}
	
	//No Overlap
	if(left > end || right < start) {
		return;
	}
	
	//Completely Overlap
	if(start >= left && end <= right) {
		tree[treeNode] += value;
		if(start != end) {
			lazy[2*treeNode] += value;
			lazy[2*treeNode+1] += value;
		}
		return;
	}
	
	//Partial Overlap
	int mid = (start + end) / 2;
	updateLazySegmentTree(tree, lazy, start, mid, 2*treeNode, left, right, value);
	updateLazySegmentTree(tree, lazy, mid+1, end, 2*treeNode+1, left, right, value);
	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

int main() {
	int arr[] = {1, 3, -2, 4};
	int n = 4;
	int tree[4*n] = {};
	buildTree(arr, tree, 0, n-1, 1);
	
	int lazy[4*n] = {};
	
	updateLazySegmentTree(tree, lazy, 0, n-1, 1, 0, 3, 3);
	updateLazySegmentTree(tree, lazy, 0, n-1, 1, 0, 1, 2);
	
	cout<<"Segment Tree"<<endl;
	
	for(int i=1;i<2*n;i++) {
		cout<<tree[i]<<endl;
	}
	
	cout<<"Lazy Tree"<<endl;
	
	for(int i=1;i<2*n;i++) {
		cout<<lazy[i]<<endl;
	}
	
	return 0;
}
