class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        
        for(int i = 0;i<s.size();i++){
            
            
            if(s[i]=='*')
                st.pop();
            else
                st.push(s[i]);
            
        }
        
        string ans;
        
        while(!st.empty()){
            
            ans.push_back(st.top());
            
            st.pop();
            
        }
        
        //reverse
        
        int n = ans.size();
        
        for(int i = 0;i<n/2; i++){
                        
            swap(ans[i],ans[n-1-i]);
            
        }
        
        return ans;
        
    }
};