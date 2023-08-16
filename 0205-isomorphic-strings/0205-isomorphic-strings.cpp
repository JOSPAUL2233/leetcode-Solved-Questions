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
            
            int first = s[i];
            int second = t[i];
            
            //if first element is already mapped to a char
            if(iso.find(first) != iso.end()){
                
                //but second element is different than mapped one
                if(iso[first] != second)
                    return false;
                
            }else{//if element is not mapped
                
                //but 2nd element is already mapped by one
                if(used[second] == true)
                    return false;
                else{
                    
                    //if fist element is not mapped and also
                    //second element is not used by another
                    
                    iso[first] = second;//map fist element to second
                    used[second] = true;//mark this as used.
                    
                    
                }
                
            }
                
        }
        
        return true;
        
    }
};