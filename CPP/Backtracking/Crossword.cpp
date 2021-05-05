/* Input
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
*/

#include<bits/stdc++.h>
using namespace std;

#define N 10

void printGrid(char grid[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

bool isValidVertical(char grid[N][N], int row, int col, string str) {
    if(row+str.size() > N || grid[row+str.size()-1][col] == '+') {
        return false;
    }
    for(int i=row;i<row+str.size();i++) {
        if(grid[i][col] == '+') {
            return false;
        } else {
            if(grid[i][col] != '-') {
                if(grid[i][col] != str[i-row]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidHorizontal(char grid[N][N], int row, int col, string str) {
    if(col + str.size() > N || grid[row][col+str.size()-1] == '+') {
        return false;
    }
    for(int j=col;j<col+str.size();j++) {
        if(grid[row][j] == '+') {
            return false;
        } else {
            if(grid[row][j] != '-') {
                if(grid[row][j] != str[j-col]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void setVertical(char grid[N][N], string str, int row, int col, bool setArray[]) {
    for(int i=row;i<row+str.size();i++) {
        if(grid[i][col] == '-') {
        	grid[i][col] = str[i-row];
            setArray[i-row] = true;
        } else {
            setArray[i-row] = false;
        }
    }
}

void setHorizontal(char grid[N][N], string str, int row, int col, bool setArray[]) {
    for(int j=col;j<col+str.size();j++) {
        if(grid[row][j] == '-') {
        	grid[row][j] = str[j-col];
            setArray[j-col] = true;
        } else {
            setArray[j-col] = false;
        }
    }
}

void resetVertical(char grid[N][N], int row, int col, bool setArray[], int n) {
    for(int i=0;i<n;i++) {
        if(setArray[i] == true) {
            grid[row+i][col] = '-';
        }
    }
}

void resetHorizontal(char grid[N][N], int row, int col, bool setArray[], int n) {
    for(int j=0;j<n;j++) {
        if(setArray[j] == true) {
            grid[row][col+j] = '-';
        }
    }
}

bool solve(char grid[N][N], vector<string> words, int index) {
    if(index == words.size()) {
        printGrid(grid);
        return true;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(grid[i][j] == '-' || grid[i][j] == words[index][0]) {
                if(isValidVertical(grid, i, j, words[index])) {
                    bool setArray[words[index].size()];
                    setVertical(grid, words[index], i, j, setArray);
                    if(solve(grid, words, index+1)) {
                        return true;
                    } else {
                        resetVertical(grid, i, j, setArray, words[index].size());
                        
                    }
                } 
                if(isValidHorizontal(grid, i, j, words[index])) {
                    bool setArray[words[index].size()];
                    setHorizontal(grid, words[index], i, j, setArray);
                    if(solve(grid, words, index+1)) {
                        return true;
                    } else {
                        resetHorizontal(grid, i, j, setArray, words[index].size());
                    }
                }
            }
        }
    }
    return false;
}

int main() {
	char grid[N][N];
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        for(int j=0;j<N;j++) {
            grid[i][j] = s[j];
        }
    }
    vector<string> words;
	string tempWords;
    cin>>tempWords;
    string temp = "";
    for(int i=0;i<tempWords.size();i++) {
        if(tempWords[i] <= 'Z' && tempWords[i] >= 'A') {
            temp += tempWords[i];
        } else {
            words.push_back(temp);
            temp = "";
        }
    }
    words.push_back(temp);
    solve(grid, words, 0);
}
