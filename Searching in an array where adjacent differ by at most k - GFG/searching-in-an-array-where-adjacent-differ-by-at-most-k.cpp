//{ Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k);


// Driver program to test above function
int main()
{
	int t,n,k,x;
	cin>>t;
	while(t--)
    {

        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>x;
        cout<<search(arr, n, x, k)<<endl;

    }
return 0;
}


// } Driver Code Ends


// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
   
   int i = 0;
   int ans = -1;
   
   while(i<n){
       
       if(arr[i]==x){
           ans = i;
           break;
       }
       
       int diff = abs(arr[i]-x);
      
       int jump = diff/k; //times to jump
     
        if(jump < 1)jump = 1; //if diff is one, 0 jumps will reflect

       
       i = i + jump; //Jump diff times
       
       
   }
   
   return ans;
}    	