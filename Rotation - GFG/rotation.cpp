//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    
	    //find the smallest element index which
	    //tells how many times the array is rotated
	    
	    int low = 0;
	    int high = n-1;
	    
	    pair<int,int> smaller = make_pair(INT_MAX,-1);//sotores --> value,index
	    
	    while(low <= high){
	        
	        int mid = low + (high - low)/2;
	        
	        //check if the left half is sorted
	        if(arr[low] <= arr[mid]){
	            
	            //store the smaller element and
	            //search in right part
	            
	            if(arr[low] < smaller.first){
	                smaller.first = arr[low];
	                smaller.second = low;
	            }
	            
	            
	            low = mid+1;
	            
	            
	        }else{
	            
	            //store the smaller element and
	            //search in left part
	            if(arr[mid] < smaller.first){
	                smaller.first = arr[mid];
	                smaller.second = mid;
	            }
	            
	            high = mid-1;
	            
	        }
	        
	    }
	    
	    return smaller.second;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends