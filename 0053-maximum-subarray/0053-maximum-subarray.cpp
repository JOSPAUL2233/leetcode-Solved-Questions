class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int asum = INT_MIN;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            
            if(asum<sum)asum = sum;
            if(sum<0)sum = 0;
            
        }
        
        return asum;
        
    }
};