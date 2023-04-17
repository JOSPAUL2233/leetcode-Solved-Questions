class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxIndex = 0;
        vector<bool> ans(candies.size(),true);
        
        for(int i = 1;i<candies.size();i++){
            
            if(candies[i] > candies[maxIndex])maxIndex = i;
            
        }
        
        for(int i = 0;i<candies.size();i++){
            
            int curr = candies[i] + extraCandies;
            
            if(curr < candies[maxIndex])ans[i] = false;
            
        }
        
        return ans;
        
        
    }
};