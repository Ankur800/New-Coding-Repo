#include<iostream> 
#include<vector>
#include		 <list> 
using namespace std; 

int bruteXorSum(int arr[],int n){
	int sum = 0;
	for(int i=0; i<n ; i++){
		for(int j=i+1;j<n;j++){
			sum += arr[i]^arr[j];
		}
	}				
	return sum;
}

int main() 
{ 	
	int arr[] = { 5, 2334, 117, 18, 9};
	int n = 5;
	cout<<"Brute Solution O(N^2) : "<<bruteXorSum(arr,n)<<endl;
	//int base = 1;
	int sum = 0;
	for(int i=0;i<32;i++){
		// i = 0 means we are concerned about 0th bit from last
		// i = 1 means we are concerned about 1 indexed bit from last (2nd bit from last)
		int zeroCount = 0, oneCount = 0;
		for(int j = 0; j < n ; j++ ){
			// How do we find last bit 1/0 ?
			if(  (arr[j]>>i ) & 1 ){
				// not zero 
				oneCount++;
			}else {
				zeroCount++;
			}
		}	
		sum += ( oneCount*zeroCount) * ( 1<<i ); // 1, 10, 100 , 1000 // Because last bit is contributing 1, 2nd last is contributing 2, 4, 8
		//base = base * 2 ;
		//base = base << 1;
	}	
	cout<<"Optimal Solution O(N) : "<< sum <<endl;
	return 0; 
}