class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        //they are not isomorphic if they have unequal lengths
        if(s.size() != t.size())
            return false;
        
        //check seperate mapping from both the directions
        map<char,char> left;
        map<char,char> right;
        
        for(int i = 0;i<s.size();i++){
            
            //check for left mapping
            if(left.find(s[i]) == left.end()){//not mapped yet
                left[s[i]] = t[i];                
            }else{
                
                //check whether the mapping was different before
                if(left[s[i]] != t[i])
                    return false;
                
            }
            
            //check for right mapping
            if(right.find(t[i]) == right.end()){//not mapped yet
                right[t[i]] = s[i];
            }else{
                
                //check whether the mapping was different before
                if(right[t[i]] != s[i])
                    return false;
                
            }
            
        }
        
        return true;
        
    }
};