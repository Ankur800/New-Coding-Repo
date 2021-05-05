/*
	
	You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.
	Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey to determine which cell contains what, but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.
	Find Minimum health for given grid, so that the player can reach from (0, 0) to (m-1, n-1)
	
	Test case
	3
	2 3
	0 1 -3
	1 -2 0
	2 2
	0 1
	2 0
	3 4
	0 -2 -3 1
	-1 4 0 -2
	1 -2 -3 0 
	 
	Output
	2
	1
	2
	
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &health, int si, int sj, int ei, int ej, int** arr) {
    if(si == ei && sj == ej) {
        return 1;
    }
    if(si > ei || sj > ej) {
        return INT_MAX;
    }
    if(arr[si][sj] > -1) {
        return arr[si][sj];
    }
    int option1;
    if(si+1 <= ei) {
		option1 = solve(health, si+1, sj, ei, ej, arr) - health[si+1][sj];
	} else {
		option1 = INT_MAX;
	}
	int option2;
	if(sj+1 <= ej ) {
		option2 = solve(health, si, sj+1, ei, ej, arr) - health[si][sj+1];
	} else {
		option2 = INT_MAX;
	}
    int ans = min(option1, option2);
    if(ans < 1) {
        ans = 1;
    }
    arr[si][sj] = ans;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> health(r, vector<int>(c));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>health[i][j];
            }
        }
        int** arr = new int*[r];
        for(int i=0;i<r;i++) {
            arr[i] = new int[c];
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                arr[i][j] = -1;
            }
        }
        int ans = solve(health, 0, 0, r-1, c-1, arr);
       
        for(int i=0;i<r;i++) {
            delete[] arr[i];
        }
        delete[] arr;
        cout<<ans<<endl;
    }
    
    return 0;
}
