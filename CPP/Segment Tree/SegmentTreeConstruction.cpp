#include<iostream>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
	if(start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	
	int mid = (start + end) / 2;
	
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode + 1);
	
	tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;
	int tree[2*n];		// 2n size tree array
	
	buildTree(arr, tree, 0, n-1, 1);	//start filling from 1st index
	
	for(int i=1;i<2*n;i++) {
		cout<<tree[i]<<endl;
	}

	return 0;
}
