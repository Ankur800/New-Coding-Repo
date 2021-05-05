#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane(vector<int> arr) {
    ll current_sum = 0;
    ll best_sum = INT_MIN;
    for(int num :  arr) {
        current_sum += num;
        if(current_sum > best_sum) {
            best_sum = current_sum;
        }
        if(current_sum < 0) {
            current_sum = 0;
        }
    }
    return best_sum;
}

ll maxSubarraySum(vector<int>arr, int k) {
    ll kadanesSum = kadane(arr);
    if(k == 1) {
        return kadanesSum;
    }
    ll current_suffix_sum = 0, current_prefix_sum = 0;
    ll max_prefix_sum = INT_MIN;
    ll max_suffix_sum = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++) {
        current_prefix_sum += arr[i];
        max_prefix_sum = max(max_prefix_sum, current_prefix_sum);
    }
    ll totalSum = current_prefix_sum;
    for(int i=n-1;i>=0;i--) {
        current_suffix_sum += arr[i];
        max_suffix_sum = max(max_suffix_sum, current_suffix_sum);
    }
    ll ans;
    if(totalSum < 0) {
        ans = max(kadanesSum, max_prefix_sum + max_suffix_sum);
    } else {
        ans = max(max_prefix_sum + max_suffix_sum + (totalSum * (k-2)), kadanesSum);
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n, k;
	    vector<int> arr;
	    cin>>n>>k;
	    for(int i=0;i<n;i++) {
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    cout<<maxSubarraySum(arr, k)<<endl;
	}
	
	return 0;
}
