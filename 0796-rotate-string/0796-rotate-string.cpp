class Solution {
public:
    bool rotateString(string s, string goal) {
        
        
        if(s==goal)return true;
        
        for(int i = 0;i<goal.size();i++){
            
            if(s==goal)return true;
            
            s = s.substr(1)+s[0];
            
        }
        
        return false;
        
        
    }
};