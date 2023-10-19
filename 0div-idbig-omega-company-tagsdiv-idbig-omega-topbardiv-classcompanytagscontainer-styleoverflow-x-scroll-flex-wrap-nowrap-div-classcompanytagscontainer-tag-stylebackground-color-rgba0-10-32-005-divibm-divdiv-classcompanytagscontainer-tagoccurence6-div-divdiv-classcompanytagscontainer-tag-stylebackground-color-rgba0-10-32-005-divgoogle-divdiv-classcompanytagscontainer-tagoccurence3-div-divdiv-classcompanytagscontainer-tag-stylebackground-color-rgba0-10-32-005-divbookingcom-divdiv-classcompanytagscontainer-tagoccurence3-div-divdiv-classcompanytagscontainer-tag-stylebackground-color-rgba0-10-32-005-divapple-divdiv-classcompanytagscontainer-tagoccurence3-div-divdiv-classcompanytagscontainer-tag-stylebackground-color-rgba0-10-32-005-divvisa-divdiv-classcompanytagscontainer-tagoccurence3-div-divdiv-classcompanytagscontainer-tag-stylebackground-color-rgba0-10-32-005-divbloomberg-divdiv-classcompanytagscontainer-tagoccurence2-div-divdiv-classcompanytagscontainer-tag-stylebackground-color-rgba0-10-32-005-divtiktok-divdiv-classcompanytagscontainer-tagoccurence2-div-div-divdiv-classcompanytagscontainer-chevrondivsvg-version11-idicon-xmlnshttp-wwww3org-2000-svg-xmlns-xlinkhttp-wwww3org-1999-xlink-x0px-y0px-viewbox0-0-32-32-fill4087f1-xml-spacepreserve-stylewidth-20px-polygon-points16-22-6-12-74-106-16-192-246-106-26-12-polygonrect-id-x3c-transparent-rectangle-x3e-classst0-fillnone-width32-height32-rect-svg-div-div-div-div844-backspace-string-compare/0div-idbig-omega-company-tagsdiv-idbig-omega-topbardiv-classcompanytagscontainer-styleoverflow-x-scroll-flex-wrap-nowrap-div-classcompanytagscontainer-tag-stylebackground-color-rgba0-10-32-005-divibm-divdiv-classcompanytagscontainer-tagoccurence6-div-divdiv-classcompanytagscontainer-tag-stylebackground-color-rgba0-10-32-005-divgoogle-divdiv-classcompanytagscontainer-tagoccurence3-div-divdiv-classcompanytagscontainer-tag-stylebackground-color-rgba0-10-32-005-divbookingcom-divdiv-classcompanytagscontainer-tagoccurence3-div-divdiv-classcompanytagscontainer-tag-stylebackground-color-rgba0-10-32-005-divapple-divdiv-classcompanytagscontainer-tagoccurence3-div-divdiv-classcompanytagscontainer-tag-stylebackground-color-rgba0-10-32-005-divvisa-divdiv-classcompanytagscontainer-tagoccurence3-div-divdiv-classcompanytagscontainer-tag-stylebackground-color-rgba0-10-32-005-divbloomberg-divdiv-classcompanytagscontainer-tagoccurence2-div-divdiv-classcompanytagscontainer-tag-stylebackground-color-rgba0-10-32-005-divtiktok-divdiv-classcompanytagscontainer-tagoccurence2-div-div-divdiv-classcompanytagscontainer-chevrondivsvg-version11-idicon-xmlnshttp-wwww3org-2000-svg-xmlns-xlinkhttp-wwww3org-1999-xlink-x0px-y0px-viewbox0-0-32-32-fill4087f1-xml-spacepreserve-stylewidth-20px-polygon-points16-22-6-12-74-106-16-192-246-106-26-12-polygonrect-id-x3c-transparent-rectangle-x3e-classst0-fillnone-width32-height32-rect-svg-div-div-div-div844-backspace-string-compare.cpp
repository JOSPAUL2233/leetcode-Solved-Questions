class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] != '#')
                st.push(s[i]);
            else
                if(!st.empty())
                st.pop();
            
        }
        
        string str1 = "";
        
        while(!st.empty()){
            
            str1.push_back(st.top());
            st.pop();
            
        }
        
        for(int i = 0;i<t.size();i++){
            
            if(t[i] != '#')
                st.push(t[i]);
            else
                if(!st.empty())
                st.pop();
            
        }
        
        string str2 = "";
        
        while(!st.empty()){
            
            str2.push_back(st.top());
            st.pop();
            
        }        
        
        return str1 == str2;
        
    }
};