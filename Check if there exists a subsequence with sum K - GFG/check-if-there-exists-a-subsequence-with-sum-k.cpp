//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    bool solve(vector<int> arr,int n,int k,int index,int sum){
        
        //base case 1 ( only applicable for positive values )
        if(sum > k)
            return false;
        
        //base case 2 ( when index exceeds)
        if(index == n){
            
            if(sum == k)
                return true;
            else
                return false;
            
        }
        
        //including and excluding with bool(true/false) statement
        
        if(solve(arr,n,k,index+1,sum) == true) //excluding
            return true;
            
        if(solve(arr,n,k,index+1,sum+arr[index]) == true)
            return true;
            
        //if no recusive call found the answer
        return false;

    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        
        int index = 0;
        int sum = 0;
        
        return solve(arr,n,k,index,sum);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends