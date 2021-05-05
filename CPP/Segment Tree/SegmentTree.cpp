#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value, length;
};

Node compare(Node node1, Node node2) {
    int value1 = node1.value;
    int length1 = node1.length;
    int value2 = node2.value;
    int length2 = node2.length;
    Node ans;
    if(value1 == 0 || value1 == 3) {
        ans.value = value2;
    } else if(value1 == 1) {
        if(length2 % 2 == 1) {
            ans.value = (2 + value2) % 3;
        } else {
            ans.value = (1 + value2) % 3;
        }
    } else {
        if(length2 % 2 == 1) {
            ans.value = (1 + value2) % 3;
        } else {
            ans.value = (2 + value2) % 3;
        }
    }
    ans.length = length1 + length2;
    return ans;
}

void buildTree(string arr, Node* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode].value = arr[start] - '0';
        tree[treeNode].length = 1;
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode] = compare(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateTree(string arr, Node* tree, int start, int end, int treeNode, int index) {
    if(start == end) {
        if(arr[start] == '0') {
            tree[treeNode].value = 1;
            arr[index] = '1';
        }
        return;
    }
    int mid = (start + end) / 2;
    if(index <= mid) {
        updateTree(arr, tree, start, mid, 2*treeNode, index);
    } else {
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index);
    }
    tree[treeNode] = compare(tree[2*treeNode], tree[2*treeNode+1]);
}

Node queryTree(Node* tree, int start, int end, int treeNode, int left, int right) {
    //outside
    if(start < left || end > right) {
        Node temp;
        temp.value = 0;
        temp.length = 0;
        return temp;
    }
    //inside
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    //partial
    int mid = (start + end) / 2;
    queryTree(tree, start, mid, 2*treeNode, left, right);
    queryTree(tree, mid+1, end, 2*treeNode+1, left, right);
    tree[treeNode] = compare(tree[2*treeNode], tree[2*treeNode+1]);
    return tree[treeNode];
}

int main() {
	int n;
    cin>>n;
    string arr;
    cin>>arr;
    Node tree[4*n] = {};
    buildTree(arr, tree, 0, n-1, 1);
    updateTree(arr, tree, 0, n-1, 1, 1);
  
    for(int i=1;i<2*n;i++) {
		cout<<tree[i].value<<endl;
	}
	Node ans = queryTree(tree, 0, n-1, 1, 2, 4);
	cout<<"ans is "<<ans.value<<endl;
    
    return 0;
}
