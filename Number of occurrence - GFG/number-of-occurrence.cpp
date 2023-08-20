//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    //Apply Binary Search
	    
	    int start = 0;
	    int end = n-1;
	    
	    //find the starting index
	    int starting = -1;
	    
	    while(start <= end){
	        
	        int mid = start + (end - start)/2;
	
	        //if found
	        if(arr[mid] == x){
	            
	            starting = mid;

	        }
	        
	        if(arr[mid] >= x){
	            
	            end = mid-1;
	            
	        }else{
	            
	            start = mid+1;
	            
	        }
	        
	    }
	    
	    //if there is no x
	    
	    if(starting == -1)
	        return 0;
	    
	    //find the ending index
	    
	    int ending = -1;
	    start = 0;
	    end = n-1;
	    
	    while(start <= end){
	        
	        int mid = start + (end - start)/2;
	
	        //if found
	        if(arr[mid] == x){
	            
	            ending = mid;

	        }
	        
	        if(arr[mid] <= x){
	            
	            start = mid+1;
	            
	        }else{
	            
	            end = mid-1;
	            
	        }
	        
	    }
	    
	    //return the diff
	    return ending - starting + 1;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends