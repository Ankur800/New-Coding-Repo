int tripletSum(int *arr, int n, int num)
{
    int count = 0;
    sort(arr, arr+n);
    
	for(int i=0;i<n-2;i++) {
    	int j = i+1;
        int k = n-1;
        while(j < k) {
            if(arr[i] + arr[j] + arr[k] < num) {
                j++;
            } else if(arr[i] + arr[j] + arr[k] > num) {
                k--;
            } else {
                count++;
                
                if((arr[j] == arr[j+1]) && (arr[k] == arr[k-1]) && j<k) {
                    int tempCount = 0;
                    while((arr[j] == arr[j+1]) && (arr[k] == arr[k-1]) && (j < k)) {
                        tempCount++;
                        j++;
                        k--;
                    }
                    count += pow(2, tempCount);
                } else if(arr[j] == arr[j+1] && j<k){
                    j++;
                } else if(arr[k] == arr[k-1] && j<k) {
                    k--;
                } else {
                    j++;
                    k--;
                }
            }
        }
    }
    return count;
}
