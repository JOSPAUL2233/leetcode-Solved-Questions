//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool isSet(int i,long long x){
        
        //checking if the ith bit from last position
        //is 1 or 0
        if((x & (1LL<<i)) != 0)
            return true;
        else
            return false;
        
    }
    
    long long reversedBits(long long X) {
        
        long long ans = 0;
        
        //iterate 32 times
        for(int i = 0;i<32;i++){
            
            //check if the corresponding bit is set
            if(isSet(i,X)){
                
                //set the rev bit (31 - i th bit) to one
                ans = ans | (1LL << (31 - i));
                
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends