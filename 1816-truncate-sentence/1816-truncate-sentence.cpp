class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string ans;
        
        int i = 0;
        
        while(k!=0 && i<s.size()){
            
            if(s[i]!=' ')ans+=s[i];
            else {
                
                k--;
                if(k!=0)ans+=' ';
            }
            
            i++;
        }
        
        return ans;
        
    }
};