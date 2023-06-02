//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        
        unordered_map<int,int> prefixSums;
        int longest = 0;
        
        int sum = 0;

        for(int i = 0;i<N;i++){
            
            sum += A[i];
        
            if(sum==K){
                longest = max(longest, i+1);
            }
            
            int rem = sum - K;

            //finding the remainder element which by subtracting,
            //we get the value as k
            if(prefixSums.find(rem) != prefixSums.end()){
                int len = i - prefixSums[rem];
                longest = max(longest,len);
            }
            
            //only store the index if it is appearing for the 1st time
            //since we need the longest length so, take the left most
            //index as the starting position of any element if it is
            //repeating
            
            if(prefixSums.find(sum) == prefixSums.end()){
                prefixSums[sum] = i;
            }
            
        }
        
        return longest;
        
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