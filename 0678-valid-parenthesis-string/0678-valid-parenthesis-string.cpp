class Solution {
public:
    bool checkValidString(string s) {
        
        //maintain seperate brackets for opening brackets and stars
        stack<int> open,star;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] == '*'){
                
                //if it's a star, simply push it into star stack
                star.push(i);

            }else if(s[i] == '('){

                //if it's an opening bracket, simply push it into opening stack  
                open.push(i);
                    
            }else{
                
                    //if it's closing bracket, check in opening stack first, then in star stack
                    //if nothing can cancel it out, then it's an invalid string
                
                    if(!open.empty()){
                        open.pop();
                    }else if(!star.empty()){
                        star.pop();
                    }else{
                        return false;
                    }
                    
            }
                
        }
        
        //if there are some opening brackets left, make sure that starts can cancel them out by checking
        //that the starts are coming after each opening brackets, so comparing the indices
        
        while(!open.empty() && !star.empty() && open.top() < star.top()){
            open.pop();
            star.pop();
        }

        //if the stack is empty, then it's valid otherwise it's invalid
        return open.empty();        
                
            
    }
        
};