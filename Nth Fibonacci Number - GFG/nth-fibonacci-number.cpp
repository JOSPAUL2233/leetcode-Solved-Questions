//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1000000007;
        
    int fibo(int n,vector<int> &dp){
        
        //base case
        if(n <= 1){
            return n;
        }
        
        if(dp[n] != -1)
            return dp[n];
            
        dp[n] = (fibo(n-1,dp) + fibo(n-2,dp)) % mod;
        
        return dp[n];
        
    }
  
    int nthFibonacci(int n){
        
        vector<int> dp(n+1,-1);
        
        return fibo(n,dp) % mod;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends