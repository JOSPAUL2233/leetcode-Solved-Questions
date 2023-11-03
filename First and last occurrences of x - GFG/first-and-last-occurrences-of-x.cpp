//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        
        int start = 0;
        int end = n-1;
        
        int first = -1;
        
        while(start <= end){
            
            int mid = start+ (end - start)/2;
            
            if(arr[mid] == x)
                first = mid;
                
            if(arr[mid] >= x)
                end = mid-1;
            else
                start = mid+1;
            
        }
        
        if(first == -1)
            return {-1,-1};
            
        int last = -1;
        
        start = 0;
        end = n-1;
        
        while(start <= end){
            
            int mid = start+(end - start)/2;
            
            if(arr[mid] == x)
                last = mid;
                
            if(arr[mid] <= x)
                start = mid+1;
            else
                end = mid-1;            
        }
        
        return {first,last};
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends