#include<iostream>
#include<vector>
using namespace std;
#define N 1000

void reverseArray(vector<int> &arr, int start, int end) {
    while (start < end) {
        int temp = arr[start]; 
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
}    

vector<int> addTwoArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> res;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    
    int carry = 0;
    while(i >= 0 || j >= 0 || carry) {
        int temp = carry;
        if(i >= 0) {
            temp += arr1[i];
        }
        if(j >= 0) {
            temp += arr2[j];
        }
        
        res.push_back(temp % 10);
        carry = temp / 10;
        i--;
        j--;
    }
    reverseArray(res, 0, res.size()-1);
    return res;
}

void fibonacci(vector<vector<int>> &arr, int i) {
    if(i <= 1) {
        vector<int> temp;
        temp.push_back(i);
        arr[i] = temp;
        return;
    }
    if(!arr[i].empty()) {
        return;
    }
    fibonacci(arr, i-1);
    fibonacci(arr, i-2);
    vector<int> res = addTwoArray(arr[i-1], arr[i-2]);
    arr[i] = res;
}

int main() {
	vector<vector<int>> arr(N); 
    fibonacci(arr, N-1);
    for(int i=0;i<N;i++) {
        for(int j=0;j<arr[i].size();j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}
