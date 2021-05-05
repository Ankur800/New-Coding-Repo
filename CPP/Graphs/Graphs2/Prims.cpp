#include<iostream>
#include<climits>
using namespace std;

int getMinVertex(bool* visited, int* weight, int n) {
	int minVertex = -1;
	for(int i=0;i<n;i++) {
		if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
			minVertex = i;	
		}
	}
	return minVertex;
}

void prims(int** edges, int n) {
	bool* visited = new bool[n]();
	int* parent = new int[n];
	int* weight = new int[n];
	
	for(int i=0;i<n;i++) {
		weight[i] = INT_MAX;
	}
	
	//Let's choose 0 as starting vertex
	parent[0] = -1;
	weight[0] = 0;
	
	for(int i=0;i<n-1;i++) {
		//Get minVertex i.e. unvisited vertex with minimum weight
		int minVertex = getMinVertex(visited, weight, n);
		visited[minVertex] = true;
		
		//Explore all the neighbours of minimum vertex and update parent
		// and weight  array according to that
		for(int j=0;j<n;j++) {
			if(edges[minVertex][j] != 0 && !visited[j]) {
				if(weight[j] > edges[minVertex][j]) {
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	
	for(int i=1;i<n;i++) {
		if(parent[i] < i) {
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		} else {
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}
	}
	
	delete[] visited;
	delete[] parent;
	delete[] weight;
}

int main() {
	int v, e;
	cin>>v>>e;
	int** edges = new int*[v];
	for(int i=0;i<v;i++) {
		edges[i] = new int[v];
		for(int j=0;j<v;j++) {
			edges[i][j] = 0;
		}
	}
	
	for(int i=0;i<e;i++) {
		int f, s, weight;
		cin>>f>>s>>weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	
	prims(edges, v);
	
	//deletion
	for(int i=0;i<v;i++) {
		delete[] edges[i];
	}
	delete[] edges;
	
	return 0;
}
