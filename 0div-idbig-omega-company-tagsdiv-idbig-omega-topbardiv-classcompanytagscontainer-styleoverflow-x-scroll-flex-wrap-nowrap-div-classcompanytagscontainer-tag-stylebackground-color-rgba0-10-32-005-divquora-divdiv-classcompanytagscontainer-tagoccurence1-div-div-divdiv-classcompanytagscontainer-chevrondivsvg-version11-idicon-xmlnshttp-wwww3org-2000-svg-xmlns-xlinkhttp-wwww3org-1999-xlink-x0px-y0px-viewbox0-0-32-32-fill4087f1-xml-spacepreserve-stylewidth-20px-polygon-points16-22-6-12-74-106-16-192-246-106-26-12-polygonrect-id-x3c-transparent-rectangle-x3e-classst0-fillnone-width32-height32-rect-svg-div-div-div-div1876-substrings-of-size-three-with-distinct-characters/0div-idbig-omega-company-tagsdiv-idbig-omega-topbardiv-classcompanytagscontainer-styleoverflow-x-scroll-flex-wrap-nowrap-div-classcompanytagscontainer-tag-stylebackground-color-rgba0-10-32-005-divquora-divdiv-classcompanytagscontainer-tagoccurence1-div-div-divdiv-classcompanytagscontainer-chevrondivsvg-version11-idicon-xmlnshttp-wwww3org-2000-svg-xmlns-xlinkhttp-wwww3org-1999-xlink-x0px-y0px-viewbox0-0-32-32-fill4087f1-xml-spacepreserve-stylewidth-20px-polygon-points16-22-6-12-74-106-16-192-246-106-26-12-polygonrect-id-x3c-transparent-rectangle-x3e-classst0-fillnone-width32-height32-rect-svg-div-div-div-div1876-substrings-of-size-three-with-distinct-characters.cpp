class Solution {
public:
    int countGoodSubstrings(string s) {
        
        if(s.size() < 3)
            return 0;
        
        char a = s[0];
        char b = s[1];
        char c = s[2];
        
        int count = 0;
        
        for(int i = 3;i<s.size();i++){
                        
            if((a != b) && (b != c) && (a != c)){
                count++;
            }
            a = b;
            b = c;
            c = s[i];
            
        }
        
        if((a != b) && (b != c) && (a != c)){
            count++;
        }
        
        return count;

        
    }
};