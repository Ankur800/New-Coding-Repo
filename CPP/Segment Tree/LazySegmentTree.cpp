#include<bits/stdc++.h>
using namespace std;

void buildTree(int arr[], int tree[], int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode] = max(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateLazyTree(int tree[], int lazy[], int start, int end, int treeNode, int left, int right, int value) {
    if(start > end) {
        return;
    }
    
    // past works
    if(lazy[treeNode] != 0) {
        tree[treeNode] += lazy[treeNode];
        if(start != end) {
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    
    // No overlap
    if(left > end || right < start) return;
    
    // Complete Overlap
    if(start >= left && end <= right) {
        tree[treeNode] += value;
        if(start != end) {
            lazy[2*treeNode] += value;
            lazy[2*treeNode+1] += value;
        }
        return;
    }
    
    // Partial Overlap
    int mid = (start + end) / 2;
    updateLazyTree(tree, lazy, start, mid, 2*treeNode, left, right, value);
    updateLazyTree(tree, lazy, mid+1, end, 2*treeNode+1, left, right, value);
    
    tree[treeNode] = max(tree[2*treeNode], tree[2*treeNode+1]);
}

int query(int tree[], int lazy[], int start, int end, int treeNode, int left, int right) {
    // wrong ranges
    
    if(lazy[treeNode] != 0) {
        tree[treeNode] += lazy[treeNode];
        if(start != end) {
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    
    // No overlap
    if(left > end || right < start) return INT_MIN;
    
    // Complete Overlap
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    
    // Partial Overlap
    int mid = (start + end) / 2;
    int ans1 = query(tree, lazy, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, lazy, mid+1, end, 2*treeNode+1, left, right);
    
    return max(ans1, ans2);
}

int main() {
	int n = 4;
	int arr[n] = {0};
    int tree[4*n] = {0};
    buildTree(arr, tree, 0, n-1, 1);
    
    int lazy[4*n] = {0};
	
    updateLazyTree(tree, lazy, 0, n-1, 1, 2, 3, 603);

    for(int i=1;i<2*n;i++) {
    	cout<<tree[i]<<" ";
    }

	return 0;
}
