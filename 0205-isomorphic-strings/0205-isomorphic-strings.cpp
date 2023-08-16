class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        //edge case
        if(s.size() != t.size())
            return false;
        
        //hashmap
        map<char,char> iso; //charecter to charector mapping
        map<char,bool> used; //tells which is already mapped to char
        
        for(int i = 0;i<s.size();i++){
            
            if(iso.find(s[i]) == iso.end() && !used[t[i]]){
                
                iso[s[i]] = t[i];
                used[t[i]] = true;
                
            }
            else{
                
                if(iso[s[i]] != t[i])
                    return false;
                
            }
                
        }
        
        return true;
        
    }
};