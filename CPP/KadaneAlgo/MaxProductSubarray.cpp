#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> arr(11, vector<int>(11 ,0));

bool canPlace(int n, int x, int y) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(arr[i][j] == 1) {
				if(i == x || j == y || i+j == x+y || i-j == x-y) {
					return false;
				}
			}
		}
	}
	return true;
}

void nQueen(int n, int row) {
	if(row == n) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"****************"<<endl;
		return;
	}
	for(int j=0;j<n;j++) {
		if(canPlace(n, row, j)) {
			arr[row][j] = 1;
			nQueen(n, row+1);
			arr[row][j] = 0;
		}
	}
}

int main() {
	int n;
	cin>>n;
	nQueen(n, 0);
	
	return 0;
}
