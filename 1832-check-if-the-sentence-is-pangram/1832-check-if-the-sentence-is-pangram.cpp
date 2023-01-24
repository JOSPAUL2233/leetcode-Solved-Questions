class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int> alpha(26,0);
        
        for(int i = 0;i<sentence.size();i++){
            
            
            alpha[sentence[i]-'a']++;
            
        }
        
        for(int i:alpha){
            if(i==0)return false;
        }
        
        return true;
        
    }
};