class Solution {
public:
    
    string reverse(string s){
        
        int n = s.size();
        
        for(int i = 0;i<n/2;i++)
            swap(s[i],s[n-1-i]);
        
        return s;
        
    }
    
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        
        for(int i = 0; i<num.size();i++){
            
            char c = num[i];
            
            if(st.empty()){
                
                if(c != '0')
                    st.push(c);
                //ignore if the char is 0 and the stack is empty since
                //the answer cannot contain leading zeroes
                
            }else{
                
                //keep removing the peak element
                while(!st.empty() && st.top() > c && k>0){
                    
                    st.pop();
                    k--;
                    
                }
                
            //push the current element into the stack after checking
            //for leading zeroes
            if(st.empty() && c == '0')
                continue;
            else
                st.push(c);
                                
            }
            
        }
        
        //remove remaining k elements from the stack
        while(!st.empty() && k>0){
            
            st.pop();
            k--;
            
        }
        
        //check if the stack is empty
        if(st.empty())
            return "0";
        
        //remove elements from the stack
        
        string ans = "";
        
        while(!st.empty()){
            
            ans += st.top();
            st.pop();
            
        }
        
        //reverset the string
        ans = reverse(ans);
        
        return ans;
        
    }
};