//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        
        //edge case, since a null string is also a substring
        if(s.size() == 0)
            return s;
            
        string ans = "";
        
        for(int i = s.size()-1 ; i>=0 ; i--){
            
            int digit = s[i] - '0';
            if(digit % 2 != 0){
                
                ans = s.substr(0,i+1);
                break;
                
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
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends