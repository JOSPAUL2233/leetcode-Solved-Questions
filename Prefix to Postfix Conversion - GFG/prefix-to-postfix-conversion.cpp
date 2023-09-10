//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        
        
        stack<string> st;
        
        for(int i = pre_exp.size()-1; i>=0 ;i--){
            
            char c = pre_exp[i];
            //check if the char is operand
            if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                
                //push the char into the stack
                string temp(1,c);
                st.push(temp);
                
            }else{
                
                //take out the top two elements and place in
                //the order of postfix
                string first = st.top();
                st.pop();
                
                string second = st.top();
                st.pop();
                
                st.push(first+second+c);
                
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends