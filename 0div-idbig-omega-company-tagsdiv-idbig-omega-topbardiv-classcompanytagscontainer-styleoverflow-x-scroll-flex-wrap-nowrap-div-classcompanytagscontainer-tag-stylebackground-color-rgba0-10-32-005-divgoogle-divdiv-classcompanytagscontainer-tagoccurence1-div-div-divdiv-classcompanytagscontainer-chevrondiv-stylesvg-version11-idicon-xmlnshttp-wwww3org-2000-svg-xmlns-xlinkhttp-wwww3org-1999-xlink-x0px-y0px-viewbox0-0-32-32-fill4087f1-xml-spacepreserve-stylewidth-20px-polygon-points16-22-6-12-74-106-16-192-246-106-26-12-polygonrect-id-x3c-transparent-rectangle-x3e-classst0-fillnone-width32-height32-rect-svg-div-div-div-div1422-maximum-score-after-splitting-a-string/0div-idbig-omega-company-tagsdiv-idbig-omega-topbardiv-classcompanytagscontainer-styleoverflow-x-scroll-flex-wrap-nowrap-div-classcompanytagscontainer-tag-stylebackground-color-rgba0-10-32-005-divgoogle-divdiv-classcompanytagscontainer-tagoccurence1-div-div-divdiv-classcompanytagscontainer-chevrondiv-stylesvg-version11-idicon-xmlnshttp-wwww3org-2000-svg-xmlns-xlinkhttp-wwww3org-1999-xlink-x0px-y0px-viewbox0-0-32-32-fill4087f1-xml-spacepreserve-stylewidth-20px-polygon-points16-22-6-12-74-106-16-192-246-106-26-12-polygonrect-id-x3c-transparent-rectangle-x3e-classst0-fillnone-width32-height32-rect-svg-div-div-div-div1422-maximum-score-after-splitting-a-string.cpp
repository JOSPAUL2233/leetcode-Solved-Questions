class Solution {
public:
    int maxScore(string s) {
        
        vector<int> leftSide(s.size(),0);
        vector<int> rightSide(s.size(),0);
        
        int left = 0;
        int right = 0;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] == '0')
                left++;
            
            if(s[s.size()-1-i] == '1')
                right++;
                
            leftSide[i] = left;
            rightSide[s.size()-1-i] = right;
            
        }
        
        int maxScore = 0;
        
        for(int i = 0;i<s.size()-1;i++){
            
            int score = leftSide[i] + rightSide[i+1];
            maxScore = max(maxScore,score);
            
        }
        
        return maxScore;
        
    }
};