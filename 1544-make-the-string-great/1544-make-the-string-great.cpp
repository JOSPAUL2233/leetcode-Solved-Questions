class Solution {
public:
    
    bool check(char a,char b){
                
        if((a>='a' && a<='z') && (b>='A' && b<='Z'))
            return (a-'a') == (b-'A');
        
        if((b>='a' && b<='z') && (a>='A' && a<='Z'))
            return (a-'A') == (b-'a');
        
        return false;
        
    }
    
    string makeGood(string s) {
        
        stack<char> st;
                
        for(int i = 0;i<s.size();i++){
            
            char c = s[i];
            
            if(st.size()==0)
                st.push(c);
            else if(!check(c,st.top())){
                st.push(c);
            }else
                st.pop();
            
        }
        
        string ans = "";
        
        while(st.size()>0){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};