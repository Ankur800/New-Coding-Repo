#include<iostream>
#include<queue>
using namespace std;

//sv = starting vertex

void printDFS(int** edges, int n, int sv, bool* visited) {
	cout<<sv<<endl;
	visited[sv] = true;
	for(int i=0;i<n;i++) {
		if(i == sv) {
			continue;
		}
		if(edges[sv][i] == 1) {
			if(visited[i] == true) {
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void printBFS(int** edges, int n, int sv, bool* visited) {
	queue<int> myQueue;
	myQueue.push(sv);
	visited[sv] = true;
	while(!myQueue.empty()) {
		cout<<myQueue.front()<<endl;
		int currentNode = myQueue.front();
		myQueue.pop();
		for(int i=0;i<n;i++) {
			if(currentNode == i) {
				continue;
			}
			if(edges[currentNode][i] == 1) {
				if(visited[i]) {
					continue;
				}
				myQueue.push(i);
				visited[i] = true;
			}
		}
	}
}

void DFS(int** edges, int n) {
	bool* visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			printDFS(edges, n, 0, visited);
		}
	}
	
	//delete
	delete[] visited;
}

void BFS(int** edges, int n) {
	bool* visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			printBFS(edges, n, 0, visited);
		}
	}
	
	//delete
	delete[] visited;
}

int main(){
	int n, e;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0;i<n;i++) {
		edges[i] = new int[n];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
	cout<<"DFS"<<endl;
	DFS(edges, n);
	
	cout<<"BFS"<<endl;
	BFS(edges, n);
	
	//Releasing Dynamically allocated spaces
	for(int i=0;i<n;i++) {
		delete[] edges[i];
	}
	delete[] edges;
	
	return 0;
}
