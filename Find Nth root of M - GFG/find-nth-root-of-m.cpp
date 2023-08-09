//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	
	//this function
	//returns 1 if == m
	//returns -1 if < m
	//returns 2 if > m
	
	int isPossible(int mid,int n,int m){
	    
	    long long ans = 1;
	    
	    for(int i = 1;i<=n;i++){
	        
	        ans *= mid;
	        
	        if(ans > m)//if the ans exceeds
	            return 2;
	        
	    }
	    
	    if(ans == m)//check for equal
	        return 1;

	   return -1;//if the value is smaller
	    
	}
	
	int NthRoot(int n, int m)
	{
	    
	    int start = 1;
	    int end = m;
	    
	    while(start <= end){
	        
	        int mid = start + (end - start)/2;
	        
	        int val = isPossible(mid,n,m);
	        
	        //found the root
	        if(val == 1){
	            
	            return mid;
	            
	        }
	        
	        //shrink the search space
	        if(val == -1){
	            
	            start = mid+1;
	            
	        }else{//if val == 2
	            
	            end = mid-1;
	            
	        }

	    }
	    
	    return -1;
	    
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends