//{ Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}


// } Driver Code Ends


long long int calculate(int a[], int n)
{
    
    map<int,int> occurance;
    long long count = 0;
    
    for(int i = 0;i<n;i++){
        
        //check if the same element were present before
        //if yes, store increase the count by number of times that element occured
        if(occurance.find(a[i]) != occurance.end()){
            
            count += occurance[a[i]];
            
        }
        
        //increase the occurance by 1
        occurance[a[i]]++;
        
    }
    
    return count;
    
}
