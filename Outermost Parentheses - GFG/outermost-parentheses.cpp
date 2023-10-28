//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        
        int count = 0;
        string ans = "";
        
        for(int i = 0;i<s.size();i++){
            
            //conditions where do not have to include in answer
            if(count == 0 && s[i] == '('){
                
                count++;
                continue;
                
            }
            
            if(count == 1 && s[i] == ')'){
                
                count--;
                continue;
                
            }
            
            //conditions where i have to include in answer
            ans.push_back(s[i]);
            
            //update count
            if(s[i] == '(')
                count++;
                
            if(s[i] == ')')
                count--;
            
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
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends