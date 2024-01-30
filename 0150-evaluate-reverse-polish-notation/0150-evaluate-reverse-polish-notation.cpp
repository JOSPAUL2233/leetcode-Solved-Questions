class Solution {
public:
    
    bool isSymbol(string s){
        
        return s=="/" || s=="+" || s=="-" || s=="*";
        
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(string s : tokens){
            
          if(isSymbol(s)){
              
              int b = st.top();
              st.pop();
              int a = st.top();
              st.pop();
              
              int ans = 0;
              
              if(s=="-") ans = a-b;
              if(s=="*") ans = a*b;
              if(s=="/") ans = a/b;
              if(s=="+") ans = a+b;
              
              st.push(ans);
              
          }else{
              
              st.push(stoi(s));
              
          }
            
        }
        
        return st.top();
        
    }
};