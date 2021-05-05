/*
Input:
* 
* 
* U is update
* Q is query
* 
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12 
 
 
 */



#include<bits/stdc++.h>
using namespace std;

struct Node{
	int first, second;
};

Node compare(Node node1, Node node2) {
    Node ans;
    if(node1.first > node2.first) {
        ans.first = node1.first;
        if(node1.second > node2.first) {
            ans.second = node1.second;
        } else {
            ans.second = node2.first;
        }
    } else {
        ans.first = node2.first;
        if(node2.second > node1.first) {
            ans.second = node2.second;
        } else {
            ans.second = node1.first;
        }
    }
    
    return ans;
}

void buildTree(int* arr, Node* tree, int start, int end, int treeNode) {
    
    if(start == end) {
        tree[treeNode].first = arr[start];
        tree[treeNode].second = 0;
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode] = compare(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateTree(int* arr, Node* tree, int start, int end, int treeNode, int index, int value) {
    if(start == end) {
        tree[treeNode].first = value;
        arr[index] = value;
        return;
    }
    
    int mid = (start + end)/2;
    if(index <= mid) {
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);
    } else {
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
    }
    
    tree[treeNode] = compare(tree[2*treeNode], tree[2*treeNode+1]);
}

Node query(Node* tree, int start, int end, int treeNode, int left, int right) {
    //inside
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    //outside
    if(start > right || end < left) {
        Node node;
        node.first = 0;
        node.second = 0;
        return node;
    }
    //partial
    int mid = (start + end) / 2;
    Node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    Node ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    Node ans = compare(ans1, ans2);
    return ans;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    Node tree[4*n] = {};
    buildTree(arr, tree, 0, n-1, 1);
    int q;
    cin>>q;
    while(q--) {
        char ch;
        int x, y;
        cin>>ch>>x>>y;
        if(ch == 'Q') {
            Node ans = query(tree, 0, n-1, 1, x-1, y-1);
            cout<<ans.first+ans.second<<endl;
        } else {
            updateTree(arr, tree, 0, n-1, 1, x-1, y);
        }
    }
    
    
}
