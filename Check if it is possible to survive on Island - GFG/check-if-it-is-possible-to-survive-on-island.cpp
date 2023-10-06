//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        
        int sundays = S/7;
        
        int buyingDays = S - sundays;
        int requiredFood = S*M;
        
        int ans = 0;
        
        if(requiredFood % N == 0)
            ans = requiredFood/N;
        else
            ans = requiredFood/N + 1;
        
        //if the minDays is more than buyingDays, then
        //she cannot survive
        
        if(ans > buyingDays)
            return -1;
        else
            return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends