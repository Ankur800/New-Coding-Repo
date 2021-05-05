/*
 * Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Output:
1
1
2
1


*/


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

void updateTree(int* arr, int* tree, int start, int end, int treeNode, int index, int value) {
    if(start == end) {
        tree[treeNode] = value;
        arr[index] = value;
        return;
    }
    
    int mid = (start + end) / 2;
    if(index <= mid) {
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);
    } else {
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
    }
    
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

int query(int* tree, int start, int end, int treeNode, int left, int right) {
    //inside
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    //outside
    if(start > right || end < left) {
        return INT_MAX;
    }
    //partial
    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    return min(ans1, ans2);
}

int main() {
	int n, q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int tree[4*n] = {};
    buildTree(arr, tree, 0, n-1, 1);
    
    while(q--) {
        char ch;
        int x, y;
        cin>>ch>>x>>y;
        if(ch == 'u') {
            updateTree(arr, tree, 0, n-1, 1, x-1, y);
        } else {
            cout<<query(tree, 0, n-1, 1, x-1, y-1)<<endl;
        }
    }
    
}
