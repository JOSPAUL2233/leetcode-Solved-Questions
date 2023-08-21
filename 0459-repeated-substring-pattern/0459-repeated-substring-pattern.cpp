class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        for(int i = 1;i<s.size();i++){
            
            //if i divides the entire size completely
            if(s.size() % i == 0){
                
                string pattern = "";
                
                //copy the substring s.size()/i times
                for(int j = 0;j<s.size()/i;j++){
                    
                    pattern += s.substr(0,i);
                    
                }
                
                //if the pattern matches the original string
                if(s == pattern)
                    return true;
                
            }
            
        }
        
        return false;
        
    }
};