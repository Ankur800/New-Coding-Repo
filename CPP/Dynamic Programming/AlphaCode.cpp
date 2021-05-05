#include <bits/stdc++.h>
using namespace std;

int const m = pow(10, 9) + 7;

int alphaCode(int* arr, int size, int* output) {
	if(size == 0) {
		return 1;
	}
	if(size == 1) {
		return 1;
	}
	if(output[size-1] != 0) {
		return output[size-1];
	}
    if(arr[size-1] == 0) {
		output[size-1] = alphaCode(arr, size-2, output);
		return output[size-1];
	}
    long long res = 0;
	res = alphaCode(arr, size-1, output);
	if((size-2 >= 0) && (arr[size-2] * 10 + arr[size-1] <= 26) && (arr[size-2] * 10 + arr[size-1] >= 10)) {
		res = ((res % m) + (alphaCode(arr, size-2, output)%m))%m;
	}
    output[size-1] = res%m;
	
	return output[size-1];
} 

int main()
{
    string s;
    while(true) {
        cin>>s;
        if(s == "0") {
            break;
        }
        int n = s.size();
        int* arr = new int[n];
        for(int i=0;i<n;i++) {
            arr[i] = s[i] - '0';
        }
        int flag = 0;
        for(int i=1;i<n;i++) {
            if(arr[i] == 0 && (arr[i-1] == 0 || arr[i-1] > 2)) {
                cout<<0<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            int* output = new int[n+1]();
            cout<<alphaCode(arr, n, output)<<endl;
            delete[] output;
        }
    }
    
    return 0;
}
