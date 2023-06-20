class Solution {
public:
    void reverseString(vector<char>& s) {
        
        stack<char> st;
        
        for(int i = 0;i<s.size();i++){
            
            st.push(s[i]);
            
        }
        
        vector<char> ans;
        
        while(!st.empty()){
            
            ans.push_back(st.top());
            st.pop();
            
        }
        
        s = ans;
        
    }
};