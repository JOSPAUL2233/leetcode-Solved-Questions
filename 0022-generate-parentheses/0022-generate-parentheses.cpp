class Solution {
    
    bool isValid(string path){
        
        stack<char> st;
        
        for(int i = 0;i<path.size();i++){
            
            char curr = path[i];
            
            if(!st.empty()){
                
                if(curr=='(' || (curr==')' && st.top()==')'))st.push(curr);
            
                if(curr==')' && st.top()=='('){

                    st.pop();

                }
                
            }else{
                st.push(curr);
            }
            
                    
        }
        
        if(st.empty())return true;
        else return false;
        
    }
    
    void solve(vector<string> &ans,string path,int n){
        
        if(path.size()==2*n){
            
            if(isValid(path)){
                
                ans.push_back(path);
                
            }
            
            return;
            
        }
        
        path+='(';
        solve(ans,path,n);
        path.pop_back();
        
        path+=')';
        solve(ans,path,n);
        path.pop_back();

    }
    
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        
        string path = "";
        
        solve(ans,path,n);
        
        return ans;
        
    }
};