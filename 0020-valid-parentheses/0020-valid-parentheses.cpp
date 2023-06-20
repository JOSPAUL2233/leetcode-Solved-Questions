class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(int i = 0;i<s.size();i++){
            
            char ele = s[i];
            
            //if element is any opening bracket, directly push
            //it into the stack
            if(ele == '(' || ele == '{' || ele == '['){
                
                st.push(ele);
                
            }else{
           
                //stack is empty and there is a closing bracket
                //which directly says that this can't be balanced.
                //because it won't be having any matching opening bracket.
                if(st.empty())
                    return false;
                
                //correct order
                if(( ele == ')' && st.top() == '(' ) || ( ele == ']' && st.top() == '[' )
                                                   ||( ele == '}' && st.top() == '{' )){
                    st.pop();
                                                       
                }else{//wrong order
                                                       
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