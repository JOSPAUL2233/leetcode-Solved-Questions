class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(auto x:s){
            
            if(x=='[' || x=='{' || x=='('){
                
                st.push(x);
               
                
            }else{
                
                if(st.empty())return false;
                
                char temp = st.top();
                
                if( (x==']' && temp=='[') || (x=='}' && temp=='{') || (x==')' && temp=='(') ){
                    
                    
                    st.pop();
                    
                }else{
                    
                    return false;
                }
            
            }
            
            
        }
        
       
        
        if(st.empty())return true;
        else return false;
        
        
    }
};