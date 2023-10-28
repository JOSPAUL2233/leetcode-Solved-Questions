//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        
        int maxCount = 0;
        int count = 0;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] == '(')
                count++;
                
            if(s[i] == ')')
                count--;
                
            maxCount = max(maxCount,count);
            
        }
        
        return maxCount;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends