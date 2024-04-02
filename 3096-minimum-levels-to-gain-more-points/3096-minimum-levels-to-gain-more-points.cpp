class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        
        int n = possible.size();
            
        int totalPoints = 0;
        
        for(int i = 0;i<n;i++){
            
            if(possible[i] == 1)
                totalPoints++;
            else
                totalPoints--;
            
        }
        
        //iterate
        
        int preSum = 0;
        
        for(int i = 0;i<n-1;i++){
            
            if(possible[i] == 1)
                preSum++;
            else
                preSum--;
            
            if(preSum > (totalPoints-preSum))
                return i+1;
            
        }
        
        return -1;        
        
    }
};