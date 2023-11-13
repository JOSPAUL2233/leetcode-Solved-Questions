//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       
       //take care of edge cases
       if(n == 0)
        return -1;
        
    //agar ek hi element hai tho that will be your peak element
       if(n == 1)
        return 0;
        
       //check for special cases, check if first and last element is your peak element
       
       if(arr[0] >= arr[1])//for first
        return 0;
        
        if(arr[n-1] >= arr[n-2])//for last
        return n-1;     
        
    
        //then the answer will lie between index 1 to n-2 nd index so do a binary search on this reange
        
       int start = 1;
       int end = n-2;
       
       while(start <= end){
           
           int mid = start + (end - start)/2;
           
           //if the peak element is found
           if(arr[mid] >= arr[mid+1] && arr[mid] >= arr[mid-1])
            return mid;
        
            //shrink the search space
            if(arr[mid] > arr[mid-1])
                start = mid+1;
            else
                end = mid-1;
           
       }
       
       return -1;
       
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends