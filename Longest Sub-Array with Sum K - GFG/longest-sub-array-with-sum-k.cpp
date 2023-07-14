//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 

        //going to store the prefixSum in the hashmap
        map<int,int> prefixSum;
        
        int maxLength = 0;
        int sum = 0;
        
        for(int i = 0;i<N;i++){
            
            sum += A[i];
            
            //check if the current sum is equal to K or not
            if(sum == K){
                
                maxLength = max(maxLength , i+1);
                
            }
            
            //find the ele after removing which, we will get the sum as k
            int rem = sum - K;
            
            //check if that element is there in the prefixSum
            if(prefixSum.find(rem) != prefixSum.end()){
                
                //get the length and store the maxLength
                int length = i - prefixSum[rem];
                maxLength = max(maxLength,length);
                
            }
            
            //since we have to find the maximum Length, we will only update the
            //hashmap index if the prefixSum was not present previously(since we have
            //to get the left most starting point)
            
            if(prefixSum.find(sum) == prefixSum.end())
                prefixSum[sum] = i;
            
        }

    return maxLength;

    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends