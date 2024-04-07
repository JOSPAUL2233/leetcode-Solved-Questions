class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open,star;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] == '*'){
                
                star.push(i);
                
                
            }else if(s[i] == '('){
                    
                    open.push(i);
                    
            }else{
                    
                    if(open.size() > 0){
                        open.pop();
                    }else if(star.size() > 0){
                        star.pop();
                    }else{
                        return false;
                    }
                    
            }
                
        }
        
        while(open.size() > 0 && star.size() > 0 && open.top() < star.top()){
            open.pop();
            star.pop();
        }

        
        return open.size()==0;        
                
            
    }
        
};