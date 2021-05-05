#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int* distance, bool* visited, int n) {
	int minVertex = -1;
	for(int i=0;i<n;i++) {
		if(!visited[i] && ((minVertex == -1) || distance[i] < distance[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges, int n) {
	bool* visited = new bool[n]();
	int* distance = new int[n];
	for(int i=0;i<n;i++) {
		distance[i] = INT_MAX;
	}
	distance[0] = 0;		// src
	
	for(int i=0;i<n-1;i++) {
		 // Get unvisited vertex with minimum distance
		 int minVertex = getMinVertex(distance, visited, n);
		 visited[minVertex] = true;
		 
		 // Explore all the neighbours of minVertex which are unvisited and update the distance array if required
		 for(int j=0;j<n;j++) {
			if(edges[minVertex][j] && !visited[j]) {	// if neighbour and not visited
				int currentDistance = distance[minVertex] + edges[minVertex][j];
				if(distance[j] > currentDistance) {
					distance[j] = currentDistance;
				}
			}
		 }
	}
	
	for(int i=0;i<n;i++) {
		cout<<i<<" "<<distance[i]<<endl; 
	}
	
	delete[] visited;
	delete[] distance;
}

int main() {
	int n, e;
	cin>>n>>e;
	int** edges = new int*[e];
	for(int i=0;i<n;i++) {
		edges[i] = new int[e];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s, w;
		cin>>f>>s>>w;
		edges[f][s] = w;
		edges[s][f] = w;
	}
	
	dijkstra(edges, n);
	
	for(int i=0;i<e;i++) {
		delete[] edges[i];
	}
	delete[] edges;
	
	return 0;
}
