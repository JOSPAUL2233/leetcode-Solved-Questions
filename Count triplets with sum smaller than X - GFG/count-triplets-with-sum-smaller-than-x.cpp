//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    
	    long long counter = 0;
	    
	    for(int first = 0;first<n;first++){
	            
	        if(first>0 && arr[first] == arr[first-1])first++;
	        
	        int second = first+1;
	        int third = n-1;
	        
	        while(second<third){
	            
	            long long currSum = arr[first]+arr[second]+arr[third];
	            
	           // cout<<first<<" "<<second<<" "<<third<<endl;

	           // cout<<"sum:"<<currSum<<endl;
	        
    	        if(currSum<sum){
    	            
    	            counter = counter + (third-second);
    	            second++;

    	            while(second<third && arr[second]==arr[second-1])second++;

    	        }else{
    	            
    	            third--;
    	            
    	        }
	            
	            
	        }
	        
	    }
	   
	   return counter;
	    
	}

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends