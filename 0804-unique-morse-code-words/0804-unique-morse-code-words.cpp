class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        set<string> s;
        
        vector<string> alpha{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        
        for(int i = 0;i<words.size();i++){
            
            string single = words[i];
            
            string ans;
            
            for(int j = 0;j<single.size();j++){
                
                ans+=(alpha[ single[j] - 'a' ]);
                
            }
            
            s.insert(ans);
            
        }
        
        return s.size();
            
        }
        
};