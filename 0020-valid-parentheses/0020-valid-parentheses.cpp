class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        
        for(char x:s){
            
            switch(x){
                    
                case '(':
                    st.push('(');
                    // cout<<st.top()<<endl;
                    
                    break;
                    
                case '{':
                    
                    st.push('{');
                    // cout<<st.top()<<endl;
                    
                    break;
                    
                case '[':
                    
                    st.push('[');
                    // cout<<st.top()<<endl;
                    
                    break;
                    
                    
                    
                case ')':
                    
                    if(!st.empty()){
                        
                        if(st.top()=='('){
                        // cout<<"before:"<<st.top()<<endl;
                        st.pop();
                        // cout<<"after:"<<st.top()<<endl;
                        
                        }else{
                            return false;
                        }
                        
                    }else{
                        return false;
                    }
                    
                    break;
                      
                case '}':
                    
                    if(!st.empty()){
                        
                        if(st.top()=='{'){
                        // cout<<"before:"<<st.top()<<endl;
                        st.pop();
                        // cout<<"after:"<<st.top()<<endl;
                        
                        }else{
                            return false;
                        }
                        
                    }else{
                        return false;
                    }
                    
                    break;

                    
                case ']':
                    
                    if(!st.empty()){
                        
                        if(st.top()=='['){
                        // cout<<"before:"<<st.top()<<endl;
                        st.pop();
                        // cout<<"after:"<<st.top()<<endl;
                        
                        }else{
                            return false;
                        }
                        
                    }else{
                        return false;
                    }
                    
                break;
                       
            }
            
            
        }
        
        // while(!st.empty()){
        //     cout<<st.top()<<endl;
        //     st.pop();
        // }
        
        if(st.empty())return true;
        else return false;
        
        
    }
};