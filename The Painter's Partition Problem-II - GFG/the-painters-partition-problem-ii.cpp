//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  
    bool isPossible(int arr[],int n,int k,long long mid){
        
        
        int count = 1;
        int sum = 0;
        
        for(int i = 0;i<n;i++){
            
            if(sum + arr[i] > mid){
                
                count++;
                sum = arr[i];
                
                if(count > k)
                    return false;
                
            }else{
                
                sum += arr[i];
                
            }
            
        }
        
        return true;
        
    }
  
    long long minTime(int arr[], int n, int k)
    {
        
        //anwer lies between maxLength and sum of all the lengths
        
        long long start = INT_MIN;
        long long end = 0;
        
        for(int i = 0;i<n;i++){
            
            if(arr[i] > start)
                start = arr[i];
            
            end += arr[i];
        }
        
        //apply binary search on answer
        
        long long ans = -1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(arr,n,k,mid)){
                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends