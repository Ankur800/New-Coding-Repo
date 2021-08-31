/*
 You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). 
 A query is defined as follows:
 Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
 Given M queries, your program must output the results of these queries. 
 INPUT:
	6 
	-2 5 -1 4 9 3
	5
	1 2
	1 3
	1 6
	4 6
	4 5
	3 5
 OUTPUT:
	5
	5
	20
	16
	13
  
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
	long long totalSum = 0, bestSum = 0, bestPrefixSum = 0, bestSuffixSum = 0;  
};

Node findBestSum(Node a, Node b) {
    Node ans;
    ans.totalSum = a.totalSum + b.totalSum;
    ans.bestPrefixSum = max(a.bestPrefixSum, a.totalSum + b.bestPrefixSum);
    ans.bestSuffixSum = max(b.bestSuffixSum, b.totalSum + a.bestSuffixSum);
    ans.bestSum = max(a.bestSum, max(b.bestSum, max(a.totalSum + b.bestPrefixSum,
                    max(b.totalSum + a.bestSuffixSum, a.bestSuffixSum + b.bestPrefixSum))));
    return ans;
}

void buildTree(int* arr, Node* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode].totalSum = arr[start];
        tree[treeNode].bestSum = arr[start];
        tree[treeNode].bestPrefixSum = arr[start];
        tree[treeNode].bestSuffixSum = arr[start];
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode] = findBestSum(tree[2*treeNode], tree[2*treeNode+1]);
}

Node query(Node* tree, int start, int end, int treeNode, int left, int right) {
    //inside
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    //outside
    if(start > right || end < left) {
        Node temp;
        temp.bestSum = INT_MIN;
        temp.totalSum = INT_MIN;
        temp.bestPrefixSum = INT_MIN;
        temp.bestSuffixSum = INT_MIN;
        return temp;
    }
    //partial
    int mid = (start + end)/2;
    Node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    Node ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    Node ans = findBestSum(ans1, ans2);
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
    int m;
    cin>>m;
    while(m--) {
        int x, y;
        cin>>x>>y;
        Node ans = query(tree, 0, n-1, 1, x-1, y-1);
        cout<<ans.bestSum<<endl;
    }
    
}
