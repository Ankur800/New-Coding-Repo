#include<bits/stdc++.h>
using namespace std;

class Edge {
	public:
		int src;
		int dest;
		int weight;
};

bool compare(Edge &e1, Edge &e2) {
	return e1.weight < e2.weight;
}

int getParent(int v, int* parent) {
	if(parent[v] == v) {
		return v;
	}
	return getParent(parent[v], parent);
}

Edge* kruskal(Edge* edges, int n, int E) {
	// Sort edges on the basis of weight
	sort(edges, edges+E, compare);
	
	Edge* output = new Edge[n-1];
	int* parent = new int[n];
	for(int i=0;i<n;i++) {
		parent[i] = i;			// Initializing the parent matrix(array)
	}
	
	int count = 0;
	int i = 0;
	while(count < (n-1)) {
		// Check the topmost parent of v1 and v2.
		// v1 and v2 are vertices of current edge.
		Edge currentEdge = edges[i];
		int srcParent = getParent(currentEdge.src, parent);
		int destParent = getParent(currentEdge.dest, parent);
		
		if(srcParent != destParent) {
			output[count++] = currentEdge;
			parent[srcParent] = destParent;
		}
		i++;
	}
	
	delete[] parent;

	return output;
}

int main() {
	int n, E;
	cin>>n>>E;
	Edge* edges = new Edge[E];
	for(int i=0;i<E;i++) {
		cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
	}
	
	Edge* output = kruskal(edges, n, E);
	
	for(int i=0;i<n-1;i++) {
		if(output[i].src < output[i].dest) {
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		} else {
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
		}
	}
	
	delete[] output;
	delete[] edges;
	
	return 0;
}
