//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    void solve(int n,vector<long long> &ans){
        
        if(n==1){
            ans.push_back(1);
            return;
        }
        
        if(n == 2){
            ans.push_back(1);
            ans.push_back(1);
            return;
        }
            
        solve(n-1,ans);
        
        int s = ans.size();
        ans.push_back(ans[s-1]+ans[s-2]);
        
        
    }
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n)
    {
        
        vector<long long> ans;
        solve(n,ans);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends