class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        map<char,char> left;
        map<char,char> right;
        
        for(int i = 0;i<s.size();i++){
            
            //check for left mapping
            if(left.find(s[i]) == left.end()){
                left[s[i]] = t[i];                
            }else{
                
                if(left[s[i]] != t[i])
                    return false;
                
            }
            
            //check for right mapping
            if(right.find(t[i]) == right.end()){
                right[t[i]] = s[i];
            }else{
                
                if(right[t[i]] != s[i])
                    return false;
                
            }
            
        }
        
        return true;
        
    }
};