//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	
    	//count the number of ones and zeros in a particular bit position
    	//for all the elements in the array
    	vector<int> ones(32,0);
    	vector<int> zeros(32,0);
    	
    	for(int i = 0;i<n;i++){
    	    
    	    int position = 0;
    	    int ele = arr[i];
    	    
    	    while(position < 32){
    	        
    	        //count number of set and unset bits
    	        if((ele & (1<<position)) > 0){
    	            
    	            ones[position]++;
    	            
    	        }else{
    	            
    	            zeros[position]++;
    	            
    	        }
    	        
    	        position++;//shift the position
    	        
    	    }
    	    
    	}
    	
    	    //now, if we get the number of ones and zeros in a position,
    	    //get the total permutation of them by multiplying each other
    	    //which will result in giving number of ones int the pairs
    	    
    	    //now, using that ones, calculate the final number like how
    	    //decimal is calculated from binary number
    	    
    	    long long ans = 0;
    	       
    	    for(int i = 0;i<32;i++){
    	        
    	       // long long answerOnes = ;
    	        ans += (long long)pow(2,i) * ones[i] * zeros[i];
    	        
    	    }
    	    
    	    return ans;    	
    	
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends