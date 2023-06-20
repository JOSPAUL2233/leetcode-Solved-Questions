class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(auto x:s){
            
            //if element is any opening bracket, directly push
            //it into the stack
            if(x=='[' || x=='{' || x=='('){
                
                st.push(x);
               
                
            }else{
                //stack is empty and there is a closing bracket
                //which directly says that this can't be balanced.
                //because it won't be having any matching opening bracket.
                if(st.empty())return false;
                
                char temp = st.top();
                
                //correct order
                if( (x==']' && temp=='[') || (x=='}' && temp=='{') || (x==')' && temp=='(') ){
                    
                    
                    st.pop();
                    
                }else{//incorrect order
                    
                    return false;
                }
            }
        }
        
        //stack should be empty(all brackets should be cancelled with other pair)
        if(st.empty())
            return true;
        else
            return false;
        
        
    }
};