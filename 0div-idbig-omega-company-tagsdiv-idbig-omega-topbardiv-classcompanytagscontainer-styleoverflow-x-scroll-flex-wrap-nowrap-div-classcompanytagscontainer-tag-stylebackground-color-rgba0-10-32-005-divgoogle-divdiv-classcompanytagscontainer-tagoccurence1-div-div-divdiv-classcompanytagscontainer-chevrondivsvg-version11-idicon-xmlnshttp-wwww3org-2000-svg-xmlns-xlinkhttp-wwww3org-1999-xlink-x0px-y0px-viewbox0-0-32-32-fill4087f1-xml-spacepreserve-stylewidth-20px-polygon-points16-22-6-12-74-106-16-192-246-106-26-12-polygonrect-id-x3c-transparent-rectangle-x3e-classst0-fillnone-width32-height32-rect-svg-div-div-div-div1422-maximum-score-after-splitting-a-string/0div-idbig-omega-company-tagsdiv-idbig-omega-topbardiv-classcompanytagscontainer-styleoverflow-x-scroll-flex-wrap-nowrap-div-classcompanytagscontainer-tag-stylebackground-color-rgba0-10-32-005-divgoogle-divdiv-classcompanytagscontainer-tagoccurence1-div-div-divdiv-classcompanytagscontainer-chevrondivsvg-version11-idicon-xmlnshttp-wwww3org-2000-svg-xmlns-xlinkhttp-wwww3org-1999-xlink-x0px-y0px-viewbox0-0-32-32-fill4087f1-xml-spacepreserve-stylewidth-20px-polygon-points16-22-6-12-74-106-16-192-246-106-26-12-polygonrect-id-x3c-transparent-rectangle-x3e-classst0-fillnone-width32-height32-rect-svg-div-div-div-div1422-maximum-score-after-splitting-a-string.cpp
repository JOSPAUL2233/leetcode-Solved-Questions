class Solution {
public:
    int maxScore(string s) {
        
        int leftZeros = 0;
        int rightOnes = 0;
        
        for(char c : s)
            if(c == '1')
                rightOnes++;
        
        int maxScore = 0;
        
        for(int i = 0;i<s.size()-1;i++){
            
            if(s[i] == '0')
                leftZeros++;
            else
                rightOnes--;
            
            int score = leftZeros + rightOnes;
            maxScore = max(maxScore,score);
            
        }
        
        return maxScore;
        
    }
};