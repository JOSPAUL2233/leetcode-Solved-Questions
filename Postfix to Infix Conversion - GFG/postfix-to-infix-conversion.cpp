//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        
        stack<string> st;
        
        for(int i = 0;i<exp.size();i++){
            
            char c = exp[i];
            
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                
                string temp(1, c);
                st.push(temp);
                
            }else{
                
                string second = st.top();
                st.pop();
                
                string first = st.top();
                st.pop();
                
                // string combine = ;
                
                st.push('(' + first + c + second + ')');
                
            }
            
        }
        
        return st.top();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends