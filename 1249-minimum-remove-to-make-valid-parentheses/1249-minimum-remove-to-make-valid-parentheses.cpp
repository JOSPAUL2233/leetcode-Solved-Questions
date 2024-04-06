class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        set<int> st;
        stack<int> sta;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] == '('){
                
                sta.push(i);
                
            }
            
            if(s[i] == ')'){
                
                if(!sta.empty() && s[sta.top()=='('])
                    sta.pop();
                else
                    st.insert(i);//this is not valid
                
            }
            
        }
        
        //take out all the unclosed opening brackets that are not valid
        while(!sta.empty()){
            st.insert(sta.top());
            sta.pop();
        }
        
        //iterate through string and get the answer
        
        string ans = "";
        
        for(int i = 0;i<s.size();i++){
            if(st.find(i)==st.end())
                ans.push_back(s[i]);
        }
        
        return ans;
        
    }
};